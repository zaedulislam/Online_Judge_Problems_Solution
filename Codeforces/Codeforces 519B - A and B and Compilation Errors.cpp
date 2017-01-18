// Codeforces 519B - A and B and Compilation Errors.cpp
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
const int SIZE = 1e5 + 10;

int a[SIZE], b[SIZE], c[SIZE];
map < int, int > A, B, C;

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, x;
	//READ();
	//WRITE();
	cin >> n;
	for(I = 0; I < n; I++)
	{
		cin >> a[I];
		A[a[I]]++;
	}

	for(I = 0; I < n - 1; I++)
	{
		cin >> b[I];
		B[b[I]]++;
	}

	for(I = 0; I < n; I++)
	{
		if(A[a[I]] != B[a[I]])
		{
			/*
			if(A[a[I]] != 0)
				A[a[I]]--;
			*/
			x = a[I];
			break;
		}
	}

	for(I = 0; I < n - 2; I++)
	{
		cin >> c[I];
		C[c[I]]++;
	}

	cout << x << NL;
	for(I = 0; I < n - 1; I++)
	{
		// A[b[I]] != C[b[I]] is also valid
		if(B[b[I]] != C[b[I]])
		{
			cout << b[I] << NL;
			break;
		}
	}

	return 0;
}

