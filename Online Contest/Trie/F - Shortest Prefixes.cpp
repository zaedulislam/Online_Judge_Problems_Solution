// F - Shortest Prefixes.cpp

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

const int SIZE = 1e6;
string S, prefix, prefix1, prefix2, up, down;
vector<string> vs;
map<int, string> MAP1;
map<string, string> MAP2;

int main()
{
	BOOST
	///READ();
	///WRITE();
	int tcases, I, J, K, N, n, m, cnt = 0, len, id;

	MAP1.clear();
	MAP2.clear();
	id = 1;
	while(cin >> S)
	{
		vs.PB(S);
		MAP1[id++] = S;
	}

	if(vs.size() == 1)
	{
		cout << vs[0] << " " << vs[0][0] << NL;
		return 0;
	}

	sort(vs.begin(), vs.end());

	n = vs.size();

	prefix = "";

	for(I = 0; I < vs[0].length(); I++)
	{
		if(vs[0][I] != vs[1][I])
		{
			prefix += vs[0][I];
			break;
		}
		else
			prefix += vs[0][I];
	}

	MAP2[vs[0]] = prefix;


	for(I = 1; I < n - 1; I++)
	{
		up = vs[I - 1];
		down = vs[I + 1];

		len = vs[I].length();
		prefix = "", prefix1 = "", prefix2 = "";


		for(J = 0;  J < len; J++)
		{
			if(J >= up.length())
			{
				prefix1 += vs[I][J];
				break;
			}

			if(vs[I][J] != up[J])
			{
				prefix1 += vs[I][J];
				break;
			}
			else
				prefix1 += vs[I][J];
		}

		for(J = 0;  J < len; J++)
		{
			if(J >= down.length())
			{
				prefix2 += vs[I][J];
				break;
			}

			if(vs[I][J] != down[J])
			{
				prefix2 += vs[I][J];
				break;
			}
			else
				prefix2 += vs[I][J];
		}

		if(prefix1.length() >= prefix2.length())
			prefix = prefix1;
		else
			prefix = prefix2;

		MAP2[vs[I]] = prefix;

	}

	prefix = "";
	for(I = 0; I < vs[n - 1].length(); I++)
	{

		if(I >= vs[n - 2].length())
		{
			prefix += vs[n - 1][I];
			break;
		}

		if(vs[n - 1][I] != vs[n - 2][I])
		{
			prefix += vs[n - 1][I];
			break;
		}
		else
			prefix += vs[n - 1][I];
	}

	MAP2[vs[n - 1]] = prefix;


	map<int, string>::iterator it = MAP1.begin();
	while(it != MAP1.end())
	{
		S = it -> second;
		cout << S << " " <<  MAP2[S] << NL;
		it++;
	}

	cout << NL;

	return 0;
}
