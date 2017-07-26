// UVa 725 - Division.cpp

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

const int SIZE = 1e6;
int ar[10];


int main()
{
	///BOOST
	///READ();
	///WRITE();
	int T, I, J, K, N, n, m, cnt = 0, len, a, b;

	T = 0;
	while(1)
	{
		SF("%d", &N);

		m = 0;

		if(N == 0)
			break;

		CLR(ar);

		cnt = 0;
        for(I = 1234; I <= 98765; I++)
		{
			a = N * I;
			b = I;

			CLR(ar);

			int f = 0;

			n = a;
			while(n > 0)
			{
				int r = n % 10;
				n /= 10;
				if(ar[r] == 1)
				{
					f = 1;
					break;
				}
				else
					ar[r] = 1;
			}


			if(f == 1)
				continue;
			else
				f = 0;


			n = b;
			while(n > 0)
			{
				int r = n % 10;
				n /= 10;

				if(ar[r] == 1)
				{
					f = 1;
					break;
				}
				else
					ar[r] = 1;

			}

			if(f == 1)
				continue;
			else
			{

				int digit = log10(a) + 1;

				for(J = 5 - digit; J > 0; J--)
					ar[0]++;

				digit = log10(b) + 1;

				for(J = 5 - digit; J > 0; J--)
					ar[0]++;

				if(ar[0] <= 1)
				{
					cnt++;

					if(T >= 1)
					{
						if(m == 0)
						{
							PF("\n");
							m = 1;
						}
					}


					digit = log10(a) + 1;

					for(J = 5 - digit; J > 0; J--)
						PF("0");

					PF("%d / ", a);

					digit = log10(b) + 1;

					for(J = 5 - digit; J > 0; J--)
						PF("0");

					PF("%d = %d\n", b, N);

				}

			}

		}

		if(cnt == 0)
		{
			if(T >= 1)
				PF("\n");

			PF("There are no solutions for %d.\n", N);
		}


		T++;
	}

	return 0;
}



