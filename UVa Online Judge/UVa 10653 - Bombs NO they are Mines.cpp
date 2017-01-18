// UVa 10653 - Bombs! NO they are Mines!!.cpp
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
const int SIZE = 1000 + 10;
///************************************************************///

int M[SIZE][SIZE], row, col;
int visited[SIZE][SIZE], dis[SIZE][SIZE];
int dx[] = {0, 0, - 1, 1}, dy[] = {-1, 1, 0, 0};
queue<pii> qi;

int BFS(int sx, int sy, int fx, int fy)
{
    while(!qi.empty())
        qi.pop();

    visited[sx][sy] = 1;
    dis[sx][sy] = 0;
    qi.push(pii(sx, sy));

    pii temp;
    int I, ux, uy, nx, ny;
    while(!qi.empty())
    {
        temp = qi.front();
        qi.pop();

        ux = temp.first;
        uy = temp.second;

        for(I = 0; I < 4; I++)
        {
            nx = ux + dx[I];
            ny = uy + dy[I];

            if(nx >= 0 && nx <= row && ny >= 0 && ny <= col && visited[nx][ny] == 0 && M[nx][ny] != -1)
            {
                visited[nx][ny] = 1;
                dis[nx][ny] = dis[ux][uy] + 1;

                if(nx == fx && ny == fy)
                    return dis[fx][fy];

                qi.push(pii(nx, ny));
            }
        }
    }
}

int main()
{
	///BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, sx, sy, fx, fy, r, c;
	///READ();
	///WRITE();
    while(SF("%d%d", &row, &col))
    {
        if(row == 0 && col == 0)
            break;

        row--;
        col--;

        memset(visited, 0, sizeof(visited));
        memset(dis, 0, sizeof(dis));
        memset(M, 0, sizeof(M));

        SF("%d", &N);

        for(I = 0; I < N; I++)
        {
            SF("%d%d", &r, &n);
            for(K = 0; K < n; K++)
            {
                SF("%d", &c);
                M[r][c] = -1;
            }
        }

        SF("%d%d", &sx, &sy);
        SF("%d%d", &fx, &fy);

        int t = BFS(sx, sy, fx, fy);
        PF("%d\n", t);
    }

	return 0;
}


