// UVa 929 - Number Maze.cpp

/// Template by Zayed ///

///************************************************************///
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
///************************************************************///
using namespace std;
int caseno = 1;
///************************************************************///
#define NL '\n'
#define SF scanf
#define PF printf
#define PC() printf("Case %d: ", caseno++)//NOTES:printf
//#define PC cout << "Case "//NOTES:cout
//#define CN cout << caseno++ << ": "//NOTES:cout
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define READ() freopen("input.txt", "r", stdin)
#define WRITE() freopen("output.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);
///************************************************************///
typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
///************************************************************///
#define INF (1 << 31) - 1
#define MOD 1000000007
#define PRIME 999998727899999 			// (largest prime below 10^16)
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
///************************************************************///
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
///************************************************************///

/*
*******4 Direction Array*******

*******8 Direction Array*******
int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1};
********Knight Moves********
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};
*/

const int SIZE = 1e3 + 10;

int dx[] = { 0, 0, -1, 1 }, dy[] = { -1, 1, 0, 0 };
int dis[SIZE][SIZE], G[SIZE][SIZE];
int N, M;


struct Node
{
	int x1, y1, cost;
	Node(){}
	Node(int _x1, int _y1, int _cost)
	{
		x1 = _x1;
		y1 = _y1;
		cost = _cost;

	}

};


priority_queue<Node> PQ;


bool operator<(Node A, Node B)
{
	return A.cost > B.cost;
}


void Dijkstra(int sx, int sy)
{

	PQ.push(Node(sx, sy, 0));
	dis[sx][sy] = G[sx][sy];


	int I, ux, uy, nx, ny;
	while (!PQ.empty())
	{
		Node node = PQ.top();
		PQ.pop();

		ux = node.x1;
		uy = node.y1;

		for (I = 0; I < 4; I++)
		{
			nx = ux + dx[I];
			ny = uy + dy[I];

			if ((nx >= 0 && nx < N) && (ny >= 0 && ny < M))
			{

				if (dis[ux][uy] + G[nx][ny] < dis[nx][ny])
				{
					dis[nx][ny] = dis[ux][uy] + G[nx][ny];
					PQ.push(Node(nx, ny, dis[nx][ny]));


				}

			}

		}

	}

}



int main()
{
	///BOOST
	///READ();
	///WRITE();
	int T, I, J, K, n, m, cnt = 0, len;


	SF("%d", &T);
	while (T--)
	{
		SF("%d%d", &N, &M);

		for (I = 0; I < N; I++)
		{
			for (J = 0; J < M; J++)
				dis[I][J] = INF;
		}

		CLR(G);

		while (!PQ.empty())
			PQ.pop();


		for (I = 0; I < N; I++)
		{
			for (J = 0; J < M; J++)
				SF("%d", &G[I][J]);
		}

		Dijkstra(0, 0);

		PF("%d\n", dis[N - 1][M - 1]);

	}

	return 0;
}




