// UVa 10026 - Shoemaker's Problem.cpp
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

#include <algorithm>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>

#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

int caseno = 1;
#define NL '\n'
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
#define SF scanf
#define PF printf
#define sf1(x) scanf("%d",&x)
#define pf1(x) printf("%d",x)
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define PC() printf("Case %d: ", caseno++)
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);

// BEGINTEMPLATE_BY_ZAYED
typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

template <class T> inline void checkmax(T &a, T b){ if (b > a) a = b; }//NOTES:checkmax(
template <class T> inline void checkmin(T &a, T b){ if (b < a) a = b; }//NOTES:checkmin(
template <class T> inline T MAX(T a, T b){ return (a > b) ? a : b; }
template <class T> inline T MIN(T a, T b){ return (a < b) ? a : b; }
template <class T> inline T sqr(T x){ return x * x; }//NOTES:square
template <class T> inline T fABS(T a) { return a < 0 ? a * (-1) : a; }
template <class T> inline void SWAP(T &a, T &b) { T t = a; a = b; b = t; }
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
const int SIZE = 1000 + 10;

struct job
{
	int time;
	int fine;
	int jobID;
};

job ar[SIZE];

bool Compare(const job &a, const job &b)
{
	double r1 = (double)a.fine / (double)a.time;
	double r2 = (double)b.fine / (double)b.time;

	return r1 > r2;
}

int main()
{
	///BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len;
	///READ();
	///WRITE();
	SF("%d", &tcases);
	while(tcases--)
	{
		SF("%d", &N);

		for(I = 0; I < N; I++)
		{
			SF("%d%d", &ar[I].time, &ar[I].fine);
			ar[I].jobID = I + 1;
		}
		/*
		for(I = 0; I < N; I++)
		{
			cout << ar[I].time << " " << ar[I].fine << " " << ar[I].jobID << NL;
		}
		*/
		stable_sort(ar, ar + N, Compare);

		PF("%d", ar[0].jobID);
		for(I = 1; I < N; I++)
			PF(" %d", ar[I].jobID);

		PF("\n");

		if(tcases)
			PF("\n");
	}

	return 0;
}

