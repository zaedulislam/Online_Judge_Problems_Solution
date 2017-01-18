// UVa 10945 - Mother Bear.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
using namespace std;

const int sz = 1e4;
char str[sz];
char sen[sz];
char palindrome[sz];
char END[] = "DONE";

int main()
{
	bool flag,exit;
	while (1) {
		memset(sen, 0, sizeof(sen));
		memset(palindrome, 0, sizeof(palindrome));
		flag = true;
		fgets(str, sz, stdin);
		int len = strlen(str);
		if (str[len - 1] != '\0')
			str[len - 1] = '\0';
		len--;
		if (len == 4) {
			exit = true;
			int e;
			for (e = 0; e < len; e++) {
				if (str[e] != END[e])
					exit = false;
			}
			if (exit)
				break;
		}
		if(!exit) {
			int i,k = 0;
			for (i = 0; i < len; i++) {
				if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
				{
					if ((str[i] >= 'A' && str[i] <= 'Z')) {
						str[i] += 'a' - 'A';
						sen[k++] = str[i];
					}
					else
						sen[k++] = str[i];
				}
				else
					continue;
			}
		}
		int lengthSen = strlen(sen);
		int m,n = 0;
		for (m = lengthSen - 1; m >= 0 ; m--)
			palindrome[n++] = sen[m];

		int index;
		for (index = 0; index < lengthSen; index++)
			if (palindrome[index] != sen[index])
				flag = false;

		if (flag)
			printf("You won't be eaten!\n");
		else
			printf("Uh oh..\n");
		
	}
	
	return 0;
}

