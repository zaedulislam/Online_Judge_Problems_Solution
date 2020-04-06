// E - Calendar.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
#include<algorithm>
typedef long long ll;
using namespace std;



int main()
{
	int day, month, _count = 0;
	scanf("%d%d", &day, &month);

	if ((month == 2) && (day>28)){
		printf("Impossible\n");
		return 0;
	}
	else if (((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) && (day>31)){
		printf("Impossible\n");
		return 0;
	}
	else if (((month == 4) || (month == 6) || (month == 9) || (month == 11)) && (day>30)){
		printf("Impossible\n");
		return 0;
	}

	if ((month > 12) || (day < 1))	{
		printf("Impossible\n");
		return 0;
	}

	int I;
	for (I = 1; I < month; I++){
		if (I == 2)
			_count += 28;

		else if ((I == 1) || (I == 3) || (I == 5) || (I == 7) || (I == 8) || (I == 10) || (I == 12))
			_count += 31;

		else
			_count += 30;
	}

	_count += day;
	if (_count % 7 == 0){
		printf("%d\n",7);
		return 0;
	}

	else	{
		printf("%d\n", _count % 7);
		return 0;
	}
	return 0;
}