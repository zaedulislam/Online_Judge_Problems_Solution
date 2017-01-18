// SPOJ FACTCG2 - Medium Factorization.cpp
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
const int SIZE = 3200;

bool status[SIZE];
int prime[SIZE], factor[SIZE], primeSZ;

void Sieve()
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
	for(I  = 3; I <= SIZE; I += 2)
	{
		if(status[I] == 0)
			prime[K++] = I;
	}

	primeSZ = K;
}

void PrimeFactorize(int N)
{
	int I, K, factorSZ = 0, sqrtN = int(sqrt((double)N));
	for(I = 0; I < primeSZ && prime[I] <= sqrtN; I++)
	{
		if(N % prime[I] == 0)
		{
			while(N % prime[I] == 0)
			{
				N /= prime[I];
				factor[factorSZ++] = prime[I];
			}
			sqrtN = int(sqrt((double)N));
		}
	}

	if(N > 1)
		factor[factorSZ++] = N;

	PF("1");
	for(I = 0; I < factorSZ; I++)
		PF(" x %d", factor[I]);

	PF("\n");
}

int main()
{
	///BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len;
	///READ();
	///WRITE();
	Sieve();

	while(SF("%d", &N) != EOF)
	{
		PrimeFactorize(N);
	}

	return 0;
}

