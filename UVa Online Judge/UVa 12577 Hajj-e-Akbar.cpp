// UVa 12577 Hajj-e-Akbar.cpp
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;

const int arraySize = 10;
char str[arraySize];

int main()
{
	int _case = 1;
	while (true) {
		int i = 0;
		fgets(str, arraySize, stdin);
		int len = strlen(str);
		if (str[len - 1] != '\0')
			str[len - 1] = '\0';
		len--;
		if (str[i] == '*')
			break;
		printf("Case %d: ", _case);
		if (strcmp(str, "Hajj") == 0)
			printf("Hajj-e-Akbar\n");
		else if (strcmp(str, "Umrah") == 0)
			printf("Hajj-e-Asghar\n");
		_case++;
	}
	return 0;
}
