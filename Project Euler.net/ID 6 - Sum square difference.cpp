// ID 6 - Sum square difference.cpp
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
    int n = 100;
    int res1 = (n * ( n + 1) * (2 * n + 1)) / 6;
    int res2 = n * ( n + 1) * 0.5;
    res2 = res2 * res2;

    printf("%d\n",res2 - res1);
    return 0;
}
