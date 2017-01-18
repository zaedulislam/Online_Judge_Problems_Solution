// Codeforces 754A - Lesha and array splitting.cpp
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

const int SIZE = 100 + 10;
int ar[SIZE];


int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len;
	///READ();
	///WRITE();
	cin >> n;

	int f = 0;
	for (I = 1; I <= n; I++)
	{
		cin >> ar[I];
		if (ar[I] != 0)
		{
			cnt++;
			f = 1;
		}
	}

	if (cnt == 1)
	{
		cout << "YES\n" << 1 << NL << 1 << ' ' << n << NL;
		return 0;
	}

	if (f == 0)
	{
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n" << cnt << NL;


	I = 1;
	while (I <= n)
	{
		int a = 0, b = 0;
		if (ar[I] == 0)
		{
			a = I;
			while (ar[I] == 0)
				I++;
			b = I;

			if (I + 1 <= n && ar[I + 1] == 0)
			{
				I++;
				while (I <= n && ar[I] == 0)
					I++;

				I = I - 1;
				b = I;
				cout << a << ' ' << b << NL;
			}
			else
				cout << a << ' ' << b << NL;

			I++;
		}
		else
		{
			a = I;
			if (I + 1 <= n && ar[I + 1] == 0)
			{
				I++;
				while (I <= n && ar[I] == 0)
					I++;

				I = I - 1;
				b = I;
				cout << a << ' ' << b << NL;

				if (I == n)
					return 0;
				I++;
			}
			else
			{
				cout << a << ' ' << a << NL;
				I++;
			}

		}
	}

	return 0;
}