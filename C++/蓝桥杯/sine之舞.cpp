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
#include<sstream>

using namespace std;

stringstream An;
stringstream Sn;


void get_An(int x, int n)
{
	if(x == n)
	{
		An << "sin(" << n << ")";	
		return;
	}
	
	if(x & 1)
		An << "sin(" << x << "-";
	else 
		An << "sin(" << x << "+";
	
	get_An(x+1, n);
	An << ")";
	
	return ;
}

int main()
{
	int n;
	
	cin >> n;
	

//	An << "sin(1)" << "+" << n;
	
/*	for(int i = 1; i <= n - 1; i++)
	{
		//如果是单数 
		if(i & 1)
		{
			An[n] << i << "-sin(";
					
		}
		else
		{
			An[n] << i << "+sin("; 
		}
	//	Sn << "(" << Sn << ")" << An << n - i + 1;
		
	}

	An[n] << n;			
	
	for(int i = 1; i < n; i++)
		An[n] << ")";
	
	
	
	*/
	string str;
	for(int i = 1; i <= n; i++)
	{
		An.clear();               //记得要清空!!!
		An.str("");//清空缓冲区 
		Sn.clear();
		An.str("");
		get_An(1, i);
		
		string an;
		string sn;
		
		An >> an; 
	//	cout << an << endl;
	//	if(i == n)
	//		Sn << an << "+1";
		if(i == 1)
		{
			Sn << an << "+" << n - i + 1; 
		} 
		else
			Sn << "(" << str << ")" << an << "+" << n - i + 1;  
		
		Sn >> sn;
		
		str = sn;
	//	cout << str << endl;
	}
	

//	Sn >> str; 
	
	cout << str << endl;
	
	return 0;
}
