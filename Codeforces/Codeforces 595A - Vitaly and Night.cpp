// Codeforces 595A - Vitaly and Night.cpp
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
using namespace std;
const double PI = 2 * acos(0.0);
const double EPS = 1e-9;


int main()
{
	int floors,flats,*arr,wake = 0;
	scanf("%d%d",&floors,&flats);
	arr = new int[2 * flats];

	int I,K,J;
	for(I = 0 ; I < floors; I++){
		for(K = 0 ; K < 2 * flats;K++){
			scanf("%d",&arr[K]);
		}
        for(J = 0 ; J < 2 * flats; J +=2){
			if(arr[J] == 1 || arr[J + 1] == 1)
				wake++;
        }
	}
	printf("%d\n",wake);

	return 0;
}
