// G - Discover the Web.cpp
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
	long long int testCase,_case = 1;
	scanf("%lld", &testCase);

	while (testCase--) {
		printf("Case %lld:\n", _case++);
		
		stack<string>S_backward;
		stack<string>S_forward;

		string webPage = "http://www.lightoj.com/";
		S_backward.push(webPage);
		string command = "";

		while (cin >> command) {
			if (command[0] == 'Q')
				break;

			else if (command[0] == 'V') {
				cin >> webPage;
				cout << webPage << endl;
				S_backward.push(webPage);
				if (!S_forward.empty()) {
					while (!S_forward.empty())
						S_forward.pop();
				}
			}
			else {
				if (command[0] == 'B') {
					S_forward.push(S_backward.top());
					S_backward.pop();
					if (!S_backward.empty())
						cout << S_backward.top() << endl;
					else{
						printf("Ignored\n");
						S_backward.push(S_forward.top());
						S_forward.pop();
					}
				}
				else if (command[0] == 'F') {
					if (!S_forward.empty()){
						cout << S_forward.top() << endl;
						S_backward.push(S_forward.top());
						S_forward.pop();
					}
					else
						printf("Ignored\n");
				}
			}
		}		
	}
	return 0;
}

