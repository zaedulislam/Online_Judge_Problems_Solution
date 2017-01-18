// UVa 10347 - Medians.cpp
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
    double median1 ,median2, median3,area;
    while(scanf("%lf%lf%lf",&median1,&median2,&median3) != EOF){
        double square1 =  (median1* median1);
        double square2 = (median2 * median2);
        double square3 = (median3) * (median3);
        area = (square1*square2) + (square2 * square3) + (square3 * square1);
        area *= 2;
        area -=(square1 * square1 + square2 * square2 + square3 * square3);

        if(area <= 0){
            printf("-1.000\n");
            continue;
        }

        area = sqrt(area);
        area /= 3;
        printf("%0.3lf\n",area);
    }

	return 0;
}

