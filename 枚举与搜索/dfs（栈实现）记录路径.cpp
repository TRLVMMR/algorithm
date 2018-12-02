#include<iostream>
#include<stack> 
using namespace std;

const int maxn = 100;
const int inf = 0x3fffffff;
//1代表墙，0代表空地，2代表终点 
int G[maxn][maxn];
//此数组记录到此节点的最小步数，类似dp。同时用来判重 
int book[maxn][maxn];
int n, m;

struct Node
{
	int x;
	int y;
	int k;//控制方向 
	Node(int x, int y, int k):x(x), y(y), k(k){};
};

//移动时的坐标改变量 
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1}; 

//dfs栈实现，非递归 
int dfs(int sx, int sy)
{	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			book[i][j] = inf;
		}
	}
	book[sx][sy] = 0;
	
	stack<Node> s;
	Node temp(sx, sy, 0);
	s.push(temp);
	while(!s.empty())
	{
		Node u = s.top();
		s.pop();
		int x = u.x;
		int y = u.y;
		//尝试向左，向右,向上，向下走 
		if(u.k < 4)
		{
			int next_x = x + dx[u.k];
			int next_y  = y + dy[u.k]; 
			//将原栈帧k+1继续入栈（因为C++这栈的元素貌似是不可变数据结构，你改变top的k值，下次top时还是原来的k值） 
			Node tmp(x, y, u.k + 1);
			s.push(tmp);
			//不能越界，也不能往障碍走 
			u.k = u.k + 1;
			if(next_x >= n || next_x < 0 || next_y >= m || next_y < 0 || G[next_x][next_y] == 1)
				continue;
			
			//如果可以走，看是否之前走过
			if(book[next_x][next_y] == inf)
			{
				//从此点继续扩展 
				Node temp(next_x, next_y, 0);
				s.push(temp);
				
				//更新步数
				book[next_x][next_y] = book[x][y] + 1; 
			}
			else
			{
				//更新步数
				book[next_x][next_y] = min(book[next_x][next_y], book[x][y] + 1);
			} 
			
			if(G[next_x][next_y] == 2)
			{
				return book[next_x][next_y];
			} 
		}
	} 
	
	return -1; 
} 


int main()
{
	cin >> n >> m;
	cout << "请输入一个" << n << "*" << m << "的地图" << endl; 
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> G[i][j];
		}
		
	}
	
	cout << dfs(0, 0) << endl;
	

	return 0;
 } 
