// SPOJ TOPOSORT - Topological Sorting.cpp

/// Template by Zayed ///

///************************************************************///
/// #include <bits/stdc++.h>
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
#define SF scanf
#define PF printf
#define PC() printf("Case %d: ", caseno++)//NOTES:printf
#define PC cout << "Case "//NOTES:cout
#define CN cout << caseno++ << ": "//NOTES:cout
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
///************************************************************///
typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64
///************************************************************///
#define INF (1 << 31) - 1
#define MOD 1000000007
#define pii pair<int, int>
#define pLL pair<LL, LL>
#define pis pair<int, string>
#define psi pair<string, int>
#define PI 2 * acos(0.0);
#define EPS 1e-11;
///************************************************************///
// Numeric Functions
// Translator Functions
///************************************************************///

/*
*******4 Direction Array*******
int dx[] = {0, 0, - 1, 1}, dy[] = {-1, 1, 0, 0};
*******8 Direction Array*******
int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1};
********Knight Moves********
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};
*/

const int SIZE = 1e4 + 10;

vector<int> G[SIZE], topOrder;
priority_queue<int, vector<int>, greater<int> > pq;
int indegree[SIZE];

void KahnsAlgorithm(int n)
{
	while(!pq.empty())
		pq.pop();

	topOrder.clear();

	int I, u, v, cnt = 0;
	for(I = 1; I <= n; I++)
	{
		if(indegree[I] == 0)
			pq.push(I);
	}

	while(!pq.empty())
	{
		u = pq.top();
		pq.pop();
		topOrder.push_back(u);

		for(I = 0; I < G[u].size(); I++)
		{
			v = G[u][I];
			indegree[v]--;

			if(indegree[v] == 0)
				pq.push(v);
		}
		cnt++;
	}

	if(cnt != n)
		PF("Sandro fails.\n");
	else
	{
		PF("%d", topOrder[0]);
		for(I = 1; I < topOrder.size(); I++)
			PF(" %d", topOrder[I]);

		PF("\n");
	}
}


int main()
{
	///BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, u, v;
	///READ();
	///WRITE();
	SF("%d%d", &n, &m);

	CLR(indegree);

	for(I = 0; I < m; I++)
	{
		SF("%d%d", &u, &v);
		indegree[v]++;
		G[u].push_back(v);
	}

	KahnsAlgorithm(n);

	return 0;
}


