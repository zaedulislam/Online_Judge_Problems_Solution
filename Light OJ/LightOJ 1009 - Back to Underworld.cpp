// LightOJ 1009 - Back to Underworld.cpp
// Trick: The maximum possible members of any race.
/* Given graph ta disconnected hote pare.Given graph a duita component ase C1 and C2. BFS dia C1 ar coloring ashlo (10,5) and C2 (5,6) // (1st coloring,2nd coloring)....
tahole solution ki hoia uchit??
obossoi 16 karon C1 theke 10 ar C2 theke 6 jon ke ak group bolte pari as tara different component.
So ai maximizing ta amra greedily e korte pari :) :).*/

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
const int SIZE = 1e5 + 10;
 
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
 
const int WHITE = 0;
const int GREY = 1;
const int BLACK = -1;
const int VAMPIRE = 1;
const int LYCAN = 2;
// fflush(stdout);
int visited[SIZE], race[SIZE], vamp, lycan, maxMember;
vector<int>G[SIZE];
queue<int>Q;
set<int>node;
 
void bfs(int src)
{
    while (!Q.empty()) Q.pop();
    vamp = 0; lycan = 0;
    visited[src] = GREY;
    race[src] = VAMPIRE;
    vamp++;
    Q.push(src);
 
    int I, u, v;
    while (!Q.empty()){
        u = Q.front();
        for (I = 0; I < G[u].size(); I++){
            v = G[u][I];
            if (!visited[v]){
                visited[v] = GREY;
                if (race[u] == VAMPIRE) {
                    race[v] = LYCAN;
                    lycan++;
                }
                else if (race[u] == LYCAN) {
                    race[v] = VAMPIRE;
                    vamp++;
                }
                Q.push(v);
            }
        }
        visited[u] = BLACK;
        Q.pop();
    }
    maxMember += MAX(vamp, lycan);
    //cout << "MAX = " << maxMember << NL;
}
 
 
int main()
{
    //std::ios_base::sync_with_stdio(0);
    int tcases, caseno = 1, I, J, K, N, n, m, cnt = 0, len, u, v, src, hi, vamp, lycan;
 
    //freopen("output.txt", "w", stdout);
    sf("%d", &tcases);
    while (tcases--){
 
        sf("%d", &n);
 
        maxMember = 0;
        memset(race, 0, sizeof(race));
        memset(visited, 0, sizeof(visited));
        node.clear();
 
        hi = 0;
        FOR(I, 0, n){
            sf("%d%d", &u, &v);
            node.insert(u);
            node.insert(v);
            if (I == 0) src = u;
            hi = MAX(u, hi); hi = MAX(v, hi);
            G[u].push_back(v);
            G[v].push_back(u);
        }
 
        set<int>::iterator it = node.begin();
        while (it != node.end()){
            int x = *it;
            if (visited[x] == WHITE) bfs(x);
            it++;
        }
        pf("Case %d: %d\n", caseno++, maxMember);
        FOR(I, 0, hi + 1) G[I].clear();
    }
 
    return 0;
}