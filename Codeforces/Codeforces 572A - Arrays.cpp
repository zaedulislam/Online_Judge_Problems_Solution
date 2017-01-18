// Codeforces 572A - Arrays.cpp
#include<iostream>
#include<cstdio>

#include<cstring>
#include<string>
#include<sstream>

#include<cmath>
#include<cstdlib>
#include<cctype>
#include<ctime>

#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

#define  LL long long
#define MAX 100005
#define MOD 1000000007

#define NL '\n'

using namespace std;

// BEGINTEMPLATE_BY_ZAYED
typedef unsigned long long llu;
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int sz = 1e5 + 10;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
template<class T> inline T sqr(T x){return x*x;}//NOTES:square
int _max(int a,int b){return (a > b) ? a : b;}
int _min(int a,int b){return (a < b) ? a : b;}
 inline int _pow(int base, int power){
	int I,result = base;
	for (I = 0; I < power - 1; I++) {
		result = result * base;
	}
	return result;
}
//Translator
bool isUpperCase(char c){return c>='A' && c<='Z';}//NOTES: isUpperCase(
bool isLowerCase(char c){return c>='a' && c<='z';}//NOTES: isLowerCase(
bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}//NOTES: isLetter(
bool isDigit(char c){return c>='0' && c<='9';}//NOTES:isDigit(
char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}//NOTES: toLowerCase(
char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}//NOTES: toUpperCase(
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toInt(
// ENDTEMPLATE_BY_ZAYED

int A[sz];
int B[sz];

int main()
{
	int n1,n2,k,m,I;
	scanf("%d%d%d%d",&n1,&n2,&k,&m);

	for(I = 0 ; I < n1; I++)
		scanf("%d",&A[I]);
	for(I = 0 ; I < n2; I++)
		scanf("%d",&B[I]);

	if(A[k - 1] < B[n2 - m])
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}
