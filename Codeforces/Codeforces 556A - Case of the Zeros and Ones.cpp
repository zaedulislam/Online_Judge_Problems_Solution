// Codeforces 556A - Case of the Zeros and Ones.cpp
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


const int _size = 2*1e5 + 10;
char str[_size];

int main()
{
	int length;
	char iFalse;
	scanf("%d%c", &length,&iFalse);
	fgets(str, _size, stdin);
	int len = strlen(str);
	if (str[len - 1] != '\0')
		str[len - 1] = '\0';
	len--;

	int I,zero = 0 ,one = 0;
	for (I = 0; I < len; I++) {
		if (str[I] == '0')
			zero++;
		else
			one++;
		}
	if (one < zero)
		printf("%d\n", length - 2 * one);
	else
		printf("%d\n", length - 2 * zero);

	return 0;
}