// C - Kindergarten Counting Game.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int sz = 1e4 + 10;
char str[sz];
char sentence[sz];

int main()
{
	int _count;
	bool flag;
	while (fgets(str, sz, stdin) != NULL) {
		_count = 0;
		memset(sentence, 0, sizeof(sentence));


		int len = strlen(str);
		if (str[len - 1] != '\0')
			str[len - 1] = '\0';
		len--;

		int i, index = 0;
		for (i = 0; i < len; i++) {
			flag = false;
			if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
				flag = true;
				while ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
					sentence[index++] = str[i];
					i++;
				}
			}
			if (flag)
				sentence[index++] = ' ';
		}
		int k;
		int l = strlen(sentence);
		for (k = 0; k < l; k++) {
			if (sentence[k] == ' ')
				_count++;
		}
		printf("%d\n", _count);

	}

	return 0;
}
