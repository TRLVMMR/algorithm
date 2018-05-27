#include<stdio.h>
#include<algorithm>
#define INF 9999999

using namespace std;

struct Cur
{
	int x;
	int y;
};

int a[100][100];
int dp[100][100];
int next[100][100];

int main()
{
	int n, m;
	
	scanf("%d %d", m, n);
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			scanf("%d",&a[i][j]);
			
		}
	}
	
	int ans = INF, first = 0;//fist是第一个节点 
	//递推要逆序，保证最优解无后效性 
	for(int j = n-1; j >= 0; j--)
	{
		for(int i = 0; i < m; i++)
		{
			 
			if(j == n-1) dp[i][j] = a[i][j];
			
			int dir[3] = {i, i-1, i+1};
			//最上面的上一行是最下面，最下面的下一行是最上面 
			if(i == 0) dir[1] = m-1;
			if(i == m-1) dir[2] = 0;
			sort(dir, dir+3);
			
			//更新dp 
			dp[i][j] = INF;
			for(int k = 0; k < 3; k++)
			{
				int temp = dp[dir[k]][j+1] + a[i][j];
				if(temp < dp[i][j])
				{
					dp[i][j] = temp;
					next[i][j] = dir[k];
				}
			}
			
		}
		if(j == 0 && dp[i][j] < ans)
		{
			ans = dp[i][j];
			first = i;
		}
	}
	
	return 0;
} 
