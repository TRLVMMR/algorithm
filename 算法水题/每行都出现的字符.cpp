/*
	���ÿ�ж����ֵ��ַ�������ж��������ֵ�����С�� 
	
	˼·����¼ÿ���ַ����һ�γ��ֵ�������ͨ���ж�ÿ���ϴγ���������һ�У�  
	
	map��������ֵ�����С��, �ײ��������Զ����� 
	
	α���룺
		��������� i ��
			��������� j ��
				if ���ַ�û�г��֣����뼯��
				else if �жϴ��ַ������������Ƿ���i - 1�� �ǵĻ�+=1, 
	
		�������ϣ�
			��������������n-1�����				 
*/
#include<iostream>
#include<map>
#define MAXV 256 

using namespace std;

char a[MAXV][MAXV];
int n, m;

char seachSame()
{
	map<char, int> num;//�������г������ֵļ��� 
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			//���û�г��� 
			if(num.find(a[i][j]) == num.end())
				num[a[i][j]] = 0;
			//ÿ��ֻ�������һ�� 
			else if(num[a[i][j]] == i - 1)
				num[a[i][j]]++;	
		}
	
	}
	
	int max = -1;
	char maxc = 0;
	
	map<char, int>::iterator it;
	for(it = num.begin(); it != num.end(); it++)
	{
		if(n - 1 == it->second)
			return it->first;
	}
	
	return 0; 
}

int main()
{
	freopen("same2.in", "r", stdin);
	
	cin >> n >> m;
	cout << n << m << endl; 
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
