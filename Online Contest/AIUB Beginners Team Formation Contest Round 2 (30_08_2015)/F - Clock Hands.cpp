// F - Clock Hands.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
typedef long long ll;
using namespace std;

int main() {

	double hour, minute,hour_angle,minute_angle,angle_diff;
	while (1) {
		scanf("%lf:%lf", &hour, &minute);

		if (hour == 0 && minute == 0)
			break;

		hour_angle = (hour * 60) / 2 + minute / 2;
		minute_angle = minute * 6;
		angle_diff = hour_angle - minute_angle;
		if (angle_diff < 0)
			angle_diff *= -1;
		if (angle_diff > 180)
			angle_diff = 360 - angle_diff;

		printf("%.3lf\n", angle_diff);
	}
	return 0;
}