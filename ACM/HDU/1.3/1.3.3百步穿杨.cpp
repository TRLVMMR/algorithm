/*

*/

#include<stdio.h>
#include<algorithm>

using namespace std;

struct Arrow
{
	int len;//������ 
	int sum;//������ 
};

bool cmp(Arrow a, Arrow b)
{
	return a.len < b.len;
}

int main()
{
	int t;
	
	scanf("%d", &t);
	while(t--)
	{
		int n;
		Arrow a[30];
		
		scanf("%d", &n);
		
		for(int i = 0; i < n; i++)
		{		
			scanf("%d %d", &a[i].len, &a[i].sum);
			a[i].len -= 2;//�����2��+ + 
		}
		
		sort(a, a+n, cmp);
		for(int i = 0; i < n; i++)
		{
			while(a[i].sum--)
			{
				printf(">+");
				for(int j = 0; j < a[i].len; j++)//
				//while((a[i].len)--)//���⣬������ѭ������while��x--����Ϊx=0��ִ�к���ѭ����һ�ֺ�x�ͻ���ԶΪ���� 
				{
					printf("-");
				}
				

				printf("+>\n");
			}
			printf("\n");
		}
	}
	
	
}
