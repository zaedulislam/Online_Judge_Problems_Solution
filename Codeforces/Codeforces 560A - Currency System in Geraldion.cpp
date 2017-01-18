// Codeforces 560A - Currency System in Geraldion.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
typedef unsigned long long llu;
using namespace std;

//const int _size = 1e6 + 10 ;
//int notes[_size];

int main()
{
	int N,notes;
	scanf("%d", &N);
	
	int I;
	for (I = 0; I < N; I++) {
		scanf("%d", &notes);
		if (notes == 1) {
			printf("-1\n");
			return 0;
		}
	}
	printf("1\n");
		
	return 0;
}