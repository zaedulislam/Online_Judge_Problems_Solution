// B - Way Too Long Words.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
#include<algorithm>
typedef long long ll;
using namespace std;

const int _size = 110;
char word[_size];

int main()
{
	int testCase;
	char iFalse;
	scanf("%d%c", &testCase, &iFalse);
	while (testCase--) {
		fgets(word, _size, stdin);
		int len = strlen(word);
		if (word[len - 1] != '\0')
			word[len - 1] = '\0';
		len--;
		if (len <= 10) {
			fputs(word, stdout);
			printf("\n");
		}
		else {
			printf("%c%d%c\n", word[0], len - 2, word[len - 1]);
		}
	}
	return 0;
}