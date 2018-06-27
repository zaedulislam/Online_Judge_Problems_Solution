// HackerRank - Identify Smith Numbers.cpp
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

#define LI long long int
#define INF 2147483648
#define MOD 1000000007

#define NL '\n'
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
#define sf1(x) scanf("%d",&x)
#define sf scanf
#define pf1(x) printf("%d",x)
#define pf printf

using namespace std;

// BEGINTEMPLATE_BY_ZAYED
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e5;

typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long LL;//NOTES:"%lld"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

template<class T> inline void checkmin(T &a, T b){ if (b < a) a = b; }//NOTES:checkmin(
template<class T> inline void checkmax(T &a, T b){ if (b > a) a = b; }//NOTES:checkmax(
template<class T> inline T sqr(T x){ return x * x; }//NOTES:square
template<class T> inline T MAX(T a, T b){ return (a > b) ? a : b; }
template<class T> inline T MIN(T a, T b){ return (a < b) ? a : b; }
template<class T> inline T fABS(T a) { return a< 0 ? a * (-1) : a; }
template<class T> inline void SWAP(T &a, T &b) { T t = a; a = b; b = t; }
inline LL POW(LL base, LL power){
	LL I, res = base; if (power == 0) return 1;
	for (I = 0; I < power - 1; I++) res *= base;
	return res;
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

// fflush(stdout);
string S, T;
char s[SIZE];
int ar[SIZE];
int M[1000][1000];

int status[SIZE], prime[SIZE];

void sieve(int n)
{
	int I, K, sqrtN = int(sqrt((double)n));

	for(I = 3; I <= sqrtN; I += 2){
		if(!status[I]){
			for(K = I * I; K <= SIZE; K += 2 * I){ // Here I <= n will result in Segmentation Fault
				status[K] = 1;
			}
		}
	}
	K = 0;
	prime[K++] = 2;
    // Here I <= n will result in Segmentation Fault
	for(I = 3; I <= SIZE; I += 2){
		if(!status[I]) prime[K++] = I;
	}
}

int factor(int n)
{
    int I, K, sumFactors = 0, sqrtN = int(sqrt((double)n));
    for(I = 0; prime[I] <= sqrtN; I++){
		if(n % prime[I] == 0){
            while(n % prime[I] == 0){
				n /= prime[I];
				int p = prime[I];
				while(p > 0){
					sumFactors += p % 10;
					p /= 10;
				}
            }
		}
    }
    if(n > 1) {
		while(n > 0){
			sumFactors += n % 10;
			n /= 10;
		}
    }
	return sumFactors;
}

int main()
{
	//std::ios_base::sync_with_stdio(0);
	int tcases, caseno = 1, I, J, K, N, n, m, cnt = 0, len, sumDigits = 0;

	sf("%d", &N);
	sieve(N);

	n = N;
	while(n > 0){
		sumDigits += n % 10;
		n /= 10;
	}
	int sumFactors = factor(N);
	if(sumDigits == sumFactors) pf("1\n");
	else pf("0\n");

	return 0;
}
