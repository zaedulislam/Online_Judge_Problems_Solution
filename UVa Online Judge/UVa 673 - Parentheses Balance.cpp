//UVa 673 - Parentheses Balance.cpp

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;

const int _size = 150;
char str[_size];

int main()
{
	int testCase;
	char iFalse;
	scanf("%d%c", &testCase,&iFalse);
	
	while (testCase--) {
		stack<char> S;
		memset(str,0, sizeof(str));
		fgets(str, _size, stdin);
		
		int len = strlen(str);
		if (str[len - 1] != '\0')
			str[len - 1] = '\0';
		len--;

		int i;
		for (i = 0; i < len; i++) {
		
			if (str[i] == ' ')
				continue;
			else if (str[i] == '(' || str[i] == '[')
				S.push(str[i]);
			else if (str[i] == ')' || str[i] == ']') {
				if (S.empty()) {
					S.push(str[i]);
					continue; 
				}
				if (S.top() == '(' && str[i] == ')')
					S.pop();
				else if(S.top() == '[' && str[i] == ']')
					S.pop();
			}
		}

		if (S.empty())
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}