/*
	输入一串数P，以P中的数作为元素，打印他们的排列
	如：输入3（元素个数）
	再输入1,2,4；打印124,142,214,241,412,421
*/

#include<stdio.h>
#include<algorithm>
using namespace std;

void print_permutation(int n,int * P,int *A,int cur)
{
	int i,j;
	int c1,c2;

	//每次打印一个全排列
	if(cur == n)//递归边界
	{
		for(i = 0; i < n; i++)
			printf("%d",A[i]);
		printf("\n");
	}
	else
	{
		for(i = 1; i <= n; i++)//尝试在A[cur]中按顺序填各种整数P[i]
		{
			if (i == 0 || P[i] != P[i-1])//由于P数组是排列好的，只需要前一个数不等于它就行
			{
				c1 = c2 = 0;
			 for (j = 0; j < cur; j++)    //已经排列的元素中p[i]出现的次数  
                {  
                    if (A[j] == P[i])  
                    {  
                        c1++;  //A中出现P[i]的个数
                    }  
                }  
                for (j = 0; j < n; j++)      //全部元素中p[i]出现的次数  
                {  
                    if (P[i] == P[j])  
                    {  
                        c2++; //P中有与P[i]相等元素的个数 
                    }  
                }  
                if (c1 < c2) //保证不遗漏，
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
	
	printf("输入你要输入要排列的元素个数，不超过50\n");
	scanf("%d",&n);

	printf("输入你要进行排列的元素");
	for(int i = 1; i <= n; i++)
		scanf("%d",&P[i]);
	
	sort(P,P+n);

	print_permutation(n,P,A,0);

	return 0;
}