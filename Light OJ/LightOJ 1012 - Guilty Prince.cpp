// LightOJ 1012 - Guilty Prince.cpp
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
#define pii pair<int,int>
#define uu first
#define vv second


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

// fflush(stdout);
string G[SIZE], T;
char s[SIZE];
int ar[SIZE];
int visited[SIZE][SIZE], W, H, cnt;
int dx[] = {0, 0, - 1, 1};
int dy[] = {-1, 1, 0, 0};

queue<pii>Q;
const int WHITE = 0;
const int GREY = 1;
const int BLACK = -1;

void bfs(int x, int y)
{
    Q.push(pii(x,y));

    visited[x][y] = GREY ;
	pii xy;

	cnt = 1;
	int ux, uy, nx, ny, I;
    while(!Q.empty()){
		xy = Q.front();
		ux = xy.first;
		uy = xy.second;

		for(I = 0; I < 4; I++){
            nx = ux + dx[I];
            ny = uy + dy[I];

            if(nx >= 0 && nx < H &&  ny >= 0 && ny < W && G[nx][ny] != '#'){
				if(visited[nx][ny] == WHITE){
                    visited[nx][ny] = GREY;
					Q.push(pii(nx,ny));
					cnt++;
				}
            }
		}
		visited[ux][uy] = BLACK;
		Q.pop();
    }
}


int main()
{
	//std::ios_base::sync_with_stdio(0);
	int tcases, caseno = 1, I, J, K, N, n, m, len, sx , sy;
	//freopen("output.txt", "w", stdout);
	cin >> tcases;
	while(tcases--){
		cin >> W >> H;

		//FOR(I,0,H) G[I].clear();
		while(!Q.empty()) Q.pop();
		memset(visited, 0, sizeof(visited));


		int flag = 0;
		for(I = 0; I < H; I++){
			cin >> G[I];
			if(!flag){
				for(K = 0; K < W; K++){
					if(G[I][K] == '@'){
						sx = I; sy = K;
						flag = 1; break;
					}
				}
			}
		}
		bfs(sx,sy);
		cout << "Case " << caseno++ << ": "<< cnt << NL;
		//cout << sx << sy << endl;
	}

	return 0;
}
