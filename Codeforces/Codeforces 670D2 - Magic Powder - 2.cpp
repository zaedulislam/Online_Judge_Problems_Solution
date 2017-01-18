// Codeforces 670D2 - Magic Powder - 2.cpp
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

int caseno = 1;
#define NL '\n'
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
#define SF scanf
#define PF printf
#define PC() printf("Case %d: ", caseno++)
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);
using namespace std;

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e5 + 10;

LL a[SIZE], b[SIZE];
LL n, k;

bool check(LL guess)
{
	LL I, xtra = k;
	for(I = 0; I < n; I++)
	{
		LL total = guess * a[I];
		if(total > b[I])
		{
			if(b[I] + xtra >= total)
				xtra = xtra - (total - b[I]);
			else
				return false;
		}
	}
	return true;
}

int main()
{
	//BOOST
	LL tcases, I, J, K, N, m, len, cnt = 0;
	//READ();
	//WRITE();
	SF("%I64d %I64d", &n, &k);

	for(I = 0; I < n; I++)
		SF("%I64d", &a[I]);

	for(I=  0; I < n; I++)
		SF("%I64d", &b[I]);

	LL first = 0, last = 10000000000, mid; // last = 1^10
	while(first <= last)
	{
		mid = (first + last) / 2;
		if(check(mid))
		{
			cnt = mid;
			first = mid + 1;
		}
		else
			last = mid - 1;
	}

	PF("%I64d\n", cnt);

	return 0;
}

