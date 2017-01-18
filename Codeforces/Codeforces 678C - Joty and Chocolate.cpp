// Codeforces 678C - Joty and Chocolate.cpp
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

#include <bitset>
#include <algorithm>
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
#define sf scanf
#define pf printf
#define PC() printf("Case %d: ", caseno++)
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64
template<class T> inline T MAX(T a, T b){ return (a > b) ? a : b; }

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e6;

int main()
{
	BOOST
	LL tcases, I, J, K, N, n, m, cnt = 0, len, k, a, b, p, q, red, blue, both, LCM, mx;
	//READ();
	//WRITE();
	cin >> n >> a >> b >> p >> q;
	red = n / a;
	blue = n / b;
	LCM = (a / __gcd(a, b)) * b;
	both = n / LCM;
	mx = MAX(((red - both) * p + blue * q), (red * p + (blue - both) * q));
	cout << mx << NL;

	return 0;
}
