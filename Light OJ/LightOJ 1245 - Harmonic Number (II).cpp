// LightOJ 1245 - Harmonic Number (II).cpp
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
const int SIZE = 1e6;

int main()
{
	///BOOST
	LL tcases, I, J, K, N, n, m, cnt = 0, len, a, b, last, sum, sqrtN;
	///READ();
	///WRITE();
	SF("%lld", &tcases);
	while(tcases--)
	{
		SF("%lld", &n);

		last = n;
		sum = 0;
		for(I = 1; I <= n; I++)
		{
			if(I != 1)
			{
				a = I;
				b = n / a;

				if(a >= last)
					break;

				sum += (n / a);

				if(b > a)
					sum += (n / b);

				if(b + 1 > a)
					sum += ((last - (b + 1)) * (a - 1));

				last = b;
			}
			else
			{
				if(n == 1)
					sum = 1;
				else
					sum += (n / 1 + n / n);
			}
		}

		PC();
		PF("%lld\n", sum);
	}
	return 0;
}

