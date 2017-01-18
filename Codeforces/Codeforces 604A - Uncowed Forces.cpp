// Codeforces 604A - Uncowed Forces.cpp
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

#define  LL long long
#define MAX 100005
#define MOD 1000000007

#define NL '\n'
using namespace std;

// BEGINTEMPLATE_BY_ZAYED
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int sz = 2 * 1e5 + 10;

typedef unsigned long long ull;//NOTES:"%llu"
typedef long long ll;//NOTES:"%lld"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

typedef stack<int> si;
typedef queue <int> qi;
typedef vector <int> vi;
typedef pair <ll, ll> pll;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef map <char, int> mci;
typedef map <string, int> msi;
typedef pair <string, int> psi;
typedef map <string, string> mss;

template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
template<class T> inline T sqr(T x){return x*x;}//NOTES:square
double _max(double a,double b){return (a > b) ? a : b;}
int _min(int a,int b){return (a < b) ? a : b;}
 inline int _pow(int base, int power){
	int I,result = base;
	if(power == 0)
		return 1;
	for (I = 0; I < power - 1; I++) {
		result = result * base;
	}
	return result;
}
//Translator
bool isUpperCase(char c){return c>='A' && c<='Z';}//NOTES: isUpperCase(
bool isLowerCase(char c){return c>='a' && c<='z';}//NOTES: isLowerCase(
bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}//NOTES: isLetter(
bool isDigit(char c){return c>='0' && c<='9';}//NOTES:isDigit(
char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}//NOTES: toLowerCase(
char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}//NOTES: toUpperCase(
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toInt(
double toDouble(string s){double r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toDouble(
// ENDTEMPLATE_BY_ZAYED

int main()
{
	std::ios_base::sync_with_stdio(0);
    int cases, caseno= 1, n, I, K, cnt = 0,var;
	double m1,m2,m3,m4,m5,w1,w2,w3,w4,w5,hs,hu;
	double p[] = {500,1000,1500,2000,2500};
	double m[10],w[10];

	for(I = 0; I < 5; I++)
		scanf("%lf",&m[I]);

	for(I = 0; I < 5; I++)
		scanf("%lf",&w[I]);

	scanf("%lf%lf",&hs,&hu);

	double sum = 0;
	for(I = 0; I < 5; I++){
		sum += _max((0.3 * p[I]),(1 - (m[I]/250) ) * p[I] - 50 * w[I] );
	}
	sum += hs * 100;
	sum -= hu * 50;

	printf("%0.0lf\n",sum);
    return 0;
}
