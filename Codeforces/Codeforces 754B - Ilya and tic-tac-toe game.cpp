// Codeforces 754B - Ilya and tic-tac-toe game.cpp

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
#include <set>

#include <algorithm>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>

#include <cmath>
#include <cstdlib>
#include <cctype>
#include <ctime>
///************************************************************///
using namespace std;
int caseno = 1;
///************************************************************///
#define NL '\n'
#define SF scanf
#define PF printf
#define PC() printf("Case %d: ", caseno++)//NOTES:printf
#define PC cout << "Case "//NOTES:cout
#define CN cout << caseno++ << ": "//NOTES:cout
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
///************************************************************///
typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64
///************************************************************///
#define INF (1 << 31) - 1
#define MOD 1000000007
#define pii pair<int, int>
#define pLL pair<LL, LL>
#define pis pair<int, string>
#define psi pair<string, int>
#define PI 2 * acos(0.0);
#define EPS 1e-11;
///************************************************************///
// Numeric Functions
// Translator Functions
///************************************************************///

/*
*******4 Direction Array*******
int dx[] = {0, 0, - 1, 1}, dy[] = {-1, 1, 0, 0};
*******8 Direction Array*******
int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1};
********Knight Moves********
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};
*/

const int SIZE = 10;
string S[SIZE];

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len;
	///READ();
	///WRITE();
	for (I = 0; I < 4; I++)
		cin >> S[I];

	/*
	for(I = 0; I < 4; I++)
	cout << S[I] << NL;
	*/

	int f = 0;
	for (I = 0; I < 4; I++)
	{
		if (S[I][0] == 'x' && S[I][1] == 'x' && S[I][2] == '.')
			f = 1;
		if (S[I][1] == 'x' && S[I][3] == 'x' && S[I][2] == '.')
			f = 1;
		if (S[I][1] == 'x' && S[I][2] == 'x' && S[I][3] == '.')
			f = 1;
		if (S[I][1] == 'x' && S[I][2] == 'x' && S[I][0] == '.')
			f = 1;
		if (S[I][0] == 'x' && S[I][2] == 'x' && S[I][1] == '.')
			f = 1;
		if (S[I][2] == 'x' && S[I][3] == 'x' && S[I][1] == '.')
			f = 1;
	}

	if (f == 1)
	{
		cout << "YES\n";
		return 0;
	}

	f = 0;
	for (I = 0; I < 4; I++)
	{
		if (S[1][I] == 'x' && S[2][I] == 'x' && S[0][I] == '.')
			f = 1;
		if (S[0][I] == 'x' && S[2][I] == 'x' && S[1][I] == '.')
			f = 1;
		if (S[2][I] == 'x' && S[3][I] == 'x' && S[1][I] == '.')
			f = 1;
		if (S[1][I] == 'x' && S[3][I] == 'x' && S[2][I] == '.')
			f = 1;
		if (S[0][I] == 'x' && S[1][I] == 'x' && S[2][I] == '.')
			f = 1;
		if (S[1][I] == 'x' && S[2][I] == 'x' && S[3][I] == '.')
			f = 1;
	}

	if (f == 1)
	{
		cout << "YES\n";
		return 0;
	}


	f = 0;
	/// From Left
	if (S[0][2] == 'x' && S[1][1] == 'x' && S[2][0] == '.')
		f = 1;
	if (S[0][2] == 'x' && S[2][0] == 'x' && S[1][1] == '.')
		f = 1;
	if (S[1][1] == 'x' && S[2][0] == 'x' && S[0][2] == '.')
		f = 1;


	//
	if (S[1][2] == 'x' && S[0][3] == 'x' && S[2][1] == '.')
		f = 1;
	if (S[0][3] == 'x' && S[2][1] == 'x' && S[1][2] == '.')
		f = 1;
	if (S[1][2] == 'x' && S[2][1] == 'x' && S[0][3] == '.')
		f = 1;
	//
	if (S[1][2] == 'x' && S[2][1] == 'x' && S[3][0] == '.')
		f = 1;
	if (S[1][2] == 'x' && S[3][0] == 'x' && S[2][1] == '.')
		f = 1;
	if (S[3][0] == 'x' && S[2][1] == 'x' && S[1][2] == '.')
		f = 1;

	//
	if (S[1][3] == 'x' && S[2][2] == 'x' && S[3][1] == '.')
		f = 1;
	if (S[1][3] == 'x' && S[3][1] == 'x' && S[2][2] == '.')
		f = 1;
	if (S[3][1] == 'x' && S[2][2] == 'x' && S[1][3] == '.')
		f = 1;


	/// From Right
	if (S[3][2] == 'x' && S[2][1] == 'x' && S[1][0] == '.')
		f = 1;
	if (S[1][0] == 'x' && S[3][2] == 'x' && S[2][1] == '.')
		f = 1;
	if (S[1][0] == 'x' && S[2][1] == 'x' && S[3][2] == '.')
		f = 1;


	//
	if (S[1][2] == 'x' && S[2][3] == 'x' && S[0][1] == '.')
		f = 1;
	if (S[0][1] == 'x' && S[2][3] == 'x' && S[1][2] == '.')
		f = 1;
	if (S[1][2] == 'x' && S[0][1] == 'x' && S[2][3] == '.')
		f = 1;

	//
	if (S[1][1] == 'x' && S[2][2] == 'x' && S[0][0] == '.')
		f = 1;
	if (S[0][0] == 'x' && S[2][2] == 'x' && S[1][1] == '.')
		f = 1;
	if (S[0][0] == 'x' && S[1][1] == 'x' && S[2][2] == '.')
		f = 1;
	//
	if (S[2][2] == 'x' && S[3][3] == 'x' && S[1][1] == '.')
		f = 1;
	if (S[1][1] == 'x' && S[3][3] == 'x' && S[2][2] == '.')
		f = 1;
	if (S[1][1] == 'x' && S[2][2] == 'x' && S[3][3] == '.')
		f = 1;

	if (f == 1)
	{
		cout << "YES\n";
		return 0;
	}

	cout << "NO\n";

	return 0;
}


