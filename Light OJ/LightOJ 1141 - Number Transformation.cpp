// LightOJ 1141 - Number Transformation.cpp
/*
Tricky Cases:
1. 's' can be greater than 't'.
2. If 's' is equal to 't', then the ans is '0'.
*/
///************************************************************///
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
///************************************************************///
using namespace std;
int caseno = 1;
///************************************************************///
#define NL '\n'
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
#define SF scanf
#define PF printf
///************************************************************///
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define PC() printf("Case %d: ", caseno++)
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);
///************************************************************///
typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

template <class T> inline void SWAP(T &a, T &b) { T t = a; a = b; b = t; }
///************************************************************///
#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1000 + 10;
///************************************************************///

/*
*******4 Direction Array*******
int dx[] = {0, 0, - 1, 1}, dy[] = {-1, 1, 0, 0};

*******8 Direction Array*******
int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1};

********Knight Moves********
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};
*/

bool status[40];
int dis[SIZE], primeSZ;
queue<int>qi;
vector<int> prime, primeFactor[SIZE];

void Sieve()
{
	int I, K, sqrtN = int(sqrt((double)SIZE));

	for (I = 3; I <= sqrtN; I += 2)
	{
		if (status[I] == 0)
		{
			for (K = I * I; K <= SIZE; K += 2 * I)
				status[K] = 1;
		}
	}

	prime.push_back(2);
	for (I = 3; I <= sqrtN; I += 2)
	{
		if (status[I] == 0)
			prime.push_back(I);
	}

	primeSZ = prime.size();
}

void PrimeFactorize(int N)
{
	int I, K = 0, M = N, sqrtN = int(sqrt((double)N));

	for (I = 0; I < primeSZ && prime[I] <= sqrtN; I++)
	{
		if (N % prime[I] == 0)
		{
			primeFactor[M].push_back(prime[I]);

			while (N % prime[I] == 0)
				N /= prime[I];

			sqrtN = int(sqrt((double)N));
		}
	}

	if (N > 1 && N != M)
		primeFactor[M].push_back(N);
}

int BFS(int src, int target)
{
	if(src == target)
		return 0;

	while (!qi.empty())
		qi.pop();

	dis[src] = 0;
	qi.push(src);

	int I, u, v, n;
	while (!qi.empty())
	{
		u = qi.front();
		qi.pop();

		for (I = 0; I < primeFactor[u].size(); I++)
		{
			v = u + primeFactor[u][I];

			if (dis[v] == 0 && v <= target)
			{
				dis[v] = dis[u] + 1;

				if(v == target)
					return dis[v];

				qi.push(v);
			}
		}
	}
	return -1;
}


int main()
{
	///BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, s, t;
	///READ();
	///WRITE();
	Sieve();

	for(I = 1; I < SIZE; I++)
		PrimeFactorize(I);

	SF("%d", &tcases);
	while (tcases--)
	{
		memset(dis, 0, sizeof(dis));

		SF("%d%d", &s, &t);

		if(s > t)
			SWAP(s, t);

		int ans = BFS(s, t);

		PC();

		if (ans == -1)
			PF("-1\n");
		else
			PF("%d\n", ans);
	}
	return 0;
}


