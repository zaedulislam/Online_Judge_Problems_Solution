// Codeforces 538B - Quasi Binary.cpp

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
template <class T> inline T MAX(T a, T b){ return (a > b) ? a : b; }
template <class T> inline T MIN(T a, T b){ return (a < b) ? a : b; }
template <class T> inline T SQRT(T x){ return x * x; }//NOTES:square
template <class T> inline T FABS(T a) { return a < 0 ? a * (-1) : a; }
template <class T> inline void SWAP(T &a, T &b) { T t = a; a = b; b = t; }
inline LL POW(LL base, LL power){
	LL I, res = base; if (power == 0) return 1;
	for (I = 0; I < power - 1; I++) res *= base; return res;
}
// Translator Functions
bool IsUpperCase(char c){ return c >= 'A' && c <= 'Z'; }//NOTES: isUpperCase(
bool IsLowerCase(char c){ return c >= 'a' && c <= 'z'; }//NOTES: isLowerCase(
bool IsVowel(char c) { return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'); }//NOTES: isVowel(
bool IsLetter(char c){ return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }//NOTES: isLetter(
bool IsDigit(char c){ return c >= '0' && c <= '9'; }//NOTES:isDigit(
char ToLowerCase(char c){ return (IsUpperCase(c)) ? (c + 32) : c; }//NOTES: toLowerCase(
char ToUpperCase(char c){ return (IsLowerCase(c)) ? (c - 32) : c; }//NOTES: toUpperCase(
int ToInt(string s){ int r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:toInt(
double ToDouble(string s){ double r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:toDouble(
string ToString(int n){ string s; stringstream convert; convert << n; s = convert.str(); return s; }//NOTES:toString
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
string S, Q;


int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, mx, q;
	///READ();
	///WRITE();
	cin >> n;

	S = ToString(n);
	len = S.length();

	char ch = '0';
	for(I = 0; I < len; I++)
	{
		if(S[I] > ch)
			ch = S[I];
	}

	//cout << "ch = " << ch << NL;
	//cout << "S = " << S << NL;

	mx = ch - '0';
	cout << mx << NL;


	for(I = 0; I < mx; I++)
	{
		len = S.length();
		Q = "";
		for(J = 0; J < len; J++)
		{
			if(S[J] == '0')
				Q += '0';
			else
				Q += '1';
		}

		n = ToInt(S);
		q = ToInt(Q);
		n = n - q;
		cout << q << ' ';

		S = ToString(n);
	}

	cout << NL;

	return 0;
}
