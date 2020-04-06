#include <bits/stdc++.h>
using namespace std;
int main(){
    map< string, int > M;
    int T,n,q=0;
    scanf("%d",&T);
    string str;
    while(T--){
        q++;
        int n;
        int max=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>str;
            M[str]++;
        }

		map<string,int >::iterator it = M.begin();
		while(it != M.end()){
			if(it->second>max){
				max= it->second;
				str= it->first;
			}
			it++;
		}
		cout<<"Case "<<q<<": "<<str<<endl;
		M.clear();
	}
}
