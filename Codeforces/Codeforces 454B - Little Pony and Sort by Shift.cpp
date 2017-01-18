// Codeforces 454B - Little Pony and Sort by Shift.cpp
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

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e5 + 10;

int ar[SIZE], ans[SIZE];

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, L, f;
	///READ();
	///WRITE();
	cin >> n;
	for(I = 0; I < n; I++)
		cin >> ar[I];

	L = 0;
	for(I = 0; I < n - 1; I++)
	{
		if(ar[I] > ar[I + 1])
		{
			L = I + 1;
			break;
		}
	}

	J = 0;
	for(I = L; I < n; I++)
		ans[J++] = ar[I];

	for(I = 0; I <= L; I++)
		ans[J++] = ar[I];

	f = 0;
	for(I = 0; I < n - 1; I++)
	{
		if(ans[I] > ans[I + 1])
		{
			f = 1;
			break;
		}
	}

	if(f)
		cout << "-1" << NL;
	else if(L == 0)
		cout << 0 << NL;
	else
		cout << n - L << NL;

	return 0;
}

