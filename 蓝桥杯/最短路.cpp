#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAXV 20002
#define INF 9999999

using namespace std;

struct Note
{
 	int v;
	int w;	
};

vector<Note> a[MAXV]; 
bool flag[MAXV];
int dis[MAXV];

int main()
{	
	fill(dis, dis + MAXV, INF); 
	int n, m;

	freopen("最短路.txt", "r", stdin);
	//正确结果为0 1 8 4 13 17 
	scanf("%d %d", &n, &m);
	dis[1] = 0;
	
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		Note note;
		scanf("%d %d %d", &u, &v, &w);
		note.v = v;
		note.w = w;
		a[u].push_back(note);
		
		//初始化dis数组 
		if(u == 1)
		{
			dis[v] = w;
		}
		
	}
	
	
	for(int i = 1; i <= n; i++)
	{
		int min = INF;
		int u = -1;
		for(int j = 1; j <= n; j++)
		{
			if(!flag[j] && dis[j] < min)
			{
				min = dis[j];
				u = j;
			}
		}
		if(u == -1) continue;
		flag[u] = true;
		for(int j = 0; j < a[u].size(); j++)
		{
			int v = a[u][j].v;
			int w = a[u][j].w;
			if(dis[u] + w < dis[v] && !flag[v])
			{
				dis[v] = dis[u] + w;
			}
			
		}
		
		
	}
	
	for(int i = 2; i <= n; i++)
	{
		printf("%d\n", dis[i]);
	}
	
	return 0;
} 
