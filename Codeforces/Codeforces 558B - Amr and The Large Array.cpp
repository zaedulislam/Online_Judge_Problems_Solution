// Codeforces 558B - Amr and The Large Array.cpp

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
#include <ctime>
///************************************************************///
using namespace std;
int caseno = 1;
///************************************************************///
#define NL '\n'
#define SF scanf
#define PF printf
#define PC() printf("Case %d: ", caseno++)//NOTES:printf
#define PC cout << "Case "//NOTES:cout
#define CN cout << caseno++ << ": "//NOTES:cout
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
///************************************************************///
typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64
///************************************************************///
#define INF (1 << 31) - 1
#define MOD 1000000007
#define pii pair<int, int>
#define pLL pair<LL, LL>
#define pis pair<int, string>
#define psi pair<string, int>
#define PI 2 * acos(0.0);
#define EPS 1e-11;
///************************************************************///
// Numeric Functions
// Translator Functions
///************************************************************///

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
map<int, int> MAP1;
map<int, pii> MAP2;

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, mx, mn, x, L, r;
	///READ();
	///WRITE();
	cin >> n;
	for(I = 1; I <= n; I++)
		cin >> ar[I];

	for(I = 1; I <= n; I++)
	{
		x = ar[I];

		if(MAP1[x] == 0)
		{
			MAP2[x].first = I;
			MAP2[x].second = I;
		}
		else
			MAP2[x].second = I;

		MAP1[x]++;
	}

	mx = 0;
	map<int, int>::iterator it = MAP1.begin();
	while(it != MAP1.end())
	{
		if(it -> second > mx)
			mx = it -> second;
		it++;
	}

	pii ans;
	mn = INF;
	it = MAP1.begin();
	while(it != MAP1.end())
	{
		if(it -> second == mx)
		{
			x = it -> first;
			L = MAP2[x].first;
			r = MAP2[x].second;

			if((r - L + 1) < mn)
			{
				mn = r - L + 1;
				ans.first = L;
				ans.second = r;
			}
		}
		it++;
	}

	cout << ans.first << ' ' << ans.second << NL;

	return 0;
}


