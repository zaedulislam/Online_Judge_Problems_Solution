// UVa 11764 - Jumping Mario.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cctype>
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
	int testCase,total_wall,high_jump, low_jump,input[55],_case = 1;
	scanf("%d",&testCase);
	while(testCase--){

		high_jump = 0,low_jump = 0;

		scanf("%d",&total_wall);

		int I;
		for(I = 0; I < total_wall;I++)
			scanf("%d",&input[I]);

		if(total_wall == 1){
			printf("Case %d: 0 0\n",_case++);
			continue;
		}

		for(I = 0 ; I < total_wall - 1;I++){
			if(input[I + 1] > input[I])
				high_jump++;
			else if(input[I + 1] < input[I] )
				low_jump++;
		}
		printf("Case %d: %d %d\n",_case++,high_jump,low_jump);
	}

	return 0;
}
