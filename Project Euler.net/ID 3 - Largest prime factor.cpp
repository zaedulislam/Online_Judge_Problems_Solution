// ID 3 - Largest prime factor.cpp
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
	llu number = 600851475143;
	
	int P,max = 0;
	for (P = 2; P <= number / P; ++P) {
		if (number % P == 0) {
			if (max < P)
				max = P;
			while (number % P == 0)
				number /= P;
		}
	}
	if (number > 1) {
		if (max < number)
			max = number;
	}

	printf("%d\n", max);
	return 0;
}