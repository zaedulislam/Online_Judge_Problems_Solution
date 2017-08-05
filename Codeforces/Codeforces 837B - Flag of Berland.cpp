// Codeforces 837B - Flag of Berland.cpp

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

const int SIZE = 100 + 10;
string S[SIZE];
set<char> sc;


int main()
{
	BOOST
	///READ();
	///WRITE();
	int T, I, J, K, N, n, m, cnt = 0, len, row, col, R = 0, G = 0, B = 0;
	char ch;

	cin >> row >> col;

	for(I = 0; I < row; I++)
		cin >> S[I];


	if((row % 3 != 0) && (col % 3 != 0))
		cout << "NO\n";
	else
	{
		/// Case 1
		if((row % 3 == 0) && (col % 3 == 0))
		{
			int f1 = 0, f2 = 0;

			/// For row-wise
			R = 0, G = 0, B = 0;
			int x = row / 3;

			for(I = 0; I < x; I++)
			{
				for(J = 0; J < col; J++)
				{
					char ch = S[I][J];
					sc.insert(ch);
				}

			}

			if(sc.size() == 1)
			{
				set<char>:: iterator it = sc.begin();
				char ch = *it;

				if(ch == 'R')
					R = 1;
				else if(ch == 'G')
					G = 1;
				else
					B = 1;
			}

			sc.clear();

			n = I;
			x += (row / 3);

			for(I = n; I < x; I++)
			{
				for(J = 0; J < col; J++)
				{
					char ch = S[I][J];
					sc.insert(ch);
				}

			}


			if(sc.size() == 1)
			{
				set<char>:: iterator it = sc.begin();
				char ch = *it;

				if(ch == 'R')
					R = 1;
				else if(ch == 'G')
					G = 1;
				else
					B = 1;
			}

			sc.clear();

			n = I;
			x += (row / 3);

			for(I = n; I < x; I++)
			{
				for(J = 0; J < col; J++)
				{
					char ch = S[I][J];
					sc.insert(ch);
				}

			}

			if(sc.size() == 1)
			{
				set<char>:: iterator it = sc.begin();
				char ch = *it;

				if(ch == 'R')
					R = 1;
				else if(ch == 'G')
					G = 1;
				else
					B = 1;
			}

			sc.clear();

			if(R == 1 && G == 1 && B == 1)
			{
				cout << "YES\n";
				return 0;
			}

			/// For column-wise
			R = 0, G = 0, B = 0;
			int y = col / 3;

			for(I = 0; I < y; I++)
			{
				for(J = 0; J < row; J++)
				{
					char ch = S[J][I];
					sc.insert(ch);
				}

			}

			if(sc.size() == 1)
			{
				set<char>:: iterator it = sc.begin();
				char ch = *it;

				if(ch == 'R')
					R = 1;
				else if(ch == 'G')
					G = 1;
				else
					B = 1;
			}

			sc.clear();

			n = I;
			y += (col / 3);

			for(I = n; I < y; I++)
			{
				for(J = 0; J < row; J++)
				{
					char ch = S[J][I];
					sc.insert(ch);
				}

			}

			if(sc.size() == 1)
			{
				set<char>:: iterator it = sc.begin();
				char ch = *it;

				if(ch == 'R')
					R = 1;
				else if(ch == 'G')
					G = 1;
				else
					B = 1;
			}

			sc.clear();

			n = I;
			y += (col / 3);

			for(I = n; I < y; I++)
			{
				for(J = 0; J < row; J++)
				{
					char ch = S[J][I];
					sc.insert(ch);
				}

			}

			if(sc.size() == 1)
			{
				set<char>:: iterator it = sc.begin();
				char ch = *it;

				if(ch == 'R')
					R = 1;
				else if(ch == 'G')
					G = 1;
				else
					B = 1;
			}

			sc.clear();

			if(R == 1 && G == 1 && B == 1)
			{

				cout << "YES\n";
				return 0;

			}

			cout << "NO\n";

		}


		/// Case 2
		else if(row % 3 == 0)
		{
			R = 0, G = 0, B = 0;
			int x = row / 3;

			for(I = 0; I < x; I++)
			{
				for(J = 0; J < col; J++)
				{
					char ch = S[I][J];
					sc.insert(ch);
				}

			}

			if(sc.size() != 1)
			{
				cout << "NO\n";
				return 0;
			}
			else
			{
				set<char>:: iterator it = sc.begin();
				char ch = *it;

				if(ch == 'R')
					R = 1;
				else if(ch == 'G')
					G = 1;
				else
					B = 1;
			}

			sc.clear();

			n = I;
			x += (row / 3);

			for(I = n; I < x; I++)
			{
				for(J = 0; J < col; J++)
				{
					char ch = S[I][J];
					sc.insert(ch);
				}

			}

			if(sc.size() != 1)
			{
				cout << "NO\n";
				return 0;
			}
			else
			{
				set<char>:: iterator it = sc.begin();
				char ch = *it;

				if(ch == 'R')
					R = 1;
				else if(ch == 'G')
					G = 1;
				else
					B = 1;
			}

			sc.clear();

			n = I;
			x += (row / 3);

			for(I = n; I < x; I++)
			{
				for(J = 0; J < col; J++)
				{
					char ch = S[I][J];
					sc.insert(ch);
				}

			}

			if(sc.size() != 1)
			{
				cout << "NO\n";
				return 0;
			}
			else
			{
				set<char>:: iterator it = sc.begin();
				char ch = *it;

				if(ch == 'R')
					R = 1;
				else if(ch == 'G')
					G = 1;
				else
					B = 1;
			}

			sc.clear();

			if(R == 1 && G == 1 && B == 1)
				cout << "YES\n";
			else
				cout << "NO\n";

		}

		/// Case 3
		else if(col % 3 == 0)
		{
			R = 0, G = 0, B = 0;
			int y = col / 3;

			for(I = 0; I < y; I++)
			{
				for(J = 0; J < row; J++)
				{
					char ch = S[J][I];
					sc.insert(ch);
				}

			}

			if(sc.size() != 1)
			{
				cout << "NO\n";
				return 0;
			}
			else
			{
				set<char>:: iterator it = sc.begin();
				char ch = *it;

				if(ch == 'R')
					R = 1;
				else if(ch == 'G')
					G = 1;
				else
					B = 1;
			}

			sc.clear();

			n = I;
			y += (col / 3);

			for(I = n; I < y; I++)
			{
				for(J = 0; J < row; J++)
				{
					char ch = S[J][I];
					sc.insert(ch);
				}

			}

			if(sc.size() != 1)
			{
				cout << "NO\n";
				return 0;
			}
			else
			{
				set<char>:: iterator it = sc.begin();
				char ch = *it;

				if(ch == 'R')
					R = 1;
				else if(ch == 'G')
					G = 1;
				else
					B = 1;
			}

			sc.clear();

			n = I;
			y += (col / 3);

			for(I = n; I < y; I++)
			{
				for(J = 0; J < row; J++)
				{
					char ch = S[J][I];
					sc.insert(ch);
				}

			}

			if(sc.size() != 1)
			{
				cout << "NO\n";
				return 0;
			}
			else
			{
				set<char>:: iterator it = sc.begin();
				char ch = *it;

				if(ch == 'R')
					R = 1;
				else if(ch == 'G')
					G = 1;
				else
					B = 1;
			}

			sc.clear();

			if(R == 1 && G == 1 && B == 1)
				cout << "YES\n";
			else
				cout << "NO\n";
		}

	}

	return 0;
}
