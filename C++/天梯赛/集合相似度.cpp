#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int flag[]

int main()
{
	int n;
	vector<int> num[50];
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		int ci;
		
		cin >> ci;
		
		for(int j = 0; j < ci; j++)
		{
			int temp;
			cin >> temp;
			
			num[i].push_back(temp);
		}
		
	}
	
	int min = 0x3fffffff;
	int minv = -1;
	
	for(int i = 0; i < n; i++)
	{

		if(min > num[i].size)
	{
			min = num[i].size;
			minv = i;
		}
		
	}
	


	
	return 0;
}
