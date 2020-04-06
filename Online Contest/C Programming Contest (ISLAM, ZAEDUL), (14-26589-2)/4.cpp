// 4.cpp
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
using namespace std;

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

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e6;

int main()
{
	//BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, left, right, f;
	//READ();
	//WRITE();
	while(SF("%d", &n) != EOF)
	{
		/// UP
		left = n, right = n + 1, f = 0;
		for(I = 0; I < n; I++)
		{
			f = 0;
			///cout << "R = " << right << NL;
			for(K = 1; K <= n * 2; K++)
			{
				if(left == K)
				{
					PF("/");
					left--;
				}
				else if(right == K && f == 0)
				{
					PF("\\");
					right++;
					f = 1;
					///cout << "R = " << right << NL;
				}
				else
					PF("-");
			}
			PF("\n");
		}


		/// DOWN
		left = 1, right = n * 2, f = 0;
		for(I = 0; I < n; I++)
		{
			f = 0;
			///cout << "R = " << right << NL;
			for(K = 1; K <= n * 2; K++)
			{
				if(left == K && f == 0)
				{
					PF("\\");
					left++;
					f = 1;
				}
				else if(right == K)
				{
					PF("/");
					right--;
					///cout << "R = " << right << NL;
				}
				else
					PF("-");
			}
			PF("\n");
		}
	}

	return 0;
}

