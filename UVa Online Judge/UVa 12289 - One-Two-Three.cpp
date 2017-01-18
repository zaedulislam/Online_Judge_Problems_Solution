// UVa 12289 - One-Two-Three.cpp
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;

const int sz = 10;
char str[sz];
int main()
{
	int testCase;
	char iFalse;
	scanf("%d%c", &testCase,&iFalse);
	memset(str,-1,sizeof(str));

	while (testCase--) {
		fgets(str, sz, stdin);
		int len = strlen(str);
		if (str[len - 1] != '\0')
			str[len - 1] = '\0';
		len--;
		bool n = false;
		bool e = false;
		bool t = false;
		bool w = false;
		bool o = false;
		if (len == 5)
			printf("3\n");
		else {
			int i;
			for (i = 0; i < 3; i++) {
				if (str[i] == 'n')
					n = true;
				if (str[i] == 'e')
					e = true;
				if (str[i] == 'o')
					o = true;
			}
			if (n & e || o & e || o & n) {
				printf("1\n");
				continue;
			}
				
			int k;
			for (k = 0; k < 3; k++) {
				if (str[k] == 't')
					t = true;
				if (str[k] == 'w')
					w = true;
				if (str[k] == 'o')
					o = true;
			}
			if (t & o || w & o || t & w)
				printf("2\n");
		}

	}
	
	return 0;
}