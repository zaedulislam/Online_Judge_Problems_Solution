// C - Maximum Sum.cpp
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
const int SIZE = 110;

int M[SIZE][SIZE], ar[SIZE];

int main()
{
	//BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, L = 0, R = 0, currSum = 0, maxSum = 0,
	maxLeft = 0, maxRight = 0, maxUp = 0, maxDown = 0, row = 0;
	//READ();
	//WRITE();
	SF("%d", &N);
	for(I = 0; I < N; I++)
	{
		for(K = 0; K < N; K++)
			SF("%d", &M[I][K]);
	}

	for(I = 0; I < N; I++)
	{
		memset(ar, 0, sizeof(ar));
		L = I, R = I;
		while(R < N)
		{
			for(row = 0; row < N; row++)
				ar[row] += M[row][R];

			currSum = 0;
			for(J = 0; J < N; J++)
			{
				currSum += ar[J];

				if(currSum < 0)
					currSum = 0;

				if(currSum > maxSum)
					maxSum = currSum;
			}
			R++;
		}
	}

	PF("%d\n", maxSum);

	return 0;
}

