#include<iostream>
#include<vector>
#include<algorithm>
#define MAXV 256
#deiine INF 0x3fffffff

using namespace std;

struct Node
{	
	int v;
	int w;
};

vector<Node> Adj[MAXV];
int n, m;
int d[MAXV];
bool flag[MAXV];

int prim(int s)
{
	int ans = 0;
	fill(flag, flag + MAXV, false);
	fill(d, d + MAXV, INF);
	
	d[s] = 0;
	
	for(int i = 0; i < n; i++)
	{
		int min = INF;
		int u = -1;
		
		for(int j = 0; j < n; j++)
		{
			if(flag[j] == false && d[j] < min)
			{
				min = d[j];
				u = j;
			}
			
		}
		
		if(u == -1)
			return -1;
		
		flag[u] = true;
		ans = d[u];
		
		int size = Adj[u].size();
		for(int j = 0; j < size; j++)
		{
			int u = Adj[u][j].u;
			int w = Adj[u][j].w;
			
			if(flag[j] == false && d[u] > w)
			{
				d[u] = w;
			}
			
		} 
		
	}
	
	return ans;
}


int main()
{
	cin >> n >> m;
	
	while(m--)
	{
		int u, v, w;
		
		cin >> u >> v >> w;
		
		Node temp;
		temp.v = v;
		temp.w = w;
		
		Adj[u].push_back(temp);
	}
	
	prim(0);
	
	return 0;
}
