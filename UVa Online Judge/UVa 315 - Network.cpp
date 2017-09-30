// UVa 315 - Network.cpp

/// Template by Zayed ///

///************************************************************///
/// #include <bits/stdc++.h>
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
//#include<unordered_map>
#include <set>
//#include<unordered_set>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdlib>
///************************************************************///
using namespace std;
int caseno = 1;
///************************************************************///
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
///************************************************************///
typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
///************************************************************///
#define INF (1 << 31) - 1
#define MOD 1000000007
#define PRIME 999998727899999 			// (largest prime below 10^16)
#define PB push_back
#define pii pair<int, int>
#define pic pair<int, char>
#define pci pair<char, int>
#define pLL pair<LL, LL>
#define pis pair<int, string>
#define psi pair<string, int>
#define pss pair<string, string>
#define PI 2 * acos(0.0)
#define EPS 1e-11
///************************************************************///
// Numeric Functions
template < class T > inline void SWAP(T &a, T &b) { T t = a; a = b; b = t; }
inline LL POW(LL base, LL power){
	LL res = base; if (power == 0) return 1;
	for (int I = 0; I < power - 1; I++) res *= base; return res;
}
// Translator Functions

double ToDouble(string s) { double r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:ToDouble(
string ToString(int n) { string s; stringstream convert; convert << n; s = convert.str(); return s; }//NOTES:ToString(
///************************************************************///

/*
*******4 Direction Array*******
int dx[] = {0, 0, - 1, 1}, dy[] = {-1, 1, 0, 0};
*******8 Direction Array*******
int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1};
********Knight Moves********
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};
*/

const int SIZE = 100 + 10;
string S;
vector<int> G[SIZE];
int low[SIZE], DT[SIZE], parent[SIZE], ar[SIZE];
bool articulationPoint[SIZE], visited[SIZE];
int t = 0;


int ToInt(string s)
{
	stringstream convert(s);

	int I = 0;
	while(convert >> ar[I++]) {}

	return I - 1;
}


void FindArticulationPoint(int u)
{
	int I, v, SZ, children = 0;
	t++;
	visited[u] = true;
	DT[u] = t;
	low[u] = t;

	SZ = G[u].size();
	for(I = 0; I < SZ; I++)
	{
		v = G[u][I];

		if(v == parent[u])
			continue;
		if(visited[v] == true)
			low[u] = min(low[u], DT[v]);

		if(visited[v] == false)
		{
			parent[v] = u;

			FindArticulationPoint(v);

			low[u] = min(low[u], low[v]);

			if(DT[u] <= low[v] && parent[u] != -1)
				articulationPoint[u] = true;

			children++;

		}

		if(children > 1 && parent[u] == -1)
			articulationPoint[u] = true;

	}

	t++;

}


int main()
{
	///BOOST
	///READ();
	///WRITE();
	int T, I, J, K, N, n, m, cnt = 0, len;

	while(1)
	{
		SF("%d", &N);

		if(N == 0)
			break;


		for(I = 0; I < SIZE; I++)
			G[I].clear();

		CLR(low);
		CLR(DT);
		CLR(articulationPoint);
		SET(parent);
		CLR(visited);

		while(1)
		{

			getline(cin, S);

			int idx = ToInt(S);

			if(idx == 1 && ar[0] == 0)
				break;

			int u = ar[0];
			for(I = 1; I < idx; I++)
			{
				int v = ar[I];

				G[u].PB(v);
				G[v].PB(u);
			}

		}

		FindArticulationPoint(1);

		cnt = 0;
		for(I = 1; I <= N; I++)
		{
			if(articulationPoint[I] == true)
				cnt++;
		}

		PF("%d\n", cnt);

	}


	return 0;
}




