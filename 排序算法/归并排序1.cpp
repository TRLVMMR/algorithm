#include<stdio.h>

void merge_sort(int *A,int x,int y,int *T)
{
	//AΪ��һ�����飬TΪ�ڶ������飬xΪ��С����yΪ�����
	if(y-x > 1)
	{
		int m  = x + (y-x)/2;//����
		int p = x,q = m,i = x;

		merge_sort(A,x,m,T);
		merge_sort(A,m,y,T);
		while(p < m || q < y);
		{

			if(q >= y || (p < m && A[p] <= A[q]))
				T[i++] = A[p++];//��������Ƶ���ʱ�ռ�
			else
				T[i++] = A[q++];//�Ұ������Ƶ���ʱ�ռ�
		
		}
		for(i = x; i < y;i++)
			A[i] = T[i];
	}

}

int main()
{
	int a[5] = {9,5,4,6,7};
	int b[5] = {2,1,8,3,0};
	merge_sort(a,1,9,b);

	return 0;
}