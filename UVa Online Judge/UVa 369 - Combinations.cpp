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
	int n, r,temp;
	while (1) {
		scanf("%d%d", &n, &r);
		temp = r;
		if (n == 0 && r == 0)
			break;
		if (r == n - 1 || r == 1) {
			printf("%d things taken %d at a time is %d exactly.\n", n, r, n);
			continue;
		}
		if (r > (n >> 1))
			r = n - r;

		int numerator, denominator = 1;
		llu res = 1;
		for (numerator = 0; numerator < r; numerator++) {
			res = res * (n - numerator);
			res = res / (denominator + numerator);
		}
		printf("%d things taken %d at a time is %llu exactly.\n", n, temp, res);
	}

	return 0;
}


