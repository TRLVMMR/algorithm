/*
	有黑白两个皇后，不同色不互相干扰 ，根据乘法原理，在放一个的基础上放第二个 
	明显的回溯法, 
	需注意，放入一个颜色的皇后后，这个位就被占用了 
	 
	对角线判断：
	这道题，调试半天，结果是坑在对角线的判断上，只考虑了左上右下。。。同行判断一开始也忘记i从0开始
	2018年3月14日22:38:07 
	 
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<vector>

using std::cin;
using std::cout;
using std::endl;

const int black = 2;
const int white = 3;

int map[10][10];
int sum = 0;
int n;

//是否有相冲突的，同行同列对角线不能有同色 
bool conflict(int row, int column, int type)
{
	//同行同列 
	for(int i = 0; i < n; i++)
	 {
		if(map[row][i] == type)
			return false;
		if(map[i][column] == type)
			return false;
	 }
	

	 //左上角对角线
	 for(int i = 1; ;i++)
	 {
	 	int rowtemp = row - i;
		int coltemp = column - i;
		if(rowtemp < 0 || coltemp < 0)
			break;
		//如果有同色，返回false 
	 	else if(map[rowtemp][coltemp] == type)
	 		return false;
	 }
	 
	 //右下角对角线 
	 for(int i = 1; ;i++)
	 {
	 	int rowtemp = row + i;
		int coltemp = column + i;
		if(rowtemp >= n || coltemp >= n)
			break;
		//如果有同色，返回false 
	 	else if(map[rowtemp][coltemp] == type)
	 		return false;
	 } 
	 
	 //右上角 
	  for(int i = 1; ;i++)
	 {
	 	int rowtemp = row - i;
		int coltemp = column + i;
		if(rowtemp < 0 || coltemp >= n)
			break;
		//如果有同色，返回false 
	 	else if(map[rowtemp][coltemp] == type)
	 		return false;
	 } 
	  
	  //左下角 
	for(int i = 1; ;i++)
	 {
	 	int rowtemp = row + i;
		int coltemp = column - i;
		if(rowtemp >= n || coltemp < n)
			break;
		//如果有同色，返回false 
	 	else if(map[rowtemp][coltemp] == type)
	 		return false;
	 } 
	
	return true;
}

void dfs(int row, int type)
{
	if(row == n)
	{ 
		if(type == black)
			sum++;
		else if(type == white)
		{
			dfs(0, black);	
		}
	
		return;
	}
	
	for(int i = 0; i < n; i++)
	{
		//如果是空地，且对角线为没同色 
		if(map[row][i] == 1 && conflict(row, i, type) )
		{
			map[row][i] = type;
			dfs(row + 1, type);
			map[row][i] = 1;
			
		}
	}
	
	return;	
}

int main()
{

	//freopen("2n皇后.in", "r", stdin);
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	
	dfs(0, white);
	
	cout << sum << endl;
	
	return 0;
}
