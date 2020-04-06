// C - How Lazy One can be Part 2.cpp
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

int ar[SIZE];

int main()
{
	///BOOST
	int tcases, caseno = 1, n, I, J, K, N, cnt = 0, len, S, currSum, windowLength, left;
	///READ();
	///WRITE();
	SF("%d", &tcases);
	while(tcases--)
	{
		SF("%d %d", &N, &S);

		for (I = 0; I < N; I++)
			SF("%d", &ar[I]);

		currSum = 0, windowLength = SIZE, left = 0;
		for (I = 0; I < N; I++)
		{
			currSum += ar[I];
			cnt++;
			while (currSum - ar[left] > S)
			{
				if (I - left < windowLength)
					windowLength = I - left;

				currSum -= ar[left];
				cnt--;
				left++;
			}
		}

		PC();

		if(windowLength != SIZE)
			PF("%d\n", windowLength);
		else
			PF("-1\n");
	}

	return 0;
}
