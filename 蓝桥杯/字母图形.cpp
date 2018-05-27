/*
	特征: 以A为基准点，左边是倒叙，右边是顺序
		若出现字母类的顺序倒叙问题 
		若x为顺序，则-x可以为倒叙 
	  
	循环次数为A的位置 
*/
#include<iostream>

using namespace std;

int main()
{
	int n, m;
	
	cin >> n >> m;	
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			//位置i为基准点，右边进行顺序，左边进行倒叙 
			if(j >= i)
				cout << char(j - i + 'A'); 
			else
				cout << char(i - j + 'A');
		}
		
		cout << endl;
	}
	
	return 0;
} 
