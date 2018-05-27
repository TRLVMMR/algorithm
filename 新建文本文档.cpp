#include<cstdio> 
#include<iostream>

using namespace std;

int main(int ar, char *arg[])
{
	
	if(ar != 2)
	{
		cout << "Error" << endl;
		
		return 1;
	}
	
	cout << "ojbk" << arg[1] << endl;
	
	return 0;
}
