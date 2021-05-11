 // Template by Zayed 

#include bitsstdc++.h
#include iostream
#include cstdio
#include iomanip

#include string
#include cstring
#include sstream

#include tuple
#include vector
#include stack
#include queue
#include deque
#include list
#include map
#includeunordered_map
#include set
#includeunordered_set

#include algorithm
#include bitset
#include cmath
#include cstdlib

typedef long long LL;NOTES%lld
typedef unsigned long long ULL;NOTES%llu

using namespace std;
int caseno = 1;

#define NL 'n'
#define SF scanf
#define PF printf
#define PC() printf(Case %d , caseno++)NOTESprintf
#define BUG() printf(n!!!!!!WHERE IS YOUR FOCUS!!!!!!n) NOTESprintf

#define BUG cout  n!!!!!!WHERE IS YOUR FOCUS!!!!!!n NOTEScout
#define PC cout  Case NOTEScout
#define CN cout  caseno++   NOTEScout

#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define READ() freopen(input.txt, r, stdin)
#define WRITE() freopen(output.txt, w, stdout)
#define BOOST stdios_basesync_with_stdio(0);
#define FOR(I,J,K) for(I = J; I  K; I++)
#define REV(I,J,K) for(I = J; I  K; I--)

#define INTMAX (1LL  31) - 1
#define LLMAX (1LL  63) - 1
#define MOD 1000000007		     (10^9 + 7)
#define PRIME 999998727899999    (largest prime below 10^16)
#define PB push_back
#define pii pairint, int
#define pdd pairdouble, double
#define pic pairint, char
#define pci pairchar, int
#define pLL pairLL, LL
#define pis pairint, string
#define psi pairstring, int
#define pss pairstring, string
#define tiii tupleint, int, int
#define PI 2  acos(0.0)
#define EPS 1e-11


template class T  bool Inside(T a, T b, T c) { return a = b && b = c; }
template  class T  inline void SWAP(T &a, T &b) { T t = a; a = b; b = t; }
inline LL POW(LL base, LL P){
	LL res = 1;
	while(P  0){ if(P & 1) res = res  base;
        base = base  base;
        P = 1;
	}
	return res;
}

Translator Functions
int ToInt(string s) { int r = 0; istringstream sin(s); sin  r; return r; }NOTESToInt(
double ToDouble(string s) { double r = 0; istringstream sin(s); sin  r; return r; }NOTESToDouble(
string ToString(int n) { string s; stringstream convert; convert  n; s = convert.str(); return s; }NOTESToString(

int dx[] = {0, 0, -1, +1}, dy[] = {-1, +1, 0, 0}; 4 Direction Array
int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1}; 8 Direction Array
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1}; Knight Moves

string target;

int main()
{
	BOOST
	READ();
	WRITE();
	int T, I, J, K, N, n, m, k, cnt = 0, len;

	cin  T;

	while(T--){
		cin  n;

		if(n = 2){
			cout  0  NL;
		} else if(n & 1){
			cout  n  2  NL;
		} else{
			cout  n  2 - 1  NL;
		}
	}

	return 0;
}
