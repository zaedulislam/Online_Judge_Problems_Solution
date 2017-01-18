// LightOJ 1022 - Circle in Square.cpp
#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

const double PI = 2 * acos(0.0);
const double EPS = 1e-9;

int main()
{
	int testCase,_case = 1;
	double radius;
	scanf("%d",&testCase);
	while(testCase--){
        scanf("%lf",&radius);
		// Calculate Area of the Circle
        double circle_area = PI * (radius * radius);
        double square_side = radius * 2;
        // Calculate Area of the Square
		double square_area = square_side * square_side;

        printf("Case %d: %0.2lf\n",_case++,(square_area - circle_area) + EPS) ;

	}
    return 0;
}
