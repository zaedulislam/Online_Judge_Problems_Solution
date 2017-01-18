// UVa 10066 - The Twin Towers.cpp
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
const int sz = 500;

int X[sz];
int Y[sz];

int max(int a, int b){
	return (a > b) ? a : b;
}
int min(int a, int b){
	return (a < b) ? a : b;
}

int main()
{
	int N1,N2,_case = 1;
	while(1){
		scanf("%d%d",&N1,&N2);
		if(N1 == 0 && N2 == 0)
			break;

		int I,K;
		for(I = 0 ; I < N1; I++)
			scanf("%d",&X[I]);
		for(K = 0; K < N2; K++)
			scanf("%d",&Y[K]);

        int L[N1 + 1][N2 + 1];

		for(I = 0 ; I <= N1; I++){
			for(K =0 ; K <= N2; K++){
				if(I == 0 || K == 0)
					L[I][K] = 0;
				else if(X[I - 1] == Y[K - 1])
					L[I][K] = L[I - 1][K -1] + 1;
				else
					L[I][K] = max(L[I][K - 1],L[I - 1][K]);
		}
    }
		printf("Twin Towers #%d\n",_case++);
		printf("Number of Tiles : %d\n\n",L[N1][N2]);
	}

	return 0;
}
