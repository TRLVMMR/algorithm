#include<stdio.h>
#include<algorithm>

using namespace std;

struct Rice
{
	int unitp;
	int weight;
};


bool cmp(Rice a, Rice b)
{
	return a.unitp < b.unitp;
}

int main()
{
	int c;
	scanf("%d", &c);
	
	while(c--)
	{
		int n, m;//nΪ�ܽ�mΪ�������� 
		double allw = 0.0;//������ 
		Rice a[1000];
		
		scanf("%d %d",&n, &m);//
		
		for(int i = 0; i < m; i++)
		{
			scanf("%d %d", &a[i].unitp, &a[i].weight);
			
		}
		
		//�����۴�С�������� 
		sort(a, a+m, cmp);
		
		for(int i = 0; ; i++)
		{
			int price = a[i].unitp * a[i].weight;
			
			if(n >= price)
			{
				n -= price;
				allw += a[i].weight;
			}
			else
			{
				allw = allw + n * 1.0 / a[i].unitp;
				break;
			}
			
		}
		
		printf("%.2lf\n", allw);
		
	}
	
	return 0;
}
