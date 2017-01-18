// LightOJ 1212 - Double Ended Queue.cpp
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
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e6;

deque < int > dq;
string S;

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, C, X;
	///READ();
	///WRITE();
	cin >> tcases;
	while(tcases--)
	{
		dq.clear();

		cin >> N >> C;

		cout << "Case " << caseno++ << ":\n";
		for(I = 0; I < C; I++)
		{
			cin >> S;

			if(S == "pushLeft")
			{
                cin >> X;
                if(dq.size() < N)
				{
					dq.push_front(X);
					cout << "Pushed in left: " << X;
				}
				else
					cout << "The queue is full";
			}
			else if(S == "pushRight")
			{
				cin >> X;
                if(dq.size() < N)
				{
					dq.push_back(X);
					cout << "Pushed in right: " << X;
				}
				else
					cout << "The queue is full";
			}
			else if(S == "popLeft")
			{
				if(!dq.empty())
				{
					cout << "Popped from left: " << dq.front();
					dq.pop_front();
				}
				else
					cout << "The queue is empty";
			}
			else if(S == "popRight")
			{
				if(!dq.empty())
				{
					cout << "Popped from right: " << dq.back();
					dq.pop_back();
				}
				else
					cout << "The queue is empty";
			}

			cout << NL;
		}
	}
	return 0;
}
