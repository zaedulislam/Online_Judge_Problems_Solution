// UVa 11462 - Age Sort.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
#include<algorithm>
typedef unsigned long long llu;
using namespace std;

int main()
{
	int *age;
	int numPeople;
	while (1) {
		scanf("%d",&numPeople);
		if (numPeople == 0)
			break;
		age = new int[numPeople];

		int I;
		for (I = 0; I < numPeople; I++)
			scanf("%d", &age[I]);

		sort(age, age + numPeople);
		
		for (I = 0; I < numPeople; I++) {
			if (I == numPeople - 1) {
				printf("%d", age[I]);
				break;
			}
			printf("%d ", age[I]);
		}
		printf("\n");
	}
	return 0;
}
