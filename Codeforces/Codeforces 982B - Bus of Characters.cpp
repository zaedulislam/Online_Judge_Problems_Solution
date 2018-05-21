// Codeforces 982B - Bus of Characters.cpp

/// Template by Zayed ///

#include <bits/stdc++.h>


using namespace std;
#define NL '\n'
#define BOOST std::ios_base::sync_with_stdio(0);
#define PB push_back
#define pii pair<int, int>


const int SIZE = 2e5 + 10;
string S;
pii ar[SIZE];
priority_queue<pii> PQ;
vector<int> rows;




int main()
{
	BOOST
	///READ();
	///WRITE();
	int T, I, J, K, N, n, m, k, cnt = 0, len;

	cin >> n;
	for(I = 0; I < n; I++)
	{
		cin >> ar[I].first;
		ar[I].second = I + 1;
	}

	cin >> S;
	len = S.length();

	sort(ar, ar + n);

	int intro = 0, pos, w;
	for(I = 0; I < len; I++)
	{
		if(S[I] == '0')
		{
			w = ar[intro].first;
			pos = ar[intro].second;
			rows.PB(pos);
			PQ.push(pii(w, pos));

            intro++;

		}
		else
		{
			pii TOP = PQ.top();
			pos = TOP.second;
			rows.PB(pos);

			PQ.pop();

		}
	}


	cout << rows[0];
	for(I = 1; I < rows.size(); I++)
		cout << ' ' << rows[I];

	cout << NL;


	return 0;

}
