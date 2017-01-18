// UVaLive 4340 I - Find Terrorists.cpp
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
int ar[SIZE];
map < int, int > MAP;
vector < int > vi;

void Sieve1()
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

	MAP[2] = 1;
	for(I = 3; I <= SIZE; I += 2)
	{
		if(status[I] == 0)
			MAP[I] = 1;
	}
}

void Sieve2()
{
	int I, K;
	for(I = 2; I <= SIZE; I ++)
	{
		for(K = 2 * I; K <= SIZE; K += I)
			ar[K]++;
	}

	for(I = 2; I <= SIZE; I++)
	{
		if(MAP[I] == 0)
			ar[I] += 2;
	}
}

int main()
{
	///BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, L, H;
	///READ();
	///WRITE();
	Sieve1();
	Sieve2();

	SF("%d", &tcases);
	while(tcases--)
	{
		vi.clear();
		SF("%d%d", &L, &H);

		cnt = 0;
		for(I = L; I <= H; I++)
		{
			if(MAP[I] == 1)
			{
				cnt++;
				vi.push_back(I);
			}

			else if(MAP[ar[I]] == 1)
			{
				vi.push_back(I);
				cnt++;
			}
		}

		if(cnt == 0)
		{
			PF("-1\n");
			continue;
		}

		int sz = vi.size() - 1;
		PF("%d", vi[0]);
		for(I = 1; I <= sz; I++)
			PF(" %d", vi[I]);

		PF("\n");
	}
	return 0;
}

