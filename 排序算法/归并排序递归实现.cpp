#include<stdio.h>

//��A����ģ�[L1��R1],[L2��R2]�������򲢺ϲ�
void merge(int A[],int L1,int R1,int L2,int R2)
{
	int i = L1,j = L2;
	int temp[256],index = 0;//temp������ʱ��ţ�index��temp���±�

	while(i <= R1  &&  j <= R2)//���򲿷�
	{
		//ÿ�ΰ���������С�Ľ��бȽϣ�Ȼ��ѽ�С�ķŵ�temp��
		if( A[i] <= A[j] )
			temp[index++] = A[i++];
		if( A[j] <= A[i] )
			temp[index++] = A[j++];

	
	}

	//�������һ������������꣬�����һ������ʣ���������temp
	while( i <= R1 )
		temp[index++] = A[i++];
	while( j <= R2 )
		temp[index++] = A[j++];

	//��temp����Ż�ȥA����
	for(i = 0; i < index; i++)
		A[L1 + i] = temp[i];


}

//�ݹ�ʵ�ֹ鲢����
void mergeSort(int A[],int left,int right)//left������ߵ��±�
{
	if(left < right)
	{
		//ȡ[left,right]���е���л���(��ȡ������)
		int mid = (left + right) / 2;
		
		mergeSort(A, left, mid);
		mergeSort(A, mid+1, right);
	
		merge(A, left, mid, mid+1, right);//������������ϲ�������
	}
	//����ʱ������ֻ��һ�ţ�����ϲ��������ţ��ٷ���������������õ����ţ��ݹ鵽���ÿ�ζ�������õ�
}

//�ǵݹ�ʵ�ֹ鲢����

int main()
{
	int A[256];
	int i,n;

	printf("������Ҫ����ĸ���");
	scanf("%d",&n);

	printf("������%d����",n);
	for( i = 0; i < n; i++ )
		scanf("%d",&A[i]);
	
	mergeSort(A, 0, n-1);

	for( i = 0; i < n; i++ )
		printf("%d	",A[i]);

	getchar();
	getchar();
	return 0;
}