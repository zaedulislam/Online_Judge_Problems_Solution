// SPOJ ADDREV - Adding Reversed Numbers.cpp

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;

int reverse(int n)
{
	int rev = 0, remainder;
	while (n>0) {
		remainder = n % 10;
		n /= 10;
		rev = rev * 10 + remainder;
	}
	return rev;
}

int main()
{
	int num1, num2;
	int testCase;
	scanf("%d", &testCase);

	while (testCase--) {
		scanf("%d%d", &num1, &num2);

		int ans1 = reverse(num1);
		int ans2 = reverse(num2);
		int add = ans1 + ans2;
		int final_add = reverse(add);
		printf("%d\n", final_add);
	}
	return 0;
}


