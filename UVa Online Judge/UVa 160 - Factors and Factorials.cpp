 // UVa - 160 Factors and Factorials.cpp

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const int MAX = 25;
int prime[MAX] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
int factors[30];

void factors_and_factorials(int n) {
	int temp,_count;
	int N = n;
	while (n > 1) {
		temp = n;
		int i = 0;
		for (; i < MAX && prime[i] <= temp; i++) {
			_count = 0;
			if (temp % prime[i] == 0) {
				while (temp%prime[i] == 0) {
					temp /= prime[i];
					_count++;
				}
				factors[i] +=_count;
			}	
		}
		n--;
	}

	printf("%3d! =",N);
	int i;
	int flag = false;
	for (i = 0; factors[i] != 0; i++) {
		if (i >= 15) {
			if (!flag) {
				printf("\n");
				printf("      ");
			}
			flag = true;
			printf("%3d", factors[i]);
		}
		else
			printf("%3d", factors[i]);
	}
	printf("\n");
	memset(factors, 0, sizeof(factors));
}

int main()
{
	int n;
	while (1){
		scanf("%d", &n);
		if (n == 0)
			break;
		factors_and_factorials(n) ;
	}
	return 0;
}

