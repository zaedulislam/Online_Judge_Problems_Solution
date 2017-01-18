// UVa 10370 - Above Average.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
using namespace std;

int main()
{
	int *finalGrade;
	int testCase,students,_count, aveGrade;
	double  sumGrade, stPercentage;
	scanf("%d", &testCase);
	while (testCase--) {
		sumGrade = 0,_count = 0;
		scanf("%d", &students);
		finalGrade = new int[students];
		int k;
		for (k = 0; k < students;k++){
			scanf("%d", &finalGrade[k]);
			sumGrade += finalGrade[k];
		}
		aveGrade = sumGrade / students;

		int i;
		for (i = 0; i < students; i++) {
			if (finalGrade[i] > aveGrade)
				_count++;
		}
		stPercentage = (_count * 100.00) / students;
		printf("%0.3lf", stPercentage);
		cout << "%\n";
	}
	
	return 0;
}

