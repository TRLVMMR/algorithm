/*
	�˳������һ�����⣬����ɸ�������Ϊ1 2 3ʱ�����Ϊ0��ʵ�����������200���� 
	����������⡣Ӯһ��+200,��һ��-200 
	̰�ģ�ÿ�θ�����С���Ǿ��������� 
*/

#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int score = 0;
		int tian[1001] = {0}, king[1001] = {0};
		

		
		if(!n)	break;
		
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &tian[i]);
		}
		
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &king[i]);
		}
		
		sort(tian, tian+n);
		sort(king, king+n);
		
		//����û����cmp������sort�����Ǵ�С���������
		int j = n-1;//����ѭ���Ᵽֻ֤��ֻ��һ�Σ����������㣬��j������ٱ�Ҳ���� 
		for(int i = n-1; i >= 0; i--)
		{	
			int ok = 1;
			 
			for( ;j >= 0 ; j--)
			{
				if(tian[i] > king[j]) 
				{
					score += 200;
					j--;//��Ϊj�Ѿ��ȽϹ��ˣ���Ҫ����һ�����������һֱ��j��
					ok = 0;
					break;
				}
				if(tian[i] == king[j])
				{
					j--;
					ok = 0;
					break; 
				}
				
			}
			//����һ�����⣬��break��������Ҳ��ִ�д���䡣���� �ѽ��������OK 
			//����ﾶ������Ӯ���˹����ܵ����������ˣ�ʣ�µ���ƥ��Ͷ�������
			if(j < 0 && ok)
			{
				score -= 200; 
				
			}
			
		}
		
		printf("%d\n", score);
		
	}
	
	return 0;
}
