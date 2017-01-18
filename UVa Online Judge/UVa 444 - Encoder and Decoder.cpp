// UVa 444 - Encoder and Decoder.cpp
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

int const _size = 100;
char message[_size];

int main()
{
	while (fgets(message, _size, stdin) != NULL) {
		int len = strlen(message);
		if (message[len - 1] != '\0')
			message[len - 1] = '\0';
		len--;
		
		int I;
		if (message[0] >= 65 && message[0] <= 90 || message[0] >= 97 && message[0] <= 122 || message[0] == 32 
			|| message[0] == 33 || message[0] == 44 ||message[0] == 46 || message[0] == 58 || message[0] == 59  || message[0] == 63) {
			for (I = len - 1; I >= 0; I--) {
				int  decimal = message[I];
				while (decimal > 0) {
					int ascii = decimal % 10;
					printf("%d", ascii);
					decimal /= 10;
				}
			}
		}
		else {
			int c = 0;
			reverse(message, message + len);
			for (I = 0; I < len; I++) {
				c = c * 10 + message[I] - 48;
				if (c >= 65 && c <= 90 || c >= 97 && c <= 122 || c == 32|| c == 33 || c == 44 || c == 46 
					|| c == 58 || c == 59 || c == 63) {
					printf("%c", c);
					c = 0;
				}
			}
		}
		printf("\n");
	}

	return 0;
}

