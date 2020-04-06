// C - Study Room.cpp
#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>

#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>

#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cctype>

#define NL endl
#define sf scanf
#define pf printf
#define READ() freopen("in.txt, "r", stdin)
#define WRITE() freopen("out.txt, "w", stout)
const int SIZE = 1e5 + 10;
const double PI = 2 * acos(0.0);

using namespace std;

int ar[SIZE];

int main()
{
    //std::ios_base::sync_with_stdio(0);
    int tcases, caseno = 1, I, J, K, N, n, m, cnt = 0, len, p;
    //READ()
    //WRITE()
    cin >> tcases;
    while(tcases--)
    {
        memset(ar, 0, sizeof(ar));
        cin >> n >> m;
        for(I = 0; I < m; I++)
        {
            cin >> p;
            ar[p] = 1;
        }

        for(I = 1; I <= n; I++)
        {

            if(ar[I] == 1)
            {
                ar[I] = 2;
                if(ar[I - 1] != 1)
                    ar[I - 1] = 2;

                if(ar[I + 1] != 1)
                    ar[I + 1] = 2;
            }

        }

        cnt = 0;
        for(I = 1; I <= n; I++)
        {
            //cout << "ar[" << I << "] = " << ar[I] << " ";
            if(ar[I] == 2)
                cnt++;
        }
        cout << "Case " << caseno++ << ": " << cnt << NL;

    }
    return 0;
}