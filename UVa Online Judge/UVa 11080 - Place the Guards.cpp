// UVa 11080 - Place the Guards.cpp
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
const int SIZE = 200 + 10;
const int BLACK = 1;
///************************************************************///

int visited[SIZE], color[SIZE], guards, black, white;
vector<int> G[SIZE];
queue<int> qi;

int BFS(int src)
{
    while(!qi.empty())
        qi.pop();

    visited[src] = 1;
    color[src] = BLACK;
    qi.push(src);

    int I, u, v;
    black = 0, white = 1;

    while(!qi.empty())
    {
        u = qi.front();
        qi.pop();

        for(I = 0; I < G[u].size(); I++)
        {
            v = G[u][I];
            if(visited[v] == 0)
            {
                if(color[u] == BLACK)
                    black++;
                else
                    white++;

                color[v] = !(color[u]);

                visited[v] = 1;
                qi.push(v);
            }
            if(color[u] == color[v])
                return -1;
        }
    }
    return min(black, white);
}

int main()
{
	///BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, v, e, a, b, x;
	///READ();
	///WRITE();
	SF("%d", &tcases);
	while(tcases--)
    {
        SF("%d%d", &v, &e);

        for(I = 0; I <= v; I++)
            G[I].clear();

        memset(visited, 0, sizeof(visited));

        for(I = 0; I < e; I++)
        {
            SF("%d%d", &a, &b);
            G[a].push_back(b);
            G[b].push_back(a);
        }

        guards = 0;
        for(I = 0; I < v; I++)
        {
            if(visited[I] == 0)
            {
                int src = I;
                x = BFS(src);

                if(black == 0)
                    guards += 1;
                else
                    guards += x;

                if(x == -1)
                    break;
            }
        }

        if(x != -1)
            PF("%d\n", guards);
        else
            PF("-1\n");
    }

	return 0;
}
