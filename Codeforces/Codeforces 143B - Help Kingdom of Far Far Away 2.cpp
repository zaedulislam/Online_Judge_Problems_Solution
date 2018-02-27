// Codeforces 143B - Help Kingdom of Far Far Away 2.cpp

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
#define BUG() printf("\n!!!WHERE IS YOUR FOCUS!!!\n")//NOTES:printf
//#define PC cout << "Case "//NOTES:cout
//#define CN cout << caseno++ << ": "//NOTES:cout
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define READ() freopen("input.txt", "r", stdin)
#define WRITE() freopen("output.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"

#define MOD 1000000007		    // (10^9 + 7)
#define PRIME 999998727899999   // (largest prime below 10^16)
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


const int SIZE = 100 + 10;
string S;
int commaPos [SIZE];




int main()
{
	BOOST
	///READ();
	///WRITE();
	int T, I, J, K, N, n, m, k, cnt = 0, len, right;
	bool isComma = false, isDot = false, isMinus = false;

	cin >> S;
	len = S.length();

	if(S[0] == '-')
		isMinus = true;

	right = 0;
	for(I = 0; I < len; I++)
	{
		if(S[I] == '.')
		{
			isDot = true;
			break;
		}
		right++;

	}


	if(isDot)
		len = right;

	cnt = 0;
	for(I = len - 1; I >= 0; I--)
	{
		cnt++;

		if(cnt == 3 && I != 0)
		{
			commaPos[I - 1] = 1;
			cnt = 0;
		}

	}


	if(isMinus)
		cout << '(';

	cout << '$';

	if(isDot)
		len = right;

	for(I = 0; I < len; I++)
	{
		if(S[I] == '-')
			continue;

		cout << S[I];
		if(commaPos[I] == 1)
			cout << ',';
	}


	len = S.length();
	cnt = 0;

	cout << '.';
	if(isDot)
	{
		for(I = right + 1; I < len; I++)
		{
			if(cnt == 2)
				break;

			cout << S[I];
			cnt++;
		}

		if(cnt == 1)
			cout << '0';
	}
	else
		cout << '0' << '0';


	if(isMinus)
		cout << ')';

	cout << NL;

	return 0;
}




