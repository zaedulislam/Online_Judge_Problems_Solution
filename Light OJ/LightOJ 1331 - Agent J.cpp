// LightOJ 1331 - Agent J.cpp
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
    int testCase,_case = 1;
    double R1,R2,R3,a,b,c,triangle_area,perimeter;
    double nominator,denominator, A,B,C,arc_length1,arc_length2, arc_length3,region,sector1,sector2,sector3;
    scanf("%d",&testCase);
    while(testCase--){
        scanf("%lf%lf%lf",&R1,&R2,&R3);
        // Connect the three center of the circles, then will form a tringle
        a = R1 + R2;
        b = R2 + R3;
        c = R3  + R1;
        // Find the perimeter of the triangle
        perimeter = (a + b+ c) / 2;
        // Calculate the area of the triangle using Heron's Formula
        triangle_area = perimeter * (perimeter - a) * (perimeter - b) * (perimeter - c );
        triangle_area = sqrt(triangle_area);

        // Using cosine formula to find out the angle between the connecting lines
        A  = acos(( b * b + c * c - a * a ) / ( 2 * b * c ));
        B = acos(( a * a + c * c - b * b ) / ( 2 * a * c ));
        C = acos(( a * a + b * b - c * c ) / ( 2 * a * b ));

        // Calculate the arc length
        arc_length1 = R1 * B;
        arc_length2 = R2 * C;
        arc_length3 = R3 * A;

        // Calculate the area of the arc respectively
        sector1 = 0.5 * (arc_length1 * R1) ;
        sector2 = 0.5 * (arc_length2 * R2 );
        sector3 = 0.5 * (arc_length3 * R3);

        region = triangle_area - (sector1 + sector2 + sector3);
        printf("Case %d: %0.8lf\n",_case++,region);
    }

	return 0;
}

