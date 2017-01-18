// UVa 10432 - Polygon Inside A Circle.cpp
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
const double PI = 2 * acos(0.0);
const double EPS = 1e-9;

int main()
{
    double radius,side;
    while(scanf("%lf%lf",&radius,&side) != EOF){
        printf("%0.3lf\n",0.5 * side * radius * radius * sin((2 * PI) / side));
    }
    return 0;
}
