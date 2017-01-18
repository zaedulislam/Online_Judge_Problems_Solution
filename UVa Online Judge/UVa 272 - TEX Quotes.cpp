// UVa 272 – TEX Quotes.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const int sz = 1e5;
char str[sz];

int main()
{
	long int flag = 0;
	while (fgets(str, sz, stdin) != NULL) {
		long int len = strlen(str);
		if (str[len - 1] != '\0')
			str[len - 1] = '\0';
		len--;
		
		long int i;
		for (i = 0; i < len; i++) {
			if (str[i] == '"') {
				flag++;
				if (flag % 2 == 0)
					printf("''");
				else
					printf("``");
			}
			else
				printf("%c", str[i]);
		}
		printf("\n");
	}
	return 0;
}


