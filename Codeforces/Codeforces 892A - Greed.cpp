// Codeforces 892A - Greed.cpp

#include <bits/stdc++.h>
using namespace std;

#define NL '\n'
#define LL long long

const int SIZE = 1e5 + 10;
LL a[SIZE], b[SIZE];


int main()
{
	LL T, I, J, K, N, n, m, cnt = 0, len;

	cin >> n;

	for(I = 0; I < n; I++)
	{
		cin >> a[I];
		cnt += a[I];
	}

	for(I = 0; I < n; I++)
		cin >> b[I];

	sort(b, b + n);

	if(cnt <= b[n - 1] + b[n - 2])
		cout << "YES" << NL;
	else
		cout << "NO" << NL;

	return 0;
}
