// UVa 10041 - Vito's Family.cpp
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
const int SIZE = 30000  + 10;

int ar[SIZE];

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, dis, r, x;
	///READ();
	///WRITE();
	cin >> tcases;
	while(tcases--)
	{
		cin >> r;
		for(I = 1; I <= r; I++)
			cin >> ar[I];

		sort(ar, ar + r + 1);

        if(r & 1)
			x = ar[r / 2 + 1];
		else
		{
			x = r / 2;
			x = ar[x + 1] + ar[x];
			x = x / 2;
		}

		dis = 0;
		for(I = 1; I <= r; I++)
				dis += abs(x - ar[I]);

		cout << dis << NL;
	}
	return 0;
}

