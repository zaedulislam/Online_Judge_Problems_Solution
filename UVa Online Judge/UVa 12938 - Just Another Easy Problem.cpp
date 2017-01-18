// UVa 12938 - Just Another Easy Problem.cpp
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
using namespace std;
const double PI = 2 * acos(0.0);
const double EPS = 1e-9;


int main()
{
	char number[10],iFalse,digit;
	int testCase,_case = 1;
	scanf("%d%c",&testCase,&iFalse);

	while(testCase--){
		scanf("%s",number);
		int len = strlen(number);

        int I,K,num,sqrtN,ways = 0;

		for(I = 0; I < len; I++){
			char temp = number[I];

			if(I == 0){
                K = 1;
                digit = '1';
                while(K <= 9){
					if(digit == temp){
						digit++;
						K++;
						continue;
					}

					number[I] = digit;
					digit++;
					K++;

					stringstream convert(number);
					convert >> num;
					sqrtN = int (sqrt((double)num));

                    if(sqrtN * sqrtN  == num)
						ways++;
                }
			}
			else{
				K = 0;
				digit = '0';
                while(K <= 9){
					if(digit == temp){
						digit++;
						K++;
						continue;
					}

					number[I] = digit;
					digit++;
					K++;
					stringstream convert(number);
					convert >> num;
					sqrtN = int(sqrt((double)num));

                    if(sqrtN * sqrtN  == num)
						ways++;

                }
			}
		number[I] = temp;
		}
		printf("Case %d: %d\n",_case++,ways);

	}
	return 0;
}

