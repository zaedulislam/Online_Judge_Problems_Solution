// UVa 10812 - Beat the Spread!.cpp
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

template <class T> inline T MAX(T &a, T &b) { return a > b ? a : b;}
template <class T> inline T MIN(T &a, T &b) { return a < b ? a : b;}

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e6;

int main()
{
	///BOOST
	LL tcases, I, J, K, N, n, m, cnt = 0, len, sum, diff, x, y;
	///READ();
	///WRITE();
	SF("%lld", &tcases);
	while(tcases--)
	{
		SF("%lld %lld", &sum, &diff);

		if((diff > sum) || ((sum + diff) & 1))  /// Dividing an odd number won't give feasible answer.
		{                                                                 /// Difference between two non-negative number can't
			PF("impossible\n");                        /// be greater than the sum of them.
			continue;
		}

		/*
			x + y = sum
			x - y = diff
			___________
			2x = sum + diff
			x = (sum + diff) / 2;
		*/

		x = (sum + diff) / 2;
		y = sum - x;

		PF("%lld %lld\n", MAX(x, y), MIN(x, y));
	}

	return 0;
}

