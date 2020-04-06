// K - Sereja and Dima.cpp
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
const int SIZE = 1000 + 10;

int ar[SIZE];

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, p1 = 0, p2 = 0;
	//READ();
	//WRITE();
	cin >> n;
	for(I = 0; I < n; I++)
		cin >> ar[I];

	I = 0, J = n - 1;
	while(1)
	{
		if(I == J)
		{
			p1 += ar[I];
			break;
		}

		if(ar[I] > ar[J])
		{
			p1 += ar[I];
			I++;
		}
		else
		{
			p1 += ar[J];
			J--;
		}

		if(ar[I] > ar[J])
		{
			p2 += ar[I];
			I++;
		}
		else
		{
			p2 += ar[J];
			J--;
		}

		if(I > J)
			break;
	}

	cout << p1 << " " << p2 << NL;

	return 0;
}

