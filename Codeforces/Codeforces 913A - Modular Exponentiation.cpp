// Codeforces 913A - Modular Exponentiation.cpp

#include <bits/stdc++.h>
using namespace std;
#define LL long long


inline LL POW(LL base, LL power){
	LL res = base; if (power == 0) return 1;
	for (int I = 0; I < power - 1; I++) res *= base; return res;
}


int main()
{

	LL T, I, J, K, N, n, m, k, cnt = 0, len;

	cin >> n >> m;

	LL p = 1;
	while(1)
	{
		if(p > n)
		{
			cout << m % N << '\n';
			return 0;
		}

		N = POW(2, p);

		if(N > m)
		{
			cout << m << '\n';
			return 0;
		}

		p++;
	}


	return 0;
}
