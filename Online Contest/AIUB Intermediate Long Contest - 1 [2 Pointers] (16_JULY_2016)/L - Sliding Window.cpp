// H - Sliding Window.cpp
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

#define INF 214748364721474836000
#define MOD 1000000007
#define pii pair < int, int >
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e6 + 10;

int ar[SIZE];
deque < int > qi;

void findMin(int N, int K)
{
	while(!qi.empty())
		qi.pop_front();

	int I;
	for(I = 0; I < K; I++)
	{
		while(!qi.empty() && ar[I] <= ar[qi.front()])
			qi.pop_front();

		qi.push_back(I);
	}

	for(I = K; I < N; I++)
	{
		PF("%d ", ar[qi.front()]);

		while(!qi.empty() && qi.front() <= I - K)
			qi.pop_front();

		while(!qi.empty() && ar[I] <= ar[qi.front()])
			qi.pop_front();

		qi.push_back(I);
	}

	PF("%d\n", ar[qi.front()]);
}


void findMax(int N, int K)
{
	while(!qi.empty())
		qi.pop_front();

	int I;
	for (I = 0; I < K; I++)
	{
		while (!qi.empty() && ar[I] >= ar[qi.front()])
			qi.pop_front();

		qi.push_back(I);
	}

	for(I = K; I < N; I++)
	{
		PF("%d ", ar[qi.front()]);

		while(!qi.empty() && qi.front() <= I - K)
			qi.pop_front();

		while(!qi.empty() && ar[I] >= ar[qi.front()])
			qi.pop_front();

		qi.push_back(I);
	}

	PF("%d\n", ar[qi.front()]);
}


int main()
{
	///BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len;
	///READ();
	///WRITE();

	while (SF("%d %d", &N, &K) != EOF)
	{
		for (I = 0; I < N; I++)
			SF("%d", &ar[I]);

		findMin(N, K);
		findMax(N, K);
	}

	return 0;
}

