// Codeforces 166A - Rank List.cpp
///************************************************************///
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
#include <ctime>
///************************************************************///
using namespace std;
int caseno = 1;
///************************************************************///
#define NL '\n'
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
#define SF scanf
#define PF printf
///************************************************************///
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define PC() printf("Case %d: ", caseno++)
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);
///************************************************************///
typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64
///************************************************************///
#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 50 + 10;
///************************************************************///

/*
*******4 Direction Array*******
int dx[] = {0, 0, - 1, 1}, dy[] = {-1, 1, 0, 0};

*******8 Direction Array*******
int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1};

********Knight Moves********
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};
*/

struct result
{
	int solved;
	int penalty;
};
result ar[SIZE];

bool Compare(const result &a, const result &b)
{
	if(a.solved > b.solved)
		return true;
	else if(a.solved == b.solved)
	{
		if(a.penalty < b.penalty)
			return true;
	}

	return false;
}

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, p, t, k;
	///READ();
	///WRITE();
	cin >> n >> k;

	for(I = 0; I < n; I++)
		cin >> ar[I].solved >> ar[I].penalty;

	sort(ar, ar + n, Compare);

	p = ar[k - 1].solved;
	t = ar[k - 1].penalty;

	for(I = 0; I < n; I++)
	{
		if(ar[I].solved == p && ar[I].penalty == t)
			cnt++;
	}

	cout << cnt << NL;

	return 0;
}


