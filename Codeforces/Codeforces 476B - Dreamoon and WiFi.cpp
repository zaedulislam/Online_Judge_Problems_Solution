// Codeforces 476B - Dreamoon and WiFi.cpp

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
#define pic pair<int, char>
#define pci pair<char, int>
#define pLL pair<LL, LL>
#define pis pair<int, string>
#define psi pair<string, int>
#define PI 2 * acos(0.0);
#define EPS 1e-11;
///************************************************************///
// Numeric Functions
template <class T> inline void CheckMax(T &a, T b){ if (b > a) a = b; }//NOTES:checkmax(
template <class T> inline void CheckMin(T &a, T b){ if (b < a) a = b; }//NOTES:checkmin(
template <class T> inline T MAX(T a, T b){ return (a > b) ? a : b; }//NOTES:return max(
template <class T> inline T MIN(T a, T b){ return (a < b) ? a : b; }//NOTES:return min(
template <class T> inline T SQRT(T x){ return x * x; }//NOTES:return square root(
template <class T> inline T FABS(T a) { return a < 0 ? a * (-1) : a; }//NOTES:return absolute value(
template <class T> inline void SWAP(T &a, T &b) { T t = a; a = b; b = t; }
inline LL POW(LL base, LL power){
	LL I, res = base; if (power == 0) return 1;
	for (I = 0; I < power - 1; I++) res *= base; return res;
}
// Translator Functions
bool IsUpperCase(char c){ return c >= 'A' && c <= 'Z'; }//NOTES: IsUpperCase(
bool IsLowerCase(char c){ return c >= 'a' && c <= 'z'; }//NOTES: IsLowerCase(
bool IsVowel(char c) { return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'); }//NOTES: IsVowel(
bool IsLetter(char c){ return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }//NOTES: IsLetter(
bool IsDigit(char c){ return c >= '0' && c <= '9'; }//NOTES:IsDigit(
char ToLowerCase(char c){ return (IsUpperCase(c)) ? (c + 32) : c; }//NOTES: ToLowerCase(
char ToUpperCase(char c){ return (IsLowerCase(c)) ? (c - 32) : c; }//NOTES: ToUpperCase(
int ToInt(string s){ int r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:ToInt(
double ToDouble(string s){ double r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:ToDouble(
string ToString(int n){ string s; stringstream convert; convert << n; s = convert.str(); return s; }//NOTES:ToString(
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
string S1, S2;
int correct = 0, unknown = 0;

void DFS(int taken, int pos1, int pos2)
{
	if (taken == unknown)
	{
		if (pos1 == pos2)
			correct++;

		return;
	}

	DFS(taken + 1, pos1, pos2 + 1);
	DFS(taken + 1, pos1, pos2 - 1);
}


int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, len1, len2, total = 0, pos1 = 0, pos2 = 0;
	///READ();
	///WRITE();
	cin >> S1 >> S2;

	len1 = S1.length();
	len2 = S2.length();

	for (I = 0; I < len1; I++)
	{
		if (S1[I] == '+')
			pos1++;
		else
			pos1--;
	}

	unknown = 0;
	for (I = 0; I < len2; I++)
	{
		if (S2[I] == '?')
			unknown++;
		else if (S2[I] == '+')
			pos2++;
		else
			pos2--;
	}

	if (unknown == 0)
	{
		double ans;
		if (pos1 == pos2)
		{
			ans = 1;
			PF("%0.12lf\n", ans);
		}
		else
		{
			ans = 0;
			PF("%0.12lf\n", ans);
		}
	}
	else
	{
		total = POW(2, unknown);

		correct = 0;
		DFS(0, pos1, pos2);
		PF("%0.12lf\n", (double)correct / (double)total);
	}

	return 0;
}
