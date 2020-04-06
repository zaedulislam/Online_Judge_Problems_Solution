// D - Path Game.cpp
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
#define R() freopen("in.txt", "r", stdin)
#define W() freopen("out.txt", "w", stdout)
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
const int SIZE = 52;

// fflush(stdout);
#define pii pair<int, int>
queue<pii> Q;
pair<int, int> parent[2][SIZE];
int visited[2][SIZE], whiteCell, col;
string G[2];

int dx[] = { +1, -1, 0 };
int dy[] = { 0, 0, +1 };

void bfs(int x, int y)
{
	while (!Q.empty()) Q.pop();

	Q.push(pii(x, y));
	visited[x][y] = 1;
	parent[x][y] = make_pair(0, 0);
	whiteCell = 1;

	int I, K, ux, uy, nx, ny;
	while (!Q.empty())
	{
		pii xy = Q.front();
		Q.pop();
		ux = xy.first;
		uy = xy.second;

		if (uy + 1 == col) break;

		for (I = 0; I < 3; I++)
		{
			nx = ux + dx[I];
			ny = uy + dy[I];
			if (nx >= 0 && nx < 2 && ny >= 0 && ny < col && G[nx][ny] != '#')
			{
				if (visited[nx][ny] == 0)
				{
					visited[nx][ny] = 1;
					parent[nx][ny] = make_pair(ux, uy);
					Q.push(pii(nx, ny));
				}
			}
		}
	}
	//cout << "(" << nx << " , " << ny << ")" << NL;
	nx = ux, ny = uy;
	while (ny != 0)
	{
		int r = nx, c = ny;
		nx = parent[r][c].first;
		ny = parent[r][c].second;
		whiteCell++;
	}
}

int main()
{
	//std::ios_base::sync_with_stdio(0);
	int tcases, I, J, K, N, n, m, len, blackCell, sx;
	//R();
	// W();
	sf("%d", &tcases);
	while (tcases--)
	{
		memset(visited, 0, sizeof(visited));
		memset(parent, 0, sizeof(parent));

		sf("%d", &col);
		whiteCell = blackCell = 0;

		for (I = 0; I < 2; I++)
		{
			cin >> G[I];
			for (K = 0; K < col; K++)
			{
				if (G[I][K] == '#')
					blackCell++;
			}
		}
		//cout << whiteCell << NL;
		if (G[0][0] == '.') sx = 0;
		else sx = 1;

		bfs(sx, 0);

		blackCell = (col * 2) - blackCell - whiteCell;
		pf("%d\n", blackCell);
	}
	return 0;
}
