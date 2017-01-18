// Codeforces 75C - Modified GCD.cpp
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
#define R() freopen("in.txt", "r", stdin)
#define W() freopen("out.txt", "w", stdout)
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
const int SIZE = 40000;

// fflush(stdout);

int prime[SIZE], factor[SIZE], power[SIZE], divisor[7000], minV, maxV, pSZ, factSZ, gcdSZ;
bool status[SIZE];

void sieve()
{
	int I, K, sqrtN = int(sqrt((double)SIZE));

	for(I = 3; I <= sqrtN; I += 2){
		if(!status[I]){
			for(K = I * I;  K <= SIZE; K += 2 * I){
				if(!status[K]) status[K] = true;
			}
		}
	}
	K = 0;
	prime[K++] = 2;
	for(I = 3;  I <= SIZE; I += 2){
		if(!status[I]) prime[K++] = I;
	}
	pSZ = K;
	//for(I = 0; I < 100; I++) cout << I << " = " << prime[I] << NL;
}

void pFactor(int n)
{
	int I, p, K = 0, sqrtN = int(sqrt((double)n));

	for(I = 0;  I < pSZ && prime[I] <= sqrtN; I++){
		if(n % prime[I] == 0){
			p = 0;
			while(n % prime[I] == 0){
				p++;
				n /= prime[I];
			}
			factor[K] = prime[I];
			power[K++] = p;
			sqrtN = int(sqrt((double)n));
		}
	}
	if(n > 1){
		factor[K] = n;
		power[K++] = 1;
	}
	factSZ = K;
	/*for(I = 0;  I < K; I++) cout << factor[I] << " ";
	cout << NL;
	for(I = 0;  I < K; I++) cout << power[I] << " ";
	cout << NL;*/
}

void findDiv()
{
	int I, J, K, x,  tempSZ, divSZ = 1;
	divisor[0] = 1;
	for(I = 0; I < factSZ; I++){
		x = 1;
		tempSZ = divSZ;
		for(J = 1;  J <= power[I]; J++){
			x = x * factor[I];
			for(K = 0; K < tempSZ; K++){
				int temp = divisor[K] * x;
				//cout << temp;
				if(minV % temp == 0 && maxV % temp == 0)
					divisor[divSZ++] = temp;
			}
		}
	}

	gcdSZ = divSZ;
	//for(I = 1;  I < divSZ; I++) cout << divisor[I] << NL;
}

int main()
{
	//std::ios_base::sync_with_stdio(0);
	int tcases, I, J, K, N, n, m, cnt = 0, len, a, b, low, high, M;
    //R();
    // W();
	sieve();
	sf("%d%d", &a, &b);

	minV = MIN(a, b);
	maxV = MAX(a, b);
	pFactor(minV);
	findDiv();

	sf("%d", &n);

	while(n--){
		sf("%d%d", &low, &high);
		M = 0; int f = 0;
		for(I = 0;  I < gcdSZ; I++){
			//cout << M << NL;
			if(divisor[I] >= low && divisor[I] <= high){
				if(divisor[I] > M){
					f = 1;
					M = divisor[I];
				}
			}
		}
		if(f == 0) pf("-1\n");
		else pf("%d\n", M);
	}
	return 0;
}
