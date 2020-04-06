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

int main()
{
	long long a, b;
	int testCase;
	scanf("%d", &testCase);
	while (testCase--) {
		scanf("%lld%lld", &a, &b);
		if (a > b)
			printf(">\n");
		else if (a < b)
			printf("<\n");
		else if (a == b)
			printf("=\n");
	}

	return 0;
}