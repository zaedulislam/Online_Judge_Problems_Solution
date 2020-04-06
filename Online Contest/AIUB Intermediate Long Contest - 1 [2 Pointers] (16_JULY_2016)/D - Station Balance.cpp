// D - Station Balance.cpp
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
#define PC() printf("Set #%d\n", caseno++)
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

template <class T> inline T fABS(T a) { return a < 0 ? a * (-1) : a; }

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 50;

int ar[SIZE];

int main()
{
	//BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, C, left, right, sum = 0;
	double average, IMBALANCE;
	//READ();
	//WRITE();
	while (SF("%d %d", &C, &n) != EOF)
	{
		sum = 0;
		for (I = 0; I < n; I++)
		{
			SF("%d", &ar[I]);
			sum += ar[I];
		}

		for (I = n; I <= 2 * C; I++)
			ar[I] = 0;

		average = (sum * 1.0) / C;
		sort(ar, ar + 2 * C);

		PC();
		IMBALANCE = 0.00;
		left = 0, right = 2 * C - 1;
		for (I = 0; I < C; I++)
		{
			PF(" %d:", I);
			if (ar[left] != 0)
				PF(" %d", ar[left]);

			if (ar[right] != 0)
				PF(" %d", ar[right]);

			IMBALANCE += fABS(ar[left] * 1.0 + ar[right] * 1.0 - average);
			left++, right--;

			PF("\n");
		}
		PF("IMBALANCE = %0.5lf\n\n", IMBALANCE);
	}

	return 0;
}



