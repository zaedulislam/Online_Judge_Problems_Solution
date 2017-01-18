// Codeforces 681B - Economy Game.cpp
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
#include <cstdlib>
#include <ctime>

int caseno = 1;
#define NL '\n'
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
#define SF scanf
#define PF printf
#define PC() printf("Case %d: ", caseno++)
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);
using namespace std;

// BEGINTEMPLATE_BY_ZAYED
typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e6;

int house = 1234567, car = 123456, computer = 1234;

int main()
{
	BOOST
	LL tcases, I, J, K, N, n, m, cnt = 0, len, a, b, c, tmp, coins;
	//READ();
	//WRITE();
    cin >> n;
    for(a = 0; a <= 811; a++)
    {
        for(b = 0; b <= 8101; b++)
        {
            coins = a * house + b * car;
            if(coins <= n)
            {
                tmp = n - coins;
                if(tmp % computer == 0)
                {
                    cout << "YES\n";
                    return 0;
                }
            }
        }
    }
    cout << "NO\n";

	return 0;
}

