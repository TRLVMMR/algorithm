#include<stdio.h>


void print_permutation(int n,int *A,int cur)
{
	int i,j;

	//ÿ�δ�ӡһ��ȫ����
	if(cur == n)//�ݹ�߽�
	{
		for(i = 0; i < n; i++)
			printf("%d",A[i]);
		printf("\n");
	}
	else
	{
		for(i = 1; i <= n; i++)//������A[cur]�а�˳�����������i(�Ͼ���1-n��ȫ���У�ֻ����ô�������)
		{
			int ok = 1;			//��Ǵ˵�û����
			for(j = 0; j < cur; j++)
				if(A[j] == i)//���A���Ѿ����ˣ���Ƿ�����
					ok = 0;
			if(ok)//���A��û��i���ͷ���i
			{
				A[cur] = i;
				print_permutation(n,A,cur+1);
			
			}
		}
	
	
	}



}

int main()
{
	int n,A[50] = {0};

	printf("������Ҫ�����ĸ�����ȫ���У�������50\n");
	scanf("%d",&n);
	
	print_permutation(n,A,0);

	return 0;
}