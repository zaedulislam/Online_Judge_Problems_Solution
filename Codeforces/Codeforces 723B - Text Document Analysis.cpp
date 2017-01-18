// Codeforces 723B - Text Document Analysis.cpp

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

const int SIZE = 1e6;
string S, A, B;

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, mxLen = 0, f1 = 0, lenA, lenB;
	///READ();
	///WRITE();
	cin >> len >> S;

	//
	//	Convert all the letters to Uppercase.
	//
	for(I = 0; I < len; I++)
	{
		if(S[I] >= 'a' && S[I] <= 'z')
			S[I] = toupper(S[I]);
	}

	//
	//	Divide the string S into A and B according to inside/outside the parentheses.
	//
	A = "", B = "";
	for(I = 0; I < len; I++)
	{
		if(S[I] == '(')
		{
			A += '_';
			f1 = 1;
		}

		if(f1 == 0)
			A += S[I];
		else
			B += S[I];

		if(S[I] == ')')
			f1 = 0;
	}

	lenA = A.length();
	lenB = B.length();

	//
	//	Finds the maximum length of a word.
	//
	cnt = 0, f1 = 0;
	for(I = 0; I < lenA; I++)
	{
		if(A[I] >= 'A' && A[I] <= 'Z')
			f1 = 1;
		else
			f1 = 0;

		if(f1 == 1)
			cnt++;
		if(f1 == 0 || I == lenA - 1)
		{
			mxLen = max(mxLen, cnt);
			cnt = 0;
		}
	}

	cout << mxLen << ' ';

	//
	//	Copy the contents of B to A excluding the parentheses.
	//
	A = "";
	cnt = 0, f1 = 0;
	for(I = 0; I < lenB; I++)
	{
		if(B[I] >= 'A' && B[I] <= 'Z')
			f1 = 1;
		else
		{
			f1 = 0;
			A += ' ';
			cnt++;
		}

		if(f1 == 1)
			A += B[I];
	}

	//
	//	Counts the number of words inside the parentheses.
	//
	lenA = A.length();
	f1 = 0, cnt = 0;
	for(I = 0; I < lenA; I++)
	{
		if(A[I] >= 'A' && A[I] <= 'Z')
			f1 = 1;

		if(f1 == 1 && A[I] == ' ')
		{
			f1 = 0;
			cnt++;
		}
	}
	cout << cnt << NL;

	return 0;
}


