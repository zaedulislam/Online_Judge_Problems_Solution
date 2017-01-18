// SPOJ FACT0 - Integer Factorization (15 digits).cpp
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
const int SIZE = 1e6;

map < LL, LL > MAP;

void PrimeFactorize(LL N)
{
	LL I, primePow;

	for(I = 2; I * I <= N; I++)
	{
		primePow = 0;
		if(N % I == 0)
		{
			while(N % I == 0)
			{
				N /= I;
				primePow++;
			}
			MAP[I] = primePow;
		}
	}

	if(N > 1)
		MAP[N] = 1;

	map < LL, LL > :: iterator it = MAP.begin();
	PF("%lld^%lld", it -> first, it-> second);
	it++;
	while(it != MAP.end())
	{
		PF(" %lld^%lld", it -> first, it-> second);
		it++;
	}
	PF("\n");
}

int main()
{
	///BOOST
	LL tcases, I, J, K, N, n, m, cnt = 0, len;
	///READ();
	///WRITE();
	while(SF("%lld", &N), (N || 0))
	{
		MAP.clear();

        PrimeFactorize(N);
	}
	return 0;
}

