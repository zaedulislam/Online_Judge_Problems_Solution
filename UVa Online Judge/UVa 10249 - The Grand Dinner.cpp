// UVa 10249 - The Grand Dinner.cpp
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
#define pii pair < int, int >
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e6;

int team[70 + 10];
pii table[50 + 10];
queue < int > qi;
set < int > si;

int main()
{
	///BOOST
	int tcases, I, J, K, N, M, n, m, cnt = 0, len, f, temp;
	///READ();
	///WRITE();
	while (SF("%d%d", &M, &N), (M || N))
	{
		while (!qi.empty())
			qi.pop();

		for (I = 0; I < M; I++)
			SF("%d", &team[I]);

		for (I = 0; I < N; I++)
		{
			SF("%d", &table[I].first);
			table[I].second = I + 1;
		}

		sort(table, table + N);

		f = 0;
		for (I = 0; I < M; I++)
		{
			si.clear();
			temp = team[I];
			for (K = N - 1; K >= 0; K--)
			{
				if (temp > 0)
				{
					if (table[K].first > 0)
					{
						table[K].first--;
						temp--;
						si.insert(table[K].second);
					}
				}
			}

			set < int > :: iterator it = si.begin();
			while(it != si.end())
			{
				qi.push(*it);
				it++;
			}

			if (temp > 0)
				f = 1;
		}

		if (f == 1)
			PF("0\n");
		else
		{
			f = 0;
			PF("1\n");
			for (I = 0; I < M; I++)
			{
				temp = team[I];
				PF("%d", qi.front());
				qi.pop();

				for (K = temp - 1; K > 0; K--)
				{
					PF(" %d", qi.front());
					qi.pop();
				}

				PF("\n");
			}
		}
	}

	return 0;
}


