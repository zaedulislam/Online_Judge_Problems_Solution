// UVa 11332 - Summing Digits.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cctype>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
#include<algorithm>
#include<vector>
typedef unsigned long long llu;
using namespace std;


int digitSum(long long int n){
	int sum = 0;
	while(n > 0){
		sum +=n % 10;
		n /=10;
	}
	return sum;
}

int main()
{
	long long int input;
	while(scanf("%lld",&input) != EOF){
		if(input == 0)
			break;

		while(input > 9 ){
			input = digitSum(input);
		}
	printf("%lld\n",input);
	}
	return 0;
}
