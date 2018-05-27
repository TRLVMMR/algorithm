#include<stdio.h>


void print_permutation(int n,int *A,int cur)
{
	int i,j;

	//每次打印一个全排列
	if(cur == n)//递归边界
	{
		for(i = 0; i < n; i++)
			printf("%d",A[i]);
		printf("\n");
	}
	else
	{
		for(i = 1; i <= n; i++)//尝试在A[cur]中按顺序填各种整数i(毕竟是1-n的全排列，只有这么多可能性)
		{
			int ok = 1;			//标记此点没放入
			for(j = 0; j < cur; j++)
				if(A[j] == i)//如果A里已经有了，标记放入了
					ok = 0;
			if(ok)//如果A里没有i，就放入i
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

	printf("输入你要输入哪个数的全排列，不超过50\n");
	scanf("%d",&n);
	
	print_permutation(n,A,0);

	return 0;
}