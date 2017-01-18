// Codeforces 735A - Ostap and Grasshopper.cpp
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
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e6;
///************************************************************///

string S;
int ar[SIZE];

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, k;
	///READ();
	///WRITE();
    cin >> n >> k;
    cin >> S;

    int G = 0, T = 0;
    for(I = 0; I < n; I++)
    {
        if(S[I] == 'G')
            G = I;
        else if(S[I] == 'T')
            T = I;
    }
    ///cout << "G = " << G << " T = " << T << NL;

    int f = 0;
    if(G < T)
    {
        for(I = G; I <= T; I += k)
        {
            if(I < n && S[I] == 'T')
            {
                f = 1;
                break;
            }
            else if(I < n && S[I] == '#')
                break;
        }
    }
    else
    {
        for(I = G; I >= T; I -= k)
        {
            if(I >= 0 && S[I] == 'T')
            {
                f = 1;
                break;
            }
            else if(I >= 0 && S[I] == '#')
                break;
        }
    }

    if(f == 1)
        cout << "YES\n";
    else
        cout << "NO\n";

	return 0;
}