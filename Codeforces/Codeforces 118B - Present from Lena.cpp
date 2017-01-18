// Codeforces 118B - Present from Lena
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
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, dig, temp, limit, mid, start, check;
	///READ();
	///WRITE();
	cin >> n;

	limit = (2 * n) + 1, mid = n + 1;

	/*UPPER HALF*/
	temp = n, check = 1;
	for(I = 1; I <= n ; I++)
	{
		dig = 0, start = limit - temp, cnt = 0;
		///cout << "START = " << start << " COUNT = " << cnt << " CHECK = " << check << NL;
		for(K = 1; K <= limit; K++)
		{
			if(K >= start && cnt < check)
			{
				cout << dig;

				if(K >= mid)
					dig--;
				else
					dig++;

				cnt++;

				if(cnt != check)
					cout << " ";
			}
			else if(K < start)
				cout << "  ";
		}
		temp++;
		check += 2;
		cout << NL;
	}
	/*UPPER HALF*/

	/*MID LINE*/
	dig = 0;
	for(I = 1; I <= limit; I++)
	{
		if(I < (limit - n))
		{
			cout << dig << " ";
			dig++;
		}
		else if(I == (limit - n))
			cout << dig << " ";
		else
		{
			dig--;
			cout << dig;
			if(I < limit)
				cout << " ";
		}
	}
	cout << NL;
	/*MID LINE*/

	/*LOWER HALF*/
	temp = n, check = check - 2;
	for(I = 1; I <= n ; I++)
	{
		dig = 0, cnt = 0;
		///cout << "START = " << start << " COUNT = " << cnt << " CHECK = " << check << NL;
		for(K = 1; K <= limit; K++)
		{
			if(K >= start && cnt < check)
			{
				cout << dig;

				if(K >= mid)
					dig--;
				else
					dig++;

				cnt++;

				if(cnt != check)
					cout << " ";
			}
			else if(K < start)
				cout << "  ";
		}
		start++;
		temp++;
		check -= 2;
		cout << NL;
	}
	/*LOWER HALF*/

	return 0;
}
