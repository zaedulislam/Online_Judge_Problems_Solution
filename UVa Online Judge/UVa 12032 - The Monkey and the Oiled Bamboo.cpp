// UVa 12032 - The Monkey and the Oiled Bamboo.cpp
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
const int SIZE = 1e5 + 10;

int ar[SIZE], n;

bool check(int st)
{
	int I, jump;
	for(I = 1; I <= n; I++)
	{
		jump = ar[I] - ar[I - 1];
		if(jump > st)
			return false;
		if(jump == st)
			st--;
	}
	return true;
}

int binSearch()
{
	int first = 1, last = INF, mid, ans;
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

	return ans;
}

int main()
{
	//BOOST
	int tcases, I, J, K, N, m, cnt = 0, len, ans;
	//READ();
	//WRITE();
	SF("%d", &tcases);
	while(tcases--)
	{
		SF("%d", &n);
		for(I = 1; I <= n; I++)
			SF("%d", &ar[I]);

		ans = binSearch();

		PC();
		PF("%d\n", ans);
		///PF("%d\n", check(6));
	}

	return 0;
}

