// Codeforces 584A - Olesya and Rodion.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cctype>
#include<cmath>
#include<stack>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<algorithm>
#include<vector>
typedef unsigned long long llu;
#define  ll long long
using namespace std;
const double PI = 2 * acos(0.0);
const double EPS = 1e-9;


int main()
{
	string num = "";
	int length,divisor,I;
	scanf("%d%d",&length,&divisor);

	if(divisor == 10){
		if(length == 1)
			printf("%d\n",-1);

		else if(length > 1){
			for(I = 0 ; I < length - 1; I++)
				num += '1';
		num += '0';
		cout << num;
		}
	}

	else if(divisor < 10){
		for(I = 0 ; I < length; I++)
			printf("%d",divisor);
	}

	printf("\n");
	return 0;
}
