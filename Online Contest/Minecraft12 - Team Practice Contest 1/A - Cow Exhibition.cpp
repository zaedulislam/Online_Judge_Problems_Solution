// A - Cow Exhibition.cpp
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

template <class T> inline T MAX(T a, T b){ return (a > b) ? a : b; }

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 110;

int a[SIZE], b[SIZE], dp[SIZE][10010];

int recurse(int pos, int taken, int n)
{
	if (pos >= n)
		return taken;

	if (dp[pos][taken] != -1)
		return dp[pos][taken];

	int ret1 = 0, ret2 = 0;
	ret1 = recurse(pos + 1, taken + a[pos] + b[pos], n);
	ret2 = recurse(pos + 1, taken, n);
	dp[pos][taken] = MAX(ret1, ret2);
	return dp[pos][taken];

}

int main()
{
	///BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len;
	///READ();
	///WRITE();
	SET(dp);

	SF("%d", &n);
	for (I = 0; I < n; I++)
		SF("%d %d", &a[I], &b[I]);

	PF("%d\n", recurse(0, 0, n));

	return 0;
}

/*
5
-5 7
8 -6
6 -3
2 1
-8 -5
*/