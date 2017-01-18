// Codeforces 534A - Exam.cpp
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

int main()
{
	//std::ios_base::sync_with_stdio(0);
    int tcases, caseno = 1, n, I, J, K = 0, cnt = 0,len,c1,c2,c3,c4,c5,k;

	scanf("%d",&k);
	if( k == 2 ){
		printf("%d\n1",1);
		return 0;
	}
	else if( k == 3){
		printf("%d\n1 3",2);
		return 0;
	}

	if(k == 4){
		printf("%d\n3 1 4 2",4);
		return 0;
	}

	for(I = 1; I <= k; I += 2)
			a[K++] = I;

	for(I = 2; I <= k ;I += 2){
		if(a[K - 1] - 1 != I && a[K - 1]  != I - 1)
			a[K++] = I;
	}

	printf("%d\n",K);
	for(I = 0; I < K - 1; I++)
		printf("%d ",a[I]);

	printf("%d",a[K - 1]);
    return 0;
}
