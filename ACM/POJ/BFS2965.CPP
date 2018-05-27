/*
	此程序缺少bfs路径寻找函数,其实此题还是适合dfs 

*/
#include<stdio.h>
#include<string.h>

const int maxstate = 1000000;
const int hashsize = 1000019;

typedef bool State[4][4];
State v[maxstate], ans[maxstate];
int dist[1000], dir[1000];//dist记录步数的数组 ，dir是记录走法的数组 

int hash_head[hashsize], hash_next[hashsize];

//初始化哈希表 
void init_hash()
{
	memset(hash_head, 0, sizeof(hash_head));
	memset(hash_next, 0, sizeof(hash_next)); 
}

//将状态转化为哈希值 
int hash(State& s)
{
	long long sum = 0;
	for(int i = 0; i <4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			//将状态s转化成16位整数 
			sum = sum * 10 + s[i][j];
			
		}
	}
	return sum % hashsize;
	
}

bool insert_hash(int s)
{
	int h = hash(v[s]);
	
	int t = hash_head[h];
	
	//顺着表头找公共溢出区(链表) ,直到为0表示空 
	while(t)
	{
		if(memcmp(v[t], v[s], sizeof(v[s]) ) == 0 )
			return false;
			
		 t = hash_next[t];
	}
	
	hash_next[s] = hash_head[h];
	hash_head[h] = s;
	return true;
}

bool goal(State s)
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
	//	memcpy(ans, v, sizeof(State) * (d+1) );
		return true;
	}
	
	return false;
} 

int bfs()
{
	int head = 0, tail = 1;
	init_hash();
	
	while(head < tail)
	{
		State& s = v[head];
		
		if(goal(s))
			return head;
		
		for(int x = 0; x < 4; x++)
		{
			for(int y = 0; y < 4; y++)
			{
				State& t = v[tail]; 
				memcpy(&t, &s, sizeof(s));
				
				//按游戏规则将x列y行的状态反转 
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
			
				//用两位数表示每次的坐标 
				dir[tail] = x * 10 + y;
				dist[tail] = dist[head] + 1;
				 
				if( insert_hash(tail) )
					tail++;
				
			}
			
		}
		head++;
	}
	
	return 0;
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
		getchar();//吃回车 
	}
	
	int ans = bfs();//返回目标状态的下标 
	
	printf("%d\n", dist[ans]);	
	for(int i = 0; i < dist[ans]; i++)
		printf("%d %d\n",dir[i]/10 + 1, dir[i]%10 + 1);
		
		
	return 0;
}
