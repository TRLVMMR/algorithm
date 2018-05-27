#include<stdio.h>

void dfs(int cur)
{
	int i,ok,j,equal,k;

	//返回0表示找到解了
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

		//判断放入i后的S数组还是不是困难串
		for(j = 1; j*2 <= cur+1; j++)//j*2 <= cur+1是为了保证j的终点是S的一半位置
		{
			equal = 1;
			for(k = 1; k < j; k++)
				if(S[cur-k] != S[cur-k-j])//每次对比两边的数，只要有一个不同，即整个不相同,接着调整j的位置继续对比
				{
					equal = 0;
					break;
				}
			if(equal)//只要找到相同的串相邻，则不是困难串，换一个i值放入
			{
				ok = 0;
				break;
			}
				
		}
		
		if(ok)//如果放入i后还符合困难串，继续放下一个
		{
			if(!dfs(cur+1))//如果找到解了，直接退出
				return 0;
		
		}
	}
	

}

int main()
{
	

}