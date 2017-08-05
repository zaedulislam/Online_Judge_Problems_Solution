// CodeChef RANBOWA - Chef and Rainbow Array.cpp

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
int ar[SIZE], A[SIZE], B[SIZE];



int main()
{
	BOOST
	///READ();
	///WRITE();
	int T, I, J, K, N, n, m, cnt = 0, len;

	cin >> T;
	while(T--)
	{
		CLR(A);
		CLR(B);

		int f = 0;

		cin >> N;
		for(I = 0; I < N; I++)
		{
			cin >> ar[I];

			if(ar[I] > 7)
				f = 1;
		}

		if(f == 1)
			cout << "no\n";
		else
		{
			f = 0;

			for(I = 0; I < N; I++)
			{
				if(ar[I] > 1)
					break;
				else
					A[ar[I]]++;
			}

			if(A[1] == 0)
			{
				cout << "no\n";
				continue;
			}

			J = I;

			for(I = J; I < N; I++)
			{
                if(ar[I] == 7)
					break;
				else
				{
					if(A[ar[I] - 1] == 0)
					{
						cout << "no\n";
						f = 1;
						break;
					}
					else
						A[ar[I]]++;

				}

			}

			if(f == 1)
				continue;

			if(I == N)
			{
				cout << "no\n";
				continue;
			}

			J = I;

			for(I = J; I < N; I++)
			{
				if(ar[I] != 7)
					break;
				else
					A[ar[I]]++;
			}

			J = I;

			for(I = J; I < N; I++)
			{
				if(ar[I] != 6)
					break;
				else
					B[ar[I]]++;
			}

			if(B[6] != A[6])
			{
				cout << "no\n";
				continue;
			}

			J = I;

			f = 0;
			for(I = J; I < N; I++)
			{
				if(B[ar[I] + 1] == 0 || ar[I] >= 7)
				{
					f = 1;
					break;
				}
				else
					B[ar[I]]++;
			}


			if(f == 1)
			{
				cout << "no\n";
				continue;
			}


			/// Final Checking
			f = 0;
			for(I = 1; I <= 6; I++)
			{
				if(A[I] != B[I])
				{
					f = 1;
					break;
				}

			}
			/// Final Checking

			if(f == 0)
				cout << "yes\n";
			else
				cout << "no\n";

		}

	}


	return 0;
}
