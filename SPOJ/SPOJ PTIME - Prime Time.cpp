// SPOJ PTIME - Prime Time.cpp
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
const int SIZE = 10000 + 10;

bool status[SIZE];
int prime[SIZE], primeSZ;
map < int, int > MAP;

void sieve()
{
	int I, K, sqrtN = int(sqrt((double)SIZE));
	for(I = 3; I <= sqrtN; I += 2)
	{
		if(status[I] == 0)
		{
			for(K = I * I; K <= SIZE; K += 2 * I)
				status[K] = 1;
		}
	}

	K = 0;
	prime[K++] = 2;
	for(I = 3; I <= SIZE; I += 2)
	{
		if(status[I] == 0)
			prime[K++] = I;
	}

	primeSZ = K;
}

void factorialFactors(int N)
{
	int I, K, cnt = 0, p, primePow, sqrtN = int(sqrt((double)N));

	for(I = 0; I < primeSZ && prime[I] <= N; I++)
	{
		p = prime[I], primePow = 2, cnt = 0;
		while(N / p >= 1)
		{
			cnt += N / p;

			p = pow(prime[I], primePow++);
		}
		MAP[prime[I]] = cnt;
	}

	map < int, int > :: iterator it = MAP.begin();

	cout << it -> first << "^" << it -> second;
	it++;
	while(it != MAP.end())
	{
		cout << " * ";
		cout << it -> first << "^" << it -> second;
		it++;
	}
	cout << NL;
}

int main()
{
	///BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len;
	///READ();
	///WRITE();
	sieve();

	while(SF("%d", &N) != EOF)
	{
		factorialFactors(N);
	}

	return 0;
}
