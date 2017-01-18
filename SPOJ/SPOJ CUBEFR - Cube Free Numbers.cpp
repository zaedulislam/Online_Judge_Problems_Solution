// SPOJ CUBEFR - Cube Free Numbers.cpp
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
const int SIZE = 1e6 + 10;

int status[SIZE];

void sieve()
{
	int I, J, Icube, pos;
	for(I  = 2; (I * I * I) < SIZE; I++)
	{
		Icube = I * I * I;
		for(J = Icube; J < SIZE; J += Icube)
			status[J] = -1;
	}

	pos = 1;
	for(I = 1; I < SIZE; I++)
	{
		if(status[I] == 0)
			status[I] = pos++;
	}
}

int main()
{
	///BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len;
	///READ();
	///WRITE();
	sieve();

	SF("%d", &tcases);
	while(tcases--)
	{
		SF("%d", &n);

		PC();
		if(status[n] == -1)
			PF("Not Cube Free\n");
		else
			PF("%d\n", status[n]);
	}
	return 0;
}

