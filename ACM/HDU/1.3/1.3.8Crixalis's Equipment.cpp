/*
	Ы���ڶ���T������������N���豸���ܿռ�V 
	�пռ�Bi���ܷţ�����ȥֻռ�ռ�Ai 
	 0<T<= 10, 0<V<10000, 0<N<1000, 0 <Ai< V, Ai <= Bi < 1000.
	 
	 ��ʼ˼·��̰�� :ÿ��ѡȡ����b���ļ���
	 		10 2
			9  9
			1  5 
			�����no 
	 
	 ��ȷ˼·��̰�ģ���������ʵ���Խ���Խ���ڣ��������˷ѣ�,�˷�Խ��Խ�÷� 
	 		���a(j) + b(i) > a(i) + b(j) ��b(i) - a(i) > b(j) - a(j)  
	 
		��i���j��ô�� V>=bi,V>=ai+bj; ����ȷ�j���i��ô��         V>=bj,V>=aj+bi; 
		��������ٷ���������ȷ�i���j����ôV>=bi,V>=ai+bj;��������ĵ�ʽ�Ӳ���������
		��V>=bj������������aj+bi>V ��ô���Եõ�aj+bi>ai+bj;��Ϊbi-ai>bj-aj
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
		
		//��b��С�Ӵ�С����h 
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
