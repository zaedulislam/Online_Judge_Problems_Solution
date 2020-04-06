// J - GPA.cpp
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

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e6;

string S;

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, f;
	double sum = 0;
	///READ();
	///WRITE();
	while(getline(cin, S))
	{
		cnt = 0, f = 0;
		sum = 0;
		len = S.length();

		for(I = 0; I < len; I++)
		{
			if(S[I] == ' ')
				continue;
			else if(S[I] == 'A')
				sum += 4, cnt++;
			else if(S[I] == 'B')
				sum += 3, cnt++;
			else if(S[I] == 'C')
				sum += 2, cnt++;
			else if(S[I] == 'D')
				sum += 1, cnt++;
			else if(S[I] == 'F')
				sum += 0, cnt++;
			else
			{
				f = 1;
				break;
			}
		}

		if(f == 1)
			cout << "Unknown letter grade in input\n";
		else
			cout << fixed << setprecision(2) << sum / (double)cnt << NL;
	}

	return 0;
}

