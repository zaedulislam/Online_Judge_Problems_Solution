// UVa 496 - Simply Subsets.cpp
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

string A, B;
map < int, int > M;
int a[SIZE], b[SIZE];

int main()
{
	BOOST
	int tcases, I, J, K, N, n1, n2, m, cnt = 0, len;
	///READ();
	///WRITE();
	while(getline(cin, A))
	{
		M.clear();

		getline(cin, B);

		n1 = 0;
		stringstream convert_A(A);
		while(convert_A >> a[n1++]) {};
		n1--;

		n2 = 0;
		stringstream convert_B(B);
		while(convert_B >> b[n2++]) {}
		n2--;

		/*
        for(I = 0; I < n1; I++)
			cout << a[I] << " ";
		cout << NL;

		for(I = 0; I < n2; I++)
			cout << b[I] << " ";
		cout << NL;
		*/

		if(n1 >= n2)
		{
			for(I = 0; I < n1; I++)
				M[a[I]]++;

			cnt = 0;
			for(I = 0; I < n2; I++)
			{
				if(M[b[I]] != 0)
					cnt++;
			}

			if(cnt == 0)
				cout << "A and B are disjoint\n";
			else if(cnt == n2 && n1 == n2)
				cout << "A equals B\n";
			else if(cnt == n2)
				cout << "B is a proper subset of A\n";
			else
				cout << "I'm confused!\n";
		}
		else
		{
			for(I = 0; I < n2; I++)
				M[b[I]]++;

				cnt = 0;
			for(I = 0; I < n1; I++)
			{
				if(M[a[I]] != 0)
					cnt++;
			}

			if(cnt == 0)
				cout << "A and B are disjoint\n";
			else if(cnt == n1 && n1 == n2)
				cout << "A equals B\n";
			else if(cnt == n1)
				cout << "A is a proper subset of B\n";
			else
				cout << "I'm confused!\n";
		}
	}

	return 0;
}

