#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#define MAXN 11111 
#define INF 9999999

using namespace std;


struct Note
{
	int v;
	int w;	

};

vector<Note>d[MAXN];
bool book[MAXN];//����Ƿ��ڶ����� 
int num[MAXN];//������д��� 

//Դ�㵽��������ľ��� 

int dis[MAXN] = {INF};
int n, m;

bool SPFA(int s)
{
	memset(num, 0, sizeof(num));
	memset(book, false, sizeof(book));
	fill(dis, dis + MAXN, INF );
	
	queue<int> q;
	dis[s] = 0;
	q.push(s);
	book[s]	= true;
	num[s]++;
	
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		book[u] = false; 
		
		for(int i = 0; i < d[u].size(); i++)
		{
			int v = d[u][i].v;
			int w = d[u][i].w;
			
			//��������ɳڣ����ɳ�			
			if(dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;
				
				//���û�ڶ����У���� 
				if(!book[v])
				{
					q.push(v);
					book[v] = true;
					num[v]++;
					
					//�������n-1�Σ���֤���и��� 
					if(num[v] > n - 1)
					{
						return false;
					}
					
				} 
			}
			
		}
		
		
	}
	
	return true;
}


int main()
{

	
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < m; i++)
	{
		int u;
		Note temp;
		scanf("%d %d %d", &u, &temp.v, &temp.w);
		d[u].push_back(temp);
	}
	
	if( SPFA(1) )
	{
		//���Դ��1������n-1��������·�� 
		for(int i = 2; i <= n; i++)
		{
			printf("%d\n", dis[i]);
		
		} 
	}
	
	return 0;
} 
