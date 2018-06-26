/*
	输出每行都出现的字符，如果有多个，输出字典序最小的 
	
	思路：记录每个字符最后一次出现的行数（通过判断每行上次出现是在上一行）  
	
	map可以输出字典序最小的, 底层红黑树会自动排序 
	
	伪代码：
		遍历数组第 i 行
			遍历数组第 j 列
				if 此字符没有出现，加入集合
				else if 判断此字符最后出现行数是否是i - 1， 是的话+=1, 
	
		遍历集合：
			如果最后行数到达n-1，输出				 
*/
#include<iostream>
#include<map>
#define MAXV 256 

using namespace std;

char a[MAXV][MAXV];
int n, m;

char seachSame()
{
	map<char, int> num;//保存所有出现数字的集合 
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			//如果没有出现 
			if(num.find(a[i][j]) == num.end())
				num[a[i][j]] = 0;
			//每行只允许计算一次 
			else if(num[a[i][j]] == i - 1)
				num[a[i][j]]++;	
		}
	
	}
	
	int max = -1;
	char maxc = 0;
	
	map<char, int>::iterator it;
	for(it = num.begin(); it != num.end(); it++)
	{
		if(n - 1 == it->second)
			return it->first;
	}
	
	return 0; 
}

int main()
{
	freopen("same2.in", "r", stdin);
	
	cin >> n >> m;
	cout << n << m << endl; 
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
