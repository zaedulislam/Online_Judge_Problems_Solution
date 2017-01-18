// UVa 12403 - Save Shetu.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
#include<algorithm>
#include<vector>
typedef unsigned long long llu;
using namespace std;

int main()
{
	int testCase,donate,totalMoney = 0;
	string str;
	scanf("%d", &testCase);
	while (testCase--) {
		cin >> str;
		if (str[0] == 'd') {
			scanf("%d", &donate);
			totalMoney += donate;
		}
		else if (str[0] == 'r')
			printf("%d\n", totalMoney);
		}
	return 0;
	}

