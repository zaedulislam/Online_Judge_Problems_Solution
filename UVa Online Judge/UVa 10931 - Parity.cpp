// UVa 10931 - Parity.cpp

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
typedef long long ll;
using namespace std;

int _count;
void decimal_binary(int decimal)
{
	int remainder;
	if (decimal <= 1){
		printf("%d", decimal);
		return;
	}
	remainder = decimal % 2;
	if (remainder == 1)
		_count++;
	decimal_binary(decimal >> 1);
	printf("%d", remainder);
}

int main()
{
	int decimal, binary;
	while (1) {
		scanf("%d", &decimal);
		if (decimal == 0)
			break;
		_count = 1;
		printf("The parity of ");
		decimal_binary(decimal);
		printf(" is %d (mod 2).", _count);
		printf("\n");
	}

	return 0;
}