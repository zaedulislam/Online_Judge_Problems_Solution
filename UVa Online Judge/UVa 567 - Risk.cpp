// UVa 567 - Risk.cpp
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
using namespace std;

int caseno = 1;
#define NL '\n'
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
#define SF scanf
#define PF printf
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define PC() printf("Test Set #%d\n", caseno++)
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

vector<int>G[SIZE];
queue<int>qi;
int visited[SIZE], level[SIZE];

int BFS(int src, int target)
{
    while(!qi.empty())
        qi.pop();

    memset(visited, 0, sizeof(visited));
    memset(level, 0, sizeof(level));

    qi.push(src);
    visited[src] = 1;
    level[src] = 0;

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
                level[v] = level[u] + 1;

                if(v == target)
                    return level[v];

                qi.push(v);
            }
        }
    }
}


int main()
{
	///BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, A, B, u, v, ans;
	///READ();
	///WRITE();
    while(SF("%d", &n) != EOF)
    {
        for(I = 0; I <= 20; I++)
            G[I].clear();

        u = 1;
        for(I = 0; I < n; I++)
        {
            SF("%d", &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        for(I = 2; I <= 19; I++)
        {
            u = I;
            SF("%d", &n);
            for(K = 0; K < n; K++)
            {
                SF("%d", &v);
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }

        SF("%d", &N);
        PC();

        for(I = 0; I < N; I++)
        {
            SF("%d%d", &A, &B);
            ans = BFS(A, B);
            PF("%2d to %2d: %d\n", A, B, ans);
        }
        PF("\n");
    }

	return 0;
}

