// UVa 624 - CD.cpp

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

const int SIZE = 20 + 10;
int ar[SIZE], mx = 0;
vector<int> ans;


void F(int pos, int T, int taken, int N, vector<int> vi)
{
	if(pos >= T)
	{
		//cout << "mx = " << taken << NL;
		if(taken <= N)
		{
			///cout << "mx = " << taken << NL;
			if(taken >= mx)
			{
				mx = taken;
				ans = vi;
				//PF("mx:%d\n", mx);
			}

		}

		return;
	}

//	if(taken <= N)
//	{
//		if(taken >= mx)
//		{
//			mx = taken;
//			ans = vi;
//			PF("%d\n", mx);
//		}
//	}

	vi.PB(ar[pos]);
	F(pos + 1, T, taken + ar[pos], N, vi);
	vi.pop_back();
	F(pos + 1, T, taken, N, vi);

}



int main()
{
	///BOOST
	///READ();
	///WRITE();
	int T, I, J, K, N, n, m, cnt = 0, len;

	while(SF("%d%d", &N, &T) != EOF)
	{
		vector<int> vi;
		ans.clear();
		mx = 0;


		int sum = 0;
		for(I = 0; I < T; I++)
		{
			SF("%d", &ar[I]);
			sum += ar[I];

		}

        if(sum <= N)
		{
			for(I = 0; I < T; I++)
				PF("%d ", ar[I]);

			PF("sum:%d\n", sum);

		}
		else
		{
			F(0, T, 0, N, vi);

			n = ans.size();

			for(I = 0; I < n; I++)
				PF("%d ", ans[I]);

			PF("sum:%d\n", mx);

		}

	}


	return 0;
}




