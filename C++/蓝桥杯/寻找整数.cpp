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

int flag[1024];

int main()
{
	int n;
	int max = -0x3ffffff;
	int num = 0;
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		int temp;

		cin >> temp;
		num++;	
		if(flag[temp] == 0)	
			flag[temp] = num;
		
		if(temp > max)
		{
			max = temp;
		}
	}
	int key;

	
	cin >> key;
	
	if(flag[key] != 0)
		cout << flag[key] << endl;
		
	else 
		cout << -1 << endl;
	
	
	return 0;
}
