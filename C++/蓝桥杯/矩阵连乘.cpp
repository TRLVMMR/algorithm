/*
	�˳����д��� 
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;


int factor[50][50];//�������� 
long long end[50][50]; 
long long rowbuffer[50];//���������л��壬��Ϊԭ��������Ԫ���ڼ����л���Ҫ�õ� 

void mertx_mult()
{
	
	
}


int main()
{
	int n, m;
	
	//cin >> n >> m;
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int temp;
			//cin >> temp;
			scanf("%d", &temp);
			factor[i][j] = temp;
			end[i][j] = temp;
		}
	}
	
	//end������һ����ͬ�������Գ˵Ĵ�����1 
	m--;
	while(m--)
	{
			
		//���һ������ĳ˷� 
	/*	for(int erow = 0; erow < n; erow++)
		{
			
			
			//������¼����Ԫ�ص�����
			int tcur = 0;
			//���һ�еļ��� 
			while(tcur < n)
			{
				int num = 0;//�������һ��Ԫ�صĽ�� 
				
				//�������У�ÿ��һ�б����꣬��ʼ������ͷ 
				int ecoul, srow;
				
				//������������ָ���ǵȼ۵ģ�һ������һ��Ҳ��				
				ecoul = srow = 0;
 				
 				//������������ָ��������������ָ��ȼ۵� 
 				int scoul = 0;
 				
			 	//���һ��Ԫ�صļ��� 
				while(ecoul < n)
				{
					//���һ����Ԫ�ظ�һ����Ԫ�ص���� 
					num = num + end[erow][ecoul++] * factor[srow++][scoul]; 
					
				}
					
				rowbuffer[tcur++] = num;
				scoul++;
				
			}
			
			//����ʱ��ŵ���������end 
			for(int i = 0; i < n; i++)
			{
				end[erow][i] = rowbuffer[i];
			}
			
		}*/
		
		/*
			������������ۣ������޸ĳɼ򵥵�д�� 
		*/
		
		//���һ������ļ��� ,iΪ�б���ָ�� 
		for(int i = 0; i < n; i++)
		{
		
			//���һ�еļ��� ,jΪ�б���ָ�� 
			for(int j = 0; j < n; j++)
			{
				long long num = 0;
				//���һ��Ԫ�صļ��� 
				for(int k = 0; k < n; k++)
				{
					num = num + end[i][k] * factor[k][j];
					
				}
					
				rowbuffer[j] = num;
			} 
			
			//����ʱ��ŵ���������end 
			for(int u = 0; u < n; u++)
			{
				end[i][u] = rowbuffer[u];
			}
			
			
		}
		
		
	
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n - 1; j++)
		{
			printf("%d ", end[i][j]);
			//cout << end[i][j] << " ";
		}
		printf("%d\n", end[i][n-1]);
		//cout << end[i][n-1] << endl;
	}
	
	
	return 0;
}
