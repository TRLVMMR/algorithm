/*
	2017��10��9��17:36:15
	ϡ��ͼ���ڽӱ�����ͼ���ڽӾ���
	���������ǵ����
*/
#include<stdio.h>

int main()
{
	int i,n,m,k;
	int u[6],v[6],w[6];//Ҫ����ʵ����������ã���m���ֵ��1
	int frist[5],next[5];//Ҫ����ʵ��������ã���n���ֵ��1

	scanf("%d %d",&n,&m);

	for(i=1;i<=n;i++)
		frist[i] = -1;



	for(i=1;i<=m;i++)
	{
		printf("��������ĵ����Լ�Ȩֵ");
		scanf("%d %d %d",u[i],v[i],w[i]);

		next[i] = frist[u[i]];//����i��Ҫ����first��ֵ�����������ݷŵ�next��i�μ�¼��λ��
		frist[u[i]] = i;//����first��ֵ������i�ζ�����Ϊu[i]�Ķ���
	
	
	}

	for(i=1;i<=n;i++)
	{//������iΪ�������б�
		k = frist[i];//k��ֵ��������Ѱ��next��ŵ�ֵ
		while(k!=-1)
		{
			printf("%d %d %d\n",u[k],v[k],w[k]);
			k = next[k];//����һ�εĴ�����K�����ʹ�õ��������iΪ�������б�
		
		}
	
	}


	return 0;
}