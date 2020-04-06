// B - Spreading The News.cpp
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
const int SIZE = 3000;

// fflush(stdout);
vector<int>G[SIZE];
queue<int>Q;
int visited[SIZE], level[SIZE], boomSZ[SIZE], E;

inline void bfs(int src)
{
    while(!Q.empty()) Q.pop();

    Q.push(src);
    visited[src] = 1;
    level[src] = 0;

    int I, u, v, cnt, boomDay = 0, f = 0;
    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        cnt = 0;
        for(I = 0;  I < G[u].size(); I++){
            v = G[u][I];
            if(visited[v] == 0){
                f = 1;
                Q.push(v);
                visited[v] = 1;
                level[v] = level[u] + 1;
                boomSZ[level[v]]++;
            }
        }
    }
    cnt = 0;
    for(I = 1; I <= E; I++){
        if(boomSZ[I] > cnt){
            cnt = boomSZ[I];
            boomDay = I;
        }
    }
    if(f == 0) pf("0\n");
    else  pf("%d %d\n", cnt, boomDay);
}

int main()
{
	//std::ios_base::sync_with_stdio(0);
	int tcases, caseno = 1, I, J, K, N, n, m, cnt = 0, len, src, u, v;

	while (sf("%d", &E) != EOF){

        for(I = 0; I <= E; I++) G[I].clear();

		for (I = 0; I < E; I++){
			sf("%d", &N);
			for (K = 0; K < N; K++){
				sf("%d", &u);
                G[I].push_back(u);
			}
		}
		sf("%d", &tcases);
		while (tcases--){
            memset(visited, 0, sizeof(visited));
            memset(level, 0, sizeof(level));
            memset(boomSZ, 0, sizeof(boomSZ));
			sf("%d", &src);
			bfs(src);
		}
	}
	return 0;
}
