// UVa 336 - A Node Too Far.cpp
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
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
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
const int SIZE = 31;

// fflush(stdout);
map<int, int> mymap;
set<int> si;
vector<int>G[SIZE];
queue<int>qi;
int visited[SIZE], level[SIZE];

int bfs(int src, int TTL)
{
    while(!qi.empty())
        qi.pop();
    memset(visited, 0, sizeof(visited));
    memset(level, 0, sizeof(level));

    qi.push(src);
    visited[src] = 1;
    level[src] = 0;

    int I, u, v, cnt = 1;
    while(!qi.empty())
    {
        u = qi.front();
        qi.pop();

        for(I = 0; I < G[u].size(); I++)
        {
            v = G[u][I];
            if(visited[v] == 0)
            {
                visited[v] = 1;
                level[v] = level[u] + 1;
                if(level[v] > TTL)
                    break;

                cnt++;
                qi.push(v);
            }
        }
    }
    return cnt;
}

int main()
{
	//std::ios_base::sync_with_stdio(0);
	int tcases, I, J, K, N, n, m, len, NC, TTL, u, v, assign, src;
    //READ();
    //WRITE();
    while(sf("%d", &NC))
    {
        if(NC == 0)
            break;

        for(I = 0; I < SIZE; I++)
            G[I].clear();

        mymap.clear();
        si.clear();

        assign = 0;
        for(I = 0; I < NC; I++)
        {
            sf("%d%d", &u, &v);
            if(mymap.find(u) == mymap.end())
                mymap[u] = assign++;
            if(mymap.find(v) == mymap.end())
                mymap[v] = assign++;

            u = mymap[u];
            v = mymap[v];

            si.insert(u);
            si.insert(v);

            G[u].push_back(v);
            G[v].push_back(u);
        }

        while(sf("%d%d", &src, &TTL), (src || TTL))
        {
            int vis = bfs(mymap[src], TTL);

            PC();
            pf("%d nodes not reachable from node %d with TTL = %d.\n", si.size() - vis , src, TTL);
        }
    }

	return 0;
}

