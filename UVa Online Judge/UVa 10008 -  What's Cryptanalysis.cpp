// UVa 10008 -  What's Cryptanalysis?.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int arraySize = 600;
char line[arraySize];
int freq[26];

int main()
{
	int testCase, iFalse,max = 0;
	scanf("%d%c", &testCase, &iFalse);
	
	while (testCase--) {
		freq[26] = { 0 };
		fgets(line, arraySize, stdin);
		int len = strlen(line);
		if (line[len - 1] != '\0')
			line[len - 1] = '\0';
		len--;
		int i = 0;
		while (line[i] != '\0') {
			if (line[i] >= 'a' &&line[i] <= 'z') {
				freq[line[i] - 'a']++;
				if (freq[line[i] - 'a']>max)
					max = freq[line[i] - 'a'];
			}
			else if (line[i] >= 'A' &&line[i] <= 'Z') {
				freq[line[i] - 'A']++;
				if (freq[line[i] - 'A']>max)
					max = freq[line[i] - 'A'];
			}
			i++;
		}
	}
	int i,c;
	for (i = max; i >= 1; i--) {
		for (c = 0; c <= 25;c++)
			if (freq[c] == i)
				printf("%c %d\n", alphabet[c], i);
	}
	return 0;
}