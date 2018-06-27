// HackerRank - Kingdom Connectivity.cpp

/// Template by Zayed ///

/// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>

#include <string>
#include <cstring>
#include <sstream>

//#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <map>
//#include<unordered_map>
#include <set>
//#include<unordered_set>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdlib>

using namespace std;
int caseno = 1;

#define NL '\n'
#define SF scanf
#define PF printf
#define PC() printf("Case %d: ", caseno++)//NOTES:printf
//#define PC cout << "Case "//NOTES:cout
//#define CN cout << caseno++ << ": "//NOTES:cout
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define READ() freopen("input.txt", "r", stdin)
#define WRITE() freopen("output.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"

#define INF (1 << 31) - 1
#define MOD 1000000000
#define PRIME 999998727899999 			// (largest prime below 10^16)
#define PB push_back
#define pii pair<int, int>
#define pic pair<int, char>
#define pci pair<char, int>
#define pLL pair<LL, LL>
#define pis pair<int, string>
#define psi pair<string, int>
#define pss pair<string, string>
//#define tiii tuple<int, int, int>
#define PI 2 * acos(0.0)
#define EPS 1e-11


// Numeric Functions
template < class T > inline void SWAP(T &a, T &b) { T t = a; a = b; b = t; }
inline LL POW(LL base, LL power){
	LL res = base; if (power == 0) return 1;
	for (int I = 0; I < power - 1; I++) res *= base; return res;
}


// Translator Functions
int ToInt(string s) { int r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:ToInt(
double ToDouble(string s) { double r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:ToDouble(
string ToString(int n) { string s; stringstream convert; convert << n; s = convert.str(); return s; }//NOTES:ToString(


/*
*******4 Direction Array*******
int dx[] = {0, 0, - 1, 1}, dy[] = {-1, 1, 0, 0};
*******8 Direction Array*******
int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1};
********Knight Moves********
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};
*/
#define WHITE 0
#define GRAY 1
#define BLACK 2
const int SIZE = 1e4 + 10;
vector<int> G[SIZE], rG[SIZE];
bool inCycle[SIZE];
int visited[SIZE], N;
LL dp[SIZE];




void CycleCheck(int u)
{
	visited[u] = GRAY;

	int I, v, SZ = G[u].size();
	for(I = 0; I < SZ; I++)
	{
        v = G[u][I];

        if(visited[v] == WHITE)
			CycleCheck(v);
		else if(visited[v] == GRAY)
			inCycle[v] = true;
	}

	visited[u] = BLACK;

}



void DFS(int u)
{
	visited[u] = GRAY;

	int I, v, SZ = rG[u].size();
	for(I = 0; I < SZ; I++)
	{
        v = rG[u][I];
        if(visited[v] == WHITE)
			DFS(v);
	}

	visited[u] = BLACK;
}



LL F(int u)
{
	if(inCycle[u] == true)
		return 0;

	if(u == N)
		return 1;

	if(dp[u] != -1)
		return dp[u];

	LL I, v, ret = 0, SZ = G[u].size();
	for(I = 0; I < SZ; I++)
	{
		v = G[u][I];
		ret = ((ret % MOD) + (F(v) % MOD)) % MOD;
	}

	dp[u] = ret;
	return dp[u];

}



int main()
{
	BOOST
	///READ();
	///WRITE();
	int T, I, J, K, n, m, k, cnt = 0, len, M, u, v;

	cin >> N >> M;

	for(I = 0; I < M; I++)
	{
		cin >> u >> v;

		G[u].PB(v);
		rG[v].PB(u);
	}

	CLR(visited);
	CycleCheck(1);


	CLR(visited);
	DFS(N);


	for(I = 1; I <= N; I++)
	{
		if(inCycle[I] == true && visited[I] == BLACK)
		{
			cout << "INFINITE PATHS\n";
			return 0;
		}

	}

	SET(dp);
	cout << F(1) << NL;


	return 0;
}




