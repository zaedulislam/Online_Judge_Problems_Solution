// UVa 10405 - Longest Common Subsequence.cpp
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
//#define  ll long long
using namespace std;
const double PI = 2 * acos(0.0);
const double EPS = 1e-9;
const int sz = 2100;

char X[sz];
char Y[sz];


int max(int a, int b){
	return (a > b) ? a : b;
}
int min(int a, int b){
	return (a < b) ? a : b;
}

int main()
{
	while (fgets(X,sz,stdin) != NULL){
		int lenX = strlen(X);
		if (X[lenX - 1] != '\0')
			X[lenX - 1] = '\0';
		lenX--;

		cin.getline(Y, sz);

		int lenY = strlen(Y);

        int L[lenX + 1][lenY + 1];

		int I, K;
		for (I = 0; I <= lenX; I++){
			for (K = 0; K <= lenY; K++){
				if (I == 0 || K == 0)
					L[I][K] = 0;
				else if (X[I - 1] == Y[K - 1])
					L[I][K] = L[I - 1][K - 1] + 1;
				else
					L[I][K] = max(L[I][K - 1], L[I - 1][K]);
			}
		}
		printf("%d\n", L[lenX][lenY]);
	}
}

