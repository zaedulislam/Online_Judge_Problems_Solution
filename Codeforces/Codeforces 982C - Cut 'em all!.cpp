// Codeforces 982C - Cut 'em all!.cpp

// Template by Zayed 

#include bitsstdc++.h


using namespace std;
#define NL 'n'
#define BOOST stdios_basesync_with_stdio(0);
#define PB push_back



const int SIZE = 1e5 + 10;
vectorint G[SIZE];
bool visited[SIZE];




int DFS(int u, int& res)
{
    visited[u] = true;
    int I, v, SZ = G[u].size(), cnt = 0;

    for (I = 0; I  SZ; I++)
    {
        v = G[u][I];
        if (!visited[v])
        {
            int subtreeNodeCount = DFS(v, res);

            if (subtreeNodeCount % 2 == 0)
                res++;
            else
                cnt += subtreeNodeCount;

        }
    }

    return (cnt + 1);
}



int main()
{
	BOOST
	READ();
	WRITE();
	int T, I, J, K, N, n, m, k, cnt = 0, len, u, v;

	cin  n;

	for(I = 0; I  n - 1; I++)
	{
		cin  u  v;
		G[u].PB(v);
		G[v].PB(u);

	}


	if(n & 1)
	{
		cout  -1  NL;
		return 0;
	}


	int res = 0;
	for(I = 1; I = n; I++)
	{
		if(!visited[I])
		{
			DFS(I, res);
			break;
		}

	}

	cout  res  NL;

	return 0;

}