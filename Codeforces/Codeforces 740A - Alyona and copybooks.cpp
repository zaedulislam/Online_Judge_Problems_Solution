// Codeforces 740A - Alyona and copybooks.cpp
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

template <class T> inline T MIN(T a, T b){ return (a < b) ? a : b; }

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 5;

LL ar[SIZE];

int main()
{
	BOOST
	LL tcases, I, J, K, N, n, m, cnt = 0, len, x, r, ans, a, b,c, y;
	///READ();
	///WRITE();
	cin >> n >> ar[1] >> ar[2] >> ar[3];

	if(n % 4 == 0)
	{
		cout << 0 << NL;
		return 0;
	}
	else
	{
		m = n / 4;
		m++;
		x = m * 4;
		r = x - n;
	}

	if(r == 1)
		ans = MIN((ar[2] + ar[3]), MIN(ar[1], (3 * ar[3])));
	else if(r == 2)
	{
		a = ar[1] * r;
		ans = MIN((2 * ar[3]), MIN(a, ar[2]));
	}
	else if(r == 3)
	{
		a = ar[1] * r;
		y = ar[2] + ar[1];
		ans = MIN(a, MIN(y, ar[3]));
	}

	cout << ans << NL;

	return 0;
}

