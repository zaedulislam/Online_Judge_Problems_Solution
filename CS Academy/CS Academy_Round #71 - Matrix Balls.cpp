// CS Academy_Round #71 - Matrix Balls.cpp

/// Template by Zayed ///

/// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>

#include <string>
#include <cstring>
#include <sstream>

//#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <map>
//#include<unordered_map>
#include <set>
//#include<unordered_set>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdlib>

using namespace std;
int caseno = 1;

#define NL '\n'
#define SF scanf
#define PF printf
#define PC() printf("Case %d: ", caseno++)//NOTES:printf
#define BUG() printf("\n!!!WHERE IS YOUR FOCUS!!!\n")//NOTES:printf
//#define PC cout << "Case "//NOTES:cout
//#define CN cout << caseno++ << ": "//NOTES:cout
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define READ() freopen("input.txt", "r", stdin)
#define WRITE() freopen("output.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"

#define MOD 1000000007		    // (10^9 + 7)
#define PRIME 999998727899999   // (largest prime below 10^16)
#define PB push_back
#define pii pair<int, int>
#define pic pair<int, char>
#define pci pair<char, int>
#define pLL pair<LL, LL>
#define pis pair<int, string>
#define psi pair<string, int>
#define pss pair<string, string>
//#define tiii tuple<int, int, int>
#define PI 2 * acos(0.0)
#define EPS 1e-11


// Numeric Functions
template < class T > inline void SWAP(T &a, T &b) { T t = a; a = b; b = t; }
inline LL POW(LL base, LL power){
	LL res = base; if (power == 0) return 1;
	for (int I = 0; I < power - 1; I++) res *= base; return res;
}


// Translator Functions
int ToInt(string s) { int r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:ToInt(
double ToDouble(string s) { double r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:ToDouble(
string ToString(int n) { string s; stringstream convert; convert << n; s = convert.str(); return s; }//NOTES:ToString(


/*
*******4 Direction Array*******
int dx[] = {0, 0, - 1, 1}, dy[] = {-1, 1, 0, 0};
********Knight Moves********
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};
*/

//*******8 Direction Array*******
int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1};
const int SIZE = 5000 + 10;
int mat[SIZE][SIZE], ans[SIZE][SIZE], N, M, p = 0;
bool visited[3 * 100000 + 10];
vector<int> G[3 * 100000 + 10], source;
map<int, pii> MAP;




void DFS(int u)
{
	visited[u] = false;
	p++;
	int I, v, SZ = G[u].size(), ret = 0;
	for(I = 0; I < SZ; I++)
	{
		v = G[u][I];
		if(!visited[v])
			DFS(v);
	}

}



int main()
{
	BOOST
	///READ();
	///WRITE();
	int T, I, J, K, n, m, k, cnt = 0, len, x, y, nx, ny, fx, fy, u, v;

	cin >> N >> M;

	for(I = 1; I <= N; I++)
	{
		for(J = 1; J <= M; J++)
		{
			cin >> mat[I][J];
			MAP[mat[I][J]] = pii(I,J);

		}
	}


	/// Conversion to forest
	for(x = 1; x <= N; x++)
	{
		for(y = 1; y <= M; y++)
		{
			int mn = mat[x][y];
			for(I = 0; I < 8; I++)
			{
				nx = x + dx[I];
				ny = y + dy[I];

				if(nx >= 1 && nx <= N && ny >= 1 && ny <= M && mn > mat[nx][ny])
				{
					mn = mat[nx][ny];
					u = mat[x][y];
					v = mat[nx][ny];

				}

			}

			if(mn == mat[x][y])
				source.PB(mat[x][y]);
			else
				G[v].PB(u);

		}

	}
	/// Conversion to forest


	for(I = 0; I < source.size(); I++)
	{
		u = source[I];

		p = 0;
		DFS(u);

		x = MAP[u].first;
		y = MAP[u].second;

		ans[x][y] = p;

	}


	for(I = 1; I <= N; I++)
	{
		for(J = 1; J <= M; J++)
			cout << ans[I][J] << ' ';

		cout << NL;
	}


	return 0;
}




