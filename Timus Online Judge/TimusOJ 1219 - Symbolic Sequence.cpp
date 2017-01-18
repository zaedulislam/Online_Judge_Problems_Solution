// TimusOJ 1219 - Symbolic Sequence.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
using namespace std;

int main()
{
	int len = 1e6;
	int I, K, X;
	while(true){
		for (I = 0; I < 26; I++) {
			for (K = 0; K < 26; K++) {
				for (X = 0; X < 26; X++) {
					if (len-- > 0)
						printf("%c", 'a' + I);
					
					if (len-- > 0)
						printf("%c", 'a' + K);
						
					if (len-- > 0)
						printf("%c", 'a' + X);
						
					else 
						return 0;
				}
			}
		}
	}
	return 0;
}
