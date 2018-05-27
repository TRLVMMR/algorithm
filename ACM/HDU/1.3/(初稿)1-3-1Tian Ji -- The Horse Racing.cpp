/*
	此程序存在一个问题，当田忌跟国王都为1 2 3时，输出为0，实际上田忌能拿200银币 
	田忌赛马问题。赢一次+200,输一次-200 
	贪心：每次跟比他小但是尽量大的马比 
*/

#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int score = 0;
		int tian[1001] = {0}, king[1001] = {0};
		

		
		if(!n)	break;
		
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &tian[i]);
		}
		
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &king[i]);
		}
		
		sort(tian, tian+n);
		sort(king, king+n);
		
		//由于没定义cmp函数，sort函数是从小到大排序的
		int j = n-1;//放在循环外保证只马只比一次，避免多余计算，比j快的马再比也是输 
		for(int i = n-1; i >= 0; i--)
		{	
			int ok = 1;
			 
			for( ;j >= 0 ; j--)
			{
				if(tian[i] > king[j]) 
				{
					score += 200;
					j--;//因为j已经比较过了，就要换下一个，否则可能一直跟j比
					ok = 0;
					break;
				}
				if(tian[i] == king[j])
				{
					j--;
					ok = 0;
					break; 
				}
				
			}
			//出现一个问题，从break跳出来后也会执行此语句。。。 已解决：加入OK 
			//如果田径最快的马都赢不了国王跑得最慢的马了，剩下的马匹配就都是输了
			if(j < 0 && ok)
			{
				score -= 200; 
				
			}
			
		}
		
		printf("%d\n", score);
		
	}
	
	return 0;
}
