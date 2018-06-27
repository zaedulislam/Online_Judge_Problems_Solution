// HackerEarth - Staircase.cpp
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

int N;

int jack(int taken)
{
	if(taken > N)
		return 0;
	if(taken == N)
		return 1;

	int ret1 = 0, ret2 = 0, ret3 = 0;
	ret1 = jack(taken + 1);
	ret2 = jack(taken + 2);
	ret3 = jack(taken + 3);

	return ret1 + ret2 + ret3;
}

int jill(int taken)
{
	if(taken > N)
		return 0;

	if(taken == N)
		return 1;

	int ret1 = 0, ret2 = 0;
	ret1 = jill(taken + 1);
	ret2 = jill(taken + 2);

	return ret1 + ret2;
}

int main()
{
	///BOOST
	int tcases, I, J, K, n, m, cnt = 0, len;
	///READ();
	///WRITE();
	SF("%d", &N);

	if(N < 0)
	{
		PF("ERROR\n");
		return 0;
	}

	PF("Jack-%d\n", jack(0));
	PF("Jill-%d\n", jill(0));

	return 0;
}

