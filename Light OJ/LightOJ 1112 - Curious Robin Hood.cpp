// LightOJ 1112 - Curious Robin Hood.cpp
#include <iostream>
#include <cstdio>

#include <string>
#include <cstring>
#include <sstream>

#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>

#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>

#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstdlib>
#include <ctime>

int caseno = 1;
#define NL '\n'
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
#define sf scanf
#define pf printf
#define sf1(x) scanf("%d",&x)
#define pf1(x) printf("%d",x)
#define PC() printf("Case %d:", caseno++)
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);
using namespace std;

// BEGINTEMPLATE_BY_ZAYED
typedef unsigned long long ULL;//NOTES:"%llu"
typedef unsigned long long uint64;//NOTES:uint64
typedef long long LL;//NOTES:"%lld"
typedef long long int64;//NOTES:int64

template<class T> inline void checkmax(T &a, T b){ if (b > a) a = b; }//NOTES:checkmax(
template<class T> inline void checkmin(T &a, T b){ if (b < a) a = b; }//NOTES:checkmin(
template<class T> inline T MAX(T a, T b){ return (a > b) ? a : b; }
template<class T> inline T MIN(T a, T b){ return (a < b) ? a : b; }
template<class T> inline T sqr(T x){ return x * x; }//NOTES:square
template<class T> inline T fABS(T a) { return a< 0 ? a * (-1) : a; }
template<class T> inline void SWAP(T &a, T &b) { T t = a; a = b; b = t; }
inline LL POW(LL base, LL power){
	LL I, res = base; if (power == 0) return 1;
	for (I = 0; I < power - 1; I++) res *= base; return res;
}
//Translator
bool isUpperCase(char c){ return c >= 'A' && c <= 'Z'; }//NOTES: isUpperCase(
bool isLowerCase(char c){ return c >= 'a' && c <= 'z'; }//NOTES: isLowerCase(
bool isVowel(char c) { return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'); }//NOTES: isVowel(
bool isLetter(char c){ return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }//NOTES: isLetter(
bool isDigit(char c){ return c >= '0' && c <= '9'; }//NOTES:isDigit(
char toLowerCase(char c){ return (isUpperCase(c)) ? (c + 32) : c; }//NOTES: toLowerCase(
char toUpperCase(char c){ return (isLowerCase(c)) ? (c - 32) : c; }//NOTES: toUpperCase(
int toInt(string s){ int r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:toInt(
double toDouble(string s){ double r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:toDouble(
string toString(int n){ string s; stringstream convert; convert << n; s = convert.str(); return s; }//NOTES:toString
// ENDTEMPLATE_BY_ZAYED

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e5 + 10;

// fflush(stdout);
int ar[SIZE];
int tree[4 *SIZE];

void init(int node, int begin, int end)
{
	if(begin == end)
	{
		tree[node] = ar[begin];
		return;
	}

	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (begin + end) / 2;
    init(left, begin, mid);
    init(right, mid + 1, end);
	tree[node] = tree[left] + tree[right];
	//cout << "NODE : " << node << " = " << tree[node] << NL;
}

void update(int node, int begin, int end, int I, int newValue)
{
	if(begin > I || end < I)
		return;
	if(begin >= I && end <= I)
	{
		pf("%d\n", tree[node]);
		tree[node] = newValue;
		return;
	}

	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (begin + end) / 2;
	update(left, begin, mid, I, newValue);
	update(right, mid + 1, end, I, newValue);
	tree[node] = tree[left] + tree[right];
}

void add(int node, int begin, int end, int I, int newValue)
{
	if(begin > I || end < I)
		return;
	if(begin >= I && end <= I)
	{
		tree[node] = tree[node] + newValue;
		return;
	}

	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (begin + end) / 2;
	add(left, begin, mid, I, newValue);
	add(right, mid + 1, end, I, newValue);
	tree[node] = tree[left] + tree[right];
}

int query(int node, int begin, int end, int I, int J)
{
	if(begin > J || end < I)
		return 0;
	if(begin >= I && end <= J)
		return tree[node];

	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (begin + end) / 2;
	int p1 = query(left, begin, mid, I, J);
	int p2 = query(right, mid + 1, end, I, J);
	return p1 + p2;
}

int main()
{
	//BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, q, v;
	//READ();
	//WRITE();
	sf("%d", &tcases);
	while(tcases--)
	{
		memset(ar, 0, sizeof(ar));
		sf("%d%d", &N, &q);

		for(I = 1; I <= N; I++)
			sf("%d", &ar[I]);

		init(1, 1, N);

		PC();
		pf("\n");
		for(K = 0; K < q; K++)
		{
			sf("%d", &n);
			if(n == 1)
			{
				sf("%d", &I);
				update(1, 1, N, I + 1, 0);
			}
			else if(n == 2)
			{
				sf("%d%d", &I, &v);
				add(1, 1 , N, I + 1, v);
			}
			else
			{
				sf("%d%d", &I, &J);
				pf("%d\n", query(1, 1, N, I + 1, J + 1));
			}
		}
	}

	return 0;
}

