// SPOJ EZDIJKST - Easy Dijkstra Problem.cpp
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

int caseno = 1;
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
#define pii pair < int, int >
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e4 + 10;

int dis[SIZE];
vector < pii > G[SIZE];
priority_queue < pii, vector < pii >, greater < pii > > pq;

void dijkstra(int src, int destination)
{
	while(!pq.empty())
		pq.pop();

	pq.push(pii(0, src));
	dis[src] = 0;

	pii tmp;
	int I, u, v, costUV;
	while(!pq.empty())
	{
		tmp = pq.top();
		u = tmp.second;

		if(u == destination)
			return;

		pq.pop();

		for(I = 0; I < G[u].size(); I++)
		{
			v = G[u][I].first;
			costUV =  G[u][I].second;

			if(dis[u] + costUV < dis[v])
			{
				dis[v] = dis[u] + costUV;
				pq.push(pii(dis[v], v));
			}
		}
	}
}


int main()
{
	//BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, V, E, u, v, w;
	//READ();
	//WRITE();
	SF("%d", &tcases);
	while(tcases--)
	{
		SF("%d%d", &V, &E);

		for(I =0 ;I <= V; I++)
			G[I].clear(), dis[I] = INF;

		memset(visited, 0, sizeof(visited));

		for(I = 0; I < E; I++)
		{
			SF("%d %d %d",&u, &v, &w);
			G[u].push_back(pii(v, w));
		}

		SF("%d %d", &u, &v);

		dijkstra(u, v);

		if(dis[v] == INF)
			PF("NO\n");
		else
			PF("%d\n", dis[v]);

	}

	return 0;
}

