// DIVSUM - Divisor Summation.cpp
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

int POW(int base, int power){
	int I, res = base; if (power == 0) return 1;
	for (I = 0; I < power - 1; I++) res *= base; return res;
}

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 710+ 10;

bool status[SIZE];
int prime[SIZE], primeSZ;

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
	for(I = 3; I <= SIZE; I += 2)
	{
		if(status[I] == 0)
			prime[K++] = I;
	}

	primeSZ = K;
}

void FindDivSum(int N)
{
	int I, K, T = N, SOD = 1, P, sqrtN = int(sqrt((double)N));
	for(I = 0; I < primeSZ && prime[I] <= sqrtN; I++)
	{
		if(N % prime[I] == 0)
		{
			P = 0;
			while(N % prime[I] == 0)
			{
				N /= prime[I];
				P++;
			}
			///cout << "N = " << N << " P = " << P << " PRIME = " << prime[I] << NL;
			SOD *= (POW(prime[I], P + 1) - 1);
			SOD /= (prime[I] - 1);
			sqrtN = int(sqrt((double)N));
		} 
	}
	///cout << "N = " << N << NL;
	if(N > 1)
	{
		SOD *= (POW(N, 2) - 1);
		SOD /= (N - 1);
	}

	PF("%d\n", SOD - T);
}

int main()
{
	///BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len;
	///READ();
	///WRITE();
	Sieve();

	SF("%d", &tcases);
	while(tcases--)
	{
		SF("%d", &N);

		FindDivSum(N);
	}
	return 0;
}

