// UVa 10922 - 2 the 9s.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int sz = 1e4 + 10;
char str[sz];

int main()
{
	int sum,degree,digitSum,temp;
	while (1) {
		fgets(str, sz, stdin);
		int len = strlen(str);
		if (str[len - 1] != '\0')
			str[len - 1] = '\0';
		len--;
		if (str[0] == '0' && len == 1)
			break;
		sum = 0,degree = 1;
		int i;
		for (i = 0; i < len; i++)
			sum += str[i] - '0';
		if (sum % 9 != 0)
			printf("%s is not a multiple of 9.\n", str);
		else {
			if (sum % 9 == 0) {
				temp = sum;
				while(temp != 9 && temp > 9) {
					digitSum = 0;
					while (temp != 0) {
						digitSum += temp % 10;
						temp /= 10;
					}
					temp = digitSum;
					degree++;
				}
				printf("%s is a multiple of 9 and has 9-degree %d.\n", str, degree);
			}
		}
	}
	return 0;
}
