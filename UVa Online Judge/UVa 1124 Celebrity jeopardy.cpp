// UVa 1124 Celebrity jeopardy.cpp
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

const int _size = 100;
char equation[_size];

int main()
{
    while(fgets(equation,_size,stdin)!= NULL){
        int len = strlen(equation);
        if(equation[len - 1] != '\0')
            equation[len - 1] = '\0';
        len--;
        fputs(equation,stdout);
        printf("\n");
    }
    return 0;
}
