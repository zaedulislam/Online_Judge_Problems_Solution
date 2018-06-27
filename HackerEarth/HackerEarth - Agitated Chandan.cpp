// HackerEarth - Agitated Chandan.cpp
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
#define PC() printf("Case %d: ", caseno++)
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
template<class T> inline T fABS(T a) { return a < 0 ? a * (-1) : a; }
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
const int SIZE = 100000 + 10;

// fflush(stdout);
struct node
{
	int n;
	int d;
};
node info;

vector<node> G[SIZE];
queue<int> qi;
int visited[SIZE], dis[SIZE], N;

int bfs(int src)
{
	while (!qi.empty())
		qi.pop();

	memset(visited, 0, sizeof(visited));
	memset(dis, 0, sizeof(dis));

	dis[src] = 0;
	visited[src] = 1;
	qi.push(src);

	int I, u, v;
	while (!qi.empty())
	{
		u = qi.front();
		qi.pop();
		for (I = 0; I < G[u].size(); I++)
		{
			v = G[u][I].n;
			if (visited[v] == 0)
			{
				visited[v] = 1;
				dis[v] = dis[u] + G[u][I].d;
				qi.push(v);
			}
		}
	}

	int mx = 0, ans = 0;
	for (I = 1; I <= N; I++)
	{
		if (dis[I] > mx)
		{
			mx = dis[I];
			ans = I;
		}
	}
	return ans;
}

int main()
{
	//BOOST
	int tcases, I, J, K, n, m, cnt = 0, len, u, v, w, ans, start, maxDis, money;
	//READ();
	//WRITE();
	sf("%d", &tcases);
	while (tcases--)
	{
		sf("%d", &N);

		for (I = 0; I <= N; I++)
			G[I].clear();

		for (I = 0; I < N - 1; I++)
		{
			sf("%d %d %d", &u, &v, &w);
			info.n = v;
			info.d = w;
			G[u].push_back(info);
			info.n = u;
			G[v].push_back(info);
		}

		start = bfs(1);
		ans = bfs(start);
		maxDis = dis[ans];

		money = 0;
		if (maxDis < 100)
			money = 0;
		else if (maxDis > 100 && maxDis <= 1000)
			money = 100;
		else if (maxDis > 1000 && maxDis <= 10000)
			money = 1000;
		else if (maxDis > 10000)
			money = 10000;

		pf("%d %d\n", money, maxDis);
	}

	return 0;
}






