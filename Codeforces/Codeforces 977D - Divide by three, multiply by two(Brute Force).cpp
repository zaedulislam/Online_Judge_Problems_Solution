// Codeforces 977D - Divide by three, multiply by two(Brute Force).cpp

/// Template by Zayed ///

/// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>

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

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"

#define INTMAX (1LL << 31) - 1
#define LLMAX (1LL << 63) - 1
#define MOD 1000000007		    // (10^9 + 7)
#define PRIME 999998727899999   // (largest prime below 10^16)
#define PB push_back
#define pii pair<int, int>
#define pic pair<int, char>
#define pci pair<char, int>
#define pLL pair<LL, LL>
#define pis pair<int, string>
#define psi pair<string, int>
#define pss pair<string, string>
//#define tiii tuple<int, int, int>
#define PI 2 * acos(0.0)
#define EPS 1e-11


// Numeric Functions
template< class T > bool Inside(T a, T b, T c) { return a <= b && b <= c; }
template < class T > inline void SWAP(T &a, T &b) { T t = a; a = b; b = t; }
inline LL POW(LL base, LL power){
	LL res = base; if (power == 0) return 1;
	for (int I = 0; I < power - 1; I++) res *= base; return res;
}


// Translator Functions
bool IsUpperCase(char c) { return c >= 'A' && c <= 'Z'; }//NOTES: IsUpperCase(
bool IsLowerCase(char c) { return c >= 'a' && c <= 'z'; }//NOTES: IsLowerCase(
bool IsLetter(char c) { return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }//NOTES: IsLetter(
bool IsVowel(char c) { return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'); }//NOTES: IsVowel(
int ToInt(string s) { int r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:ToInt(
double ToDouble(string s) { double r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:ToDouble(
string ToString(int n) { string s; stringstream convert; convert << n; s = convert.str(); return s; }//NOTES:ToString(


/*
*******4 Direction Array*******
int dx[] = {0, 0, -1, +1}, dy[] = {-1, +1, 0, 0};
*******8 Direction Array*******
int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1};
********Knight Moves********
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};
*/


const int SIZE = 100 + 10;
ULL ar[SIZE], newar[SIZE], ansarr[SIZE];
vector<ULL> two, three, baki;




int main()
{
	BOOST
	///READ();
	///WRITE();
	ULL T, I, J, K, N, n, m, k, cnt = 0, len, f = 0, x, temp3;


	cin >> n;
	for(I = 1; I <= n; I++)
		cin >> ar[I];

	sort(ar + 1, ar + n + 1);

	CLR(newar);
	CLR(ansarr);
	for(I = 1; I <= n; I++)
	{
		x = ar[I];
		newar[1] = x;
	
		for(J = 2; J <= n; J++)
		{
			if(x % 3 == 0)
			{
				temp3 = x / 3;

				f = 0;
				for(K = 1; K <= n; K++)
				{
					if(I != K && ar[K] == temp3)
					{
						f = 1;
						break;
					}
				}


				if(f)
				{
					x /= 3;
					newar[J] = x;
				}
				else
				{
					x *= 2;
					newar[J] = x;
				}


			}
			else
			{
				x *= 2;
				newar[J] = x;
			}

		}
		

		for(J = 1; J <= n; J++)
			ansarr[J] = newar[J];

		f = 0;
		sort(newar + 1, newar + n + 1);

		for(K = 1; K <= n; K++)
		{
			if(ar[K] != newar[K])
			{
				f = 1;
				break;
				
			}
			
		}


		if(!f)
		{
			cout << ansarr[1];
			for(J = 2; J <= n; J++)
				cout << ' ' << ansarr[J];

			cout << NL;
			break;
		}


		CLR(newar);
		CLR(ansarr);

	}



	return 0;

}