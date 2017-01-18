// Codeforces 291A - Spyke Talks.cpp
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
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int sz = 1e4;

typedef unsigned long long ull;//NOTES:"%llu"
typedef long long ll;//NOTES:"%lld"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

typedef stack<int> si;
typedef queue <int> qi;
typedef vector <int> vi;
typedef pair <ll, ll> pll;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef map <char, int> mci;
typedef map <string, int> msi;
typedef pair <string, int> psi;
typedef map <string, string> mss;

template<class T> inline void checkmin(T &a,T b){ if(b < a) a = b; }//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){ if(b > a) a = b; }//NOTES:checkmax(
template<class T> inline T sqr(T x){ return x * x; }//NOTES:square
template<class T> inline T _max(T a,T b){ return (a > b) ? a : b; }
template<class T> inline T _min(T a,T b){ return (a < b) ? a : b; }
template<class T> inline T _pow(T base, T power){ T I,result = base; if(power == 0) return 1;
	for (I = 0; I < power - 1; I++)
		result = result * base;
	return result;
}
//Translator
bool isUpperCase(char c){ return c >= 'A' && c <= 'Z'; }//NOTES: isUpperCase(
bool isLowerCase(char c){ return c >='a' && c <= 'z'; }//NOTES: isLowerCase(
bool isVowel(char c) { return (c == 'a'|| c == 'e'|| c == 'i'|| c == 'o'|| c == 'u'|| c == 'A'|| c == 'E'|| c == 'I'|| c == 'O'|| c =='U'); }//NOTES: isVowel(
bool isLetter(char c){ return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }//NOTES: isLetter(
bool isDigit(char c){ return c >= '0' && c <= '9'; }//NOTES:isDigit(
char toLowerCase(char c){ return (isUpperCase(c))?(c+32) : c; }//NOTES: toLowerCase(
char toUpperCase(char c){ return (isLowerCase(c))?(c-32) : c; }//NOTES: toUpperCase(
int toInt(string s){ int r=0;istringstream sin(s); sin >> r; return r; }//NOTES:toInt(
double toDouble(string s){double r=0; istringstream sin(s); sin >> r; return r; }//NOTES:toDouble(
// ENDTEMPLATE_BY_ZAYED

int a[sz];

int main()
{
	std::ios_base::sync_with_stdio(0);
    int tcases, caseno=1, n, I, K = 0, cnt = 0;

    scanf("%d",&n);
    for(I  = 0; I < n; I++)
        scanf("%d",&a[I]);

    sort(a, a + n);
    int tmp = 0; bool flag = false;
    for(I = 0; I < n - 1; I++){
        if(a[I] == a[I + 1] & a[I] != 0){
            tmp++;
            if(tmp >= 2){
                flag = true;
                break;
            }
        }
        else
            tmp = 0;
    }

    if(flag == false){
        for(I = 0; I < n; I++){
        if(a[I] == 0)
            continue;
        for(K = I + 1; K < n ; K++){
            if(a[I] == a[K] )
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    else
        printf("-1\n");

    return 0;
}
