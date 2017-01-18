// Codeforces 432A - Choosing Teams.cpp
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
const int sz = 2000 + 10;

// My Code Template Goes Here
int _max(int a, int b){
	return (a > b) ? a : b;
}
int _min(int a, int b){
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

int a[sz];

int main()
{
	int I,n,k,_count = 0;
	scanf("%d%d",&n,&k);

	for(I = 0; I < n; I++)
		scanf("%d",&a[I]);

	for(I = 0; I < n; I++){
		if(5 - a[I] >= k)
			_count++;
	}
	int ans = _count / 3;

	printf("%d\n",ans);

	return 0;
}
