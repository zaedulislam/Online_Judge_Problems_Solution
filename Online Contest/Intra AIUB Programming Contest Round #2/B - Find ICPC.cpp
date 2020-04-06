// B - Find ICPC.cpp
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

#define sf scanf
#define pf printf
#define READ() freopen("in.txt, "r", stdin)
#define WRITE() freopen("out.txt, "w", stout)
#define NL endl

const int SIZE = 1000 + 10;
const double PI = 2 * acos(0.0);

using namespace std;

string s;
//char s[SIZE];

int main()
{
    std::ios_base::sync_with_stdio(0);
    int tcases, caseno = 1, I, J, K, N, n, m, cnt = 0, len, lenT, t = 1;
    //READ()
    //WRITE()
    char ch;
    cin >> tcases;
    while(tcases--)
    {
        cnt = 0;
        /*fgets(s, SIZE, stdin);
        len = strlen(s);
        if(s[len - 1] != '\0')
            s[len - 1] = '\0';
        len--;*/

        cin.ignore();
        cin >> s;
        len = s.length();

        I = 0;
        while(I < len)
        {
            if(I +  3 < len && s[I] == 'I' && s[I + 1] == 'C' && s[I + 2] == 'P' && s[I+ 3] == 'C')
            {
                I += 4;
                cnt++;
            }
            else
                I++;
        }
        cout << "Case " << t << ": " << cnt << NL;
        t++;
        //fputs(s, stdout);
    }

    return 0;
}