// DCP 18 - Number Sort.cpp
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

double toDouble(string s){ double r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:toDouble(
///************************************************************///
#define INF 2147483647
#define MOD 1000000007
#define p pair<double,string>
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e6 + 10;
///************************************************************///

string S;

struct Num
{
	double d;
	string S;
	int Id;
};
Num ar[SIZE];

bool Compare(const Num &a, const Num &b)
{
	if(a.d < b.d)
		return true;
	if(a.d == b.d)
	{
		if(a.Id < b.Id)
			return true;
		else
			return false;
	}

	return false;
}

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len;
	///READ();
	///WRITE();
	cin >> tcases;
	while(tcases--)
	{

		cin >> N;

		for(I = 1; I <= N; I++)
		{
			cin >> S;
			double x = toDouble(S);

			ar[I].d = x;
			ar[I].S = S;
			ar[I].Id = I;
			///cout << x << NL;
		}

		sort(ar + 1, ar + N + 1, Compare);

		cout << ar[1].S;
		for(I = 2; I <= N; I++)
			cout << "," << ar[I].S;

		cout << NL;
	}

	return 0;
}


