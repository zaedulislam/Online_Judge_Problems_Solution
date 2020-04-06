// A - Age Sort.cpp
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<string>
//#include<cmath>
//#include<stack>
//#include<ctime>
//#include<queue>
//typedef unsigned long long llu;
//using namespace std;
//
//const int _size = 2000010;
//int age[_size];
//
//bool compare(int const &a, int const &b)
//{
//	if (a<b)return true;
//	return false;
//}
//
//int main()
//{
//
//	int numPeople;
//	while (1) {
//		scanf("%d",&numPeople);
//		if (numPeople == 0)
//			break;
//
//		/*age = new int[numPeople];*/
//		int I;
//		for (I = 0; I < numPeople; I++)
//			scanf("%d", &age[I]);
//
//		sort(age, age + numPeople,compare);
//		
//		for (I = 0; I < numPeople; I++) {
//			if (I == numPeople - 1) {
//				printf("%d", age[I]);
//				break;
//			}
//			printf("%d ", age[I]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int _size = 2000010;
int age[_size];

bool compare(int const &a, int const &b)
{
	if (a<b)return true;
	return false;
}

int main()
{
	int numPeople, i;
	while (scanf("%d", &numPeople) == 1 && numPeople != 0)
	{
		int I;
		for (I = 0; I <numPeople; I++)
			scanf("%d", &age[I]);
		sort(age, age + numPeople, compare);

		for (I = 0; I < numPeople; I++) {
			if (I == numPeople - 1) {
				printf("%d", age[I]);
				break;
			}
			printf("%d ", age[I]);
		}
		printf("\n");
	}
	return 0;
}