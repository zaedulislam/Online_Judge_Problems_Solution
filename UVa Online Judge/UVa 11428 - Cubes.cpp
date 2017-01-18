// UVa 11428 - Cubes.cpp
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;

inline int cube(int a) {
	return a * a * a;
}

int main()
{
	int N,x,y;
	
	while (true) {
		scanf("%d", &N);
		if (N == 0)
			break;

		x = y = 0;
		while (1) {
			if (N == (cube(x) - cube(y))) {
				printf("%d %d\n", x, y);
				break;
			}
			if (N < cube(x) - cube(y))
				y++;
			if (N > cube(x) - cube(y))
				x++;
			if (cube(x) - cube(y) == 0 || x >= 60 || y >= 59) {
				printf("No solution\n");
				break;
			}
		}
	}
	
	return 0;
}

I just simply iterate looking for a pair x, y that satisfy n = x^3 - y^3 and I do it until 
x >= 60 || y>= 59 because the diference between them is greater than 10,000 this means that 
there is no solution.
for example if n = 1 then:
1 = 1^3 - 0^3 then printf "1 0"
2 = 0^3 - 0^3 doesn't match ... so I keep it up looking for the next candidate
2 = 1^3 - 0^3 equal to 1 so also, doesn't match again and as this is less than n = 2 x must be greater so increase it again ...
2 = 2^3 - 0^3 this is 8 , we have exceeded so we need to modify y now. so we increse it.
2 = 2^3 - 1^3 this is 7 , this goes being the same (or be it greater) so y++ again
2 = 2^3 - 2^3 this becomes less than 2 again so it means that there is no solution