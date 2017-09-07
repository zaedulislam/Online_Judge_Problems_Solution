// UVa 10452 - Marcus.cpp

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

const int SIZE = 10 + 10;
string S[SIZE], str = "IEHOVA";
vector<int> vi;
int dx[] = { 0, 0, -1 }, dy[] = { -1, +1, 0 };



void F(int I, int J, int pos, int m, int n)
{
	int K, x, y, f;

	f = 0;
	for (K = 0; K < 3; K++)
	{

		x = I + dx[K];
		y = J + dy[K];

		if((x >= 0 && x < m) && (y >= 0 && y < n) && S[x][y] == '#')
		{
			if (K == 0)
				vi.PB(1);

			else if (K == 1)
				vi.PB(2);

			else
				vi.PB(3);

			return;
		}

		if ((x >= 0 && x < m) && (y >= 0 && y < n) && pos < str.size() && S[x][y] == str[pos])
		{

			f = 1;
			if (K == 0)
				vi.PB(1);

			else if (K == 1)
				vi.PB(2);

			else
				vi.PB(3);

			F(x, y, pos + 1, m, n);

		}

	}

}



int main()
{
	BOOST
	///READ();
	///WRITE();
	int T, I, J, K, N, n, m, cnt = 0, len, x, y;

	cin >> T;

	while (T--)
	{

		for (I = 0; I < SIZE; I++)
			S[I].clear();

		vi.clear();

		cin >> m >> n;

		for (I = 0; I < m; I++)
		{
			cin >> S[I];

			for (J = 0; J < n; J++)
			{
				if (S[I][J] == '@')
				{
					x = I;
					y = J;

				}

			}

		}


		F(x, y, 0, m, n);

		len = vi.size();
		for (I = 0; I < len; I++)
		{
			if (I > 0)
				cout << ' ';
			if (vi[I] == 1)
				cout << "left";
			else if (vi[I] == 2)
				cout << "right";
			else
				cout << "forth";
		}

		cout << NL;


	}


	return 0;
}




