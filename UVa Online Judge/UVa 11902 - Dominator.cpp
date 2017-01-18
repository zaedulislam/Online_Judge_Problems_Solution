// UVa 11902 - Dominator.cpp
///************************************************************///
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

#include <algorithm>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>

#include <cmath>
#include <cstdlib>
#include <cctype>
#include <ctime>
///************************************************************///
using namespace std;
int caseno = 1;
///************************************************************///
#define NL '\n'
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
#define SF scanf
#define PF printf
///************************************************************///
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define PC() printf("Case %d:\n", caseno++)
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);
///************************************************************///
typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64
///************************************************************///
#define INF 2147483647
#define MOD 1000000007
#define pii pair<int, int>
#define pLL pair<LL, LL>
#define psi pair<string, int>
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 100 + 10;
///************************************************************///

/*
*******4 Direction Array*******
int dx[] = {0, 0, - 1, 1}, dy[] = {-1, 1, 0, 0};

*******8 Direction Array*******
int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1};

********Knight Moves********
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};
*/

int M[SIZE][SIZE], visited[SIZE], visited1[SIZE];
vector<int> G[SIZE];

void DFS(int u)
{
	int I, v;
	visited[u] = 1;

	for (I = 0; I < G[u].size(); I++)
	{
		v = G[u][I];
		if (visited[v] == 0)
			DFS(v);
	}
}

void DFS1(int u, int X)
{
	int I, v;

	if (u == X)
		return;

	visited1[u] = 1;

	for (I = 0; I < G[u].size(); I++)
	{
		v = G[u][I];
		if (visited1[v] == 0)
			DFS1(v, X);
	}
}

int main()
{
	///BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len;
	///READ();
	///WRITE();

	SF("%d", &tcases);
	while (tcases--)
	{
		SF("%d", &N);

		for (I = 0; I <= N; I++)
			G[I].clear();

		for (I = 0; I < N; I++)
		{
			for (K = 0; K < N; K++)
			{
				SF("%d", &M[I][K]);
				if (M[I][K] == 1)
					G[I].push_back(K);
			}
		}

		memset(visited, 0, sizeof(visited));
		DFS(0);

		PC();

		/// Prints Hyphened Line
		PF("+");
		for (J = 1; J <= (2 * N) - 1; J++)
			PF("-");
		PF("+\n");
		/// Prints Hyphened Line

		for (I = 0; I < N; I++)
		{
			memset(visited1, 0, sizeof(visited1));

			DFS1(0, I);

			for (K = 0; K < N; K++)
			{
				PF("|");

				if (visited[K] == 0 || visited1[K] == 1)
					PF("N");
				else
					PF("Y");
			}
			PF("|\n");

			/// Prints Hyphened Line
			PF("+");
			for (J = 1; J <= (2 * N) - 1; J++)
				PF("-");
			PF("+\n");
			/// Prints Hyphened Line

		}

	}
	return 0;
}


