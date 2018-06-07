/*	
	交换相邻的两个字符，使它变成回文串，输出最少交换的次数
	
	思路：
		先找到这几个字符所能组成的回文串 
	
	
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


//用来存放，字符出现位置跟次数 
int letter[26];
char a[10000];

int main()
{
	int n;
	
//	freopen("input8.txt", "r", stdin);
	
	cin >> n;
	
	
	//int len = a.size();
	
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		int pos = a[i] - 'a';
		letter[pos]++;
	}
	
	bool flag = false; 
	 
	//判断是否是回文串：回文串只能存在一个字符出现次数是单数 
	for(int i = 0; i < 26; i++)
	{
		if(letter[i] & 1)
		{
			if(flag)
			{
				cout << "Impossible" << endl;
				return 0;
			}
			flag = true;
		}
	}
	
	int sum = 0;//计数 
	int end = n - 1;//最后一个元素 
	int alone = -1;//记录单独那个的坐标 

	//循环一边就行,右边反正会调整好
	//每次调整好一次外围，左右两边靠近 
	for(int i = 0; i < n / 2; i++ )
	{		
		bool phave = false;//是否有同伴 
		for(int j = end; j > i; j--)
		{
			if(a[j] == a[i])
			{
				while(j != end)
				{
					swap(a[j],a[j+1]);
					j++;
					sum++;
				}
				//若是单个字符，等最后再调整，但右边字符要先放好 
				end--;
				phave = true; 
				break;
			}
	
		}
		
		//如果没找到相同的 ，则是那个单的 
		if(!phave)
		{
			alone = i;
		}
	
	} 
	
	//若存在单的,调到最中间 
	if(alone != -1)
	{
		while(alone != n / 2)
		{
			swap(a[alone],a[alone+1]);
			alone++;
			sum++;
		}
	}
	
/*	bool fl = true;
	for(int i = 0; i < n; i++)
	{
		int j = n - 1 - i;
		if(a[i] != a[j])
		{
			cout << "false" << endl;;
			fl = false;
			break;
		}
		
	}
	if(fl)
	cout << "true" << endl;*/
	
	cout << sum << endl;
	
	return 0;
}
