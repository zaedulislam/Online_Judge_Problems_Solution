// HackerRank - Queue using Two Stacks.cpp

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    stack<int> S1, S2;
    int I, type, x, q;
    
    cin >> q;
    while(q--)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> x;
            S1.push(x);
        }
        else if(type == 2)
        {
            if(!S2.empty())
                S2.pop();
            else
            {
                while(!S1.empty())
                {
                    x = S1.top();
                    S1.pop();
                    S2.push(x);
                }
                
                S2.pop();
            }
        }
        else
        {
            if(!S2.empty())
                cout << S2.top() << endl;
            else
            {
                while(!S1.empty())
                {
                    x = S1.top();
                    S1.pop();
                    S2.push(x);
                }
                
                cout << S2.top() << endl;
            }
        }
    }
    
    
    return 0;
}
