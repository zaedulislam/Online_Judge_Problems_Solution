// Codeforces 508B - Anton and currency you all know.cpp

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

const int SIZE = 1e5;
string S;

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, d, f;
	///READ();
	///WRITE();
	cin >> S;
	len = S.length();

	char ch;
	f = 0;
	for(I = 0; I < len - 1; I++)
	{
		d = S[I] - '0';

		if(d % 2 == 0)
		{
			f = 1;
			if(S[len - 1] > S[I])
			{
				ch = S[len - 1];
				S[len - 1] = S[I];
				S[I] = ch;
				break;
			}
		}
	}

	d = S[len - 1] - '0';
	if(f == 1 && (d % 2 != 0))
	{
		for(I = len - 2; I >= 0; I--)
		{
			d = S[I] - '0';

			if(d % 2 == 0)
			{
				ch = S[len - 1];
				S[len - 1] = S[I];
				S[I] = ch;
				break;
			}
		}
	}

	if(f == 0)
	{
		cout << -1 << NL;
		return 0;
	}

	cout << S << NL;

	return 0;
}