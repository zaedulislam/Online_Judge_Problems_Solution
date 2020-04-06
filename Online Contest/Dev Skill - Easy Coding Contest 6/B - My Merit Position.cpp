// B - My Merit Position.cpp
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
#define PAIR pair < string, double >
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 100;

double ar[SIZE], C;
string S;
map < PAIR, int > MAP;

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, f;
	double C;
	///READ();
	///WRITE();
	cin >> N;
	for (I = 0; I < N; I++)
	{
		cin >> S >> C;
		MAP[PAIR(S, C)]++;
		ar[I] = C;
	}

	sort(ar, ar + N, greater < double >());

	cnt = 1;
	for (I = 0; I < N; I++)
	{
		f = 0;
		map < PAIR, int > ::iterator it = MAP.begin();
		while (it != MAP.end())
		{
			///cout << it -> second << NL;
			if ((it-> first.second) == ar[I])
			{
				len = it->second;

				if (len > 0)
					f = 1;
				///cout << f << NL;
				while (len > 0)
				{
					cout << cnt << ".";
					cout << it->first.first << NL;
					len--;
				}
				it-> second = -1;
				///break;
			}
			it++;
		}

		///cout << "F = " << f << NL;
		if(f)
			cnt++;
		///cout << "cnt = " << cnt << NL;
	}

	return 0;
}

/*
3
A 2
B 2
A 1

1.A
1.B
2.A
*/

