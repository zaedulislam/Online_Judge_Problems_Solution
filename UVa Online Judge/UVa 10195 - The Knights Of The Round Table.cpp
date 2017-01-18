// UVa 10195 - The Knights Of The Round Table.cpp
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
	double side1,side2,side3,radius,perimeter,half_perimeter,triangle_area;
    while(scanf("%lf%lf%lf",&side1,&side2,&side3) != EOF){
		perimeter = side1 + side2 + side3;
		if(side1 == 0 && side2 == 0 && side3 == 0){
			printf("The radius of the round table is: %0.3lf\n",0.000);
			continue;
		}

		half_perimeter = perimeter / 2;
		triangle_area = half_perimeter * (half_perimeter - side1) * (half_perimeter - side2) * (half_perimeter - side3);
		triangle_area = sqrt(triangle_area);
		radius = (2 * triangle_area) / perimeter;

		printf("The radius of the round table is: %0.3lf\n",radius);

    }

	return 0;
}
