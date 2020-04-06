#include <bits/stdc++.h>
using namespace std;
int main(){
    int T,n,q=0;
    scanf("%d",&T);

    while(T--){
        q++;
        int K;
        cin>>K;
        if(K==0){
            int a,b,c,meat;
            cin>>meat;
            a=meat/3;
            meat=meat-a;
            b=(meat*2)/3;
            c=meat-b;
            printf("Case %d:\n%d\n%d\n%d\n",q,a,b,c);
        }
        else{
            int n;
            cin>>n;
            int a,b,c;
            b=n*2;
            c=3*(n+b)/2;
            a=c/3;
            printf("Case %d:\n%d\n%d\n%d\n",q,a,b,c);
        }
	}
}
