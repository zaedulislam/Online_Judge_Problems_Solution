// ID 25306 - Easy Marks.cpp
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
	int testCase,_case = 1;
	int N,n, avg_mark,sum_marks;
	scanf("%d", &testCase);
	
	while (testCase--) {
		scanf("%d%d", &N, &avg_mark);
		
		sum_marks = 0;
		int I;
		for (I = 0; I < N; I++) {
			scanf("%d", &n);
			sum_marks += n;
		}

		int temp = sum_marks;
		int last_Quiz = 0;
		
		while (1) {
			temp += last_Quiz;
			if (temp / (N + 1) == avg_mark)
				break;
			last_Quiz++;
			temp = sum_marks;
		}
		printf("Case %d: %d\n", _case++, last_Quiz);
	}

	return 0;
}