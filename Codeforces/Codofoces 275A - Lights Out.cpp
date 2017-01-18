// Codeforces 275A - Lights Out.cpp
///************************************************************///
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
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
#define SF scanf
#define PF printf
///************************************************************///
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define PC() printf("Case %d: ", caseno++)
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);
///************************************************************///
typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64
///************************************************************///
#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e6;
///************************************************************///

/*
*******4 Direction Array*******
int dx[] = {0, 0, - 1, 1}, dy[] = {-1, 1, 0, 0};

*******8 Direction Array*******
int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1};

********Knight Moves********
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};
*/

int G[10][10], flag[10][10];

int main()
{
	BOOST
		int tcases, I, J, K, N, n, m, cnt = 0, len;
	///READ();
	///WRITE();
	for (I = 0; I < 3; I++)
	{
		for (K = 0; K < 3; K++)
			cin >> G[I][K];
	}

	for (I = 0; I < 3; I++)
	{
		for (K = 0; K < 3; K++)
			flag[I][K] = 1;
	}

	int f;
	for (I = 0; I < 3; I++)
	{
		for (K = 0; K < 3; K++)
		{
			if (G[I][K] == 0)
				continue;

			f = 0;
			if (G[I][K] % 2 != 0)
			{
				f = 1;
				flag[I][K] = !flag[I][K];
			}

			if (K - 1 >= 0)
			{
				if (f)
					flag[I][K - 1] = !flag[I][K - 1];
			}
			if (K + 1 < 3)
			{
				if (f)
					flag[I][K + 1] = !flag[I][K + 1];
			}
			if (I + 1 < 3)
			{
				if (f)
					flag[I + 1][K] = !flag[I + 1][K];
			}
			if (I - 1 >= 0)
			{
				if (f)
					flag[I - 1][K] = !flag[I - 1][K];
			}
		}
	}

	for (I = 0; I < 3; I++)
	{
		for (K = 0; K < 3; K++)
			cout << flag[I][K];
		cout << NL;
	}

	return 0;
}


