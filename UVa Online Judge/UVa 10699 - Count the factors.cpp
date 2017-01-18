// UVa 10699 - Count the factors.cpp
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
using namespace std;

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE =  1000000 + 10;

bool status[SIZE];
int prime[SIZE], primeSZ;

void sieve()
{
	int I, K, sqrtN = int(sqrt((double)SIZE));
	status[0] = 1, status[1] = 1;
	for(I = 3; I <= sqrtN; I += 2)
	{
		if(status[I] == 0)
		{
			for(K = I * I; K <= SIZE; K += 2 * I)
				status[K]  = 1;
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

void factorize(int n)
{
	int I, K, cnt = 0, N = n, sqrtN = int(sqrt((double)n));
	for(I = 0; I < primeSZ && prime[I] <= sqrtN; I++)
	{
		if(n % prime[I] == 0)
		{
			cnt++;
			while(n % prime[I] == 0)
				n /= prime[I];
		}
	}
	if(n > 1)
		cnt++;

	PF("%d : %d\n", N, cnt);
}

int main()
{
	//BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len;
	//READ();
	//WRITE();
	sieve();

	while(1)
	{
		SF("%d", &n);
		if(n == 0)
			break;
		factorize(n);
	}

	return 0;
}