// B - Distance in the Tree.cpp
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
LL POW(LL base, LL power){
	LL I, res = base; if (power == 0) return 1;
	for (I = 0; I < power - 1; I++) res *= base; return res;
}

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 50000 + 10;

struct node
{
    int n;
    int weight;
};
node info;

vector < node > tree[SIZE];
int parent[SIZE], L[SIZE], dis[SIZE], table[SIZE][16];

void dfs(int from, int u, int level)
{
	int I, v;
	parent[u] = from;
	L[u] = level;
	for (I = 0; I < tree[u].size(); I++)
	{
		v = tree[u][I].n;
		if (v == from)
			continue;
        dis[v] = dis[u] + tree[u][I].weight;
		dfs(u, v, level + 1);
	}
}

void initLCA(int N)
{
	memset(table, -1, sizeof(table));
	int I, J;
	for (I = 0; I < N; I++)
		table[I][0] = parent[I];

	for (J = 1; (1 << J) < N; J++)
	{
		for (I = 0; I < N; I++)
		{
			if (table[I][J - 1] != -1)
				table[I][J] = table[table[I][J - 1]][J - 1];
		}
	}
}

int lcaQuery(int N, int u, int v)
{
	int tmp, log, I;
	if (L[u] < L[v])
	{
		tmp = u;
		u = v;
		v = tmp;
	}

	log = 1;
	while (1)
	{
		int next = log + 1;
		if ((1 << next) > L[u])
			break;
		log++;
	}

	for (I = log; I >= 0; I--)
	{
		int x = (1 << I);
		if (L[u] - x >= L[v])
			u = table[u][I];
	}

	if(u == v)
		return u;

	for (I = log; I >= 0; I--)
	{
		if (table[u][I] != -1 && table[u][I] != table[v][I])
		{
			u = table[u][I];
			v = table[v][I];
		}
	}
	return parent[u];
}

int main()
{
	//BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, Q, u, v, w, LCA;
	//READ();
	//WRITE();
	SF("%d", &N);
	for (I = 0; I < N - 1; I++)
	{
		SF("%d %d %d", &u, &v, &w);
		info.n = v;
		info.weight = w;
		tree[u].push_back(info);
		info.n = u;
		tree[v].push_back(info);
	}

	dfs(0, 0, 0);
	initLCA(N);

	SF("%d", &Q);
	for (I = 0; I < Q; I++)
	{
		SF("%d %d", &u, &v);
		LCA = lcaQuery(N, u, v);
		// dis(root, u) + dis(root, v) - 2 * dis(root, LCA)
		PF("%d\n", dis[u] + dis[v] - 2 * dis[LCA] );
	}
	return 0;
}

/*
9
0 1 1
1 2 1
1 3 1
2 4 1
0 5 1
5 6 1
5 7 1
6 8 1
0
*/

/*
17
0 1 1
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1
6 14 1
6 7 1
1 8 1
8 9 1
9 10 1
10 11 1
11 12 1
11 15 1
12 16 1
12 13 1
1
14 11
*/

/*
7
0 1 1
0 2 1
1 3 2
1 5 3
2 4 5
4 6 10
2
3 6
*/
