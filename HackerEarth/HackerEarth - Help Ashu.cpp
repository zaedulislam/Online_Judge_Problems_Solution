// HackerEarth - Help Ashu.cpp

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


const int SIZE = 1e5 + 10;
int ar[SIZE];
pii tree[4 * SIZE];




void Init(int node, int b, int e)
{

	if(b == e)
	{
		if(ar[b] & 1)
			tree[node].first = 1;
		else
			tree[node].second = 1;

		return;
 	}

	int left = 2 * node;
	int right = 2* node + 1;
	int mid = (b + e) / 2;

	Init(left, b, mid);
	Init(right, mid + 1, e);

	tree[node].first = (tree[left].first + tree[right].first);
	tree[node].second = (tree[left].second + tree[right].second);

}



void Update(int node, int b, int e, int I, int delta)
{

	if(b > I || e < I)
		return;

	if(b == I && e == I)
	{
		if(delta & 1)
		{
			tree[node].first = 1;
			tree[node].second = 0;
		}
		else
		{
			tree[node].first = 0;
			tree[node].second = 1;
		}

		return;
	}

	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (b + e) / 2;

	Update(left, b, mid, I, delta);
	Update(right, mid + 1, e, I, delta);

	tree[node].first = (tree[left].first + tree[right].first);
	tree[node].second = (tree[left].second + tree[right].second);
}



int Query(int node, int b, int e, int I, int J, int flag)
{
	if(b > J || e < I)
		return 0;

	if(b >= I && e <= J)
	{
		if(flag == 1)
			return tree[node].second;
		else
			return tree[node].first;

	}

	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (b + e) / 2;

	int ret1 = Query(left, b, mid, I, J, flag);
	int ret2 = Query(right, mid + 1, e, I, J, flag);

	return ret1 + ret2;

}



int main()
{
	///BOOST
	///READ();
	///WRITE();
	int T, I, J, K, N, n, m, k, cnt = 0, len, Q, x, y;

	SF("%d", &N);

	for(I = 1; I <= N; I++)
		SF("%d", &ar[I]);

	SF("%d", &Q);

	Init(1, 1, N);

	for(I = 1; I <= Q; I++)
	{
		SF("%d%d%d", &n, &x, &y);

        if(n == 0)
			Update(1, 1, N, x, y);
		else if(n == 1)
			PF("%d\n", Query(1, 1, N, x, y, 1));
		else
			PF("%d\n", Query(1, 1, N, x, y, 2));

	}

	
	return 0;
}




