// UVa 10361 - Automatic Poetry.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const int sz = 1e4;
char str_1[sz];
char str_2[sz];
           
int main()
{
	int testCase,flag1,flag2,flag3,flag4,_count;
	char iFalse;
	scanf("%d%c", &testCase, &iFalse);
	
	while (testCase--) {
		flag1 = flag2 = flag3 = flag4 = _count = 0;

		fgets(str_1, sz, stdin);
		int len = strlen(str_1);
		if (str_1[len - 1] != '\0')
			str_1[len - 1] = '\0';
		len--;
		
		fgets(str_2, sz, stdin);
		int len2 = strlen(str_2);
		if (str_2[len2 - 1] != '\0')
			str_2[len2 - 1] = '\0';
		len2--;
		int i;	
		for (i = 0; i<len; i++){
			if (str_1[i] == '<')
				flag1 = i;
			if (str_1[i] == '>'){
				flag2 = i;
				break;
			}
		}
		for (i = flag2 + 1; i<len; i++){
			if (str_1[i] == '<')
				flag3 = i;
			if (str_1[i] == '>'){
				flag4 = i;
				break;
			}
		}
		for (i = 0; i<len; i++){
			if (str_1[i] != '<' && str_1[i] != '>')
				printf("%c", str_1[i]);
		}
		printf("\n");
		for (i = 0; i<len2 - 3; i++)
			printf("%c", str_2[i]);
		for (i = flag3 + 1; i<flag4; i++)
			printf("%c", str_1[i]);
		for (i = flag2 + 1; i<flag3; i++)
			printf("%c", str_1[i]);
		for (i = flag1 + 1; i<flag2; i++)
			printf("%c", str_1[i]);
		for (i = flag4 + 1; i<len; i++)
			printf("%c", str_1[i]);
		printf("\n");

	}
	return 0;
}
 