// Codeforces 699A - Launch of Collider.cpp
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

template <class T> inline T MIN(T a, T b){ return (a < b) ? a : b; }

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 200000 + 10;

string S;
int ar[SIZE];

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, ans = INF ,x , r, L, f1 = 0, f2 = 0;
	//READ();
	//WRITE();
	cin >> n;
	cin >> S;

    for(I = 0; I < n; I++)
		cin >> ar[I];

	for(I = 0; I < n;I++)
	{
		if(S[I] == 'R')
		{
			r = I;
			f1 = 1;
		}
		else if(f1 == 1 && S[I] == 'L')
		{
			L = I;
			f2 = 1;
			x = (ar[L] - ar[r]) / 2;
			///cout << "x = " << x << NL;
			ans = MIN(ans, x);
		}
	}

	if(f1 && f2)
		cout << ans << NL;
	else
		cout << -1 << NL;

	return 0;
}

/*
4
RLRL
2 10 12 16
*/
