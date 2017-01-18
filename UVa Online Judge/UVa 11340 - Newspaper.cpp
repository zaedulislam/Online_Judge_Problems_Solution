// UVa 11340 - Newspaper.cpp

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

const int _size = 10000 + 10;
char character[110];
int char_value[110];
char article[_size];

int main()
{
	int testCase, K;
	double price;

	scanf("%d", &testCase);

	while (testCase--) {
		price = 0;
		scanf("%d", &K);

		int I;
		for (I = 0; I < K; I++)
			cin >> character[I] >> char_value[I];
		/*scanf("%c%d\n", &character[I], &char_value[I]);*/

		int numLine;
		char iFalse;
		scanf("%d%c", &numLine, &iFalse);

		for (I = 0; I < numLine; I++) {
			fgets(article, _size, stdin);
			int len = strlen(article);
			if (article[len - 1] != '\0')
				article[len - 1] = '\0';
			len--;

			int V, S;
			for (V = 0; V < K; V++) {
				for (S = 0; S < len; S++) {
					if (article[S] == character[V])
						price += char_value[V];
				}
			}
		}
		printf("%.2lf$\n", price / 100);
	}
	return 0;
}
