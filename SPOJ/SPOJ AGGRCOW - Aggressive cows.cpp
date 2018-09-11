// SPOJ AGGRCOW - Aggressive cows.cpp

#include<iostream>
#include<algorithm>
using namespace std;
int ar[100000 + 5], N, C;




int Check(int X, int N)
{
	int I, cnt = 1, pos = ar[1];
	for (I = 2; I <= N; I++)
	{
		if (ar[I] - pos >= X)
		{
			cnt++;
			pos = ar[I];

			if (cnt == C)
				return 1;
		}
	}

	return -1;
}



int BinarySearch(int N)
{
	int first = 0, last = ar[N], mid, maxi = -1;
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (Check(mid, N) == 1)
		{
			if(mid > maxi)
				maxi = mid;

			first = mid + 1;
		}
		else
			last = mid - 1;
	}

	return maxi;
}



int main()
{
	int I, J, t, T;

	cin >> T;
	for (t = 1; t <= T; t++)
	{
		cin >> N >> C;
		for (I = 1; I <= N; I++)
			cin >> ar[I];

		sort(ar + 1, ar + N + 1);
		
		cout << BinarySearch(N) << '\n';

	}

	return 0;
}