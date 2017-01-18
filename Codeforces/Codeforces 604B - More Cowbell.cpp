// Codeforces 604B - More Cowbell.cpp
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

int ar[SIZE], n, k;

bool check(int guess)
{
	int I = 0, J = n - 1, box = 0;
	while(I <= J)
	{
		if(I != J && ar[I] + ar[J] <= guess)
		{
			box++;
			I++;
			J--;
		}
		else if(ar[J] <= guess)
		{
			box++;
			J--;
		}
		else if(ar[I] <= guess)
		{
			box++;
			I++;
		}
		else
			return 0;

	}
	if(I > J && box <= k)
		return 1;
	else
		return 0;
}


int main()
{
	BOOST
	int tcases, I, J, K, N, m, len, ans;
	//READ();
	//WRITE();
	cin >> n >> k;
	for(I = 0; I < n; I++)
		cin >> ar[I];

	int first = 0, last = INF, mid;
	while(first <= last)
	{
		mid = (first + last) / 2;
		if(check(mid))
		{
			ans = mid;
			last = mid - 1;
		}
		else
			first = mid + 1;
	}
	cout << ans << NL;

	return 0;
}

