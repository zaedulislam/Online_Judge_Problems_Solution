// UVa 439 - Knight Moves.cpp
///************************************************************///
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
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
#define SF scanf
#define PF printf
///************************************************************///
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define PC() printf("Case %d: ", caseno++)
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);
///************************************************************///
typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64
///************************************************************///
#define INF 2147483647
#define MOD 1000000007
#define pii pair<int, int>
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 50;
///************************************************************///

string a, b;
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};
int visited[SIZE][SIZE], level[SIZE][SIZE];
queue<pii>qi;

int BFS(int sx, int sy, int fx, int fy)
{
    while(!qi.empty())
        qi.pop();

    qi.push(pii(sx, sy));
    visited[sx][sy] = 1;
    level[sx][sy] = 0;

    pii temp;
    int I, ux, uy, nx, ny;
    while(!qi.empty())
    {
        temp = qi.front();
        qi.pop();

        ux = temp.first;
        uy = temp.second;

        for(I = 0; I < 8; I++)
        {
            nx = ux + dx[I];
            ny = uy + dy[I];

            if(nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8 && visited[nx][ny] == 0)
            {
                visited[nx][ny] = 1;
                level[nx][ny] = level[ux][uy] + 1;

                if(nx == fx && ny == fy)
                    return level[nx][ny];

                qi.push(pii(nx, ny));

            }
        }
    }
}

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, x ,y, moves;
	///READ();
	///WRITE();
    while(cin >> a >> b)
    {
        memset(visited, 0, sizeof(visited));
        memset(level, 0, sizeof(level));

        x = a[1] - '0';
        y = a[0] - 'a' + 1;

        int fx = b[1] - '0';
        int fy = b[0] - 'a' + 1;

        if(x == fx && y == fy)
            moves = 0;
        else
            moves = BFS(x, y, fx, fy);

        cout << "To get from " << a << " to " << b << " takes " << moves << " knight moves."<< NL;
    }
	return 0;
}


