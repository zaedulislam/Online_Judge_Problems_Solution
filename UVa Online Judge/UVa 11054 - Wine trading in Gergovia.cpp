// UVa 11054 - Wine trading in Gergovia.cpp
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
#include <cstdlib>
#include <ctime>
using namespace std;

int caseno = 1;
#define NL '\n'
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
#define SF scanf
#define PF printf
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define PC() printf("Case %d: ", caseno++)
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e5 + 10;

LL ar[SIZE];

int main()
{
	///BOOST
	LL tcases, I, J, K, N, n, m, cnt = 0, len, amount, ABS_K;
	///READ();
	///WRITE();
	while (SF("%lld", &n), (n || 0))
	{
		for (I = 0; I < n; I++)
			SF("%lld", &ar[I]);

		J = 0;
		while (J < n)
		{
			if (ar[J] > 0)
				break;
			J++;
		}

		K = 0;
		while (K < n)
		{
			if (ar[K] < 0)
				break;
			K++;
		}

		///cout << "J = " << J << " K = " << K << NL;

		amount = 0;
		while (J < n && K < n)
		{
			if (ar[J] == 0 && ar[K] == 0)
				break;

			ABS_K = (LL)abs((double)ar[K]);

			if (ar[J] == ABS_K)
			{
				amount += ((LL)abs(K - J) * ABS_K);
				ar[J] = 0;
				ar[K] = 0;

				while (J < n)
				{
					if (ar[J] > 0)
						break;
					J++;
				}

				while (K < n)
				{
					if (ar[K] < 0)
						break;
					K++;
				}

			}
			else if (ar[J] > ABS_K)
			{
				amount += ((LL)abs(K - J) * ABS_K);
				ar[J] = ar[J] - ABS_K;
				ar[K] = 0;

				while (K < n)
				{
					if (ar[K] < 0)
						break;
					K++;
				}

			}
			else if (ar[J] < ABS_K)
			{
				amount += ((LL)abs(K - J) * ar[J]);
				ar[K] = (-1) * (ABS_K - ar[J]);
				ar[J] = 0;

				while (J < n)
				{
					if (ar[J] > 0)
						break;
					J++;
				}

			}

		}

		PF("%lld\n", amount);
	}

	return 0;
}

/*
5
5 -4 1 -3 1
6
-1000 -1000 -1000 1000 1000 1000
0
*/
