#include<stdio.h>
#include<string.h>

typedef int State[3][3];//定义状态

const int maxstate  = 1000000;
State st[maxstate],goal;//st存放路径的状态，goal为目标数组
int dirt[maxstate];//dirt为距离数组

const int hashstate = 1000019;
int head_hash[hashstate],next_hash[maxstate];

//定义方向数组,	   上,下,左, 右。x，y为行列
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

void Init_hash()
{
	memset(head_hash, 0, sizeof(head_hash) ); 
	memset(next_hash, 0, sizeof(next_hash) );
	
}

//传入状态， 把这状态改成9位数，返回他的头节点的哈希值 
int change_hash(State& s)
{
	int sum = 0;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			sum = sum * 10 + s[i][j];
			
	return sum % hashstate;
}

//插入哈希表，（处理冲突的方法估计是公共溢出区法 + 静态链表） 
bool insert_hash(int s)
{
	int h, u;
	h = change_hash(st[s]);
	u = head_hash[h];
	
/*	这种方法是头插法，创建一个节点next[s]，这个节点存放原本头结点的值，然后head存放新节点的值  
	while(u)
	{
		if(memcmp(st[u],st[s],sizeof(st[s]) ) == 0 )
			return false;
		u = next_hash[u];
	}
	
	next_hash[s] = head_hash[h];
	head_hash[h] = s;
	return true;*/
	
	//尾插法。如果表头没有插入过 ,将s插入 
	if(!u)
	{	
		head_hash[h] = s;
		return true;
	}
	
	//如果表头插入过了，顺着表头的指针往公共溢出区找 
	while(u)
	{
		//比较s跟u，如果找到相同的，表示哈希表中已有，插入失败 
		if (memcmp(st[s],st[u],sizeof(st[s]) ) == 0)
			return false;
		//如果没找到，继续找 
		u = next_hash[u];		
	}
	//如果哈希表里没有这个值 ，插入成功 
	 head_hash[u] = s;	
	return true;
}

int bfs()
{
	int head,tail;



	Init_hash();//初始化哈希表 
	head = 1;
	tail = 2;
	
	while(head < tail)
	{
		State& s = st[head];
		//如果找到目标状态，返回
		if ( memcmp(goal, s, sizeof(s) ) == 0)
			return head;
		//如果没有找到目标状态，则枚举各种走法
		//找到空格的位置，（空格为0）
		int x, y;
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				if( s[i][j] == 0 )
				{
					x = i;
					y = j;
					break;
				}
		
		//枚举各方向的走法
		for(int i = 0; i < 4; i++)
		{
			int newx = x + dx[i];
			int newy = y + dy[i];
			//如果走法不合格，跳过
			if(newx >= 3 || newx < 0 || newy >= 3 || newy < 0)
				continue;

			State& t = st[tail];
			//如果走法合格，创造出这个合格的状态空间
			memcpy(&t, &s, sizeof(s));

			//将空格与新走的格子交换表示走了一格
			t[x][y] = s[newx][newy];
			t[newx][newy] = s[x][y];

			dirt[tail] = dirt[head] + 1;
			if( insert_hash(tail) )
				tail++;
		}
		head++;
	}
	
	return 0;
}


int main()
{
	freopen("八数码.in","r",stdin);
	//输入初始化状态 
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
		{
			scanf("%d",&st[1][i][j]);
		}
	
	
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
		{
			scanf("%d",&goal[i][j]);
		}
	
	int ans = bfs();
	
	if(ans > 0)
		printf("%d\n",dirt[ans]);
	else
		printf("-1\n");
		
	return 0;
}
