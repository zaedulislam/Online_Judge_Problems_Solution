// Codeforces 500A - New Year Transportation.cpp
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
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
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
const int SIZE = 1e5;

int ar[SIZE], visited[SIZE];
vector < int > G[SIZE];
queue < int > qi;

void BFS(int src)
{
	while(!qi.empty())
		qi.pop();

	visited[src] = 1;
	qi.push(src);

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
				qi.push(v);
			}
		}
	}
}

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, t, temp, u, v;
	///READ();
	///WRITE();

	memset(visited, 0, sizeof(visited));

	for(I = 0; I < SIZE; I++)
		G[I].clear();

	SF("%d %d", &N, &t);
	for(I = 1; I < N; I++)
		SF("%d", &ar[I]);

	for(I = 1; I < N; I++)
	{
		u = I;
		v = I + ar[I];
		G[u].push_back(v);
	}

	BFS(1);

	if(visited[t] == 0)
		PF("NO\n");
	else
		PF("YES\n");

	return 0;
}

