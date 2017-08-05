// CodeChef TSHIRTS - Little Elephant and T-Shirts.cpp

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
#define PI 2 * acos(0.0);
#define EPS 1e-11;
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

const int SIZE = 100 + 5;
char str[300 + 10];
LL dp[(1 << 10) + 5][SIZE];
vector<int> shirtId[SIZE];
int allMask;


LL F(int mask, int pos)
{
	if (mask == allMask)
		return 1;

	if (pos > 100)
		return 0;

	if (dp[mask][pos] != -1)
		return dp[mask][pos];

	LL ret = 0;
	ret += F(mask, pos + 1);

	int SZ = shirtId[pos].size(), I;
	for (I = 0; I < SZ; I++)
	{
		if (mask & (1 << shirtId[pos][I]))
			continue;
		else
		{
			ret += F((mask) | (1 << shirtId[pos][I]), pos + 1);
			ret %= MOD;
		}

	}

	dp[mask][pos] = ret;
	return dp[mask][pos];

}


void ParseInput(int N)
{
	int I, id;
	for (I = 0; I < N; I++)
	{
		fgets(str, sizeof(str), stdin);
		int len = strlen(str);

		if(str[len - 1] != '\0')
			str[len - 1] = '\0';

		stringstream convert(str);
		while (convert >> id)
			shirtId[id].PB(I);

	}

}


int main()
{
	///BOOST
	///READ();
	///WRITE();
	int tcases, I, J, K, N, n, m, cnt = 0, len;

	SF("%d", &tcases);
	while (tcases--)
	{
		SET(dp);
		for (I = 0; I <= 100; I++)
			shirtId[I].clear();

		char ch;
		SF("%d%c", &N, &ch);

		ParseInput(N);

		allMask = (1 << N) - 1;
		PF("%lld\n", F(0, 1));

	}

	return 0;
}
