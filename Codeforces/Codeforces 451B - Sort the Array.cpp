// Codeforces 451B - Sort the Array.cpp
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
const int SIZE = 1e5 + 10;

vector<int> ar;

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, L = 0, R = 0, f = 0;
	///READ();
	///WRITE();
	cin >> n;
	for(I = 0; I < n; I++)
	{
		cin >> m;
		ar.push_back(m);
	}

	for(I = 0; I < n - 1; I++)
	{
		if(ar[I] > ar[I + 1])
		{
			if(f == 0)
			{
				L = I + 1;
				f = 1;
			}
			R = I + 2;

			if(ar[I + 1] < ar[I + 2])
				break;

		}
	}

	sort(ar.begin() + L - 1, ar.begin() + R);

	f = 0;
	for(I = 0; I < n - 1; I++)
	{
		if(ar[I] > ar[I + 1])
		{
			f = 1;
			break;
		}
	}

	if(f)
		cout << "no\n";
    else
	{
		if(L == 0 && R == 0)
			cout << "yes\n" << 1 << " " << 1 << NL;
		else
			cout << "yes\n" << L << " " << R << NL;
	}

	return 0;
}


