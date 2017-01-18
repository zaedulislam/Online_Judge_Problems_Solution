// UVa 11577 - Letter Frequency.cpp
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

string S;
int freq[26 + 2];

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, mx;
	///READ();
	///WRITE();
	cin >> tcases;
	cin.ignore();
	while (tcases--)
	{
		CLR(freq);

		getline(cin, S);

		len = S.length();

		for (I = 0; I < len; I++)
		{
			if ((S[I] >= 'a' && S[I] <= 'z') || (S[I] >= 'A' && S[I] <= 'Z'))
			{
				ch = tolower(S[I]);
				freq[ch - 'a']++;
			}
		}

		mx = 0;
		for (I = 0; I < 26; I++)
		{
			if (freq[I] > mx)
				mx = freq[I];
		}

		for (I = 0; I < 26; I++)
		{
			if (freq[I] == mx)
				cout << char(I + 'a');
		}

		cout << NL;
	}

	return 0;
}

