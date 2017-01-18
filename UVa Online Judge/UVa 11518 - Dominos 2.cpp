// UVa 11518 - Dominos 2.cpp
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
#define PC() printf("Case %d: ", caseno++)
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
const int SIZE = 1e4 + 10;
///************************************************************///

/*
*******4 Direction Array*******
int dx[] = {0, 0, - 1, 1}, dy[] = {-1, 1, 0, 0};

*******8 Direction Array*******
int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1};

********Knight Moves********
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};
*/

vector<int> G[SIZE];
int visited[SIZE], cnt;

void DFS(int u)
{
	int I, v;
	visited[u] = 1;

	for(I = 0; I < G[u].size(); I++)
	{
		v = G[u][I];
		if(visited[v] == 0)
		{
			cnt++;
			DFS(v);
		}
	}
}

int main()
{
	///BOOST
	int tcases, I, J, K, N, n, m, len, L, x, y, z;
	///READ();
	///WRITE();

	SF("%d", &tcases);
	while(tcases--)
	{
		SF("%d%d%d", &n, &m, &L);

		for(I = 0; I  <= n; I++)
			G[I].clear();
		memset(visited, 0, sizeof(visited));

		for(I = 0; I < m; I++)
		{
			SF("%d%d", &x, &y);
			G[x].push_back(y);
		}

		cnt = 0;
		for(I = 0; I < L; I++)
		{
			SF("%d", &z);

			if(visited[z] == 0)
			{
				cnt++;
				DFS(z);
			}
		}

		PF("%d\n", cnt);
	}

	return 0;
}


