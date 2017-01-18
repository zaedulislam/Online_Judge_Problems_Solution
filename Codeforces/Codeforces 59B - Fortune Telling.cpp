// Codeforces 59B - Fortune Telling.cpp
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
const int SIZE = 100 + 10;

int odd[SIZE], even[SIZE];

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, n1 = 0, n2 = 0, mx = 0;
	///READ();
	///WRITE();
	cin >> n;
	for(I = 0; I < n; I++)
	{
		cin >> m;

		if(m & 1)
			odd[n1++] = m;
		else
			even[n2++] = m;
	}

	if(n1 == 0)
	{
		cout << 0 << NL;
		return 0;
	}

	sort(odd, odd + n1);
	sort(even, even + n2);

	for(I = 0; I < n2; I++)
		mx += even[I];

	if(!(n1 & 1))
		cnt++;

	for(I = cnt; I < n1; I++)
		mx += odd[I];

	cout << mx << NL;

	return 0;
}

