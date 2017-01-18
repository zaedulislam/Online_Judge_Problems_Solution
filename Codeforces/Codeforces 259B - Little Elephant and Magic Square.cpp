// Codeforces 259B - Little Elephant and Magic Square.cpp
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

//#define  LL long long
#define MAX 100005
#define MOD 1000000007

#define NL '\n'
using namespace std;

// BEGINTEMPLATE_BY_ZAYED
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int sz = 1e6;

typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long LL;//NOTES:"%lld"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

typedef stack<int> SI;
typedef queue <int> QI;
typedef vector <int> VI;
typedef pair <LL, LL> PLL;
typedef map <int, int> MII;
typedef pair <int, int> PII;
typedef map <char, int> MCI;
typedef map <string, int> MSI;
typedef pair <string, int> PSI;
typedef map <string, string> MSS;

template<class T> inline void checkmin(T &a,T b){ if(b < a) a = b; }//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){ if(b > a) a = b; }//NOTES:checkmax(
template<class T> inline T sqr(T x){ return x * x; }//NOTES:square
template<class T> inline T _max(T a,T b){ return (a > b) ? a : b; }
template<class T> inline T _min(T a,T b){ return (a < b) ? a : b; }
LL _pow(LL base, LL power){ LL I,result = base; if(power == 0) return 1;
	for (I = 0; I < power - 1; I++)
		result = result * base;
	return result;
}
//Translator
bool isUpperCase(char c){ return c >= 'A' && c <= 'Z'; }//NOTES: isUpperCase(
bool isLowerCase(char c){ return c >='a' && c <= 'z'; }//NOTES: isLowerCase(
bool isVowel(char c) { return (c == 'a'|| c == 'e'|| c == 'i'|| c == 'o'|| c == 'u'|| c == 'A'|| c == 'E'|| c == 'I'|| c == 'O'|| c =='U'); }//NOTES: isVowel(
bool isLetter(char c){ return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }//NOTES: isLetter(
bool isDigit(char c){ return c >= '0' && c <= '9'; }//NOTES:isDigit(
char toLowerCase(char c){ return (isUpperCase(c))?(c + 32) : c; }//NOTES: toLowerCase(
char toUpperCase(char c){ return (isLowerCase(c))?(c - 32) : c; }//NOTES: toUpperCase(
int toInt(string s){ int r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:toInt(
double toDouble(string s){ double r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:toDouble(
string toString(int n){ string s; stringstream convert; convert << n; s = convert.str(); return s; }//NOTES:toString
// ENDTEMPLATE_BY_ZAYED

string S,T;
char s[sz];
int a[sz];
int M[100][100];

int main()
{
	//std::ios_base::sync_with_stdio(0);
    int tcases, caseno = 1, n, I, J, K , cnt = 0,len,sum = 0;

	for(I = 0; I < 3; I++){
		for(K = 0; K < 3; K++){
			scanf("%d",&M[I][K]);
				sum += M[I][K];
		}
	}

	sum /= 2;

	M[0][0] = sum -  M[0][1] - M[0][2];
	M[1][1] = sum -  M[1][0] - M[1][2];
	M[2][2] = sum -  M[2][0] - M[2][1];

	for(I = 0; I < 3; I++){
		for(K = 0; K < 2; K++)
			printf("%d ",M[I][K]);

		printf("%d",M[I][K]);
		cout << NL;
	}
    return 0;
}
