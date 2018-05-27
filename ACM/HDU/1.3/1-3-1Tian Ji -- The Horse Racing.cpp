/*
	̰��1����������Ӯ��Ӯ�����һ�Ҫ̰Ӯ������Ӯ��̰�䣺����������ȥ�� 
	̰��2�����������ֻ��ƽ���ǾͿ��������� 
			��1����������� > ���������죺	Ӯtmd
			��2����������� < ������������	����ȥ���ѣ�̰�� 
			��3����������� == ��������		���ɷ����� ��̰�� 
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
		int ks = 0, kq = n-1;//����ѭ���Ᵽֻ֤��ֻ��һ�Σ����������㣬��j������ٱ�Ҳ����
		int s = 0, q = n-1;
		
		//ֻҪ��ɿ��������� 
		while(s <= q)
		{			 
			//��� > ���� 
			if(tian[q] > king[kq]) 
			{
				kq--;
				q--;
				score += 200;
			}
			//��� == ���� 
			else if(tian[q] == king[kq])
			{
				// ֱ����ɵ����� <= ��������
				while(1)
				{
					if(tian[s] > king[ks])
					{
						s++;
						ks++;
						score += 200;
					}
					//��ɵ����� <= ��������
					else
					{
						//������� == ���� (��ʱ��������һ���ٶ���)
						if(tian[s] == king[kq])
						{
							s++;
							kq--;
						}
						else
						{
							s++;
							kq--;
							score -= 200;
						}
							break;
					}
				}
			}
			//��� < ���� 
			else
			{
				//���ȿ� 
				kq--;
				s++;//����ȥ���� 
				score -= 200;		
			}
		
			
		}
		
		printf("%d\n", score);
		
	}
	
	return 0;
}
