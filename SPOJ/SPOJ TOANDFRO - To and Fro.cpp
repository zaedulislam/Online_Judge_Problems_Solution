// SPOJ TOANDFRO	 - To and Fro.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;

const int SIZE = 500;
char message[SIZE];

int main()
{
	int column; char iFalse;
	while (true) {
		scanf("%d%c", &column, &iFalse);

		if (column == 0)
			break;

		fgets(message, SIZE, stdin);
		int len = strlen(message);
		if (message[len - 1] != '\0')
			message[len - 1] = '\0';
		len--;
		
		int I = 0, K;

		for (K = 0; K < column; K++) {
			while (I < len) {
				if (I % (column * 2) == K || I % (column * 2) == (column * 2 - K - 1))
					printf("%c", message[I++]);
				else
					I++;
			}
			I = 0;
		}
		printf("\n");
	}
	return 0;
}
