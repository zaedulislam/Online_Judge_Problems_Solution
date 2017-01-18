// UVa 10055 - Hashmat the Brave Warrior.cpp

#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long int  a, b;
	while (scanf("%lld %lld", &a, &b) == 2)
	{
		if (a>b)
			printf("%lld\n", a - b);
		else
			printf("%lld\n", b - a);
	}
	return 0;
}