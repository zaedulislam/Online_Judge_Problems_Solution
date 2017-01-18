// UVa 12820 - Cool Word.cpp

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
typedef unsigned long long llu;

const int _size = 50;
char str[_size];

int main()
{
	int testCase, _case = 1, _count;
	char iFalse;
	while(scanf("%d%c", &testCase, &iFalse) != EOF){
		
		_count = 0;
		while (testCase--) {
			int freq[26] = { 0 };
			fgets(str, _size, stdin);
			int len = strlen(str);
			if (str[len - 1] != '\0')
				str[len - 1] = '\0';
			len--;
			if (len == 1)
				continue;

			int I,K;
			for (I = 0; I < len; I++) {
				if (str[I] >= 97 && str[I] <= 122) {
					freq[str[I] - 'a']++;
				}
			}
			bool isCool = true;
			for (I = 0; I < 25; I++) {
				for (K = I; K <= 25; K++) {
					if (freq[I] == freq[K + 1] && freq[I] != 0 && freq[K + 1] != 0) {
						isCool = false;
						break;
					}	
				}
				if (!isCool)
					break;
			}
			if (isCool)
				_count++;
			
			memset(str, 0, sizeof(str));
		}
		printf("Case %d: %d\n", _case, _count);
		_case++;
	}

	return 0;
}