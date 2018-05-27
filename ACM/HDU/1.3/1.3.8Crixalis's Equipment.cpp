/*
	蝎子挖洞，T个测试用例，N个设备，总空间V 
	有空间Bi才能放，放下去只占空间Ai 
	 0<T<= 10, 0<V<10000, 0<N<1000, 0 <Ai< V, Ai <= Bi < 1000.
	 
	 开始思路：贪心 :每次选取需求b最大的加入
	 		10 2
			9  9
			1  5 
			输出是no 
	 
	 正确思路：贪心：梦想与现实差距越大的越先挖（尽量少浪费）,浪费越少越好放 
	 		如果a(j) + b(i) > a(i) + b(j) 即b(i) - a(i) > b(j) - a(j)  
	 
		放i后放j那么有 V>=bi,V>=ai+bj; 如果先放j后放i那么有         V>=bj,V>=aj+bi; 
		对上面的再分析，如果先放i后放j，那么V>=bi,V>=ai+bj;并且下面的的式子不成立，但
		是V>=bj成立，所以有aj+bi>V 那么可以得到aj+bi>ai+bj;即为bi-ai>bj-aj
*/

#include<stdio.h>
#include<algorithm>

using namespace std;

struct Hole
{
	int a;
	int b;
};

bool cmp(Hole x, Hole y)
{
	return x.b -x.a > y.b - y.a;	
}

int main()
{
	int n;
	scanf("%d", &n);
	
	while(n--)
	{
		Hole h[1001];
		int sum, v;
		
		scanf("%d %d", &v, &sum);
		for(int i = 0; i < sum; i++)
		{	
			scanf("%d %d", &h[i].a, &h[i].b);
			
		}
		
		//按b大小从大到小排序h 
		int ok = 1;
		sort(h, h+sum, cmp);
		for(int i = 0; i < sum; i++)
		{
			if(v >= h[i].b)
			{
				v = v - h[i].a;
			}
			else
			{
				ok = 0;
				break; 
			}
		}
		
		if(ok)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	
	
	return 0;
}
