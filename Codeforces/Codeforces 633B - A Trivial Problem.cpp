// Codeforces 633B - A Trivial Problem.cpp
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

#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iomanip>

int caseno = 1;
#define NL '\n'
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
#define sf1(x) scanf("%d",&x)
#define sf scanf
#define pf1(x) printf("%d",x)
#define pf printf
#define PC() printf("Case %d: ", caseno++)
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
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
inline LL POW(LL base, LL power){ LL I, res = base; if (power == 0) return 1;
	for (I = 0; I < power - 1; I++) res *= base; return res; }
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
const int SIZE = 400020;

// fflush(stdout);
int ar[SIZE];

int findTrailingZeros(int n)
{
	int I = 5, cnt = 0;
	while(n / I >= 1)
	{
		cnt += n / I;
		I *= 5;
	}
	//cout << n << " = " << cnt << NL;
	return cnt;
}

void upperLower(int mid)
{
	int I, K, upper = 0, lower = 0;
	for(I = mid - 1; I >= 0; I--)
	{
		if(ar[I] != ar[mid])
		{
			lower = I;
			break;
		}
	}

	for(I = mid + 1;  I < SIZE; I++)
	{
		if(ar[I] != ar[mid])
		{
			upper = I;
			break;
		}
	}
	pf("%d\n", upper - lower - 1);
	for(I = lower + 1; I < upper; I++)
		pf("%d ", I);
	pf("\n");
	//cout << "L = " << lower << " U = " << upper << NL;
}

void binarySearch(int value)
{
    int first = 0, last = SIZE - 1, mid;
    bool found = false;
    while(first <= last)
	{
		mid = (first + last) / 2;
        if(ar[mid] == value)
		{
			upperLower(mid);
			//cout << mid << NL;
			found = true;
			break;
        }
		else if(ar[mid] > value)
			last = mid - 1;
		else first = mid + 1;
	}
	if(!found) pf("0\n");
}

int main()
{
	//std::ios_base::sync_with_stdio(0);
	int tcases, I, J, K, N, n, m, cnt = 0, len;
    //READ();
    //WRITE();
    sf("%d", &m);

	for(I = 1; I < SIZE; I++)
	{
        ar[I] = findTrailingZeros(I);
	}

	binarySearch(m);

	return 0;
}
