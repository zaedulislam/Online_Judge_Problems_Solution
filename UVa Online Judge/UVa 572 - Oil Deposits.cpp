// UVa 572 - Oil Deposits.cpp
// Hints: Find the Connected Components (Oil Deposits)
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
using namespace std;

int caseno = 1;
#define NL '\n'
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
#define SF scanf
#define PF printf
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define PC() printf("Case %d: ", caseno++)
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

#define INF 2147483647
#define MOD 1000000007
#define pii pair < int, int >
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 100 + 10;

string G[SIZE];
int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1};
int visited[SIZE][SIZE], row, col;
queue < pii > qi;

void BFS(int x, int y)
{
	while(!qi.empty())
		qi.pop();

    visited[x][y] = 1;
    qi.push(pii(x, y));

    pii xy;
    int I, ux, uy, nx, ny;
    while(!qi.empty())
	{
		xy = qi.front();
		qi.pop();

		ux = xy.first;
		uy = xy.second;

		for(I = 0; I < 8; I++)
		{
			nx = ux + dx[I];
			ny = uy + dy[I];

			if(nx >= 0 && nx < row && ny >= 0 && ny < col && visited[nx][ny] == 0 && G[nx][ny] == '@')
			{
				visited[nx][ny] = 1;
				qi.push(pii(nx, ny));
			}
		}
	}
}

int main()
{
	///BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, sx, sy;
	///READ();
	///WRITE();
	while(SF("%d%d", &row, &col), (row || 0))
	{
		for(I = 0; I <= row; I++)
			G[I].clear();

		memset(visited, 0, sizeof(visited));

		for(I = 0; I < row; I++)
			cin >> G[I];

		cnt = 0;
		for(I = 0; I < row; I++)
		{
			for(K = 0; K < col; K++)
			{
				sx = I;
				sy = K;
				if(visited[sx][sy] == 0 && G[sx][sy] == '@')
				{
					///cout << "SX = " << sx << " SY = " << sy << NL;
					BFS(sx, sy);
					cnt++;
					///cout << cnt << NL;
				}
			}
		}
		PF("%d\n", cnt);
	}

	return 0;
}

/*
7 6
@*@@**
**@@@@
@**@*@
@@*@**
*@***@
**@@**
*@*@@*
*/
