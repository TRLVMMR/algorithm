/*
	�����ɸ�һ�����ȵ�ľ���г�n�Σ�
	��Ŀ����֪n�θ�ÿ�γ��ȣ���ԭ����С�ĳ��� 
*/
#include<stdio.h>
#include<algorithm>

using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int n;
	
	while(scanf("%d", n) && n != 0)
	{
		int len[100] = {0};
		
		for(int i = 0; i < n; i++)
		{
			scanf("%d",&len[i]);
		}
		
		sort(len, len+n, cmp);
		

	}
	
	
	return 0;
}
