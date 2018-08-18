// CodeChef GCDMOD - Modular GCD.cpp

/// Template by Zayed ///

///#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <iomanip>

#include <string>
#include <cstring>
#include <sstream>

//#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <map>
//#include<unordered_map>
#include <set>
//#include<unordered_set>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdlib>

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"

using namespace std;
int caseno = 1;

#define NL '\n'
#define SF scanf
#define PF printf
#define PC() printf("Case %d: ", caseno++)//NOTES:printf
//#define BUG() printf("\n!!!!!!WHERE IS YOUR FOCUS!!!!!!\n") //NOTES:printf

#define BUG cout << "\n!!!!!!WHERE IS YOUR FOCUS!!!!!!\n" //NOTES:cout
//#define PC cout << "Case "//NOTES:cout
//#define CN cout << caseno++ << ": "//NOTES:cout

#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define READ() freopen("input.txt", "r", stdin)
#define WRITE() freopen("output.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)

#define INTMAX (1LL << 31) - 1
#define LLMAX (1LL << 63) - 1
#define MOD 1000000007		    // (10^9 + 7)
#define PRIME 999998727899999   // (largest prime below 10^16)
#define PB push_back
#define pii pair<int, int>
#define pdd pair<double, double>
#define pic pair<int, char>
#define pci pair<char, int>
#define pLL pair<LL, LL>
#define pis pair<int, string>
#define psi pair<string, int>
#define pss pair<string, string>
//#define tiii tuple<int, int, int>
#define PI 2 * acos(0.0)
#define EPS 1e-11


template< class T > bool Inside(T a, T b, T c) { return a <= b && b <= c; }
template < class T > inline void SWAP(T &a, T &b) { T t = a; a = b; b = t; }
inline LL POW(LL base, LL P){
	LL res = 1;
	while(P > 0){ if(P & 1) res = res * base;
        base = base * base;
        P >>= 1;
	}
	return res;
}

//Translator Functions
int ToInt(string s) { int r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:ToInt(
double ToDouble(string s) { double r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:ToDouble(
string ToString(int n) { string s; stringstream convert; convert << n; s = convert.str(); return s; }//NOTES:ToString(

//int dx[] = {0, 0, -1, +1}, dy[] = {-1, +1, 0, 0}; //4 Direction Array
//int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1}; //8 Direction Array
//int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1}; //Knight Moves


const int SIZE = 1e6;




LL ModularMultiplication(LL a, LL b, LL mod)
{
    LL res = 0;
    a = a % mod;

    while(b > 0)
    {
        if(b & 1)
            res = (res + a) % mod;

        a = (a + a) % mod;
        b >>= 1;
    }

    return res;
}



LL BigMod(LL b, LL P, LL mod = MOD)
{
    LL res = 1 % mod, base = b % mod;
    while(P > 0)
    {
        if(P & 1)
            res = ModularMultiplication(res, base, mod) % mod;

        base = ModularMultiplication(base, base, mod) % mod;
        P >>= 1;
    }

    return res;
}



int main()
{
	BOOST
	///READ();
	///WRITE();
	LL T, I, J, K, N, n, m, k, cnt = 0, len, A, B, r;


    cin >> T;
    while(T--)
    {
        cin >> A >> B >> N;

        if(A == B)
            cout << BigMod(A, N, MOD) + BigMod(B, N, MOD) << NL;
        else
        {
            r = BigMod(A, N, abs(A - B)) + BigMod(B, N, abs(A - B));
            cout << __gcd(abs(A - B), r) % MOD << NL;
        }

    }


	return 0;
}
