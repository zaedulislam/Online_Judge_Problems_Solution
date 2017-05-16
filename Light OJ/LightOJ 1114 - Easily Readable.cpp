// LightOJ 1114 - Easily Readable.cpp

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
#include<tr1/unordered_map>

#include <set>
//#include<unordered_set>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdlib>
///************************************************************///
using namespace std;
using namespace tr1;
int caseno = 1;
///************************************************************///
#define NL '\n'
#define SF scanf
#define PF printf
#define PC() printf("Case %d:\n", caseno++)//NOTES:printf
//#define PC cout << "Case "//NOTES:cout
//#define CN cout << caseno++ << ":\n"//NOTES:cout
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
#define p 999998727899999 			// (largest prime below 10^16)
#define PB push_back
#define pii pair<int, int>
#define pic pair<int, char>
#define pci pair<char, int>
#define pLL pair<LL, LL>
#define pis pair<int, string>
#define psi pair<string, int>
#define pss pair<string, string>
#define PI 2 * acos(0.0);
#define EPS 1e-11;
///************************************************************///
// Numeric Functions
template < class T > inline void SWAP(T &a, T &b) { T t = a; a = b; b = t; }
inline LL POW(LL base, LL power){
	LL I, res = base; if (power == 0) return 1;
	for (I = 0; I < power - 1; I++) res *= base; return res;
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

const int SIZE = 10000 + 10;
string S, w;
char str[SIZE];
unordered_map<LL, LL> MAP;

void Hashing(int len)
{
	LL hashno = 0, base = 1, mod = p;
    for(int I = 0; I < len; I++)
	{
        hashno = (hashno + (str[I] * base)) % mod;
		base = (base * 57) % mod;
    }

	MAP[hashno]++;
}


int main()
{
	///BOOST
	///READ();
	///WRITE();
	int tcases, I, J, K, N, n, m, cnt = 0, len;

	LL res;
	SF("%d", &tcases);

	while(tcases--)
	{
		MAP.clear();
		res = 1;

		SF("%d", &n);

		for(I = 0; I < n; I++)
		{
			SF("%s", str);
			int len = strlen(str);

			if(len > 2)
				sort(str + 1, str + len - 1);

			Hashing(len);
		}

		PC();

		char ch;
		SF("%d%c", &m, &ch);

		for(I = 0; I < m; I++)
		{
			res = 1;

            gets(str);

            stringstream ss(str);

            while(ss >> w)
			{
				len = w.length();

				if(len > 2)
					sort(w.begin() + 1, w.end() - 1);

				LL hashno = 0, base = 1, mod = p;
				for(int J = 0; J < len; J++)
				{
					hashno = (hashno + (w[J] * base)) % mod;
					base = (base * 57) % mod;
				}

				if(MAP.find(hashno) != MAP.end())
					res = res * MAP[hashno];
				else
					res = 0;

				if(res == 0)
					break;
			}

			PF("%lld\n", res);

		}

	}

	return 0;
}




