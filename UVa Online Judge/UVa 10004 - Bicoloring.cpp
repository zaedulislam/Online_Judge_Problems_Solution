// UVa 10004 - Bicoloring.cpp
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

//#define  LL long long
#define MAX 100005
#define MOD 1000000007

#define NL '\n'
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
#define sf1(x) scanf("%d",&x)
#define sf scanf
#define pf1(x) printf("%d",x)
#define pf printf

using namespace std;

// BEGINTEMPLATE_BY_ZAYED
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int sz = 1e5;

typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long LL;//NOTES:"%lld"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

typedef stack<int> SI;
typedef queue <int> QI;
typedef vector <int> VI;
typedef pair <LL, LL> PLL;
typedef map <int, int> MII;
typedef pair <int, int> PII;
typedef map <char, int> MCI;
typedef map <string, int> MSI;
typedef pair <string, int> PSI;
typedef map <string, string> MSS;

template<class T> inline void checkmin(T &a, T b){ if (b < a) a = b; }//NOTES:checkmin(
template<class T> inline void checkmax(T &a, T b){ if (b > a) a = b; }//NOTES:checkmax(
template<class T> inline T sqr(T x){ return x * x; }//NOTES:square
template<class T> inline T _max(T a, T b){ return (a > b) ? a : b; }
template<class T> inline T _min(T a, T b){ return (a < b) ? a : b; }
template<class T> inline T fAbs(T a) { return a< 0 ? a * (-1) : a; }
template<class T> inline void SWAP(T &a, T &b) { T t = a; a = b; b = t; }
LL POW(LL base, LL power){
	LL I, res = base; if (power == 0) return 1;
	for (I = 0; I < power - 1; I++) res *= base;
	return res;
}
//Translator
bool isUpperCase(char c){ return c >= 'A' && c <= 'Z'; }//NOTES: isUpperCase(
bool isLowerCase(char c){ return c >= 'a' && c <= 'z'; }//NOTES: isLowerCase(
bool isVowel(char c) { return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'); }//NOTES: isVowel(
bool isLetter(char c){ return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }//NOTES: isLetter(
bool isDigit(char c){ return c >= '0' && c <= '9'; }//NOTES:isDigit(
char toLowerCase(char c){ return (isUpperCase(c)) ? (c + 32) : c; }//NOTES: toLowerCase(
char toUpperCase(char c){ return (isLowerCase(c)) ? (c - 32) : c; }//NOTES: toUpperCase(
int toInt(string s){ int r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:toInt(
double toDouble(string s){ double r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:toDouble(
string toString(int n){ string s; stringstream convert; convert << n; s = convert.str(); return s; }//NOTES:toString
// ENDTEMPLATE_BY_ZAYED

// fflush(stdout);
string S, T;
char s[sz];
int ar[sz];
int M[1000][1000];
VI G[1000];
QI Q;
int visited[1000], colour[1000];
const int Black = -1, White = -2;


int main()
{
	//std::ios_base::sync_with_stdio(0);
	int tcases, caseno = 1, n, I, J, K, N, cnt = 0, len, u, v, s, flag, src, node, edge;

	while (sf("%d", &node)){
		if (node == 0) break;
		sf("%d", &edge);
		FOR(I, 0, 1000) G[I].clear();

		FOR(I, 0, edge){
			sf("%d%d", &u, &v);
			if (I == 0) src = u;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		flag = 0;
		FOR(I, 0, 1000){
			visited[I] = 0; colour[I] = 0;
		}

		while (!Q.empty()) Q.pop();

		visited[src] = 1;
		colour[src] = Black;

		Q.push(src);

		while (!Q.empty()){
			u = Q.front();

			s = G[u].size();
			FOR(I, 0, s){
				v = G[u][I];

				if (!visited[v]) {
					visited[v] = 1;
					if (colour[u] == Black) colour[v] = White;
					else if (colour[u] == White) colour[v] = Black;
					Q.push(v);
				}
				else{
					if (colour[u] == colour[v]) {
						flag = 1; break;
					}
				}
			}
			Q.pop();
			if (flag) break;
		}
		if (flag) pf("NOT BICOLORABLE.\n");
		else pf("BICOLORABLE.\n");
	}

	return 0;
}
