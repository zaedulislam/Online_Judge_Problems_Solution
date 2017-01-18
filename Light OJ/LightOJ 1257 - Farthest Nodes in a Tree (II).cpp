// LightOJ 1257 - Farthest Nodes in a Tree (II).cpp
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
#define PC() printf("Case %d:\n", caseno++)
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
int visited[SIZE], cost1[SIZE], cost2[SIZE];

int bfs(int src)
{
    int mxCost = 0, src2 = 0;
    while(!qi.empty())
        qi.pop();

    memset(visited, 0, sizeof(visited));
	memset(cost1, 0, sizeof(cost1));

    qi.push(src);
    visited[src] = 1;
    cost1[src] = 0;

    int u, v, I;
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
                cost1[v] = cost1[u] + G[u][I].weight;
                if(cost1[v] > mxCost)
				{
					mxCost = cost1[v];
					src2 = v;
				}
                qi.push(v);
            }
        }
    }

	return src2;
}

void bfs1(int src)
{
	while(!qi.empty())
		qi.pop();

	memset(visited, 0, sizeof(visited));
	memset(cost2, 0, sizeof(cost2));

	qi.push(src);
	visited[src] = 1;
	cost2[src] = 0;

	int I, u, v;
	while(!qi.empty())
	{
		u = qi.front();
		qi.pop();

		for(I = 0; I < G[u].size(); I++)
		{
			v = G[u][I].n;
			if(visited[v] == 0)
			{
				cost2[v] = cost2[u] + G[u][I].weight;
				visited[v] = 1;
				qi.push(v);
			}
		}
	}
}

int main()
{
    //BOOST
    int tcases, I, J, K, N, n, m, cnt = 0, len, u, v, w, src, a, b;
    //READ();
    //WRITE();
    SF("%d", &tcases);
    while(tcases--)
    {
        SF("%d", &N);

        for(I = 0; I <= N; I++)
            G[I].clear();

        node tmp;
        for(I = 0; I < N - 1; I++)
        {
            SF("%d %d %d", &u, &v, &w);
            tmp.n = v;
            tmp.weight = w;
            G[u].push_back(tmp);
            tmp.n = u;
            G[v].push_back(tmp);
        }

        a = bfs(0);
        //cout << "src = " << a << NL;
        PC();
        b = bfs(a);
		//cout << "src = " << b << NL;
		bfs1(b);

        for(I = 0; I < N; I++)
			PF("%d\n", MAX(cost1[I], cost2[I]));
    }

    return 0;
}


/*
1
7
0 1 2303
3 5 5957
3 2 7732
0 2 163
4 0 1689
4 6 5156
*/

/*
Case 1:
13852
16155
13689
14740
15541
20697
20697
*/

/*
Algorithm:
1. Run a BFS from any node and determine the farthest node from it and Name this node as b.
2. Run another BFS from b and save all node’s distance from b (dis array). and determine the farthest node from b and name this node as a;
3. Run another BFS from a and save all nodes distance from a (dis1 array).
4. Now print for all node max(dis[node], dis1[node]).
*/