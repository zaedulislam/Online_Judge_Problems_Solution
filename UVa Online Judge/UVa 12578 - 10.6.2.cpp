// UVa 12578 - 10:6:2.cpp
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
const double PI = acos(-1);
const double EPS = 1e-9;
const int sz = 100;

// My Code Template Goes Here
int max(int a,int b){
    return (a > b) ? a : b;
}
int min(int a,int b){
    return (a < b) ? a : b;
}
 inline int _pow(int base, int power){
	int I,result = base;
	for (I = 0; I < power - 1; I++) {
		result = result * base;
	}
	return result;
}
// My Code Template Goes Here

// Driver function
int main()
{
	int testCase;
	double length,radii,rect_area,circle_area,width;
	scanf("%d",&testCase);
	
	while(testCase--){
        scanf("%lf",&length);
        radii = (2.00 * length) / 10.00;
        circle_area = PI * radii * radii;

        width =  (6.00 * length) / 10.00;
        rect_area = (width * length);

        printf("%0.2lf %0.2lf\n", circle_area, rect_area - circle_area);
	}
	return 0;
}
