// UVa 10062 - Tell me the frequencies!.cpp

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

const int _size = 1e4 + 5;
char str[_size];

int main()
{
	int _case = 0; int freq[130];
	while (fgets(str, _size, stdin) != NULL) {
		if (_case != 0)
			printf("\n");

		int len = strlen(str);
		if (str[len - 1] != '\0')
			str[len - 1] = '\0';
		len--;

		int I,K,_count;
		for (I = 32; I <= 127; I++) {
			_count = 0;
			for (K = 0; K < len; K++) {
				if (str[K] == I)
					_count++;
			}
			freq[I] = _count;
		}

		int max = 0;
		for (I = 32; I <= 127; I++) {
			if (freq[I] > max)
				max = freq[I];
		}

		for (I = 1; I <= max; I++) {
			for (K = 127; K >= 32; K--) {
				if (freq[K] == I)
					printf("%d %d\n", K, I);
			}
		}
		_case = 1;
	}
	return 0;
}

