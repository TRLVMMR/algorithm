#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

vector<int> G[100];//�ڽӱ�
int n,m,inDegree[100];//�����������

bool topologicalSort()
{
	int num = 0;

	queue<int> q;

	for(int i= 0; i < n; i++)
	{
		if(0 == inDegree[i])//�ҳ��������Ϊ0�Ķ���,�������
			q.push(i);	
	
	}

	while(!q.empty())//ֻҪ���в�Ϊ��
	{
		int u = q.front();//ȡ����Ԫ��
		
		
		for(int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i];//ȡu�ĺ�̽ڽ��
			inDegree[v]--;	//����v����ȼ�һ
			if(0 == inDegree[v])//������Ϊ0�����
				q.push(v);

		}
		q.pop();//���׳�����
		num++;//ÿ�γ���һ�Σ�num��һ�������������ڵ�������Ϊ�յĶ�����
	}


	if(num == n)//������ж��㶼�����ˣ�����true
		return true;
	else//����������ж��㶼�����ˣ����ڽӱ�ش��ڻ�������false
		return false;
}

int main()
{
	printf("�����붥����������\n");
	scanf("%d %d",&n,&m);

	printf("������n���ߣ���Ҫ���ڻ�");
	
	for(i = 0; i < m; i++)
	{
		

	}
	


	return 0;
}