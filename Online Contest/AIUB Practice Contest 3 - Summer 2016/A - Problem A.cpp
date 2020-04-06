// A - Problem A.cpp
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

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e6;

char s[SIZE];

int main()
{
	//BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len;
	//READ();
	//WRITE();
	while(fgets(s, SIZE, stdin) != NULL)
	{
		int len = strlen(s);
		if(s[len - 1] != '\0')
			s[len - 1] = '\0';
		len--;

		J = 0;
		for(I = 0; I < len; I++)
		{
			if(I == len - 1)
			{
				for(K = I; K >= J; K--)
					PF("%c", s[K]);
			}
			else if(s[I] == ' ')
			{
				for(K = I - 1; K >= J; K--)
					PF("%c", s[K]);
				PF(" ");
				J = I + 1;
			}
		}
		PF("\n");
	}

	return 0;
}