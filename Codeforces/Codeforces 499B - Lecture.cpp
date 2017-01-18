// Codeforces 499B - Lecture.cpp
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

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e6;

string a, b, S;
map < string, string > MAP1, MAP2;
queue < string > qs;

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len;
	///READ();
	///WRITE();
	cin >> n >> m;

	for(I = 0; I < m; I++)
	{
		cin >> a >> b;
		MAP1[a] = b;
		MAP2[b] = a;
	}

	for(I = 0; I < n; I++)
	{
		cin >> S;
		a = MAP1[S];
		b = MAP2[a];

		if(a.length() == b.length())
			qs.push(b);
		else if(a.length() < b.length())
			qs.push(a);
		else
			qs.push(b);
	}

	while(!qs.empty())
	{
		cout << qs.front() << " ";
		qs.pop();
	}

	cout << NL;

	return 0;
}

