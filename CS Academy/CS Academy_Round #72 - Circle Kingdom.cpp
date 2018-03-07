// CS Academy_Round #72 - Circle Kingdom.cpp

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
#define BUG() printf("\n!!!WHERE IS YOUR FOCUS!!!\n")//NOTES:printf
//#define PC cout << "Case "//NOTES:cout
//#define CN cout << caseno++ << ": "//NOTES:cout
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define READ() freopen("input.txt", "r", stdin)
#define WRITE() freopen("output.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"

#define INTMAX (1LL << 31) - 1
#define LLMAX (1LL << 63) - 1
#define MOD 1000000007		    // (10^9 + 7)
#define PRIME 999998727899999   // (largest prime below 10^16)
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
LL ToInt(string s) { LL r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:ToInt(
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


const int SIZE = 5000 + 10;
vector< pLL > G[SIZE];
priority_queue< pLL, vector< pLL >, greater < pLL > > pq;
LL dis[SIZE], cost[SIZE];




void Dijkstra(LL src)
{

	pq.push(pLL(0, src));
	dis[src] = 0;


	pLL tmp;
	LL I, u, v, costUV;
	while (!pq.empty())
	{
		tmp = pq.top();
		u = tmp.second;
		pq.pop();

		LL SZ = G[u].size();

		for (I = 0; I < SZ; I++)
		{
			v = G[u][I].first;
			costUV = G[u][I].second;

			if (dis[u] + costUV < dis[v])
			{
				dis[v] = dis[u] + costUV;
				pq.push(pLL(dis[v], v));

			}

		}

	}

}



int main()
{
	///BOOST
	///READ();
	///WRITE();
	LL T, I, J, K, N, n, m, k, cnt = 0, len, u, v;

	SF("%lld", &N);

	for(I = 1; I <= N; I++)
		SF("%lld", &cost[I]);

	for(I = 1; I <= N; I++)
	{
		u = I;
		v = I + 1;

		if(u == N)
			v = 1;

		G[u].PB(pLL(v, cost[I]));
		G[v].PB(pLL(u, cost[I]));

	}


	LL mx, capital, mn = LLMAX;
	for(I = 1; I <= N; I++)
	{
		u = I;

		for(J = 1; J <= N; J++)
			dis[J] = LLMAX;

		Dijkstra(u);

		mx = 0;
		for(J = 1; J <= N; J++)
			mx = max(mx, dis[J]);


		if(mx < mn)
		{
			mn = mx;
			capital = u;
		}

	}

	PF("%lld\n", capital);


	return 0;
}




