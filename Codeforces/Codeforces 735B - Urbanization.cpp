// Codeforces 735B - Urbanization.cpp
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
const double EPS = 1e-7;
const int SIZE = 1e5 + 10;
///************************************************************///

LL ar[SIZE];

int main()
{
	///BOOST
	LL tcases, I, J, K, N, n, m, cnt = 0, len, n1, n2, x1, x2, sum1, sum2, p1, p2;
	///READ();
	///WRITE();
	SF("%I64d%I64d%I64d", &n, &n1, &n2);

	for (I = 0; I < n; I++)
		SF("%I64d", &ar[I]);

	sort(ar, ar + n, greater<int>());

	x1 = min(n1, n2);
	x2 = max(n1, n2);

	p1 = x1;
	p2 = x2;

	sum1 = 0, sum2 = 0;
	I = 0;
	while (I < n && x1 > 0)
	{
		sum1 += ar[I];
		x1--;
		I ++;
	}
	///cout << "sum1 = " << sum1 << NL;
	///cout << "I = " << I << NL;

	J = I;
	while (J < n && x2 > 0)
	{
		sum2 += ar[J];
		x2--;
		J++;
	}
	///cout << "sum2 = " << sum2 << NL;
	///cout << "J = " << J << NL;

	double s1, s2;
	s1 = (double)sum1 / (double)p1;
	s2 = (double)sum2 / (double)p2;

	PF("%0.8lf\n", (s1 + s2));

	return 0;
}



