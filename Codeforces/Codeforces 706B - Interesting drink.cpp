// Codeforces 706B - Interesting drink.cpp
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

int ar[SIZE];

int binSearch(int n, int x)
{
	int first = 1, last = n, mid, pos = -1;
	while(first <= last)
	{
		mid = (first + last) / 2;
		if(ar[mid] == x)
		{
			pos = mid;
			first = mid + 1;
		}
		else if(ar[mid] > x)
			last = mid - 1;
		else
			first = mid + 1;
	}

	if(pos != -1)
		return pos;
	else
		return first - 1;
}


int main()
{
	///BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, x, ans, Q;
	///READ();
	///WRITE();
	SF("%d", &n);

	for(I = 1; I <= n; I++)
		SF("%d", &ar[I]);

	sort(ar , ar + n + 1);

	SF("%d", &Q);
	for(I = 0; I < Q; I++)
	{
		SF("%d", &x);

		ans = binSearch(n, x);
		if(ans != -1)
			PF("%d\n", ans - 1 + 1);
		else
			PF("%d\n", 0);
	}

	return 0;
}

