// UVa 11715 - Car.cpp
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

int main()
{
	///BOOST
	int tcase, I, J, K, N, n, m, cnt = 0, len;
	double u, v, a, s, t;
	///READ();
	///WRITE();
	while(SF("%d", &tcase), (tcase || 0))
	{
		PC();

		/// Case 1
		if(tcase == 1)
		{
			SF("%lf %lf %lf",&u, &v, &t);
			/*
				v = u + a * t
			=> a * t = v - u
			=> a = (v - u) / t
			*/
			a = (v - u) / t;

			/*
				s = u * t + (1/2) * a * t^2
			*/
			s = u * t + (0.5) * a * (t * t);

			PF("%0.3lf %0.3lf\n", s, a);

		}
		/// Case 2
		else if(tcase == 2)
		{
			SF("%lf %lf %lf",&u, &v, &a);
			/*
				v = u + at
			=> a * t = v - u
			=> t = (v - u) / a
			*/
			t = (v - u) / a;

			/*
				s = ut + (1/2) *a * t^2
			*/
			s = u * t + (0.5) * a * (t * t);

			PF("%0.3lf %0.3lf\n", s, t);

		}
		/// Case 3
		else if(tcase == 3)
		{
			SF("%lf %lf %lf",&u, &a, &s);
			/*
				v^2 = u^2 + 2 * a * s
			=> v = sqrt(u ^ 2 + 2 * a * s)
			*/
			v = sqrt((u * u) + 2  * a * s);

			/*
				v = u + a * t
			=> t = (v - u) / a
			*/
			t = (v - u)  / a;

			PF("%0.3lf %0.3lf\n", v, t);

		}
		/// Case 4
		else if(tcase == 4)
		{
			SF("%lf %lf %lf",&v, &a, &s);
			/*
				v^2 = u ^2 + 2 * a * s
			=> u^2 = v^2 - 2 * a * s
			=> u = sqrt(v^2 - 2 * a * s)
			*/
			u = sqrt((v * v) - 2 * a * s);

			/*
				v = u + a * t
			=> a * t = v - u
			=> t = (v - u) / a
			*/
			t = (v - u) / a;

			PF("%0.3lf %0.3lf\n", u, t);

		}
	}

	return 0;
}

