// UVa 10670 - Work Reduction.cpp
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
const int SIZE = 100 + 10;

string S, X;
int rate[5];

struct table
{
	string name;
	int cost;
};

struct agency
{
	string name;
	int rate1;
	int rate2;
};

agency ar[SIZE];
table ans[SIZE];

void ToInt(string S)
{
		stringstream convert(S);
		int I = 0;
		while (convert >> rate[I++]) {}
}

bool Compare(const table &a, const table &b)
{
	if(a.cost < b.cost)
		return true;
	else if(a.cost == b.cost && (a.name < b.name))
		return true;

	return false;
}

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, target, L, x, cost;
	///READ();
	///WRITE();
	cin >> tcases;
	while(tcases--)
	{
		for(I = 0; I < SIZE; I++)
		{
			ans[I].cost = 0;
			ar[I].rate1 = 0;
			ar[I].rate2 = 0;
		}

		cin >> N >> target >> L;

		cin.ignore();

		for(I = 0; I < L; I++)
		{
			getline(cin,S);

			len = S.length();

			ar[I].name = "";
			for(K = 0; K < len; K++)
			{
				if(S[K] == ':')
					break;
				ar[I].name += S[K];
			}

			X = "";
			for(J = K + 1; J < len; J++)
			{
				if(S[J] == ',')
					X += ' ';
				else
					X += S[J];
			}

			ToInt(X);

			ar[I].rate1 = rate[0];
			ar[I].rate2 = rate[1];
		}

		for(I = 0; I < L; I++)
		{
			ans[I].name = ar[I].name;

			x = N, cost = 0;
			while(x != target)
			{
				if(((x / 2) >= target) && (((x / 2) * ar[I].rate1) >  ar[I].rate2))
				{
					cost += ar[I].rate2;
					x = x / 2;
				}
				else
				{
					cost += ar[I].rate1;
					x--;
				}
			}
			ans[I].cost = cost;
		}

		sort(ans, ans + L, Compare);

		cout << "Case " << caseno++ << NL;
		for(I = 0; I < L; I++)
			cout << ans[I].name << " " << ans[I].cost << NL;

	}

	return 0;
}

/*
1
100000 9 1
ABC:10000,10000

1
100000 1 2
B:10000,10
A:10,10000
*/




