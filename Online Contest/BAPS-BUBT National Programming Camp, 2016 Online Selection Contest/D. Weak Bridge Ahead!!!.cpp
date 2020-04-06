// D. Weak Bridge Ahead!!!.cpp
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
const int SIZE = 10000 + 10;

LL a[SIZE], b[SIZE];

int main()
{
	///BOOST
	LL tcases, I, J, K, N, M, n, m, cnt = 0, t;
	///READ();
	///WRITE();
	SF("%lld", &tcases);
	while (tcases--)
	{
		SF("%lld%lld", &N, &M);

		for (I = 0; I < N; I++)
			SF("%lld", &a[I]);

		for (I = 0; I < M; I++)
			SF("%lld", &b[I]);

		t = 0;
		I = 0, J = 0;
		while (1)
		{
			if (I >= N && J >= M)
			{
				if (a[N - 1] >= b[M - 1])
					t -= a[N - 1];
				else
					t -= b[M - 1];
				break;
			}

			if (I < N)
			{
				if (J < M)
				{
					if (a[I] <= b[J])
					{
						t += a[I];
						I++;
					}
					else
					{
						t += b[J];
						J++;
					}
				}
				else
				{
					t += a[I];
					I++;
				}
			}
			else if (J < M)
			{
				t += b[J];
				J++;
			}
		}

		PC();
		PF("%lld\n", t);
	}
	return 0;
}

