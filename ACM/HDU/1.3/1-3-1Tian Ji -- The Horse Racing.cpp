/*
	贪心1：最快的马能赢就赢，而且还要贪赢，不能赢就贪输：拿最慢的马去输 
	贪心2：如果最快的马只能平，那就看最慢的马 
			（1）如果田慢马 > 国王慢马还快：	赢tmd
			（2）如果田慢马 < 国王慢马还慢：	废物去死把，贪输 
			（3）如果田慢马 == 国王慢马：		当成废物用 ，贪输 
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
		int ks = 0, kq = n-1;//放在循环外保证只马只比一次，避免多余计算，比j快的马再比也是输
		int s = 0, q = n-1;
		
		//只要田忌快马比慢马快 
		while(s <= q)
		{			 
			//田快 > 王快 
			if(tian[q] > king[kq]) 
			{
				kq--;
				q--;
				score += 200;
			}
			//田快 == 王快 
			else if(tian[q] == king[kq])
			{
				// 直到田忌的慢马 <= 国王慢马
				while(1)
				{
					if(tian[s] > king[ks])
					{
						s++;
						ks++;
						score += 200;
					}
					//田忌的慢马 <= 国王慢马
					else
					{
						//如果田慢 == 国快 (此时国王的马都一样速度了)
						if(tian[s] == king[kq])
						{
							s++;
							kq--;
						}
						else
						{
							s++;
							kq--;
							score -= 200;
						}
							break;
					}
				}
			}
			//田快 < 王快 
			else
			{
				//慢比快 
				kq--;
				s++;//慢马去死把 
				score -= 200;		
			}
		
			
		}
		
		printf("%d\n", score);
		
	}
	
	return 0;
}
