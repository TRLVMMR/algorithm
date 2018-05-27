//创建日期：2017.10,2
//修改日期：2017.10.8
#include<stdio.h>

int a[256],book[256],n,t;//n表示最大的牌，a数组即存放牌的箱子

void dfs(int step)//除了输出那次，执行一次放一张牌
{
	int i;//i表示哪张牌，1号，2号，3号牌

	if(n < step)//如果停在比最大的箱子还大的箱子前，证明没牌了
	{
		for(i=1;i<=n;i++)
			printf("%d",a[i]);
			printf("\n");
			t++;
		return;
	}

	for(i=1;i<=n;i++)
	{
		//如果没有此牌，什么都不做
		if(0 == book[i])//如果有这张牌，放进去盒子
		{
			a[step] = i;
			book[i] = 1;
			dfs(step+1);//一个盒子已经放好，走到下一个盒子，例如放123，此时在2这里
			book[i] = 0;//所有牌放完之后将牌收回，进行下一次尝试，例如放了123，下次尝试可能是132
		//	t++;//无法统计全排列种数，统计的是收回牌的次数
		}
	}

	return;
}

int main()
{
	printf("请输入需要全排列的数：");
	scanf("%d",&n);
	dfs(1);//先站在第一个盒子面前
	printf("总共有%d种可能性",t);
	getchar();
	getchar();

	return 0;
}