/*
	题目要求：输入一个矩阵，找出每行都出现的整数 
	
		做法：
			 

*/
#include<iostream>
#include<vector> 
#define MAXV 256

using namespace std;

int a[MAXV][MAXV];
int n, m;

int num[MAXV];//存储出现数字的数组，首先存第一行的数，因为如果这个数没在第一行出现，那他也不可能每行都出现 
int count[MAXV];//对应数字出现次数的数组

//返回param在num里的索引，如果没有，返回-1 
int find_num(int param)
{
	for(int j = 0; j < m; j++)
		if(num[j] == param)
			return j;	
	return -1;
} 

int seachSame()
{
	//把第一列的数字加入存储数组 
	for(int j = 0; j < m; j++)
		num[j] = a[0][j];

	for(int i = 1; i < n; i++)
	{ 
		for(int j = 0; j < m; j++)
		{	
			
			int index = find_num(a[i][j]);
			if(index != -1 && count[index] == i - 1)
			{
				count[index]++;
			
			}
			
		}
	}
	
	int max = -1;
	int maxv = -1;
	for(int j = 0; j < m; j++)
	{
		if(max < count[j])
		{
			max = count[j];
			maxv = j;
		}
	}
	
	return num[maxv];
}

int main()
{
	
	freopen("same1.in", "r", stdin);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			
		}
	}
	
	cout << seachSame() << endl;
	
	
	return 0;
} 
