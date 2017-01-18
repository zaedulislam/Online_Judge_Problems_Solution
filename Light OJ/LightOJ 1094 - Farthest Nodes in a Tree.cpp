// LightOJ 1094 - Farthest Nodes in a Tree.cpp
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

template <class T> inline T MAX(T a, T b){ return (a > b) ? a : b; }

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 30000 + 10;

struct node
{
	int n;
	int weight;
};

node info[SIZE];

vector< node > G[SIZE];
queue< int > qi;
int visited[SIZE], cost[SIZE];

int bfs(int src, int flag)
{
	int mxLevel= 0, mxCost = 0, src2 = 0;
	while(!qi.empty())
		qi.pop();

	memset(visited, 0, sizeof(visited));
	memset(cost, 0, sizeof(cost));

	qi.push(src);
	visited[src] = 1;
	cost[src] = 0;

	int u, v , I;
	while(!qi.empty())
	{
		u = qi.front();
		qi.pop();
		for(I = 0; I < G[u].size(); I++)
		{
			v = G[u][I].n;
			if(visited[v] == 0)
			{
				visited[v] = 1;
				cost[v] = cost[u] + G[u][I].weight;

				if(cost[v] >= mxCost)
				{
					mxCost = cost[v];
					src2 = v;
				}
				qi.push(v);
			}
		}
	}
	if(!flag)
		return src2;
	else
		return mxCost;
}


int main()
{
	//BOOST
	int tcases, I, J, K, N, m, cnt = 0, len, u, v, w, maxLevel = 0, src;
	//READ();
	//WRITE();
	SF("%d", &tcases);
	while(tcases--)
	{
		node tmp;
		SF("%d", &N);

		for(I = 0; I <= N; I++)
			G[I].clear();

		for(I = 0; I < N - 1; I++)
		{
			SF("%d %d %d", &u, &v, &w);
			tmp.n = v;
			tmp.weight = w;
			G[u].push_back(tmp);
			tmp.n = u;
			G[v].push_back(tmp);
		}
		src = bfs(0, 0);
		PC();
		PF("%d\n", bfs(src, 1));
	}

	return 0;
}

