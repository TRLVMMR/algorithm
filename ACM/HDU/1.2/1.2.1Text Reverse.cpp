/*
	����1:%s��ȡ�ַ���ʱ�������ո�ͽ�����������puts 
	����2���ڹ���j��forѭ���а�j��ֵ���ˣ����µ��԰���
	����3����Ϊ�ַ������һ���ַ���\0ǰһ���ַ��� ��ʵ�Ǵ�ġ���������Ϊ�����Ҷ��һ���ַ����³��� 
	����4:���԰�gets�ĳ�fgets�����fgets�ǲ��Կո�� 
		 
*/
#define LOCAT 1
#include<stdio.h>
#include<string.h>


int main()
{
	#ifdef LOCAT
		freopen("1-2-1.in", "r", stdin);
	#endif
	char c[1001],d[1001];
	int n;
	scanf("%d",&n);
	getchar();
	
	for(int i = 0; i < n; i++)
	{
		int j, k = 0;
		memset(c, 0, sizeof(c));
		memset(d, 0, sizeof(d));
		
		//����1�� 
		gets(c); 
	//	fgets(c,1000,stdin);//����4��fgets���Կո񣬵��±�����Ҫ�Ķ�һ���ַ� 
	
		for(j = 0; j < strlen(c); j++)
		{
			if(c[j] == ' ')
			{
				int temp = j;
				while(k < j)
				{
					d[k++] = c[--temp];
				}
				d[k++] = ' ';//����������ո� 
				/*
					����2�� 
					һ��ʼ��дd[k++] = c[--j] 
					������ˣ�ԭ���������ǰ�j���ˣ�forѭ���ͻ���� 
				*/
			}
			
		}
		//�����һ���ո�\0ǰ���ַ�����d 
		int temp = j;
		while(k < j)
		{
			d[k++] = c[--temp];
		}	
		/*
		����3�� 
		һ��ʼ��while(k <= j)���������û���ύ�����Presentation Error����
		�����˻����˿հ��ַ�
		ԭ�����Ұ����һ������ǰ�Ŀո�Ҳ��ӡ�����ˣ�ֻ�������������  
		���ҵ��������ˣ���ȷ����ǣ����һ���ַ���\0��������\0ǰһ���ַ� 
		*/
		puts(d);
	//	fputs(d,stdout);
	}
	
	return 0;
}
