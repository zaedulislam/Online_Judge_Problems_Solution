// UVa 10986 - Sending email.cpp
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
#define PC() printf("Case #%d: ", caseno++)
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

#define INF 2147483647
#define MOD 1000000007
#define pii pair< int, int >
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 20000 + 10;

priority_queue< pii, vector< pii >, greater < pii > > pq;
vector< pii > G[SIZE];
int dis[SIZE];

void dijkstra(int src, int T)
{
	while(!pq.empty())
		pq.pop();

	pq.push(pii(0, src));
	dis[src] = 0;

	pii data;
	int I, u, v, costUV;
	while(!pq.empty())
	{
		data = pq.top();
		u = data.second;

		if(u == T)
			return;

		pq.pop();

		for(I = 0; I < G[u].size(); I++)
		{
			v = G[u][I].first;
			costUV = G[u][I].second;

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
	int tcases, I, J, K, N, n, m, cnt = 0, len, S, T, u, v, w;
	//READ();
	//WRITE();
	SF("%d", &tcases);
	while(tcases--)
	{
		SF("%d %d %d %d", &n, &m, &S, &T);

		for(I = 0; I <= n; I++)
		{
			G[I].clear();
			dis[I] = INF;
		}

        for(I = 0; I < m; I++)
		{
			SF("%d %d %d", &u, &v, &w);
			G[u].push_back(pii(v, w));
			G[v].push_back(pii(u, w));
		}

		PC();
		dijkstra(S, T);

		if(dis[T] == INF)
			PF("unreachable\n");
		else
			PF("%d\n", dis[T]);
	}

	return 0;
}

