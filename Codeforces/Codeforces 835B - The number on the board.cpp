// Codeforces 835B - The number on the board.cpp

/// Template by Zayed ///

///************************************************************///
/// #include <bits/stdc++.h>
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
//#include<unordered_map>
#include <set>
//#include<unordered_set>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdlib>
///************************************************************///
using namespace std;
int caseno = 1;
///************************************************************///
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
///************************************************************///
typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
///************************************************************///
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
#define PI 2 * acos(0.0)
#define EPS 1e-11
///************************************************************///
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
///************************************************************///

/*
*******4 Direction Array*******
int dx[] = {0, 0, - 1, 1}, dy[] = {-1, 1, 0, 0};
*******8 Direction Array*******
int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1};
********Knight Moves********
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};
*/

const int SIZE = 1e6 + 10;
string S, T, P;
vector<int> v[20];


int main()
{
	BOOST
	///READ();
	///WRITE();
	LL I, J, K, N, n, m, cnt = 0, len, k;

//	char c = 1 + '0';
//	cout << c << NL;

	cin >> k >> S;
	len = S.length();

	T = S;
   // cout << "k = " << k << " S = " << S << NL;
	LL sum = 0;
	for(I = 0; I < len; I++)
	{
		n = S[I] - '0';
		v[n].PB(I);
		sum += (S[I] - '0');
	}

	//cout << "sum = " << sum << NL;

	if(sum >= k)
		cout << 0 << NL;
	else
	{
		for(I = 0; I <= 9; I++)
		{
			for(J = 0; J < v[I].size(); J++)
			{
				if(sum >= k)
					break;

				int pos = v[I][J];
				char ch = I + '0';

                while(1)
				{
					if(sum >= k)
						break;

					if(ch == '9')
						break;

					else
					{
						ch++;
						T[pos] = ch;
						sum += 1;
					}

				}

			}

		}

		for(I = 0; I < len; I++)
		{
			if(S[I] != T[I])
				cnt++;
		}

		//cout << "T = " << T << NL;
		cout << cnt << NL;

	}

	return 0;
}

