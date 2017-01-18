// UVa 11805 - Bafana Bafana.cpp

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
typedef unsigned long long llu;

using namespace std;
     
int main()
{
	int testCase,_case,numPlayer,randPlayer,numPasses;
	scanf("%d", &testCase);
	_case = 1;
	while (testCase--) {
		scanf("%d%d%d", &numPlayer, &randPlayer, &numPasses);
		
		if (numPlayer == numPasses) {
			printf("Case %d: %d\n", _case, randPlayer);
			_case++;
			continue;
		}
		int I;
		for (I = 1; I <= numPasses; I++) {
			if (randPlayer == numPlayer)
				randPlayer = 1;
			else
				randPlayer++;
		}
		printf("Case %d: %d\n", _case, randPlayer);
		_case++;
	}

	return 0;
}

