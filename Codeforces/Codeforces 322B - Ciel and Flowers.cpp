// Codeforces 322B - Ciel and Flowers.cpp
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

LL POW(LL base, LL power){
	LL I, res = base; if (power == 0) return 1;
	for (I = 0; I < power - 1; I++) res *= base; return res;
}

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 100;

int main()
{
	BOOST
	LL tcases, I, J, K, N, n, m, cnt = 0, len, r, g, b, R, G, B;
	///READ();
	///WRITE();
	cin >> r >> g >> b;

	R = r, G = g, B = b;

	cnt += r / 3;
	r = r % 3;

	cnt += g / 3;
	g = g % 3;

	cnt += b / 3;
	b = b % 3;

	cnt += min(min(r, g), b);

	if((r + g + b == 4) && ((r % 3 == 0) || (g % 3 == 0) || (b % 3 == 0)) && min(min(R, G), B) > 0)
		cnt++;

	cout << cnt << NL;

	return 0;
}

