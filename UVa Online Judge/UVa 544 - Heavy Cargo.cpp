// UVa 544 - Heavy Cargo.cpp

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
//#define PC() printf("Case %d: ", caseno++)//NOTES:printf
#define PC cout << "Scenario #"//NOTES:cout
#define CN cout << caseno++ << "\n" //NOTES:cout
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
int ToInt(string s) { int r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:ToInt(
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

const int SIZE = 200 + 10;
int cost[SIZE], taken[SIZE];
vector<pii> G[SIZE];
string A, B;
map<string, int> MAP;
vector<int> mst;


struct Node
{
	int a, cost;
	Node() {}
	Node(int _a, int _cost)
	{
		a = _a;
		cost = _cost;

	}

};


bool operator<(Node A, Node B)
{
	return A.cost < B.cost;
}

priority_queue<Node> PQ;


void PRIM(int src, int N)
{
	int I;
	for (I = 0; I <= N; I++)
	{
		cost[I] = 0;
		taken[I] = 0;
	}

	while (!PQ.empty())
		PQ.pop();

	cost[src] = 0;
	PQ.push(Node(src, 0));


	int u, v, costU, costV;

	while (!PQ.empty())
	{

		Node node = PQ.top();
		u = node.a;
		costU = node.cost;
		PQ.pop();

		if (taken[u] == 1)
			continue;
		else
			mst.PB(u);

		taken[u] = 1;

		int SZ = G[u].size();
		for (I = 0; I < SZ; I++)
		{
			pii temp = G[u][I];
			v = temp.first;
			costV = temp.second;

			if (taken[v] == 1)
				continue;
			if (costV > cost[v])
			{
				cost[v] = costV;
				PQ.push(Node(v, costV));
			}

		}

	}

}



int main()
{
	BOOST
	///READ();
	///WRITE();
	int T, I, J, K, N, n, m, cnt = 0, len, r, id, s, d, w, u, v;

	while (1)
	{
		for (I = 0; I < SIZE; I++)
			G[I].clear();

		mst.clear();
		MAP.clear();

		cin >> n >> r;

		if(n == 0 && r == 0)
			break;

		id = 1;
		for (I = 0; I < r; I++)
		{
			cin >> A >> B >> w;

			if (MAP.find(A) != MAP.end())
				u = MAP[A];
			else
			{
				MAP[A] = id;
				u = id++;
			}

			if (MAP.find(B) != MAP.end())
				v = MAP[B];
			else
			{
				MAP[B] = id;
				v = id++;
			}

			G[u].PB(pii(v, w));
			G[v].PB(pii(u, w));

		}

		cin >> A >> B;

		s = MAP[A];
		d = MAP[B];

		PRIM(s, n);

		PC; CN;

		int mn = INF;
		for (I = 1; I < mst.size(); I++)
		{
			mn = min(mn, cost[mst[I]]);

			if(mst[I] == d)
			{
				cout << mn << " tons\n\n";
				break;
			}
		}

	}


	return 0;
}




