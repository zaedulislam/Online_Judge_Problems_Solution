// UVa 10929 – You can say 11.cpp
// Algorithm
// For this problem use a string to handle input, even unsigned long long can’t hold a large number containing 1000 digits.
// We can check if a large number is divisible by another number by subtracting the sum of even index number 
// from odd index numbers.For example,

// if, ABCD, A - B + C - D % N == 0, then the number is divisible by N
// if, 2937, 2 - 9 + 3 - 7 % 11 == -11 % 11 = 0, So, 2937 is divisible by 11

#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;

const int sz = 1e3 + 10;
static char str[sz];

int main()
{
	long long  int len,sum;
	while (1) {
		/*fgets(str, sz, stdin);*/
		scanf("%s", str);
		sum = 0;
  		len = strlen(str);
	/*	if (str[len - 1] != '\0')
			str[len - 1] == '\0';
		len--;*/
		if (str[0] == '0' && len == 1)
			break;
		long long int i;
		for (i = 0; i < len; i += 2)
			sum += str[i] - '0';
		
		for (i = 1; i < len; i += 2)
			sum -= str[i] - '0';
		
		if (sum % 11 == 0) 
			printf("%s is a multiple of 11.\n",str);
		else 
			printf("%s is not a multiple of 11.\n",str);
	}
	return 0;
}

