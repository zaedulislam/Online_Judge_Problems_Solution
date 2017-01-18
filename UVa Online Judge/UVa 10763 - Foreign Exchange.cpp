// UVa 10763 - Foreign Exchange.cpp
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
#define pii pair < int, int >
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 500000 + 10;

map < pii, int > MAP;

int main()
{
	///BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, a, b, f;
	///READ();
	///WRITE();
	while (SF("%d", &n), (n || 0))
	{

		MAP.clear();

		for (I = 0; I < n; I++)
		{
			SF("%d %d", &a, &b);
			MAP[pii(a, b)]++;
		}

		pii ab;
		f = 0;
		map < pii, int > ::iterator it = MAP.begin();
		while (it != MAP.end())
		{
			ab = it->first;

			a = ab.first;
			b = ab.second;

			if (MAP[pii(a, b)] != MAP[pii(b, a)] )
			{
				PF("NO\n");
				f = 1;
				break;
			}

			it++;
		}

		if (f == 0)
			PF("YES\n");
	}

	return 0;
}

