// Codeforces 501B - Misha and Changing Handles (Using DFS).cpp

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


const int SIZE = 2000 + 10;
bool visited[SIZE];
vector<int> G[SIZE];
vector<pii> vi;
map<string, int> MAP1;
map<int, string> MAP2;
string S1, S2;




int DFS(int u)
{
	visited[u] = true;

	int I, v, ret = u, SZ = G[u].size();
	for(I = 0; I < SZ; I++)
	{
		v = G[u][I];
		if(!visited[v])
			ret = DFS(v);

	}

	return ret;

}



int main()
{
	BOOST
	///READ();
	///WRITE();
	int T, I, J, K, N, n, m, k, cnt = 0, len, q, id, u, v;

	cin >> q;

	id = 1;
	while(q--)
	{
		cin >> S1 >> S2;

		if(MAP1.find(S1) == MAP1.end())
		{
			MAP1[S1] = id;
			MAP2[id] = S1;
			id++;
		}


		if(MAP1.find(S2) == MAP1.end())
		{
			MAP1[S2] = id;
			MAP2[id] = S2;
			id++;
		}


		u = MAP1[S1];
		v = MAP1[S2];

		G[u].PB(v);

	}

	N = id;


	for(I = 1; I < N; I++)
	{
		u = I;

		if(!visited[u])
		{
			v = DFS(u);
			vi.PB(pii(u, v));
		}
	}

	cout << vi.size() << NL;
	for(I = 0; I < vi.size(); I++)
		cout << MAP2[vi[I].first] << ' ' << MAP2[vi[I].second] << NL;

	return 0;
}




