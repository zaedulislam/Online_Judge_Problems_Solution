// UVa 10221 - Satellites.cpp

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
const double Earth_radius = 6440;


int main()
{
    double distance,angle,arc_distance,chord_distance;
    char str[4];
    while(scanf("%lf%lf%s",&distance,&angle,&str) != EOF){
        if(str[0] == 'm'){
            angle /= 60;
            if(angle > 180)
                angle = 360 - angle;
            angle = ( PI * angle) / 180;
        }
        else if(str[0] == 'd'){
            if(angle > 180)
                angle = 360 - angle;
            angle = (PI * angle) / 180;
        }

        arc_distance = (Earth_radius + distance) * angle;
        chord_distance = (Earth_radius + distance) * (sqrt( 2 - 2 * cos(angle)));
        printf("%0.6lf% 0.6lf\n",arc_distance,chord_distance);
    }
	return 0;
}

