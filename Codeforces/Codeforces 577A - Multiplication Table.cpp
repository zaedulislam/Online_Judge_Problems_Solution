// Codeforces 577A - Multiplication Table.cpp
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
    int I,n,x,res = 0;
    scanf("%d%d",&n,&x);
    for( I = 1; I <= n; I++){
		if(x % I == 0 && x / I <= n)
			res++;
    }
	printf("%d\n",res);
	return 0;
}
