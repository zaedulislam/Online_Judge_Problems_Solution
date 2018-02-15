// CodeChef PERMPAL - Permutation and Palindrome.cpp

/// Template by Zayed ///

/// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>

#include <string>
#include <cstring>
#include <sstream>

//#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <map>
//#include<unordered_map>
#include <set>
//#include<unordered_set>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdlib>

using namespace std;
int caseno = 1;

#define NL '\n'
#define SF scanf
#define PF printf
#define PC() printf("Case %d: ", caseno++)//NOTES:printf
//#define PC cout << "Case "//NOTES:cout
//#define CN cout << caseno++ << ": "//NOTES:cout
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define READ() freopen("input.txt", "r", stdin)
#define WRITE() freopen("output.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"

#define INF (1 << 31) - 1
#define MOD 1000000007
#define PRIME 999998727899999 			// (largest prime below 10^16)
#define PB push_back
#define pii pair<int, int>
#define pic pair<int, char>
#define pci pair<char, int>
#define pLL pair<LL, LL>
#define pis pair<int, string>
#define psi pair<string, int>
#define pss pair<string, string>
//#define tiii tuple<int, int, int>
#define PI 2 * acos(0.0)
#define EPS 1e-11


// Numeric Functions
template < class T > inline void SWAP(T &a, T &b) { T t = a; a = b; b = t; }
inline LL POW(LL base, LL power){
	LL res = base; if (power == 0) return 1;
	for (int I = 0; I < power - 1; I++) res *= base; return res;
}


// Translator Functions
int ToInt(string s) { int r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:ToInt(
double ToDouble(string s) { double r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:ToDouble(
string ToString(int n) { string s; stringstream convert; convert << n; s = convert.str(); return s; }//NOTES:ToString(


/*
*******4 Direction Array*******
int dx[] = {0, 0, - 1, 1}, dy[] = {-1, 1, 0, 0};
*******8 Direction Array*******
int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1};
********Knight Moves********
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};
*/


const int SIZE = 1e5 + 10;
string S;
int freq[26 + 10];
vector<int> a, b, ans;
vector<pci> vi;




int main()
{
	BOOST
	///READ();
	///WRITE();
	int T, I, J, K, N, n, m, k, cnt = 0, len, odd, f, idx, x;
	char ch;

	cin >> T;
	while(T--)
	{

		vi.clear();
		a.clear();
		b.clear();
		ans.clear();
		CLR(freq);


		cin >> S;
		len = S.length();

		for(I = 0; I < len; I++)
		{
			freq[S[I] - 'a']++;
			vi.PB(pci(S[I], I));
		}


		odd = 0, f = 0, idx = -1;
		for(I = 0; I < 26; I++)
		{
			if(freq[I] & 1)
			{
				odd++;
				idx = I;
			}

			if(odd > 1)
			{
				f = 1;
				break;
			}

		}


		if(f == 1)
			cout << -1 << NL;
		else
		{
			sort(vi.begin(), vi.end());

			if(idx != -1)
				ch = idx + 97;
			else
				ch = 'A';

			J  = 0;
			for(I = 0; I < 26; I++)
			{

				if(!(freq[I] & 1) && freq[I] != 0)
				{
					n = freq[I];
					m = n / 2;

					cnt = 0;
					for(; J < vi.size(); J++)
					{
						if(vi[J].first == ch)
							continue;

						if(cnt == n)
							break;

                        if(cnt < m)
							a.PB(vi[J].second);
						else
							b.PB(vi[J].second);

						cnt++;
					}

				}

			}


			for(I = 0; I < a.size(); I++)
				ans.PB(a[I] + 1);


			for(I = 0; I < vi.size(); I++)
			{
				if(vi[I].first == ch)
					ans.PB(vi[I].second + 1);
			}

			for(I = b.size() - 1; I >= 0; I--)
				ans.PB(b[I] + 1);

			cout << ans[0];
			for(I = 1; I < ans.size(); I++)
				cout << ' ' << ans[I];

			cout << NL;
		}

	}


	return 0;
}
