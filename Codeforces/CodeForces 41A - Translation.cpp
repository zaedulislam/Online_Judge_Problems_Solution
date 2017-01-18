// CodeForces 41A - Translation.cpp
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

const int sz = 105;
char str1[sz];
char  str2[sz];

int main()
{
        scanf("%s",str1);
        scanf("%s",str2);
        int len1 = strlen(str1);

        reverse(str1,str1 + len1);
        int I;
        for( I = 0 ; I < len1; I++){
            if(str1[I] != str2[I])
                break;
        }
        if(I == len1 )
            printf("YES\n");
        else
            printf("NO\n");

	return 0;
}
