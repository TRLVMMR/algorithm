#include<stdio.h>

void dfs(int cur)
{
	int i,ok,j,equal,k;

	//����0��ʾ�ҵ�����
	if(cnt++ == n)
	{
		for(i = 0; i < cur; i++)
			printf("%c",'A'+S[i]);
		printf("\n");

		return 0;
	}

	for(i = 0; i < L; i++)
	{
		S[cur] = i;
		ok = 1;

		//�жϷ���i���S���黹�ǲ������Ѵ�
		for(j = 1; j*2 <= cur+1; j++)//j*2 <= cur+1��Ϊ�˱�֤j���յ���S��һ��λ��
		{
			equal = 1;
			for(k = 1; k < j; k++)
				if(S[cur-k] != S[cur-k-j])//ÿ�ζԱ����ߵ�����ֻҪ��һ����ͬ������������ͬ,���ŵ���j��λ�ü����Ա�
				{
					equal = 0;
					break;
				}
			if(equal)//ֻҪ�ҵ���ͬ�Ĵ����ڣ��������Ѵ�����һ��iֵ����
			{
				ok = 0;
				break;
			}
				
		}
		
		if(ok)//�������i�󻹷������Ѵ�����������һ��
		{
			if(!dfs(cur+1))//����ҵ����ˣ�ֱ���˳�
				return 0;
		
		}
	}
	

}

int main()
{
	

}