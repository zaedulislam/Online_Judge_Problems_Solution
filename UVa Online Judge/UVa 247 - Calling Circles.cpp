// UVa 247 - Calling Circles.cpp
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
#include <cstdlib>
#include <ctime>
using namespace std;

#define NL '\n'
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
#define SF scanf
#define PF printf
#define PC() printf("Case %d: ", caseno++)
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 50;

string p1, p2;
map< string, int > MAP1;
map< int, string > MAP2;
stack< int > topSort;
vector< int > G[SIZE], rG[SIZE], ans[SIZE];
int visited[SIZE], ar[SIZE], indx;

void dfs(int u)
{
	int I, v;
	visited[u] = 1;
	for (I = 0; I < G[u].size(); I++)
	{
		v = G[u][I];
		if (visited[v] == 0)
			dfs(v);
	}
	topSort.push(u);
}

void dfs1(int u)
{
	int I, v;
	visited[u] = 1;
	//cout << MAP2[u] << " ";
	ans[indx].push_back(u);

	for (I = 0; I < rG[u].size(); I++)
	{
		v = rG[u][I];
		if (visited[v] == 0)
			dfs1(v);
	}
}

int main()
{
	//BOOST
    int tcases, caseno = 1, I, J, K, N, n, m, cnt = 0, len;
	//READ();
	//WRITE();
	while (1)
	{
		memset(visited, 0, sizeof(visited));
		while (!topSort.empty())
			topSort.pop();

		MAP1.clear();
		MAP2.clear();

        cin >> n >> m;

		if (n == 0 && m == 0)
			break;

        if (caseno >= 2)
            cout << NL;

		for (I = 0; I <= n; I++)
			G[I].clear(), rG[I].clear(), ans[I].clear();

		cnt = 1;
		for (I = 0; I < m; I++)
		{
			cin >> p1 >> p2;
			if (MAP1[p1] == 0)
			{
				MAP1[p1] = cnt;
				MAP2[cnt] = p1;
				cnt++;
			}

			if (MAP1[p2] == 0)
			{
				MAP1[p2] = cnt;
				MAP2[cnt] = p2;
				cnt++;
			}

			G[MAP1[p1]].push_back(MAP1[p2]);
			rG[MAP1[p2]].push_back(MAP1[p1]);
		}

		for (I = 1; I <= n; I++)
		{
			if (visited[I] == 0)
				dfs(I);
		}

		memset(visited, 0, sizeof(visited));

		cout << "Calling circles for data set " << caseno++ << ":\n";

		indx = 0;
		while (!topSort.empty())
		{
			int u = topSort.top();
			topSort.pop();

			if (visited[u] == 0)
			{
				dfs1(u);
				indx++;
			}
		}

		for (I = 0; I < indx; I++)
		{
			for (J = 0; J < ans[I].size(); J++)
			{
				int u = ans[I][J];
				cout << MAP2[u];
				if (J < ans[I].size() - 1)
					cout << ", ";
			}
			cout << NL;
		}
	}

	return 0;
}

