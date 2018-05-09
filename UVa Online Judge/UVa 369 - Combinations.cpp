// UVa 369 -  Combinations.cpp

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
typedef unsigned long long llu;
using namespace std;

int main()
{
	int I, n, r;
	while (1) {

		scanf("%d%d", &n, &r);

		int m = r, N = n;
        	if(n == 0 && r == 0)
			break;

		if(n - r < r)
			r = n - r;

		long long ans = 1;
		for(I = 1; I <= r; I++, n--)
		{
			ans *= n;
			ans /= I;
		}

		printf("%d things taken %d at a time is %lld exactly.\n", N, m, ans);
	}

	return 0;
}


