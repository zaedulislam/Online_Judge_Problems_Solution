//  Codeforces 271B - Prime Matrix.cpp
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
const int SIZE = 1e5 + 10;

// fflush(stdout);
int status[SIZE], prime[SIZE], M[510][510], primeM[510][510], pSIZE;

void sieve()
{
	int I, K, sqrtN = int(sqrt((double)SIZE));
	status[0] = 1; status[1] = 1;
	for(I = 2;  I <= sqrtN; I++)
	{
		if(!status[I])
		{
			for(K = I * I ; K <= SIZE; K += I)
			{
                if(!status[K])
					status[K] = 1;
 			}
		}
	}
	K = 0;
	prime[K++] = 2;
	for(I = 3; I <= SIZE; I += 2)
	{
		if(!status[I])
			prime[K++] = I;
	}
	pSIZE = K;
}

int binarySearch(int val)
{
	int first = 0, last = pSIZE - 1, mid, soFar = INF;
	while(first <= last)
	{
		mid = (first + last) / 2;
		if(prime[mid] < val)
			first = mid + 1;
		else if(prime[mid] > val)
		{
			soFar = MIN(soFar, prime[mid]);
			//cout << soFar << NL;
			last = mid - 1;
		}
	}
	return soFar;
}

int main()
{
	//std::ios_base::sync_with_stdio(0);
	int tcases, I, J, K, N, n, m, cnt = 0, len, r, c, p, f = 0, mov = INF, s1 , s2;
    //READ();
    //WRITE();
    sieve();
	sf("%d%d", &r, &c);

	for(I = 0; I < r; I++)
	{
		for(K = 0; K < c; K++)
		{
			sf("%d", &M[I][K]);
            n = M[I][K];
            if(status[n] == 0)
				primeM[I][K] = n;
			else
			{
				p = binarySearch(n);
				//cout << p << NL;
				primeM[I][K] = p;
			}
		}
	}

	for(I = 0; I < r; I++)
	{
		s1 = 0, s2 = 0;
		for(K = 0; K < c; K++)
			s1 += M[I][K];

		for(K = 0; K < c; K++)
			s2 += primeM[I][K];
		mov = MIN(mov, (s2 - s1));
	}

	for(I = 0; I < c; I++)
	{
		s1 = 0, s2 = 0;
		for(K = 0; K < r; K++)
			s1 += M[K][I];

		for(K = 0; K < r; K++)
			s2 += primeM[K][I];
		mov = MIN(mov, (s2 - s1));
	}

    pf("%d\n", mov);

	return 0;
}
