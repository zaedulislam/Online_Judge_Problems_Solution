// LightOJ 1109 - False Ordering.cpp
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

#define NL '\n'
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
#define sf1(x) scanf("%d",&x)
#define sf scanf
#define pf1(x) printf("%d",x)
#define pf printf
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
inline LL POW(LL base, LL power){
    LL I, res = base; if (power == 0) return 1;
    for (I = 0; I < power - 1; I++) res *= base; return res;
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

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1000 + 1;

// fflush(stdout);
int status[SIZE], indx = 0;

struct order{
    int n;
    int div;
};
order data[SIZE];

bool compare(const order &x, const order &y)
{
    if (x.div < y.div)
        return true;
    if (x.div == y.div)
        return x.n > y.n;
    return false;
}

void sieve()
{
    int I, K, sqrtN = int(sqrt((double)SIZE));
    for (I = 2; I <= sqrtN; I++){
        if (!status[I]){
            for (K = I * I; K <= SIZE; K += I) status[K] = 1;
        }
    }
    for (I = SIZE; I > 1; I--){
        if (!status[I]) {
            data[indx].n = I;
            data[indx].div = 2;
            indx++;
        }
    }
    //cout << p<< NL;
    //for(I = 1;  I <= 50; I++) cout << I <<" = " << ar[I] << NL;
}

void f(int n)
{
    int N = n, p, NOD = 1, cnt;
    for (p = 2; p * p <= n; ++p){
        cnt = 0;
        if (n % p == 0){
            while (n % p == 0){
                n /= p;
                cnt++;
            }
            NOD *= (cnt + 1);
        }
    }
    cnt = 0;
    if (n > 1){
        cnt++;
        NOD *= (cnt + 1);
    }
    data[indx].n = N;
    data[indx].div = NOD;
    indx++;
    //cout << K << " = " << NOD << NL;
}

int main()
{
    //std::ios_base::sync_with_stdio(0);
    int tcases, caseno = 1, I, J, K, N, n, m, len;
    //freopen("output.txt", "w", stdout);

    sieve();
    for (I = 2; I < SIZE; I++){
        if (status[I] == 1) f(I);
    }
    sort(data, data + SIZE, compare);
    data[1].n = 1;

    sf("%d", &tcases);
    while (tcases--){
        sf("%d", &n);
        cout << "Case " << caseno++ << ": " << data[n].n << NL;
        //pf("Case %d: %d\n", caseno++, ans[n]);
    }
    return 0;
}
