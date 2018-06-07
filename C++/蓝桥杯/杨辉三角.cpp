#include<iostream>
#define MAXV 50

using namespace std;
int yanghui[MAXV][MAXV];

int main()
{
	int n;
	
	cin >> n;
	
	yanghui[0][0] = 1;
	
	for(int i = 0; i < n; i++)
	{
		yanghui[i][0] = 1;
	}
	
	cout << 1 << endl;	
	//第0行不用了, 第一列也不用了，都是1	
	for(int i = 1; i < n; i++)
	{
		cout << 1;
		for(int j  = 1; j <= i; j++)
		{
			yanghui[i][j] = yanghui[i-1][j-1] + yanghui[i-1][j];
			cout << " " << yanghui[i][j]; 
		}
		cout << endl;
		
	}
	

	
	
	return 0;
}
