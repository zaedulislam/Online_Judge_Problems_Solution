// Codeforces 602A - Two Bases.cpp
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

#define  LL long long
#define MAX 100005
#define MOD 1000000007

#define NL '\n'

using namespace std;

// BEGINTEMPLATE_BY_ZAYED
typedef unsigned long long ull;
typedef long long ll;
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64


typedef stack<int>si;
typedef queue <int> qi;
typedef vector <int> vi;
typedef pair <ll, ll> pll;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef map <char, int> mci;
typedef map <string, int> msi;
typedef pair <string, int> psi;
typedef map <string, string> mss;

const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int sz = 100;
template<class T> inline void checkmin(T &a, T b){ if (b<a) a = b; }//NOTES:checkmin(
template<class T> inline void checkmax(T &a, T b){ if (b>a) a = b; }//NOTES:checkmax(
template<class T> inline T sqr(T x){ return x*x; }//NOTES:square
int _max(int a, int b){ return (a > b) ? a : b; }
int _min(int a, int b){ return (a < b) ? a : b; }
inline ull _pow(ull base, ull power){
	ull I, result = base;
	if (power == 0)
		return 1;
	for (I = 0; I < power - 1; I++) {
		result = result * base;
	}
	return result;
}
//Translator
bool isUpperCase(char c){ return c >= 'A' && c <= 'Z'; }//NOTES: isUpperCase(
bool isLowerCase(char c){ return c >= 'a' && c <= 'z'; }//NOTES: isLowerCase(
bool isLetter(char c){ return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }//NOTES: isLetter(
bool isDigit(char c){ return c >= '0' && c <= '9'; }//NOTES:isDigit(
char toLowerCase(char c){ return (isUpperCase(c)) ? (c + 32) : c; }//NOTES: toLowerCase(
char toUpperCase(char c){ return (isLowerCase(c)) ? (c - 32) : c; }//NOTES: toUpperCase(
int toInt(string s){ int r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:toInt(
double toDouble(string s){ double r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:toDouble(
// ENDTEMPLATE_BY_ZAYED


int main()
{
		ull a1[sz],a2[sz];
		ull dx, bx, X = 1, dy, by, Y = 1, I, dec1 = 0, dec2 = 0;
	
		scanf("%I64u%I64u", &dx, &bx);
		for (I = 0; I < dx; I++)
			scanf("%I64u", &a1[I]);

		scanf("%I64u%I64u", &dy, &by);
		for (I = 0; I < dy; I++)
			scanf("%I64u", &a2[I]);

		int P = 0;
		I = dx - 1;
		while (P < dx) {
			dec1 += a1[I] * _pow(bx, P);
			++P;
			I--;
		}
		
		P = 0;
		I = dy - 1;
		while (P < dy) {
			dec2 += a2[I] * _pow(by, P);
			++P;
			I--;
		}

		if (dec1 < dec2)
			printf("<\n");
		else if (dec1 > dec2)
			printf(">\n");
		else
			printf("=\n");
	
		return 0;
}



