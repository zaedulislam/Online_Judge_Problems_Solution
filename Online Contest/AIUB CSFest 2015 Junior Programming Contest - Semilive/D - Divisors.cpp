// D - Divisors.cpp
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
const int sz = 1000;

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

template<class T> inline void checkmin(T &a, T b){ if (b<a) a = b; }//NOTES:checkmin(
template<class T> inline void checkmax(T &a, T b){ if (b>a) a = b; }//NOTES:checkmax(
template<class T> inline T sqr(T x){ return x*x; }//NOTES:square
int _max(int a, int b){ return (a > b) ? a : b; }
int _min(int a, int b){ return (a < b) ? a : b; }
inline int _pow(int base, int power){
	int I, result = base;
	if (power == 0)
		return 1;
	for (I = 0; I < power - 1; I++) {
		result = result * base;
	}
	return result;
}
//Translator
bool isUpperCase(char c){ return c >= 'A' && c <= 'Z'; }//NOTES: isUpperCase(
bool isLowerCase(char c){ return c >= 'a' && c <= 'z'; }//NOTES: isLowerCase(
bool isLetter(char c){ return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }//NOTES: isLetter(
bool isDigit(char c){ return c >= '0' && c <= '9'; }//NOTES:isDigit(
char toLowerCase(char c){ return (isUpperCase(c)) ? (c + 32) : c; }//NOTES: toLowerCase(
char toUpperCase(char c){ return (isLowerCase(c)) ? (c - 32) : c; }//NOTES: toUpperCase(
int toInt(string s){ int r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:toInt(
double toDouble(string s){ double r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:toDouble(
// ENDTEMPLATE_BY_ZAYED
int prime[sz];

int main()
{
	int t,L,R,cs = 1;
	scanf("%d", &t);
	while (t--){
        scanf("%d%d",&L,&R);
        int sqrtN = int(sqrt((double)sz));
        int I, K,cnt = 0;
        prime[0] = 1, prime[1] = 1;
        for(I = 3; I <= sqrtN; I += 2 ){
            if(prime[I] == 0){
                for(K = I * I; K <= sz; K += 2 * I )
                    prime[K] = 1;
            }
        }
        for(I = L; I <= R; I++){
            if(I == 2)
                cnt++;
            if( I % 2 != 0){
                if(prime[I] == 0)
                    cnt++;
            }
        }
        printf("Case %d: There are %d numbers between %d and %d.\n",cs++,cnt,L,R);
	}
	return 0;
}
