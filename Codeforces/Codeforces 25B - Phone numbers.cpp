
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

string no;

int main()
{
	BOOST
	int tcases, I, J, K, N, m, cnt = 0, len, tmpLen;
	///READ();
	///WRITE();
	cin >> len >> no;

	if (!(len & 1))
	{
		for (I = 0; I < len; I++)
		{
			cout << no[I];

			if ((I & 1) && (I < len - 1))
				cout << "-";
		}
	}
	else
	{
		if (len % 3 == 0)
		{
			for (I = 0; I < len; I++)
			{
				cout << no[I];

				if ((I + 1) % 3 == 0 && (I < len - 1))
					cout << "-";
			}
		}
		else
		{
			tmpLen = len;

			I = 0;
			while (I < len)
			{
				if (tmpLen - 3 > 1)
				{
					K = 0;
					while (K < 3)
					{
						cout << no[I];
						I++;
						K++;
					}

					if (I < len - 1)
						cout << "-";

					tmpLen = tmpLen - 3;
				}
				else
				{
					K = 0;
					while (K < 2)
					{
						cout << no[I];
						I++;
						K++;
					}

					if (I < len - 1)
						cout << "-";

					tmpLen = tmpLen - 2;
				}
			}
		}
	}

	cout << NL;

	return 0;
}

