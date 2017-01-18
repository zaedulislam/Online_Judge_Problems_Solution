// Codeforces 688A - Opponents.cpp
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

template <class T> inline T MAX(T a, T b){ return (a > b) ? a : b; }

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e6;

string S;

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, f = 0, mx = 0, d;
	//READ();
	//WRITE();
	cin >> n >> d;

	for(I = 0; I < d; I++)
	{
		cin >> S;
		for(K = 0; K < n; K++)
		{
			if(S[K] == '0')
			{
				f = 1;
				cnt++;
				break;
			}
		}

		if(K == n)
			cnt = 0;

		else if(f == 1)
		{
			mx = MAX(mx, cnt);
			f = 0;
		}
	}
	cout << mx << NL;

	return 0;
}

