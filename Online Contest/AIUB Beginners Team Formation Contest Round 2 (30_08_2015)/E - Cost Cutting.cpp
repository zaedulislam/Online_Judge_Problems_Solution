// E - Cost Cutting.cpp

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int arr[3];
int main()
{
	int testCase, a, b, c;
	scanf("%d", &testCase);
	int _case = 1;
	while (testCase--) {
		scanf("%d%d%d", &a, &b, &c);
		arr[0] = a;
		arr[1] = b;
		arr[2] = c;
		printf("Case %d: ", _case);
		int i, item;
		for (i = 1; i <= 3 - 1; i++)     // Starts with 1 (not 0)
		{
			item = arr[i];
			int index = i - 1;
			while (index >= 0 && arr[index] > item)  // Larger values move up
			{
				arr[index + 1] = arr[index];
				index--;
			}
			arr[index + 1] = item;  // Put item into its proper location
		}
		printf("%d\n", arr[1]);
		_case++;
	}

	return 0;
}