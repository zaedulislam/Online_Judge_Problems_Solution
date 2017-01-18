// Codeforces 580A - Kefa and First Steps.cpp
#include<iostream>
#include<cstdio>

#include<cstring>
#include<string>
#include<sstream>

#include<cmath>
#include<cstdlib>
#include<cctype>
#include<ctime>

#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

#define  LL long long
#define MAX 100005
#define MOD 1000000007

#define NL '\n'

typedef unsigned long long llu;
using namespace std;

const double PI = 2 * acos(0.0);
const double EPS = 1e-9;
const int sz = 1e5 + 10;

// My Code Template Goes Here
int max(int a, int b){
	return (a > b) ? a : b;
}
int min(int a, int b){
	return (a < b) ? a : b;
}
inline int _pow(int base, int power){
	int I, result = base;
	for (I = 0; I < power - 1; I++) {
		result = result * base;
	}
	return result;
}
// My Code Template Goes Here

int arr[sz];

int main()
{
	int n, I, _count, max = 1;
	scanf("%d", &n);
	for (I = 0; I < n; I++)
		scanf("%d", &arr[I]);

	for (I = 0; I < n; I++){
		if (arr[I + 1] >= arr[I]){
			_count = 1;
			while (arr[I + 1] >= arr[I]){
				I++;
				_count++;
			}
			if (_count > max)
				max = _count;
		}
	}
	printf("%d\n", max);
	return 0;
}

/*
// Time Complexity O(n)
int arr[sz];

int main()
{
	int n,I,M = 0,_count;
	scanf("%d", &n);

	for (I = 0; I < n; I++)
		scanf("%d", &arr[I]);
	_count = 1;

	for (I = 0; I < n; I++){
		if (arr[I + 1] >= arr[I])
			_count++;
		else{
			M = _max(M,_count);
			_count = 1;
		}
	}
	printf("%d\n",M);

	return 0;
}
*/