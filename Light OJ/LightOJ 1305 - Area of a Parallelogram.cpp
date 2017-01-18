// LightOJ 1305 - Area of a Parallelogram.cp
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
	double Ax,Ay,Bx,By,Cx,Cy,Dx,Dy,area;
	scanf("%d", &testCase);
	while (testCase--) {
         scanf("%lf%lf%lf%lf%lf%lf",&Ax,&Ay,&Bx,&By,&Cx,&Cy);
        Dx = Cx - (Bx - Ax);
        Dy = Cy - (By - Ay);
        area = (( Ax * By) + (Bx * Cy) + (Cx * Dy) + (Dx * Ay)) - ((Ay * Bx) + (By * Cx) + (Cy * Dx) + (Dy * Ax));
        area = 0.5 * area;
        // Due to the position of the co-ordinates the result of the area may come with a negative value.
        if(area < 0)
            area *= -1;
        printf("Case %d: %0.0lf %0.0lf %0.0lf\n",_case++,Dx, Dy,area);
	}

	return 0;
}

