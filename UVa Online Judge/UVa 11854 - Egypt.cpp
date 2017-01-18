// UVa 11854 - Egypt.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cctype>
#include<cmath>
#include<stack>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<algorithm>
#include<vector>
typedef unsigned long long llu;
#define  ll long long
using namespace std;
const double PI = 2 * acos(0.0);
const double EPS = 1e-9;
const int sz = 100;

int max(int a,int b){
    return (a > b) ? a : b;
}
int min(int a,int b){
    return (a < b) ? a : b;
}
 inline int _pow(int base, int power){
	int I,result = base;
	for (I = 0; I < power - 1; I++) {
		result = result * base;
	}
	return result;
}

// Driver function
int main()
{
	ll s1,s2,s3;

	while(1){
		scanf("%lld%lld%lld",&s1,&s2,&s3);

		if(s1 == 0 && s2 == 0 && s3 == 0)
			break;

		if( s1 * s1 + s2 * s2 == s3 * s3)
			printf("right\n");
		else if(s1 * s1 + s3 * s3 == s2 * s2)
			printf("right\n");
		else if(s3 * s3 + s2 * s2 == s1 * s1)
			printf("right\n");
		else
			printf("wrong\n");
	}

	return 0;
}
