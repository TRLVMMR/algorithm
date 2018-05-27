/*

	2/3 = 1/2 + 1/6
	分子为1
	加数个数越少越好，
	如果加数个数相同，最大的分母越小越好，
	加数不允许相同

*/

#include<stdio.h>
#include<string.h>
#define UNI int
//#define UNI unsigned int 出错，估计是unsigned跟int的转化中出现负数或者超大的数，然后用这个数入访问ans或者v数组，所以报错
int ans[100],v[100];//ans存放分母最优解，v存放分母
int maxd;

int max(int a,int b)
{
	return a > b ? a : b;
}

//辗转相除法求最大公因数
int mult(int x, int y)
{
	int a = x, b = y, c;

	while(b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	
	return a;
}

//返回1/c <= a/b最小的c（即最大那个分数）
int get_first(int a,int b)
{
	int mul;
	
	//分数化简
	mul = mult(a,b);
	a = a/mul;
	b = b/mul;

	for(int i = 1; ; i++)
	{
		if((1.0 / i) <= (a * 1.0)/(b * 1.0))//此句也可放在for循环判断里
			  break;
	}

	return i;
}

//更新最优解的问题
bool better(int d)
{
	int i;
	//将得到的解v倒着跟ans每个元素比较，如果比ans小，或者ans没有更新，返回true
	for( i = d; i >= 0; i--)
	{
		if(v[i] != ans[i])
		{
			return ans[i] == -1 || v[i] < ans[i];
		}
	}
	

	return false;
}

//当前深度d,分母不能小于from,剩余分数之和为aa/bb
bool dfs(int d, int from, UNI aa, UNI bb)//aa为分子，bb为分母
{
	//递归边界
	if(d == maxd)
	{
		//必须是埃及分数（分子为1）
		if(bb % aa)		return false;
		 v[d] = bb/aa;
		 //若是更好的解，把v的值给ans
		 if(better(d))
			 memcpy(ans,v,sizeof(UNI) * (d+1));//拷贝v到ans
		 return true;
	}

	bool ok = false;
	from = max(from,get_first(aa,bb));
	for(int i = from;  ; i++)//迭代加深尝试各种分母
	{
		//最优性剪枝：把之后的所有项都放大成1/i,大小为(max+1-d)/i,如果还比aa/bb小，就剪枝
		if(bb * (maxd + 1 - d) <= i * aa) break;

		v[d] = i;//最后不用恢复全局变量：记录了深度d，回溯后，因为同层，v[d]会被覆盖
		// aa/bb - 1/i，然后约分
		UNI b2 = bb * i;
		UNI a2 = aa*i -bb;
		UNI g = mult(a2,b2);
		//放入成功，继续放下一个
		if(dfs(d+1,i+1,a2/g,b2/g))
			ok = true;
	
	}

	

	return ok;
}

int main()
{
	int ok = 0;
	int a,b;

	printf("输入分子a跟分母b\n");
	scanf("%d %d",&a,&b);

	//加数递增，直到找到合适解返回，由于是递增的，找到一定是加数最少的解
	for(maxd = 1; ; maxd++ )
	{
		memset(ans,-1,sizeof(ans));
		if(dfs(0, get_first(a,b), a, b))
		{
			ok = 1;
			break;
		}
	}

	if(ok)
	{	
		printf("%d/%d = ",a,b);
		for(int i = 0; i < maxd; i++)
			printf("1/%d + ",ans[i]);
		printf("1/%d\n",ans[i]);
	
	}
	getchar();
	getchar();
	return 0;
}