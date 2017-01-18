// UVa 11455  - Behold My Quadrangle.cpp

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


int main()
{
	int testCase;
	scanf("%d", &testCase);
	while (testCase--) {
		int side[4];
		scanf("%d%d%d%d", &side[0], &side[1], &side[2], &side[3]);

		sort(side, side + 4);
		int sum_length = side[0] + side[1] + side[2];

		if (side[0] == side[1] && side[2] == side[3]) {
			bool flag = false;
			int I;
			for (I = 0; I < 3; I++) {
				if (side[I] != side[I + 1])
					break;
			}
			if (I == 3)
				printf("square\n");
			else
				printf("rectangle\n");
		}

		else if (sum_length > side[3])
			printf("quadrangle\n");
		else
			printf("banana\n");
	}

	return 0;
}


