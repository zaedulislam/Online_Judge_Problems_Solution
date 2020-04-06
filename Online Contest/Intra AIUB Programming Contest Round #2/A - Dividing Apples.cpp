// A - Dividing Apples.cpp
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

const int SIZE = 1e6;
const double PI = 2 * acos(0.0);

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int tcases, caseno = 1, I, J, K, N, n, m, cnt = 0, len, M, rem;
    //READ()
    //WRITE()
    cin >> N >> M;
    if(M == 0 || M > N)
    {
        //cout << "X" << NL;
         cout << N << NL;
         return 0;
    }
    else
    {
        //cnt = N / M;
        rem = N % M;
        cout << rem << NL;
    }

   // cout << cnt << NL;

    return 0;
}
