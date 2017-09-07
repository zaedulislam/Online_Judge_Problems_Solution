// CS Academy_Round #44 - Square Cover.cpp

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

const int SIZE = 300 + 10;
int m[SIZE][SIZE];
int MAP[100000 + 10];
set<int> si;
pii ar[100000 + 10];


int main()
{
	///BOOST
	///READ();
	///WRITE();
	int T, I, J, K, N, n, cnt = 0, len, M, L, r, c, f;

	for(I = 0; I < 100000 + 10; I++)
		ar[I] = pii(-1, -1);

	SF("%d%d", &N, &M);

	for(I = 0; I < N; I++)
	{
		for(J = 0; J < M; J++)
		{
			SF("%d", &m[I][J]);
			si.insert(m[I][J]);

			cnt = m[I][J];

			if(ar[cnt].first == -1 && ar[cnt].second == -1)
				ar[cnt] = pii(I, J);


		}

	}

    set<int> :: iterator it = si.begin();
    while(it != si.end())
	{
		int x = *it;

		if(MAP[x] == 1)
		{
			PF("0\n");
			return 0;
		}

		f = 0, r = 0, c = 0;

		I = ar[x].first;
		J = ar[x].second;

		MAP[x] = 1;

		for(K = J; K < M; K++)
		{
			if(m[I][K] == x)
			{
				m[I][K] = -1;
				r = 1;
				c++;
			}

		}

		f = 0;

		int p = 0;
		for(L =  I + 1; L < N; L++)
		{

			for(K = J; K < J + c; K++)
			{
				if(m[L][K] == x)
					m[L][K] = -1;
				else
				{
					f = 1;
					break;
				}

			}

			if(f == 1)
				break;

			r++;
		}

		if(r != c)
		{
			PF("0\n");
			return 0;
		}


		it++;
	}


	for(I = 0; I < N; I++)
	{
		for(J = 0; J < M; J++)
		{
			if(m[I][J] != -1)
			{
				PF("0\n");
				return 0;
			}

		}

	}

	PF("1\n");


	return 0;
}








