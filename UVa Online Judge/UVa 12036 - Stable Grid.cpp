// UVa 12036 - Stable Grid.cpp
/// Use Pigeon Hole Principle
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

int ar[SIZE];

int main()
{
	///BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, mx;
	///READ();
	///WRITE();
	SF("%d", &tcases);
	while(tcases--)
	{
		memset(ar, 0, sizeof(ar));

		SF("%d", &n);

		mx = 0;
		for(I = 0; I < n; I++)
		{
			for(K = 0; K < n; K++)
			{
				SF("%d", &m);
				ar[m]++;

				if(m > mx)
					mx = m;
			}
		}

		PC();
		for(I = 0; I <= mx; I++)
		{
			if(ar[I] > n)
			{
				PF("no\n");
				break;
			}
		}

		if(I > mx)
			PF("yes\n");
	}

	return 0;
}

