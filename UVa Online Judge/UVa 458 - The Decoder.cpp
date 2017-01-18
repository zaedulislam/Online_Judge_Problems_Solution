// UVa 458 - The Decoder.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
#include<algorithm>
#include<vector>
typedef unsigned long long llu;
using namespace std;

int const _size = 1000;
char decode[_size];

int main()
{
	while (fgets(decode, _size, stdin) != NULL) {
		int len = strlen(decode);
		if (decode[len - 1] != '\0')
			decode[len - 1] = '\0';
		len--;
		int I;
		for (I = 0; I < len; I++)
			printf("%c", decode[I] - 7); 
		printf("\n");
	}

	return 0;
}

