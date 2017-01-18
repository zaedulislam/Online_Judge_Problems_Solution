// UVa 12210 - A Match Making Problem.cpp
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
const int SIZE = 1e4 + 10;

vector<int>B, S;

int main()
{
	///BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, x, y, mx;
	///READ();
	///WRITE();
	while(SF("%d%d", &n, &m), (n || 0))
	{
		B.clear();
		S.clear();

		for(I = 0; I < n; I++)
		{
			SF("%d", &N);
			B.push_back(N);
		}

		for(I = 0; I < m; I++)
		{
			SF("%d", &N);
			S.push_back(N);
		}

		PC();
		if(n <= m)
		{
			PF("0\n");
			continue;
		}

		sort(B.begin(), B.end(), greater<int>());
		sort(S.begin(), S.end(), greater<int>());

		I = 0, J = 0;
		while(B.size() > 0 && S.size() > 0)
		{
			x = INF, y = INF;

			x = abs(S[J] - B[I]);

			if((J + 1 < S.size()))
				y = abs(S[J + 1] - B[I]);

			if(x <= y)
			{
				B.erase(B.begin() + I);
				S.erase(S.begin() + J);
			}
			else
			{
				B.erase(B.begin() + I);
				S.erase(S.begin() + J + 1);
			}
		}

		sort(B.begin(), B.end());

		PF("%d %d",B.size(), B[0]);
		PF("\n");
	}
	return 0;
}

