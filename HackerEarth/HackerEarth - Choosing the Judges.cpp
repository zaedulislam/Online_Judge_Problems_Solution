// HackerEarth - Choosing the Judges.cpp
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

template <class T> inline T MAX(T &a, T &b) { return a > b ? a : b; }

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e4 + 10;

int ar[SIZE], dp[SIZE], N;

int func(int pos, int taken)
{
	if (pos >= N)
		return 0;

	if (dp[pos] != -1)
		return dp[pos];

	int profit1 = 0, profit2 = 0;
	profit1 = ar[pos] + func(pos + 2, taken + ar[pos]);
	profit2 = func(pos + 1, taken);

	dp[pos] = MAX(profit1, profit2);
	return dp[pos];
}

int main()
{
	///BOOST
	int tcases, I, J, K, n, m, cnt = 0, len;
	///READ();
	///WRITE();
	SF("%d", &tcases);
	while (tcases--)
	{
		SET(dp);

		SF("%d", &N);
		for (I = 0; I < N; I++)
			SF("%d", &ar[I]);

		PC();
		PF("%d\n", func(0, 0));
	}

	return 0;
}

