// UVa 374 - Big Mod.cpp
// C++ Program to Implement Modular Exponentiation Algorithm

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
//#define ll long long
using namespace std;

// Function to calculate modulus of x raised to the power y

long long int bigMod(long long int base, long long int exponent, int modulus)
{
	long long int result = 1;
	while (exponent > 0){
		if (exponent % 2 == 1) 
			result = (result * base) % modulus;
   		exponent = exponent >> 1;
		base = (base * base) % modulus;
	}
	return result;
}

int main()
{
	long long int B, P;
	int mod;
	while (scanf("%lld%lld%d",&B,&P,&mod) != EOF) {
		printf("%d\n", bigMod(B, P, mod));
	}
	
	return 0;
}