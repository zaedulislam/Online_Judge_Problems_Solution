// Codeforces 982A - Row.cpp

/// Template by Zayed ///

#include <bits/stdc++.h>


using namespace std;
#define NL '\n'
#define BOOST std::ios_base::sync_with_stdio(0);
#define PB push_back


const int SIZE = 1e5 + 10;
string S;




int main()
{
	BOOST
	///READ();
	///WRITE();
	int T, I, J, K, N, n, m, k, cnt = 0, len;

	cin >> len >> S;

	if(len == 1)
	{
		if(S[0] == '0')
			cout << "No\n";
		else
			cout << "Yes\n";

		return 0;
	}


	bool ok1 = true, ok2 = true;
	for(I = 1; I < len; I++)
	{
		if((S[I] == '1' && S[I - 1] == '1'))
		{
			ok1 = false;
			break;
		}

	}


	if(!ok1)
	{
		cout << "No\n";
		return 0;
	}


    // From left
	I = 0, cnt = 0;
    while(I < len && S[I] == '0')
    {
        I++;
        cnt++;
    }
    if(cnt >= 2)
        ok2 = 0;

	if(!ok1 || !ok2)
	{
		cout << "No\n";
		return 0;
	}


    // From right
    J = len - 1, cnt = 0;
    while(J >= 0 && S[J] == '0')
    {
        J--;
        cnt++;
    }
    if(cnt >= 2)
        ok2 = false;


    if(!ok1 || !ok2)
	{
		cout << "No\n";
		return 0;
	}


    // Mid
	for(J = I; J < len; J++)
	{
        cnt = 0;
        while(J < len && S[J] == '0')
        {
            J++;
            cnt++;
        }

        if(cnt >= 3)
            ok2 = false;

	}


	if(!ok1 || !ok2)
		cout << "No\n";
	else
		cout << "Yes\n";



	return 0;

}
