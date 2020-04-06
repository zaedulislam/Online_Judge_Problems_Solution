// C - Car Broker.cpp
#include <iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;

int main()
{
    int testCase,_case = 0;
    char iFalse;
    long long int get,pay,profit;
    scanf("%d%c",&testCase,&iFalse);

    while(testCase--){

        scanf("Owner gets: Tk. %lld%c",&get,&iFalse);
        fflush(stdin);

        scanf("Buyer pays: Tk. %lld%c",&pay,&iFalse);
        fflush(stdin);
        profit = get - pay;

        if(profit < 0){
            profit *= -1;
            printf("Shawkat loses: Tk. %lld",profit);
        }

        else
            printf("Shawkat gains: Tk. %lld",profit);

        if(testCase != 0)
            printf("\n\n");

    }
    return 0;
}






#include <iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;

int main()
{
    int testCase,_case = 1;
    char iFalse;
    double u,v,time,displacement,acc;
    scanf("%d",&testCase);
    while(testCase--){
        scanf("%lf%lf%lf",&u,&v,&time);
        acc = (v - u) / time;
        displacement = u * time + 0.5 * acc * time * time;
        printf("Case %d: %0.3lf",_case,displacement);
        if(testCase != 0)
            printf("\n");
        _case++;
    }
    return 0;
}


#include <iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;

int addDigit(long long int N)
{
    int remainder,sum = 0;
    while(N != 0){
        remainder = N % 10;
        sum  += remainder;
        N /=10;
    }
    return sum;
}

int main()
{
    int testCase,_case = 1;
    long long int N;

    char iFalse;
    scanf("%d%c",&testCase,&iFalse);
    while(testCase--){

    scanf("%lld",&N);
    while(N > 9)
        N = addDigit(N);

    if(N % 2 == 0)
        printf("Test %d: feven",_case);
    else
        printf("Test %d: fodd",_case);

    if(testCase != 0)
            printf("\n");
        _case++;
    }

    return 0;
}


#include <iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#define PI 2*acos(0.0)

using namespace std;

int main()
{
    int testCase,_case = 1;
    char iFalse;
    double area;
    scanf("%d%c",&testCase,&iFalse);
    while(testCase--){
        scanf("%lf",&area);
        area /= 2;
        area = (double)area * PI;
        printf("Case %d: %0.3lf",_case,area);
        if(testCase != 0)
            printf("\n");
        _case++;
    }
    return 0;
}


#include <iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#define PI 2*acos(0.0)

using namespace std;
int arr[1000000];

int main()
{
    int testCase,_case = 1;
    char iFalse;
    long long int N,remainder;
    scanf("%lld%c",&testCase,&iFalse);

    while(testCase--){
        int I = 0;
        scanf("%lld",&N);
        if(N == 0){
            printf("0\n");
            continue;
        }
        while(N != 0){
            remainder = N % 14;
            N /=14;
            arr[I++] = remainder ;
        }
        int K;
        for(K = 0 ;K < I ;K++){
            if(arr[K] == 10)
                printf("A");
            else if(arr[K]==11)
                printf("B");
            else if(arr[K] == 12)
                printf("C");
            else if(arr[K] == 13)
                printf("D");
            else
                printf("%d",arr[K]);
        }

        if(testCase != 0)
            printf("\n");
        _case++;
    }
    return 0;
}

