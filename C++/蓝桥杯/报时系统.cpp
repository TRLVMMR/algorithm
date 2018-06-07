#include<iostream>
#include<map>
#include<string>

using namespace std;

map<int, string> count;

int main()
{
	int h, m;
	
	cin >> h >> m;
	
	count[0] = "zero";
	count[1] = "one";
	count[2] = "two";
	count[3] = "three";
	count[4] = "four";
	count[5] = "five";
	count[6] = "six";
	count[7] = "seven";
	count[8] = "eight";
	count[9] = "nine";
	count[10] = "ten";
	count[11] = "eleven";
	count[12] = "twelve";
	count[13] = "thirteen";
	count[14] = "fourteen";
	count[15] = "fifteen";
	count[16] = "sixteen";
	count[17] = "seventeen";
	count[18] = "eighteen";
	count[19] = "nineteen";
	count[20] = "twenty";
	count[30] = "thirty";
	count[40] = "forty";
	count[50] = "fifty";
	
	if(h > 20)
	{
		cout << count[20] << " " << count[h - 20] << " ";
	} 
	else
	{
		cout << count[h] << " ";
	} 
	
	if(m > 20) 
	{
		if(m >= 50)
		{
			cout << count[50];
			if(m > 50)
				cout << " " << count[m - 50];
			cout << endl;
		}
		else if(m >= 40)
		{
			cout << count[40];
			if(m > 40) 
				cout << " "<< count[m - 40];
			cout << endl;
		}
		else if(m >= 30)
		{
			cout << count[30];
			if(m > 30) 
				cout << " " << count[m - 30];
			cout << endl;
		}
		else
		{
			cout << count[20];
			if(m > 20) 
				cout << " " << count[m - 20];
			cout << endl;
		}
	}
	else 
	{
		if(m == 0)
			cout << "o'clock" << endl;
		else
			cout << count[m] << endl;
	} 
	return 0;
}
