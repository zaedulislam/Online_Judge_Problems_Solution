// H - Valentine Fight.cpp
#include <iostream>
#include <cstdio>

#include <string>
#include <cstring>
#include <sstream>

#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>

#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#define LI long long int
#define MAXIMUM 100005
#define MOD 1000000007

#define NL '\n'
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
#define sf1(x) scanf("%d",&x)
#define sf scanf
#define pf1(x) printf("%d",x)
#define pf printf

using namespace std;

#define ll long long
#define inf 19999999991
void find_div(ll n1)
{
    int i,j,k;
    ll m,ans=inf;
    for(i=1;i<=sqrt(n1);i++)
    {
        if(n1%i==0)
        {
            m=n1/i;
            ans=min(ans,abs(m-i));

        }
    }
    cout<<ans<<endl;
}
int main()
{
    ll n,i,t,n1;
    scanf("%lld",&n);
    for(t=1;t<=n;t++)
    {
        scanf("%lld",&n1);
        find_div(n1);
    }
    return 0;
}
