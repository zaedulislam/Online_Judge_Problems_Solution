// CodeChef RD19 - Minimum Deletions.cpp

#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
const int SIZE = 1000 + 10;
int ar[SIZE];
 
 
 
 
int main()
{
    int T, I, J, K, N, n, m, k, cnt = 0, len;
 
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		for(I = 0; I < N; I++)
			scanf("%d", &ar[I]);
 
 
		int GCD = ar[0];
		for(I = 1; I < N; I++)
			GCD = __gcd(GCD, ar[I]);
 
 
		if(GCD == 1)
			printf("0\n");
		else
			printf("-1\n");
 
	}
 
 
    return 0;
}