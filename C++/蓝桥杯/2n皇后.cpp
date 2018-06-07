/*
	�кڰ������ʺ󣬲�ͬɫ��������� �����ݳ˷�ԭ���ڷ�һ���Ļ����Ϸŵڶ��� 
	���ԵĻ��ݷ�, 
	��ע�⣬����һ����ɫ�Ļʺ�����λ�ͱ�ռ���� 
	 
	�Խ����жϣ�
	����⣬���԰��죬����ǿ��ڶԽ��ߵ��ж��ϣ�ֻ�������������¡�����ͬ���ж�һ��ʼҲ����i��0��ʼ
	2018��3��14��22:38:07 
	 
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

//�Ƿ������ͻ�ģ�ͬ��ͬ�жԽ��߲�����ͬɫ 
bool conflict(int row, int column, int type)
{
	//ͬ��ͬ�� 
	for(int i = 0; i < n; i++)
	 {
		if(map[row][i] == type)
			return false;
		if(map[i][column] == type)
			return false;
	 }
	

	 //���ϽǶԽ���
	 for(int i = 1; ;i++)
	 {
	 	int rowtemp = row - i;
		int coltemp = column - i;
		if(rowtemp < 0 || coltemp < 0)
			break;
		//�����ͬɫ������false 
	 	else if(map[rowtemp][coltemp] == type)
	 		return false;
	 }
	 
	 //���½ǶԽ��� 
	 for(int i = 1; ;i++)
	 {
	 	int rowtemp = row + i;
		int coltemp = column + i;
		if(rowtemp >= n || coltemp >= n)
			break;
		//�����ͬɫ������false 
	 	else if(map[rowtemp][coltemp] == type)
	 		return false;
	 } 
	 
	 //���Ͻ� 
	  for(int i = 1; ;i++)
	 {
	 	int rowtemp = row - i;
		int coltemp = column + i;
		if(rowtemp < 0 || coltemp >= n)
			break;
		//�����ͬɫ������false 
	 	else if(map[rowtemp][coltemp] == type)
	 		return false;
	 } 
	  
	  //���½� 
	for(int i = 1; ;i++)
	 {
	 	int rowtemp = row + i;
		int coltemp = column - i;
		if(rowtemp >= n || coltemp < n)
			break;
		//�����ͬɫ������false 
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
		//����ǿյأ��ҶԽ���Ϊûͬɫ 
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

	//freopen("2n�ʺ�.in", "r", stdin);
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
