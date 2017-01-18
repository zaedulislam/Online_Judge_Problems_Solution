// Codeforces 714B - Filya and Homework.cpp
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
const int SIZE = 1e5 + 10;

int ar[SIZE], temp[5];
set < int > si;

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, sum;
	///READ();
	///WRITE();
	cin >> n;
	for(I = 0; I < n; I++)
	{
		cin >> m;
		si.insert(m);
	}

	if(si.size() == 1)
	{
		cout << "YES\n";
		return 0;
	}
	if(si.size() > 3)
		cout << "NO\n";
	else
	{
		I = 0;
		set < int > :: iterator it = si.begin();
		while(it != si.end())
		{
			temp[I++] = *it;
			it++;
		}

		if(si.size() == 2)
		{
			sum = temp[0] + temp[1];
			if(temp[0] == sum - temp[1])
			{
				cout << "YES\n";
				return 0;
			}
			else
			{
				cout << "NO\n";
				return 0;
			}
		}

		if((temp[1] - temp[0]) != (temp[2] - temp[1]))
		{
				cout << "NO\n";
				return 0;
		}
		cout << "YES\n";
	}
	return 0;
}

