#include <bits/stdc++.h>
using namespace std;

int main(){
    string str[]={"FRIDAY","SATURDAY","SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY","THURSDAY"};
    string S;
    int T,q=0;
    cin>>T;
    while(T--){
        q++;
        int x,y;
        cin>>x>>y;
        cin>>S;
        int dif=y-x;
        
        dif=dif%7;
        if(dif<0)
            dif=7+dif;
        int i;
        for(i=0;i<7;i++){
            if(str[i]==S)
                break;
        }
        dif=(i+dif)%7;
        cout<<"Case "<<q<<": "<<str[dif]<<endl;
    }
}
