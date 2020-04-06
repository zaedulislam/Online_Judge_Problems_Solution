// ID 1 - Multiples of 3 and 5.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
typedef unsigned long long llu;

int main()
{
	int sum = 0;
	int three = 0, five = 0;
	while(three + 3 < 1000) {
		three += 3;
		sum += three;
	}
	while (five + 5 < 1000) {
		five += 5;
		if (five % 3 == 0)
			continue;
		sum += five;
	}
	printf("%d\n", sum);
	return 0;
}