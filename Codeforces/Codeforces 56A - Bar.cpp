// Codeforces 56A - Bar.cpp
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

char str[11005];

int main()
{
    int client,age,check = 0;
    char iFalse;
    scanf("%d%c",&client,&iFalse);

    while(client--){

        scanf("%s",str);
        age = 0;
        int lenStr = strlen(str);

        if(strcmp(str,"ABSINTH")==0 || strcmp(str,"BEER")==0 || strcmp(str,"BRANDY")==0 || strcmp(str,"CHAMPAGNE")==0 || strcmp(str,"GIN")==0 || strcmp(str,"RUM")==0 || strcmp(str,"SAKE")==0 || strcmp(str,"TEQUILA")==0 || strcmp(str,"VODKA")==0 || strcmp(str,"WHISKEY")==0 || strcmp(str,"WINE")==0)
                check++;

        if(str[0]>=48 && str[0] <= 57){
            stringstream convert(str);
            convert >> age;
            //printf("%d\n", age);
            if(age < 18 )
                check++;
        }

    }
    printf("%d\n",check);
    return 0;
}


