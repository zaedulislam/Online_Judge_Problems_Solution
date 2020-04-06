// B - Ditto and String.cpp
#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<sstream>

#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>

#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>

#define NL '\n'
#define FOR(I,J,K) for(I = J;  I < K; I++)
#define FOR(I,J,K) for(I = J; I > K; I--)
#define R() freopen("in.txt", "r", stdin)
#define W() freopen("out.txt", "w", stdout)
#define PC() printf("Case %d: ", caseno++)
#define sf scanf
#define pf printf
#define INF 2147483647
#define MOD 100000007
#define pii pair<int, int>

//bool isVowel(char c){ return (c == )}
//char toUppercase(char c){ return }


const int PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e6;
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

string S;

int main()
{
    //std::ios_base::sync_with_stdio(0);
	int tcases, caseno = 1, I, K, N, M, n, m, cnt = 0, len;
	//R();
	// W();
	cin >> S;
	len = S.length();

	for(I = 0;  I < len; I++){
		if(S[I] == 'a' || S[I] == 'e' || S[I] == 'i' || S[I] == 'o' || S[I] == 'u'){
			S[I] = S[I] - 32;
		}
	}
	cout << S << NL;
	//pf("\n");
    //cout << "Hello world!" << NL;
    return 0;
}
