// UVa 10340 - All in All.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cctype>
#include<cmath>
#include<stack>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<algorithm>
#include<vector>
typedef unsigned long long llu;
#define  ll long long
using namespace std;
const double PI = 2 * acos(0.0);
const double EPS = 1e-9;

int const sz = 1000000;
char S[sz];
char T[sz];


int main()
{
    while(scanf("%s %s",&S,&T) != EOF){
        int lenS = strlen(S);
        int lenT =  strlen(T);

        int I = 0 ,K = 0;
        while( I < lenS && K < lenT){
            if(S[I] == T[K])
                I++;
            K++;
        }

        if(I == lenS)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
