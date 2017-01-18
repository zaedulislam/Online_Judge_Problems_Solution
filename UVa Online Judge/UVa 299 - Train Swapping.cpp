// UVa 299 - Train Swapping.cpp
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
const int _size = 100;
int a[_size];

int main()
{
	int testCase, num, _count;
	scanf("%d", &testCase);

	while (testCase--) {
		_count = 0;
		scanf("%d", &num);
		int I, K;
		for (I = 0; I< num; I++)
			scanf("%d", &a[I]);

		int temp;
		for (I = 0; I < num; I++)
			for (K = 0; K < num - 1; K++)
			if (a[K + 1] < a[K]) {
				_count++;
				temp = a[K + 1];
				a[K + 1] = a[K];
				a[K] = temp;
			}
		printf("Optimal train swapping takes %d swaps.\n", _count);
	}
	return 0;
}