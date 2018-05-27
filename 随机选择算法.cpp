#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void swap(int *x,int *y)
{
	int k;
 	k = *x;
	*x = *y;
	*y = k;


}

int randPartition(int *a,int left,int right)
{
	int i,j;

	int p = ((int)(0.5 + 1.0 * rand()/RAND_MAX *(right - left) + left));

	i = left;
	j = right;

	swap(&a[left],&a[p]);
	
	while(i != j)
	{
		while(j > i && a[j] > a[left])
			j--;
		while(j > i && a[i] < a[left])
			i++;

		if(j > i)
			swap(&a[i],&a[j]);
	
	}

	swap(&a[left],&a[i]);
	
	return i;
}

//随机选择算法：找出你需要的第几大的数
void randSelect(int *a,int left,int right,int K)
{
	if(left == right) return;

	int p = randPartition(a,left,right);//找到p应有的位置
	int M = p - left + 1;//p在数组里是第M大

	if(M == K) return;

	if(K < M)//第K大的数在主元左侧
		randSelect(a,left,p-1,K);
	else
		randSelect(a,p+1,right,K-M);//K是主元右侧数组的K-M大

}

int main()
{
	int a[256];
	int i = 0,n = -1;

	srand((unsigned)time(NULL));

	printf("请输入需要排序的数，按p结束");

	do
	{		
		scanf("%d",&a[i]);
		i++;
		n++;

	}while('p' != getchar());

	randSelect(a,0,n-1,n/2);


	for(i=0;i<n;i++)
		printf("%d	",a[i]);

	getchar();
	getchar();
	return 0;
}