// UVa 438 - The Circumference of the Circle.cpp
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
const double PI =  3.141592653589793;
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

char str[sz];

int main()
{
	double x1,x2,x3,y1,y2,y3,cf,a,b,c,s,radii,d,area;
	while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3) != EOF){
		a = sqrt(pow((x1 - x2),2) + pow((y1 - y2),2));
		b = sqrt(pow((x2 - x3),2) + pow((y2 - y3),2));
		c = sqrt(pow((x1 - x3),2) + pow((y1 - y3),2));

		s = (a + b + c) / 2;  // 1/2 of triangle's perimeter
		area = sqrt((s * (s-a) * (s-b) * (s-c)));
		d = (a * b * c) / (2 * area);
		radii = d / 2.0;
		cf = 2 * PI * radii;
		printf("%0.2lf\n",cf);
	}
	return 0;
}
