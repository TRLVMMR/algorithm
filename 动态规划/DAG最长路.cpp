#include<stdio.h>
#include<algorithm>
#define INF 65536

int dp[256] = {0},flag[256];
int choice[256]={-1};//��¼���ĺ�̣���һ����
int G[50][50],n;

int DP(int i)
{
	int j,temp;
	if(dp[i] > 0)	return dp[i];//���dp[i]�����
	
	for(j = 1; j < n; j++)
	{
		if(G[i][j] != INF)
		{
			//�൱��max(dp[i],DP[j] + G[i][j])������Ϊ�˼�¼��̣���ֳ�����
			temp = DP(j) + G[i][j];
			if(temp < dp[i])
			{
				dp[i] = temp;
				choice[i] = j;
				
			}
		}	
	}

	return dp[i];
}

//β�ݹ�������
void PrintPath(int i)
{
	if(-1 == i)	return;//�߽缴ѭ�����ж�

	printf("->%d",choice[i]);
	PrintfPath(choice[i]);//�൱��i = choice
	/*
	β�ݹ�ɻ���
	while(choice[i] == -1)
	{
		i = choice[i];
		printf("->%d",i);//�൱�ڵݹ���printf��ݹ飬��ѭ����printf����жϣ�
	}
	*/
}

int main()
{
	//��Ҫ�ѱ߽��ʼ��

	return 0;
}