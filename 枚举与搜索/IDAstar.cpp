#include<iostream>
#include<cmath>
using namespace std;

const int maxn = 100;
const int inf = 0x3fffffff;
//1代表墙，0代表空地，2代表终点 
int G[maxn][maxn];
int n, m;

//移动时的坐标改变量 
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1}; 

int endx, endy;
int maxd;
//多了个d记录深度 
bool dfs(int x, int y, int d)
{
	//到达最大深度则返回 
	if(d == maxd)
	{
		//找到终点返回true，否则false 
		if(G[x][y] == 2)
			return true;
		return false;
	}
		
	//预剪枝：如果可步数大于最短距离， 直接返回 
	if(abs(x - endx) + abs(y - endy) > maxd - d)
		return false; 
		
	//尝试向左，向右,向上，向下走
	for(int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		//不能越界，也不能往障碍走 
		if(next_x >= n || next_x < 0 || next_y >= m || next_y < 0 || G[next_x][next_y] == 1)
			continue;
		
		//只要有一个返回true 
		if(dfs(next_x, next_y, d+1))
		{
			return true;
		}
	} 
	return false;
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
			//记下终点 
			if(G[i][j] == 2)
			{
				endx = i;
				endy = j;
			}
		}
		
	}

	//枚举步数，最少多少步能到达目标 
	for(maxd = 1; ;maxd++)
	{
		if(dfs(0, 0, 0))
		{
			cout << maxd << endl; 
			break;
		}
	}
	
	return 0;
 } 
