// SPOJ LASTDIG - The last digit.cpp
#include<cstdio>
#include<iostream>
using namespace std;
#define SF scanf
#define PF printf

int bigMod(int b, int P)
{
	int res = 1 % 10, base = b % 10;
	while(P > 0)
	{
		if(P & 1)
			res = (res * base) % 10;

		P >>= 1;
		base = (base * base) % 10;
	}
	return res;
}

int main()
{
	int tcases, I, J, K, N, n, m, cnt = 0, len, b, P;
	SF("%d", &tcases);
	while(tcases--)
	{
		SF("%d%d", &b, &P);
		PF("%d\n", bigMod(b, P));
	}
	return 0;
}

