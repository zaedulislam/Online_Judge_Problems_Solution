// UVa 12250 - Language Detection.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
#include<algorithm>
typedef unsigned long long llu;

using namespace std;

const int _size = 20;
char input[_size];

int main()
{
	int _case = 1;
	int I;
	while(1){
		
		cin.getline(input, _size);
		if (input[0] == '#' && input[1] == '\0')
			return 0;
		else if (strcmp(input,"HELLO") == 0)
			printf("Case %d: ENGLISH\n",_case++);
		else if (strcmp(input,"HOLA") == 0)
			printf("Case %d: SPANISH\n",_case++);
		else if (strcmp(input,"HALLO") == 0)
			printf("Case %d: GERMAN\n", _case++);
		else if (strcmp(input,"BONJOUR") == 0)
			printf("Case %d: FRENCH\n", _case++);
		else if (strcmp(input,"CIAO") == 0)
			printf("Case %d: ITALIAN\n", _case++);
		else if (strcmp(input,"ZDRAVSTVUJTE")==0)
			printf("Case %d: RUSSIAN\n", _case++);
		else
			printf("Case %d: UNKNOWN\n", _case++);
	}
	return 0;
}