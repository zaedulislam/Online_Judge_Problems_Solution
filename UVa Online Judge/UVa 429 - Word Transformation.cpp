// UVa 429 - Word Transformation.cpp
///************************************************************///
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

#include <algorithm>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>

#include <cmath>
#include <cstdlib>
#include <cctype>
#include <ctime>
///************************************************************///
using namespace std;
int caseno = 1;
///************************************************************///
#define NL '\n'
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
#define SF scanf
#define PF printf
///************************************************************///
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define PC() printf("Case %d: ", caseno++)
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);
///************************************************************///
typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64
///************************************************************///
#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 200 + 10;
///************************************************************///

/*
*******4 Direction Array*******
int dx[] = {0, 0, - 1, 1}, dy[] = {-1, 1, 0, 0};

*******8 Direction Array*******
int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1};

********Knight Moves********
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};
*/

int visited[SIZE], level[SIZE];
string S;
vector<string> word;
vector<int> G[SIZE];
queue<int>qi;
map<int, string> MAP1;
map<string, int> MAP2;

void ParsingInput()
{
	string A, B;
	int I, J, K, cnt = 0, SZ = word.size(), lenA, lenB, Id = 1, u, v;
	for (I = 0; I < SZ; I++)
	{
		A = word[I];
		lenA = A.length();

		for (J = 0; J < SZ; J++)
		{
			B = word[J];
			lenB = B.length();
			cnt = 0;

			if (A != B && lenA == lenB)
			{
				for (K = 0; K < lenA; K++)
				{
					if (A[K] != B[K])
						cnt++;
				}
			}

			if (cnt == 1)
			{
				int f1 = 0, f2 = 0;
				if (MAP1[Id] == "" && MAP2[A] == 0)
				{
					MAP1[Id] = A;
					MAP2[A] = Id;
					Id++;
					f1 = 1;
				}
			
				if (MAP1[Id] == "" && MAP2[B] == 0)
				{
					MAP1[Id] = B;
					MAP2[B] = Id;
					Id++;
					f2 = 1;
				}
				
				u = MAP2[A];
				v = MAP2[B];

				G[u].push_back(v);
				G[v].push_back(u);

			}
		}
		///cout << B << NL;
	}
}

int BFS(int src, int target)
{
	while (!qi.empty())
		qi.pop();

	memset(visited, 0, sizeof(visited));
	memset(level, 0, sizeof(level));

	visited[src] = 1;
	level[src] = 0;
	qi.push(src);

	int I, u, v;
	while (!qi.empty())
	{
		u = qi.front();
		qi.pop();

		for (I = 0; I < G[u].size(); I++)
		{
			v = G[u][I];

			if (visited[v] == 0)
			{
				visited[v] = 1;
				level[v] = level[u] + 1;

				if (v == target)
					return level[v];

				qi.push(v);
			}
		}
	}
}


int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, u, v;
	///READ();
	///WRITE();
	cin >> tcases;
	while (tcases--)
	{
		word.clear();
		MAP1.clear();
		MAP2.clear();

		for (I = 0; I <= SIZE; I++)
			G[I].clear();

		while (1)
		{
			cin >> S;

			if (S == "*")
				break;

			word.push_back(S);
		}

		ParsingInput();

		/*
		for (I = 0; I < word.size(); I++)
			cout << word[I] << " = " << MAP2[word[I]] << NL;
		*/

		cin.ignore();

		while (1)
		{
			string A = "", B = "";
			getline(cin, S);
			
			if (S == "")
				break;

			int L = S.length(), f = 0;
			for (I = 0; I < L; I++)
			{
				if (S[I] == ' ')
				{
					f = 1;
					continue;
				}

				if (f == 0)
					A += S[I];
				else
					B += S[I];
			}

			u = MAP2[A];
			v = MAP2[B];
			///cout << "u = " << u << " v = " << v << NL;
			int t;
			if (u == v)
				t = 0;
			else
				t = BFS(u, v);

			cout << A << ' ' << B << ' ' << t << NL;
		}

		if (tcases)
			cout << NL;
	}
	return 0;
}


