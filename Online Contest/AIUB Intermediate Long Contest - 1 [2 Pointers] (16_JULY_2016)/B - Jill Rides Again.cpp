// B - Jill Rides Again.cpp
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
#define pii pair < int, int >
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e6;

int ar[SIZE];
pii stops;

int main()
{
	//BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, currSum, finalSum, first = 0, last = 0, f1, f2, mx, dis;
	//READ();
	//WRITE();
	SF("%d", &tcases);
	while(tcases--)
	{
		SF("%d", &n);
		for(I = 2; I <= n; I++)
			SF("%d", &ar[I]);

		currSum = 0, finalSum = 0, first = 0, last = 0, f1 = 0, f2 = 0, mx = 0, dis = 0;
		for(I = 2; I <= n; I++)
		{
			if(f1 == 0)
			{
				first = I - 1;
				f1 = 1;
			}

			currSum += ar[I];

			if(currSum < 0)
			{
				currSum = 0;
				f1  = 0;
			}

			if(currSum >= finalSum)
			{
				finalSum = currSum;
				last = I;
			}

			if(finalSum > mx)
			{
				mx = finalSum;
				stops.first = first;
				stops.second = last;
			}
			else if(finalSum == mx)
			{
				if(last - first > dis)
				{
					dis = last - first;
					stops.first = first;
					stops.second = last;
				}
			}
		}

		if(finalSum <= 0)
			PF("Route %d has no nice parts\n", caseno++);
		else
			PF("The nicest part of route %d is between stops %d and %d\n", caseno++, stops.first, stops.second);
	}

	return 0;
}

/*
3
3
-1
6

10
4
-5
4
-3
4
4
-4
4
-5

4
-2
-3
-4
*/


