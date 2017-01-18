//UVa 10408 - Farey sequences.cpp

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

void fareySequences(long long order,long long k_term) 
{
	long long int numerator, denominator, previous_n, previous_d;
	long long int  h, k, temp;
	long long int _count;
	numerator = 0;
	denominator = 1;

	h = 1; 
	k = order;
	_count = 0;
	
	while (_count != k_term) {
		temp = (order + denominator) / k;
		
		previous_n = numerator;
		previous_d = denominator;
		
		numerator = h;
		denominator = k;

		h = temp * h - previous_n;
		k = temp * k - previous_d;
		_count++;
	}
	printf("%lld/%lld\n", numerator, denominator);
}

int main()
{
	long long int order, k_term;
	while (scanf("%lld %lld", &order, &k_term) != EOF) 
		fareySequences(order,k_term);
	return 0;
}

