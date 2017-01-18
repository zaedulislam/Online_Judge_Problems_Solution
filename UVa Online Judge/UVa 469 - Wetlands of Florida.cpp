// UVa 469 - Wetlands of Florida.cpp

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
#define PC() printf("Case %d: ", caseno++)
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
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
typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64
///************************************************************///
// Numeric Functions
// Translator Functions
int toInt(string s){ int r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:toInt(
///************************************************************///

/*
*******4 Direction Array*******
int dx[] = {0, 0, - 1, 1}, dy[] = {-1, 1, 0, 0};
*******8 Direction Array*******
int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1};
********Knight Moves********
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};
*/

const int SIZE = 100 + 10;

string S, G[SIZE], X, Y;
int visited[SIZE][SIZE], row, col, cnt;
int dx[] = { 0, 0, -1, +1, -1, -1, +1, +1 }, dy[] = { -1, +1, 0, 0, -1, +1, -1, +1 };
queue<pii> qi;

int BFS(int sx, int sy)
{
	while (!qi.empty())
		qi.pop();

	if (G[sx][sy] == 'W')
		cnt++;

	visited[sx][sy] = 1;
	qi.push(pii(sx, sy));

	pii temp;
	int I, ux, uy, nx, ny;
	while (!qi.empty())
	{
		temp = qi.front();
		qi.pop();

		ux = temp.first;
		uy = temp.second;

		for (I = 0; I < 8; I++)
		{
			nx = ux + dx[I];
			ny = uy + dy[I];

			if (visited[nx][ny] == 0 && G[nx][ny] == 'W' && nx >= 0 && nx < row && ny >= 0 && ny < col)
			{
				cnt++;
				visited[nx][ny] = 1;
				qi.push(pii(nx, ny));
			}
		}
	}
	return cnt;
}

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, len, x, y, w, got, f;
	///READ();
	///WRITE();
	cin >> tcases;

	cin.ignore();	// Consume the endline after the test case number.
	getline(cin, S);	// Consume the blank line.

	while (tcases--)
	{
		for (I = 0; I < SIZE; I++)
			G[I].clear();

		/* Input Parsing */
		I = 0, got = 0, f = 0;
		while (1)
		{
			getline(cin, S);

			if(S[0] != 'W' && S[0] != 'L')
			{
				got = 1;
				break;
			}

			G[I] = S;

			if(f == 0)
			{
				col = S.length();
				f = 1;
			}
			I++;
		}
		row = I;

		while (1)
		{
			X = "", Y = "";

			if(got == 1)
				got = 0;
			else
				getline(cin, S);

			if (S.empty())
				break;

			f = 0;
			len = S.length();

			for (I = 0; I < len; I++)
			{
				if (S[I] == ' ')
				{
					f = 1;
					continue;
				}

				if (f == 0)
					X += S[I];
				else
					Y += S[I];
			}
			x = toInt(X);
			y = toInt(Y);

			/* Input Parsing */

			memset(visited, 0, sizeof(visited));

			cnt = 0;
			w = 0;
			w += BFS(x - 1, y - 1);
			cout << w << NL;
		}

		if(tcases)
			cout << NL;
	}

	return 0;
}
