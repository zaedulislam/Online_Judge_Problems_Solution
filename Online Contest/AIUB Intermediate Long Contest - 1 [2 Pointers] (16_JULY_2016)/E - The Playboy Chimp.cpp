
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
const int SIZE = 50000 + 10;

int ar[SIZE], N, shorter, taller;

void upperLowerBound(int mid)
{
	int I;
	for(I = mid - 1; I >= 0; I--)
	{
		if(ar[I] != ar[mid])
		{
			shorter = ar[I];
			break;
		}
	}

	for(I = mid + 1; I < N; I++)
	{
		if(ar[I] != ar[mid])
		{
			taller = ar[I];
			break;
		}
	}
}

void binSearch(int h)
{
	int first = 0, last = N - 1, mid;
	while(first <= last)
	{
		mid = (first + last) / 2;
		if(ar[mid] == h)
		{
			upperLowerBound(mid);
			return;
		}
		else if(ar[mid] > h)
			last = mid - 1;
		else
			first = mid + 1;
	}

	/// if(first < N)
	taller = ar[first];
	if(last >= 0)
		shorter = ar[last];
}

int main()
{
	//BOOST
	int tcases, I, J, K, n, m, cnt = 0, len, h, Q;
	//READ();
	//WRITE();
	SF("%d", &N);
	for(I = 0; I < N; I++)
		SF("%d", &ar[I]);

	SF("%d", &Q);
	for(I = 0; I < Q; I++)
	{
		shorter = -1, taller = -1;

		SF("%d", &h);
		binSearch(h);

		if(shorter != -1 && shorter != 0)
			PF("%d ", shorter);
		else
			PF("X ");

		if(taller != -1 && taller != 0)
			PF("%d\n", taller);
		else
			PF("X\n");
	}

	return 0;
}

