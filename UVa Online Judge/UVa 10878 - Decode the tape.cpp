// UVa 10878 - Decode the tape.cpp
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

const int _size = 100;
char line[_size];

int main() {

	while (fgets(line, _size, stdin) != NULL) {

		char ch = 0;
		int len = strlen(line);
		if (line[len - 1] != '\0')
			line[len - 1] = '\0';
		len--;

		if (line[0] != '|')
			continue;

		int I;
		for (I = 0; I < len; I++) {
			if (line[I] == ' ' || line[I] == 'o')
				ch = ch << 1;
			if (line[I] == 'o')
				ch++;
		}
		printf("%c", ch);
	}
	return 0;
}