// UVa 530 - Binomial Showdown.cpp

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;

int main()
{
	int n, r;
	while (1) {
		scanf("%d%d", &n, &r);
		if (n == 0 && r == 0)
			break;
		if (r == n - 1 || r == 1) {
			printf("%d\n", n);
			continue;    
		}
		if( r > (n / 2))
			r = n - r;

		unsigned long long res = 1;
		int i,numerator,denominator = 1;
		for (numerator = 0 ; numerator < r; numerator++) {
			res *= (n - numerator);
			res /= (denominator + numerator);
		}
		printf("%llu\n", res);
	}
	return 0;
}