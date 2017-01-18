// UVa 11709 - Trust groups.cpp
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
const int SIZE = 1000 + 10;

map < string, int > MAP1;
map < int , string > MAP2;
vector < int > G[SIZE], rG[SIZE];
stack < int > topSort;
string S, U, V;
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
    visited[u]  =1;
    for(I = 0; I < rG[u].size(); I++)
    {
        v = rG[u][I];
        if(visited[v] == 0)
            dfs1(v);
    }
}

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 1, len, P, T;
	//READ();
	//WRITE();
    while(cin >> P >> T)
    {
        if(P == 0 && T == 0)
            break;

        cin.ignore();
        for(I = 0; I <= P; I++)
            G[I].clear(), rG[I].clear();

        memset(visited, 0, sizeof(visited));
        while(!topSort.empty())
            topSort.pop();

        MAP1.clear();
        MAP2.clear();

        for(I = 0; I < P; I++)
            getline(cin, S);

        cnt = 1;
        for(I = 0; I < T; I++)
        {
            getline(cin, U);
            getline(cin, V);

            if(MAP1[U] == 0)
            {
                MAP1[U] = cnt;
                MAP2[cnt] = U;
                cnt++;
            }
            if(MAP1[V] == 0)
            {
                MAP1[V] = cnt;
                MAP2[cnt] = V;
                cnt++;
            }

            G[MAP1[U]].push_back(MAP1[V]);
            rG[MAP1[V]].push_back(MAP1[U]);
            //cout << U << NL << V << NL;
        }

        for(I = 1; I <= P; I++)
        {
            if(visited[I] == 0)
                dfs(I);
        }

        memset(visited, 0, sizeof(visited));

        cnt = 0;
        while(!topSort.empty())
        {
            int u = topSort.top();
            topSort.pop();

            if(visited[u] == 0)
            {
                dfs1(u);
                cnt++;
            }
        }

        cout << cnt << NL;
    }

	return 0;
}

