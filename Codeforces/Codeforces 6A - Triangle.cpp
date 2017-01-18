// Codeforces 6A - Triangle.cpp
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

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, a, b, c, d, f1;
	///READ();
	///WRITE();
	cin >> a >> b >> c >> d;

	f1 = 0;
	if((a + b > c) && (b + c > a) && (a + c > b))
		f1 = 1;
	else if((a + b > d) && (b + d > a) && (a + d > b))
		f1 = 1;
	else  if((a + c > d) && (c + d > a) && (a + d > c))
		f1 = 1;
	else if((b + c > d) && (b + d > c) && (c + d > b))
		f1 = 1;

	if(f1 == 1)
	{
		cout << "TRIANGLE\n";
		return 0;
	}

	/*
	Another Approach
	if((a + b == c) || (b + c  == a) || (a + c == b))
		f1 = 1;
	else if((a + b == d) || (b + d == a) || (a + d == b))
		f1 = 1;
	else  if((a + c == d) || (c + d == a) || (a + d == c))
		f1 = 1;
	else if((b + c == d) || (b + d == c) || (c + d == b))
		f1 = 1;

	if(f1 == 1)
	{
		cout << "SEGMENT\n";
		return 0;
	}
	*/

	double s, A;

	s = (a + b + c) / 2;
	A = s * (s - a) * (s - b) * (s - c);
	A = (int)sqrt(A);
	if((int)A == 0)
	{
		cout << "SEGMENT\n";
		return 0;
	}

	s = (a + b + d) / 2;
	A = s * (s - a) * (s - b) * (s - d);
	A = sqrt((double)A);
	if((int)A == 0)
	{
		cout << "SEGMENT\n";
		return 0;
	}

	s = (a + c + d) / 2;
	A = s * (s - a) * (s - c) * (s - d);
	A = (int)sqrt(A);
	if((int)A == 0)
	{
		cout << "SEGMENT\n";
		return 0;
	}

	s = (b + c + d) / 2;
	A = s * (s - b) * (s - c) * (s - d);
	A = (int)sqrt(A);
	if((int)A == 0)
	{
		cout << "SEGMENT\n";
		return 0;
	}

	cout << "IMPOSSIBLE\n";

	return 0;
}
