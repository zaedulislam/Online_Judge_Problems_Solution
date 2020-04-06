// C - Flea circus.cpp
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
const int SIZE = 5000 + 10;

template<class T> inline void SWAP(T &a, T &b) { T t = a; a = b; b = t; }

vector < int > tree[SIZE]; 	// tree
int parent[SIZE], L[SIZE], table[SIZE][13]; 	// parent/level/Sparse Table
int a[SIZE], b[SIZE]; 	

// DFS Finds parent and level 
void dfs(int from, int u, int level)
{
	int I, v;
	parent[u] = from;
	L[u] = level;
	for(I = 0; I < tree[u].size(); I++)
	{
		v = tree[u][I];
		if(v == from)
			continue;
		dfs(u, v,level + 1);
	}
}

// Builds Sparse Table
void initLCA(int N)
{
	memset(table, -1, sizeof(table));
	int I, J;
	for(I = 1; I <= N; I++)
		table[I][0] = parent[I];

	for(J = 1; (1 << J) < N; J++)
	{
		for(I = 1; I <= N; I++)
		{
			if(table[I][J - 1] != - 1)
				table[I][J] = table[table[I][J - 1]][J - 1];
		}
	}
}

// Finds LCA
int lcaQuery(int N, int u, int v)
{
	int log, I, tmp;
	if(L[u] < L[v])
	{
		tmp = u;
		u = v;
		v = tmp;
	}

	log = 1;
	while(1)
	{
		int next = log + 1;
		if((1 << next) > L[u])
			break;
		log++;
	}

	for(I = log; I >= 0; I--)
	{
		int x = (1 << I);
		if(L[u] - x >= L[v])
			u = table[u][I];
	}

	if(u == v)
		return u;

	for(I = log; I >= 0; I--)
	{
		if(table[u][I] != - 1 && table[u][I] != table[v][I])
		{
			u = table[u][I];
			v = table[v][I];
		}
	}
	return parent[u]; // Returns LCA
}

int main()
{
	//BOOST
	int tcases, I, J, K, N, n, m, cnt1 = 0, cnt2 = 0, len, u, v, Q, LCA;
	//READ();
	//WRITE();
	while(SF("%d", &n), (n || 0))
	{
		memset(parent, 0, sizeof(parent));
		memset(L, 0, sizeof(L));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for(I = 0; I <= n; I++)
			tree[I].clear();

		for(I = 0; I < n - 1; I++)
		{
			SF("%d %d", &u, &v);
			tree[u].push_back(v);
			tree[v].push_back(u);
		}

		dfs(1, 1, 0);
		initLCA(n);

		SF("%d", &Q);
		for(I = 0; I < Q; I++)
		{
			SF("%d %d", &u, &v);
            
            /* Corner Case */
			if(u == v)
			{
				PF("The fleas meet at %d.\n", u);
				continue;
			}
			if(n == 1)
			{
				PF("The fleas jump forever between %d and %d.\n", u, v);
				continue;
			}
            /* Corner Case */

			LCA = lcaQuery(n, u, v);

			cnt1 = 0, cnt2 = 0;
			// Path(bottom_up) from u to LCA in array_a [both inclusive]
            while(parent[u] != LCA && u != LCA)
			{
				a[cnt1++] = u;
				u = parent[u];
			}
			a[cnt1++] = u;
			if(u != LCA)
				a[cnt1++] = LCA;
            
            // Path(bottom_up) from v to LCA in array_b
			while(parent[v] != LCA && v != LCA)
			{
				b[cnt2++] = v;
				v = parent[v];
			}
			if(v != LCA)
				b[cnt2++] = v;
			cnt2--;
            
            // Path from u to v in array_a [both inclusive]
			while(cnt2 >= 0)
			{
				a[cnt1] = b[cnt2];
				cnt1++;
				cnt2--;
			}

			if(cnt1 & 1)       // cnt1 is Odd
				PF("The fleas meet at %d.\n", a[cnt1 >> 1]);
			else
			{
				cnt1 = cnt1 >> 1;
				u = a[cnt1];
				v = a[cnt1 - 1];

				if(u > v)       // As statement says  p <= r
					SWAP(u, v);

				PF("The fleas jump forever between %d and %d.\n", u, v);
			}
		}
	}

	return 0;
}


/*
8
1 2
1 3
2 4
2 5
3 6
3 7
5 8
5
5 1
7 4
1 8
4 7
7 8
0
*/

