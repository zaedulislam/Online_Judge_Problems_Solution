// UVa 11371 - Number Theory for Newbies.cpp
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
template < class T > inline T MAX(T &a, T &b) { return a > b ? a : b; }

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 10 + 10;

char s[SIZE];

int main()
{
	///BOOST
	LL tcases, I, J, K, N, m, n, cnt = 0, len, x, ans, a, b, q;
	///READ();
	WRITE();
	while(SF("%s", s) != EOF)
	{

		len = strlen(s);
		sort(s, s + len);

		if(s[0] == '0')
		{
			do
			{
				if(s[0] != '0')
				{
					x = strtoll(s, NULL, 10);
					break;
				}
			}while(next_permutation(s, s + len));
		}
		else
			x = strtoll(s, NULL, 10);

		sort(s, s + len, greater<char>());

		///cout << s << NL;

		ans = 0;
		do
		{
			if(s[0] == '0')
				continue;
			n = strtoll(s,NULL, 10);
			///cout << n << NL;
			if(n - x >= ans && (n - x) % 9 == 0)
			{
				a = n;
				b = x;
				ans = (n - x);
				q = (n - x) / 9;
				break;
			}
		}while(prev_permutation(s, s + len));

		PF("%lld - %lld = %lld = 9 * %lld\n", n, x, ans, q);
	}

	return 0;
}

