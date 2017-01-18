// LightOJ 1338 - Hidden Secret!.cpp
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

const int _size = 105;
char name1[_size];
char name2[_size];
char name1_UP[_size];
char name2_UP[_size];


int main()
{
	int testCase, _case = 1;
	char iFalse;
	scanf("%d%c", &testCase, &iFalse);
	while (testCase--) {
		fgets(name1, _size, stdin);
		int len_1 = strlen(name1);
		if (name1[len_1 - 1] != '\0')
			name1[len_1 - 1] = '\0';
		len_1--;

		fgets(name2, _size, stdin);
		int len_2 = strlen(name2);
		if (name2[len_2 - 1] != '\0')
			name2[len_2 - 1] = '\0';
		len_2--;


		int I,K = 0;
		for (I = 0; I < len_1; I++) {
			if (name1[I] >= 'A' && name1[I] <= 'Z') 
				name1_UP[K++] = name1[I];
		
			else if (name1[I] >= 'a' && name1[I] <= 'z') 
				name1_UP[K++] = name1[I] - 32; 
		}
		name1_UP[K] = '\0';
		sort(name1_UP,name1_UP + K);

		K = 0;
		for (I = 0; I < len_2; I++) {
			if (name2[I] >= 'A' && name2[I] <= 'Z')
				name2_UP[K++] = name2[I];
			else if (name2[I] >= 'a' && name2[I] <= 'z')
				name2_UP[K++] = name2[I] - 32;
		}
		name2_UP[K] = '\0';
		sort(name2_UP, name2_UP + K);

		if (strcmp(name1_UP, name2_UP) == 0)
			printf("Case %d: Yes\n", _case);
		else
			printf("Case %d: No\n", _case);

		
		_case++;
	}
	return 0;
}