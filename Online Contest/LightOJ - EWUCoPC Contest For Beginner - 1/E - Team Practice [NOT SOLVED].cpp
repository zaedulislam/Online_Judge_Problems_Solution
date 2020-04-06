// E - Team Practice.cpp
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
string S, T, semester[10] = {"SPRING", "SUMMER", "FALL"};
char s[SIZE];
int ar[SIZE];
int M[1000][1000];

int main()
{
	//std::ios_base::sync_with_stdio(0);
	int tcases, caseno = 1, I, J, K, N, n, m, cnt = 0, len, AC, BD;
	char c1,c3,c2;

	sf("%d", &tcases);
	while(tcases--){
		cin >> AC >> BD;
        cin >> c1 >> c2 >> c3;
        if((c1 == c2) && (c2 == c3) && (c3 == c1)) pf("Case %d: 0.00!\n",caseno++);

       else{
			/*if(((c1 == 'A' && c2 == 'A') || (c2 == 'A' && c3 == 'A')  || (c1== 'A' && c3 == 'A')) || ( (c1 == 'C' && c2 == 'C') || (c2 == 'C' && c3 == 'C') || (c1== 'C' && c3 == 'C' ))){
				  pf("Case %d: %0.2lf!\n",caseno++, (double)AC/ 2.00 + (double)BD / 2.00);
			}*/
			if(((c1 == 'A' && c2 == 'A') || (c2 == 'A' && c3 == 'A')  || (c1== 'A' && c3 == 'A')) || ( (c1 == 'C' && c2 == 'C') || (c2 == 'C' && c3 == 'C') || (c1== 'C' && c3 == 'C' ))){
				  if((c1 != 'B' && c2 != 'B' && c3 != 'B') && (c1 != 'D' && c2 != 'D' || c3 != 'D'))
					pf("Case %d: %0.2lf!\n",caseno++, (double)AC/ 2.00 + (double)AC / 2.00);

				  else pf("Case %d: %0.2lf!\n",caseno++, (double)AC/ 2.00 + (double)BD / 2.00);
			}

			else if(((c1 == 'B' && c2 == 'B') || (c2 == 'B' && c3 == 'B') || (c1== 'B' && c3 == 'B')) || ((c1 == 'D' && c2 == 'D') || (c2 == 'D' && c3 == 'D') || (c1== 'D' && c3 == 'D'))){
				  if((c1 != 'A' && c2 != 'A' && c3 != 'A') && (c1 != 'C' && c2 != 'C' || c3 != 'C'))
					pf("Case %d: %0.2lf!\n",caseno++, (double)BD/ 2.00 + (double)BD / 2.00);

				  else pf("Case %d: %0.2lf!\n",caseno++, (double)AC/ 2.00 + (double)BD / 2.00);
			}

			else if((c1 == 'A' || c2 == 'A' || c3 == 'A') && (c1== 'C' || c2 == 'C' || c3 == 'C'))
                pf("Case %d: %0.2lf!\n",caseno++, (double)AC + (double)BD / 2.00);
			else if((c1 == 'B' || c2 == 'B' || c3 == 'B') && (c1 == 'D' || c2 == 'D' || c3 == 'D'))
                pf("Case %d: %0.2lf!\n",caseno++, (double)BD + (double)AC / 2.00);
        }
	}
	return 0;
}
