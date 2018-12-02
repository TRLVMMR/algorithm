/*
	2017年10月11日21:50:32
*/
#include<stdio.h>

int n,f[256],sum;

//初始化所有强盗的首领是自己
void init()
{
	int i;
	for(i=1;i<=n;i++)
		f[i] = i;

}

int getf(int v)//不停向上找，直到找到首领,返回首领的编号
{
	if(f[v] == v)//如果v就是首领
		return f[v];
	else
	{
		f[v] = getf(f[v]);//不停递归，找到首领，最后把首领的编号给f[v]
		return f[v];
	
	}

}

void merge(int v,int u)
{
	int t1,t2;
	t1 = getf(u);
	t2 = getf(v);

	if(t1 != t2)//如果v,u两个首领不同 
		f[t2] = t1;//则让u团伙归顺v的首领，这样，原u团伙的首领就不是指向自己了。 
	//靠左原则。
	//让u团队首领归顺就行，跟着u那些等函数经过再“顺便”调整

}

int main()
{
	int i,x,y;

	printf("输入有多少个强盗");
	scanf("%d",&n);

	init();

	do
	{		
		printf("输入谁跟谁一伙的,输入p结束输入");
		scanf("%d %d",&x,&y);
		merge(x,y);
	}while('p' != getchar());
	
	for(i=1;i<=n;i++)
	{
		if(f[i] == i)
			sum++;
	}

	printf("强盗团伙有%d个\n",sum);
	getchar();
	getchar();

	return 0;
}
