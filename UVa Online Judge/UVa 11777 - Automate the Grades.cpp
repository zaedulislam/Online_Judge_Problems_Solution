// UVa 11777 - Automate the Grades.cpp

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
    int Term1,Term2,Final,Attendance,Class_Test[3],Total;
    scanf("%d",&testCase);
    while(testCase--){
            scanf("%d%d%d%d%d%d%d",&Term1,&Term2,&Final,&Attendance,&Class_Test[0],&Class_Test[1],&Class_Test[2]);
            Total = Term1 +Term2 +Final + Attendance;

            sort(Class_Test,Class_Test + 3);

            Total += (Class_Test[1] + Class_Test[2]) / 2;

            if(Total >= 90)
                printf("Case %d: A\n",_case++);
            else if(Total >= 80 && Total < 90)
                 printf("Case %d: B\n",_case++);
            else if(Total >= 70 && Total < 80)
                 printf("Case %d: C\n",_case++);
            else if(Total >= 60 && Total < 70)
                printf("Case %d: D\n",_case++);
            else if(Total < 60)
                printf("Case %d: F\n",_case++);

    }

	return 0;
}

