// UVa 762 - We Ship Cheap.cpp
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
const int sz = 1e6;

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
string S, T, n1, n2, u, v;
char s[sz];
int ar[sz];
int M[1000][1000];

map<string, vector<string> > G;
map<string, string> parent;
map<string, int> visited;
queue<string> Q;

string src, destination;

int bfs()
{
	while (!Q.empty()) Q.pop();
	parent.clear();
	
	visited[src] = 1;

	Q.push(src);
	int I,s;
	while (!Q.empty()){
		u = Q.front();
		if (u == destination) return visited[u];
		s = G[u].size();
		FOR(I, 0, s){
			v = G[u][I];
			if (visited[v] == 0){
				visited[v] = 1;
				parent[v] = u;
				Q.push(v);
			}
		}
		Q.pop();
	}
	return -1;
}

void printRoute(string n1, string n2)
{
	if (n1 == n2) return ;
	printRoute(parent[n1], n2);
	cout << parent[n1] << " " << n1 << NL;
}

int main()
{
	//std::ios_base::sync_with_stdio(0);
	int tcases, caseno = 1, n, I, J, K, N, cnt = 0, len, flag = 0;

	while (sf("%d", &n) != EOF){
		G.clear();

		while (n--){
			cin >> n1 >> n2;
			G[n1].push_back(n2);
			G[n2].push_back(n1);
			visited[n1] = 0;
			visited[n2] = 0;
		}
		cin >> src >> destination;
		if (flag) pf("\n"); 
		flag = 1;
		if (bfs() != -1) printRoute(destination, src);
		else pf("No route\n");

		visited.clear();
	}

	return 0;
}
