// UVa 11716 - Digital Fortress.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cctype>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
#include<algorithm>
#include<vector>
typedef unsigned long long llu;
using namespace std;

int const _size = 10010;
char cipher[_size];


int main()
{
	int testCase;
	char iFalse;
	scanf("%d%c", &testCase,&iFalse);
	while (testCase--) {
		cin.getline(cipher, _size);
		int len = strlen(cipher);
		int sqrtlen = floor(sqrt((double)len));
		int squareSide;
		
		if (sqrtlen * sqrtlen == len)
			squareSide = sqrtlen;
		else {
			printf("INVALID\n");
			continue;
		}
			
		int I,K;
		for (I = 0; I < squareSide; I++) {
			for (K = I; K < len; K += squareSide) 
					printf("%c", cipher[K]);
		}
		printf("\n");
	}
	return 0;
}

