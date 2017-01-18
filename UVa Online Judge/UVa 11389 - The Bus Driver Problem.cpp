// UVa 11389 - The Bus Driver Problem.cpp
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

int toInt(string s){ int r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:toInt(

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 100 + 10;

int ar[SIZE], mor[SIZE], after[SIZE];

int main()
{
	///BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, ans, d, r;
	///READ();
	///WRITE();
	while(SF("%d %d %d", &n, &d, &r), (n || d || r))
	{
		for(I = 0; I < n; I++)
			SF("%d", &mor[I]);

		for(I = 0; I < n; I++)
			SF("%d", &after[I]);

		sort(mor, mor + n);
		sort(after, after + n);

		K = n - 1, ans = 0;
		for(I = 0; I < n; I++)
		{
			if(mor[I] + after[K] > d)
				ans += (mor[I] + after[K] - d) * r;
			K--;
		}

		PF("%d\n", ans);
	}

	return 0;
}

