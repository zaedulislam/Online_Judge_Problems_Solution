// UVa 10082 - WERTYU.cpp

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

const int _size = 10000;
char str[_size];
char digit[] = "`1234567890-=";
char alphabet[] = "QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";


int main()
{
	while (fgets(str, _size, stdin) != NULL) {
		int len = strlen(str);
		if (str[len - 1] != '\0')
			str[len - 1] = '\0';
		len--;

		int I, K;
		for (I = 0; I < len; I++) {
			if (str[I] == ' ')
				printf(" ");
			else if ((str[I] >= '0' && str[I] <= '9') || str[I] == '-' || str[I] == '=') {
				for (K = 0; K < strlen(digit); K++) {
					if (str[I] == digit[K])
						printf("%c", digit[K - 1]);

				}
			}
			else {
				for (K = 0; K < strlen(alphabet); K++) {
					if (str[I] == alphabet[K])
						printf("%c", alphabet[K - 1]);

				}
			}
		}
		printf("\n");
	}

	return 0;
}
