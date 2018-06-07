/*
	此程序还有错误 
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;


int factor[50][50];//乘数因子 
long long end[50][50]; 
long long rowbuffer[50];//行向量的行缓冲，因为原·列向量元素在计算中还需要用到 

void mertx_mult()
{
	
	
}


int main()
{
	int n, m;
	
	//cin >> n >> m;
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int temp;
			//cin >> temp;
			scanf("%d", &temp);
			factor[i][j] = temp;
			end[i][j] = temp;
		}
	}
	
	//end里已有一个相同矩阵，所以乘的次数减1 
	m--;
	while(m--)
	{
			
		//完成一个矩阵的乘法 
	/*	for(int erow = 0; erow < n; erow++)
		{
			
			
			//用来记录放入元素的行数
			int tcur = 0;
			//完成一行的计算 
			while(tcur < n)
			{
				int num = 0;//用来存放一个元素的结果 
				
				//行向量中，每次一行遍历完，初始化到开头 
				int ecoul, srow;
				
				//这两个遍历用指针是等价的，一个加另一个也加				
				ecoul = srow = 0;
 				
 				//此列向量的列指针与行向量的行指针等价的 
 				int scoul = 0;
 				
			 	//完成一个元素的计算 
				while(ecoul < n)
				{
					//完成一个行元素跟一个列元素的相乘 
					num = num + end[erow][ecoul++] * factor[srow++][scoul]; 
					
				}
					
				rowbuffer[tcur++] = num;
				scoul++;
				
			}
			
			//将临时存放的列向量给end 
			for(int i = 0; i < n; i++)
			{
				end[erow][i] = rowbuffer[i];
			}
			
		}*/
		
		/*
			根据上面的理论，可以修改成简单的写法 
		*/
		
		//完成一个矩阵的计算 ,i为列遍历指针 
		for(int i = 0; i < n; i++)
		{
		
			//完成一行的计算 ,j为行遍历指针 
			for(int j = 0; j < n; j++)
			{
				long long num = 0;
				//完成一个元素的计算 
				for(int k = 0; k < n; k++)
				{
					num = num + end[i][k] * factor[k][j];
					
				}
					
				rowbuffer[j] = num;
			} 
			
			//将临时存放的列向量给end 
			for(int u = 0; u < n; u++)
			{
				end[i][u] = rowbuffer[u];
			}
			
			
		}
		
		
	
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n - 1; j++)
		{
			printf("%d ", end[i][j]);
			//cout << end[i][j] << " ";
		}
		printf("%d\n", end[i][n-1]);
		//cout << end[i][n-1] << endl;
	}
	
	
	return 0;
}
