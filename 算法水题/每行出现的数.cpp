/*
	��ĿҪ������һ�������ҳ�ÿ�ж����ֵ����� 
	
		������
			 

*/
#include<iostream>
#include<vector> 
#define MAXV 256

using namespace std;

int a[MAXV][MAXV];
int n, m;

int num[MAXV];//�洢�������ֵ����飬���ȴ��һ�е�������Ϊ��������û�ڵ�һ�г��֣�����Ҳ������ÿ�ж����� 
int count[MAXV];//��Ӧ���ֳ��ִ���������

//����param��num������������û�У�����-1 
int find_num(int param)
{
	for(int j = 0; j < m; j++)
		if(num[j] == param)
			return j;	
	return -1;
} 

int seachSame()
{
	//�ѵ�һ�е����ּ���洢���� 
	for(int j = 0; j < m; j++)
		num[j] = a[0][j];

	for(int i = 1; i < n; i++)
	{ 
		for(int j = 0; j < m; j++)
		{	
			
			int index = find_num(a[i][j]);
			if(index != -1 && count[index] == i - 1)
			{
				count[index]++;
			
			}
			
		}
	}
	
	int max = -1;
	int maxv = -1;
	for(int j = 0; j < m; j++)
	{
		if(max < count[j])
		{
			max = count[j];
			maxv = j;
		}
	}
	
	return num[maxv];
}

int main()
{
	
	freopen("same1.in", "r", stdin);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			
		}
	}
	
	cout << seachSame() << endl;
	
	
	return 0;
} 
