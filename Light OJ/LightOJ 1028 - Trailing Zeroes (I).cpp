// LightOJ 1028 - Trailing Zeroes (I).cpp
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
const int SIZE = 1e6 + 10;

// fflush(stdout);
int prime[SIZE], primeSZ;
bool status[SIZE];

void sieve()
{
	int I, K, sqrtN = int(sqrt((double)SIZE));

	for(I = 3; I <= sqrtN; I += 2)
	{
		if(status[I] == 0)
		{
			for(K = I * I; K <= SIZE; K += 2 * I)
				status[K] = 1;
		}
	}

	primeSZ = 0;
	prime[primeSZ++] = 2;
	for(I = 3; I <= SIZE; I += 2)
	{
		if(status[I] == 0)
			prime[primeSZ++] = I;
	}
}

int findTrailingZeros(LL N)
{
	int I, K, p = 0, NOD = 1, sqrtN = int(sqrt((double)N));
	for(I = 0; I < primeSZ && prime[I] <= sqrtN; I++)
	{
		if(N % prime[I] == 0)
		{
			p = 0;
			while(N % prime[I] == 0)
			{
				N /= prime[I];
				p++;
			}
			sqrtN = int(sqrt((double)N));
			NOD = NOD * (p + 1);
		}
	}

	if(N > 1)
		NOD = NOD * (1 + 1);

	return NOD - 1; // Every Number is divisible by 1.1 -> In Base 1, no trailing zero exists.
}

int main()
{
	//std::ios_base::sync_with_stdio(0);
	LL tcases, I, J, K, N, n, m, cnt = 0, len;
    //READ();
    //WRITE();
    sieve();
	sf("%lld", &tcases);
	while(tcases--)
	{
		sf("%lld", &N);
		PC();
		pf("%d\n", findTrailingZeros(N));
	}

	return 0;
}



