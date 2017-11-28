// UVa 256 - Quirksome Squares.cpp

/// Template by Zayed ///

///************************************************************///
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
//#define tiii tuple<int, int, int>
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
string S, A, B;
vector<string> vi[10];

void F(int x, int n)
{
	A = "", B = "";
	int I, J, cnt = 0, a, b, len = S.length(), temp, mid = n / 2;

	S = ToString(x);
	len = S.length();

	temp = n - len;
	string P = "";
	for(I = 0; I < temp; I++)
		P += '0';

	P += S;

	for(I = 0; I < mid; I++)
		A += P[I];

	for(I = mid; I < n; I++)
		B += P[I];

	a = ToInt(A);
	b = ToInt(B);

	if(POW((a + b), 2) == x)
		cout << P << NL;

}



int main()
{
	BOOST
	///READ();
	///WRITE();
	int T, I, J, K, N, n, m, cnt = 0, len;

	vi[2].PB("00");
	vi[2].PB("01");
	vi[2].PB("81");

	vi[4].PB("0000");
	vi[4].PB("0001");
	vi[4].PB("2025");
	vi[4].PB("3025");
	vi[4].PB("9801");

	vi[6].PB("000000");
	vi[6].PB("000001");
	vi[6].PB("088209");
	vi[6].PB("494209");
	vi[6].PB("998001");

	vi[8].PB("00000000");
	vi[8].PB("00000001");
	vi[8].PB("04941729");
	vi[8].PB("07441984");
	vi[8].PB("24502500");
	vi[8].PB("25502500");
	vi[8].PB("52881984");
	vi[8].PB("60481729");
	vi[8].PB("99980001");


	while(cin >> n)
	{
		int SZ = vi[n].size();

		for(I = 0; I < SZ; I++)
			cout << vi[n][I] << NL;

	}

	return 0;
}




