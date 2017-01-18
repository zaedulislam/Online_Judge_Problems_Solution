// UVa 627 - The Net.cpp
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
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 500 + 10;
///************************************************************///

string S;
vector<int> G[SIZE];
stack<int> route;
queue<int> qi;
int ar[SIZE], arSZ = 0;
int visited[SIZE], parent[SIZE];

void ToInt(string S)
{
	arSZ = 0;
	stringstream convert(S);

	while(convert >> ar[arSZ++]);
	arSZ--;
}

void BFS(int src, int target)
{
	while(!qi.empty())
		qi.pop();

	memset(visited, 0, sizeof(visited));
	memset(parent, 0, sizeof(parent));

	parent[src] = 0;
	visited[src] = 1;
	qi.push(src);

	int I, u, v;
	while(!qi.empty())
	{
		u = qi.front();
		qi.pop();

		for(I = 0; I < G[u].size(); I++)
		{
			v = G[u][I];
			if(visited[v] == 0)
			{
				visited[v] = 1;
				parent[v] = u;

				if(v == target)
					return;

				qi.push(v);
			}
		}
	}
}

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, u, v, pv, x;
	///READ();
	///WRITE();
	while(cin >> n)
	{
		for(I = 0; I <= n; I++)
			G[I].clear();

		for(I = 0; I < n; I++)
		{
			cin >> S;
			len = S.length();

			for(K = 0;  K < len; K++)
			{
				if(S[K] == '-' || S[K] == ',')
					S[K] = ' ';
			}

			memset(ar, 0, sizeof(ar));
			ToInt(S);

			u = ar[0];
			for(K = 1; K < arSZ; K++)
			{
				v = ar[K];
				G[u].push_back(v);
			}
			///cout << S << NL;
		}

		cin >> m;
		cout << "-----\n";
		for(I = 0; I < m; I++)
		{
			cin >> u >> v;
			BFS(u, v);

			///cout << visited[v] << NL;

			if(visited[v] == 0)
				cout << "connection impossible\n";
			else
			{
				while(!route.empty())
					route.pop();

				route.push(v);
				pv = parent[v];

				while(pv != u)
				{
					route.push(pv);
					pv = parent[pv];

				}

				route.push(u);

				cout << route.top();
				route.pop();

				while(!route.empty())
				{
					cout << ' ' << route.top();
					route.pop();
				}

				cout << NL;
			}
		}
		
	}

	return 0;
}


