/* 
	这是用迭代加深做的，可是超时了（本来想用IDA*结果想不到客观估价函数） 
	题目规定时间只有1s，却给了6M的空间，明显是用bfs做的 
*/
#include<stdio.h>
#include<string.h>

typedef bool State[4][4];
int maxd;
State v[10000], ans[10000];
int dirt[1000];

bool dfs(int d, State& s)
{
	if(d == maxd)
	{
		int ok = 1;
		//如果图中全部为-（即true），返回true，否则返回false 
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				if(s[i][j] == false)
				{	ok = 0;
					return false; 
				} 
			}
		}
		
		if(ok)
		{
		//	if(better(d))
		//此题中ans不是必要 
			memcpy(ans, v, sizeof(State) * (d+1) );
			return true;
		}
	
	}
	
	bool flag;
	//按规则变换  
	for(int x = 0; x < 4; x++)
	{
		for(int y = 0; y < 4; y++)
		{
			//客观估价函数OR最优性剪枝在哪？？？ 没有，滚 我迭代加深而已 
			State& t = v[d+1];
			memcpy(&t, &s, sizeof(s));
			
			//将x列y行的状态反转 
			for(int i = 0; i < 4; i++)
			{
				t[x][i] = !t[x][i];
				
			}
			for(int i = 0; i < 4; i++)
			{
				t[i][y] = !t[i][y]; 
			}
			//两次会让交界点的t[x][y]改变回来 ，所以还需要一次 
				t[x][y] = !t[x][y];
			
			//把x，y组成两位数放入 
			dirt[d] = x * 10 + y;
			//进行下一次变换 
			flag = dfs(d+1, t);
			
			//找到解马上切断，如果还需要字典序最小之类的就不能马上切断 
			if(flag)
				return true;
		}
	}
	return false;
}


int main()
{
	//给初始状态赋值 
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			char ch;
			ch = getchar();
			
			if(ch == '+')
				v[0][i][j] = false;
	
			else if(ch == '-')
				v[0][i][j] = true;
	
		}
		getchar();//空格 
	}
	//	scanf("%d", &v[0][i]);
	
	for(maxd = 0; ;maxd++)
	{
		memset(ans, 0, sizeof(ans));
		if(dfs(0, v[0]))
		{
			printf("%d\n", maxd);
			break;
		}
	}
	for(int i = 0; i < maxd; i++)
		printf("%d %d\n",dirt[i]/10 + 1, dirt[i]%10 + 1);
	
	return 0;
}
