// B - Credit Shop.cpp
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

#include <bitset>
#include <algorithm>
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
#define sf scanf
#define pf printf
#define PC() printf("Case %d: ", caseno++)
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);
using namespace std;

// BEGINTEMPLATE_BY_ZAYED
typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 2000 + 10;

int ar[SIZE];

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 1, len, C, f;
	//READ();
	//WRITE();
	cin >> tcases;
	while(tcases--)
	{
		cin >> C >> n;
		for(I = 1; I <= n; I++)
			cin >> ar[I];

		f = 0;
		for(I = 1; I <= n; I++)
		{
			for(J = 1; J <= n; J++)
			{
				for(K = 1; K <= n; K++)
				{
					if(ar[I] + ar[J] + ar[K] == C)
					{
						f = 1;
						break;
					}
				}
			}
		}

		cout << "Case " << cnt++ << ": ";
		if(f == 1)
			cout << I << " " << J  << " " << K;
		else
			cout << "You are out of your luck!\n";
	}

	return 0;
}

