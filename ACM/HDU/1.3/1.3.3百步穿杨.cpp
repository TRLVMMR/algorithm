/*

*/

#include<stdio.h>
#include<algorithm>

using namespace std;

struct Arrow
{
	int len;//箭身长度 
	int sum;//箭数量 
};

bool cmp(Arrow a, Arrow b)
{
	return a.len < b.len;
}

int main()
{
	int t;
	
	scanf("%d", &t);
	while(t--)
	{
		int n;
		Arrow a[30];
		
		scanf("%d", &n);
		
		for(int i = 0; i < n; i++)
		{		
			scanf("%d %d", &a[i].len, &a[i].sum);
			a[i].len -= 2;//箭身减2是+ + 
		}
		
		sort(a, a+n, cmp);
		for(int i = 0; i < n; i++)
		{
			while(a[i].sum--)
			{
				printf(">+");
				for(int j = 0; j < a[i].len; j++)//
				//while((a[i].len)--)//问题，不能在循环里用while（x--）因为x=0不执行后，外循环加一轮后x就会永远为负数 
				{
					printf("-");
				}
				

				printf("+>\n");
			}
			printf("\n");
		}
	}
	
	
}
