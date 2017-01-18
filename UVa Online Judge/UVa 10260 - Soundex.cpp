// UVa 10260 - Soundex.cpp
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
#define MAXIMUM 100005
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
const int SIZE = 1e6;

typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long LL;//NOTES:"%lld"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

typedef stack<int> si;
typedef queue <int> qi;
typedef vector <int> vi;
typedef pair <LL, LL> pLL;
typedef pair <string, int> psi;
typedef pair <int, int> Pii;
typedef map <int, int> mii;
typedef map <char, int> mci;
typedef map <string, int> msi;
typedef map <string, string> mss;

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

int main()
{
	//std::ios_base::sync_with_stdio(0);
	int tcases, caseno = 1, I, J, K, N, n, m, cnt = 0, len;

	while(cin >> S){
		T = 	"";
        len = S.length();
        FOR(I,0,len){
            if(S[I] == 'B' || S[I] == 'F'  || S[I] == 'P' || S[I] == 'V') {
				if(I == 0) T += '1';
				else if(I > 0 && (S[I - 1] != 'B' && S[I - 1] != 'F' && S[I - 1] != 'P' && S[I - 1] != 'V') )
					T += '1';
            }
            else if(S[I] == 'C' || S[I] == 'G' || S[I] == 'J' || S[I] == 'K' || S[I] == 'S' || S[I] == 'Q' || S[I] == 'X' || S[I] == 'Z' ) {
            	if(I == 0) T += '2';
				else if(I > 0 && (S[I - 1] != 'C' && S[I - 1] != 'G' && S[I - 1] != 'J' && S[I - 1] != 'K' && S[I - 1] != 'S' && S[I - 1]  != 'Q' && S[I - 1]  != 'X' && S[I - 1] != 'Z' ))
					T += ' 2';
			}
            else if(S[I] == 'D' || S[I] == 'T'){
            	if(I == 0) T += '3';
				else if(I > 0 && (S[I - 1] != 'D' && S[I - 1] != 'T'))
					T += '3';
			}
            else if(S[I] == 'L'){
				if(I == 0) T += '4';
				else if(I > 0 && S[I - 1] != 'L')
					T += '4';
            }
            else if(S[I] == 'N' || S[I] == 'M' ) {
            	if(I == 0) T += '5';
				else if(I > 0 && (S[I - 1] != 'N' && S[I - 1] != 'M' ))
					T += '5';
            }
            else if(S[I] == 'R') {
            	if(I == 0) T += '6';
				else if(I > 0 && S[I - 1] != 'R')
					T += '6';
            }
        }
       cout << T << NL;
	}

	return 0;
}
