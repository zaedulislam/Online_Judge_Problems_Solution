// UVa 11152 - Colourful Flowers.cpp
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
	double side1,side2,side3,radius,perimeter,half_perimeter,triangle_area,sunflowers,violets,roses,circumradius;
    while(scanf("%lf%lf%lf",&side1,&side2,&side3) != EOF){

		perimeter = side1 + side2 + side3;

		if(side1 == 0 && side2 == 0 && side3 == 0){
			printf("The radius of the round table is: %0.3lf\n",0.000);
			continue;
		}

		half_perimeter = perimeter / 2;
		triangle_area = sqrt(half_perimeter * (half_perimeter - side1) * (half_perimeter - side2) * (half_perimeter - side3));

		radius = (2 * triangle_area) / perimeter;
		roses = PI * radius * radius;

		violets = triangle_area - roses;

		circumradius =(side1 *  side2 * side3) / sqrt(((side1 + side2  + side3) * (side2 + side3 - side1) * (side3 + side1 - side2) * (side1 + side2 - side3)));

		printf("%0.4lf %0.4lf %0.4lf\n",(PI * circumradius * circumradius) -triangle_area,violets,roses);

    }

	return 0;
}
