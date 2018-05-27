/*
	num��¼ĳ����Ӵ������ж��Ƿ���ڸ��������ĺ�Ϊ��������������num��������n-1
	�Ѷ���front���н��,����ѭ����ÿ���ɳھͽ��ɳڵĵ�����push
	ֱ������Ϊempty
	

*/
#include<stdio.h>
#include<vector>
#include<queue>
#define MAXV 50//��󶥵���

using namespace std;

struct Note
{
	int v,w;//u->v,Ȩֵw
};

vector<Note> G[MAXV];//ͼG��G[u]�����u�����ܵ�������ж���
int n,m;
int dis[MAXV];

bool SPFA(int s)
{
	queue<int> q;
	static int num[MAXV];
	bool inq[MAXV];

	memset(inq,false,sizeof(inq));

	//Դ����Ӳ���
	q.push(s);//��Դ�����
	inq[s] = true;//���Դ���ڶ�����
	num[s]++;//���Դ�����Ӽ�1

	while( !q.empty() )
	{
		//��¼���׶��㣬Ȼ�������
		int u = q.front();
		q.pop();
		inq[u] = false;

		//��������u��ɴ�������
		for(int j = 0; j < G[u].size(); j++)
		{
			int v = G[u][j].v;
			int w = G[u][j].w;
			
			//����dis��ֵ
			if(dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;

				//���v��û�ڶ����У���������
				if( !inq[v] )
				{
					q.push(v);
					inq[v] = true;
					num[v]++;

					if(num[v] >= n)		return false;//�пɴ︺��
				
				}
			}
		
		
		}

	
	}

	return true;

}

int main()
{
	int i,j,u,v,w;
	Note temp;

	printf("�����붥�����Լ�������");
	scanf("%d %d",&n,&m);
	
	//��ʼ���ڽӱ�
	printf("��������ĵ����Լ�Ȩֵ");
	for(i = 0; i < m; i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		temp.v = v;
		temp.w = w;
		G[u].push_back(temp);
	
	}

	return 0;
}