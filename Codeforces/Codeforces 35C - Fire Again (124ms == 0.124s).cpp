// Codeforces 35C - Fire Again (124ms == 0.124s).cpp

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

*******8 Direction Array*******
int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1};
********Knight Moves********
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};
*/

//*******4 Direction Array*******
int dx[] = {0, 0, - 1, 1}, dy[] = {-1, 1, 0, 0};
int N, M, fx, fy;
const int SIZE = 2000 + 10;
bool visited[SIZE][SIZE];
queue<pii> Q;




void BFS()
{
	int I, x, y, nx, ny;
	while(!Q.empty())
	{
		pii temp = Q.front();
		Q.pop();

		x = temp.first;
		y = temp.second;

		fx = x;
		fy = y;

		for(I = 0; I < 4; I++)
		{
			nx = x + dx[I];
			ny = y + dy[I];

			if(nx >= 1 && nx <= N && ny >= 1 && ny <= M && !visited[nx][ny])
			{
				visited[nx][ny] = true;
				Q.push(pii(nx, ny));
			}

		}

	}

}



int main()
{
	BOOST
	READ();
	WRITE();
	int T, I, J, K, n, m, k, cnt = 0, len, x, y;


	cin >> N >> M >> K;

	for(I = 0; I < K; I++)
	{
		cin >> x >> y;
		visited[x][y] = true;
		Q.push(pii(x, y));
	}

	BFS();

	cout << fx << ' ' << fy << NL;



	return 0;
}




