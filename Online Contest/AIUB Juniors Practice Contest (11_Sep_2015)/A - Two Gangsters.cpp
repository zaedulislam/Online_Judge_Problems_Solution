// A - Two Gangsters.cpp
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


int main()
{
	int harry,larry,totalCan;
	while (scanf("%d%d", &harry,&larry) != EOF) {
		totalCan = harry + larry;
		printf("%d %d\n", totalCan - harry - 1, totalCan - larry - 1);
	}
	return 0;
}