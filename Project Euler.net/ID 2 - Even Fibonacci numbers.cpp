// ID 2 - Even Fibonacci numbers.cpp
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
	int first_term = 1;
	int second_term = 2;
	int sum = 0,fib = 0;
	
	while (fib < 4e6) {
		fib = first_term + second_term;
		if (fib % 2 == 0)
			sum += fib;
		first_term = fib - first_term;
		second_term = fib;

	}
	printf("\n%d\n", sum + 2);
	return 0;
}