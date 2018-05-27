/*
	����һ����P����P�е�����ΪԪ�أ���ӡ���ǵ�����
	�磺����3��Ԫ�ظ�����
	������1,2,4����ӡ124,142,214,241,412,421
*/

#include<stdio.h>
#include<algorithm>
using namespace std;

void print_permutation(int n,int * P,int *A,int cur)
{
	int i,j;
	int c1,c2;

	//ÿ�δ�ӡһ��ȫ����
	if(cur == n)//�ݹ�߽�
	{
		for(i = 0; i < n; i++)
			printf("%d",A[i]);
		printf("\n");
	}
	else
	{
		for(i = 1; i <= n; i++)//������A[cur]�а�˳�����������P[i]
		{
			if (i == 0 || P[i] != P[i-1])//����P���������кõģ�ֻ��Ҫǰһ����������������
			{
				c1 = c2 = 0;
			 for (j = 0; j < cur; j++)    //�Ѿ����е�Ԫ����p[i]���ֵĴ���  
                {  
                    if (A[j] == P[i])  
                    {  
                        c1++;  //A�г���P[i]�ĸ���
                    }  
                }  
                for (j = 0; j < n; j++)      //ȫ��Ԫ����p[i]���ֵĴ���  
                {  
                    if (P[i] == P[j])  
                    {  
                        c2++; //P������P[i]���Ԫ�صĸ��� 
                    }  
                }  
                if (c1 < c2) //��֤����©��
                {  
                    A[cur] = P[i];  
                    print_permutation(n, P, A,cur+1);  
				}
			}
		}
	}
}

int main()
{
	int n,A[50] = {0},P[50] = {0};
	
	printf("������Ҫ����Ҫ���е�Ԫ�ظ�����������50\n");
	scanf("%d",&n);

	printf("������Ҫ�������е�Ԫ��");
	for(int i = 1; i <= n; i++)
		scanf("%d",&P[i]);
	
	sort(P,P+n);

	print_permutation(n,P,A,0);

	return 0;
}