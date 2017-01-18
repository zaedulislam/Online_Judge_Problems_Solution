// LightOJ 1238 - Power Puff Girls.cpp
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
#define INF 2147483647
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
const int SIZE = 50;

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

#define pii pair<int,int>
const int WHITE = 0;
const int GREY = 1;
const int BLACK = -1;

// fflush(stdout);
string G[SIZE], T;
char s[SIZE];
int visited[SIZE][SIZE], level[SIZE][SIZE], row, col;
queue<pii>Q;
int dx[] = {0, 0, -1, +1};
int dy[] = {-1, +1, 0, 0};
int ax, ay , bx, by, cx, cy, hx, hy, minLevel, minTime = 0;

void bfs(int x, int y)
{
	while(!Q.empty()) Q.pop();
	memset(visited, 0, sizeof(visited));
	memset(level, 0, sizeof(level));
	visited[x][y] = GREY;
	level[x][y] = 0;
	Q.push(pii(x,y));

    minLevel = INF;

	int I, ux, uy, nx, ny;
	while(!Q.empty()){
		pii xy =  Q.front();
        ux = xy.first;
        uy = xy.second;

		int flag = 0;
        for(I = 0; I < 4; I++){
            nx = ux + dx[I];
            ny = uy + dy[I];

            if(nx >= 0 && nx < row && ny >= 0 && ny < col && G[nx][ny] != 'm' && G[nx][ny] != '#') {
				if(visited[nx][ny] == WHITE){

					visited[nx][ny] = GREY;
                    level[nx][ny] = level[ux][uy] + 1;

					if(G[nx][ny] == 'h'){
                        if(level[nx][ny] < minLevel)
								 minLevel = level[nx][ny];
					}
					Q.push(pii(nx,ny));
				}
            }
        }
        visited[ux][uy] = BLACK;
        Q.pop();
	}
    if(minLevel > minTime) minTime = minLevel;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	int tcases, caseno = 1, I, J, K, N, n, m, cnt = 0, len;
	//freopen("output.txt", "w", stdout);

	cin >> tcases;
	while(tcases--){
		cin >> row >> col;

		FOR(I,0, row) 
			G[I].clear();

		for(I = 0; I < row; I++){
			cin >> G[I];
			for(K = 0; K < col; K++){
				if(G[I][K] == 'a'){
					ax = I; ay = K;
				}
				else if(G[I][K] == 'b'){
					bx = I; by = K;
				}
				else if(G[I][K] == 'c'){
					cx = I;  cy = K;
				}
				else if(G[I][K] == 'h'){
					hx = I; hy = K;
				}
			}
		}
		minTime = 0;
		bfs(ax,ay);
		bfs(bx,by);
		bfs(cx,cy);
		cout << "Case " << caseno++ << ": "<< minTime << NL;
	}
		return 0;
}

