// UVa 11498 -  Division of Nlogonia.cpp
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
    int testCase,div_x,div_y,X,Y;
    while(1){
        scanf("%d",&testCase);
        if(testCase == 0)
            break;

        scanf("%d%d",&div_x,&div_y);
        while(testCase--){

            scanf("%d%d",&X,&Y);

            if(X > div_x && Y > div_y)
                printf("NE\n");

            else if(X < div_x && Y > div_y)
                printf("NO\n");

            else if(X < div_x && Y < div_y)
                printf("SO\n");

            else if(X > div_x && Y < div_y)
                printf("SE\n");

            else if((X == div_x && Y == div_y) || ( X == div_x ) || (Y == div_y))
                printf("divisa\n");

        }
    }
    return 0;
}
