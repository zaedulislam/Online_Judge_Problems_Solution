// UVa 11838 - Come and Go.cpp
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
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e6;

vector< int > G[SIZE], rG[SIZE];
stack< int > topSort;
int visited[SIZE];

void dfs(int u)
{
    int I, v;
    visited[u] = 1;
    for(I = 0; I < G[u].size(); I++)
    {
        v = G[u][I];
        if(visited[v] == 0)
            dfs(v);
    }
    topSort.push(u);
}

void dfs1(int u)
{
    int I, v;
    visited[u] = 1;
    for(I = 0; I < rG[u].size(); I++)
    {
        v = rG[u][I];
        if(visited[v] == 0)
            dfs1(v);
    }
}

int main()
{
	//BOOST
	int tcases, I, J, K, N, M,n, m, cnt = 0, len, u, v, P, f;
	//READ();
	//WRITE();
    while(1)
    {
        SF("%d %d", &N, &M);

        if(N == 0 && M == 0)
            break;

        memset(visited, 0, sizeof(visited));
        for(I = 0; I <= N; I++)
            G[I].clear(), rG[I].clear();

        for(I = 0; I < M; I++)
        {
            SF("%d %d %d", &u, &v, &P);
            G[u].push_back(v);
            rG[v].push_back(u);

            if(P == 2)
            {
                G[v].push_back(u);
                rG[u].push_back(v);
            }
        }

        for(I = 1; I <= N; I++)
        {
            if(visited[I] == 0)
                dfs(I);
        }

        memset(visited, 0, sizeof(visited));

        cnt = 0, f = 1;
        while(!topSort.empty())
        {
            u = topSort.top();
            topSort.pop();

            if(visited[u] == 0)
            {
                cnt++;
                if(cnt >= 2)
                {
                    f = 0;
                    break;
                }
                dfs1(u);
            }
        }

        if(f == 1)
            PF("1\n");
        else
            PF("0\n");
    }

	return 0;
}

