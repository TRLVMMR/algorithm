#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

char a[100];
char b[100];
char c[100];

int flag[52];

int main()
{
	gets(a);
	gets(b);
	
	int len = strlen(b);
	
	for(int i = 0; i < len; i++)
	{
		int temp = b[i];
		if('a' <= temp && temp <= 'z')
		{
			flag[temp - 'a'] = 1;
		}
		else if('A' <= temp && temp <= 'Z')
		{
			flag[temp - 'A' + 26] = 1;
		}
	}
	
	int alen = strlen(a);
	
	for(int i = 0; i < 26; i++)
	{
		if(flag[i] == 1)
		{
			for(int j = 0; j < alen; j++)
			{
				if(a[j] == i + 'a')
				{
					a[j] = 0;
				}
			}
		}
		
	}
	
	for(int i = 26; i < 52; i++)
	{
		if(flag[i] == 1)
		{
			for(int j = 0; j < alen; j++)
			{
				if(a[j] == i + 'A' - 26)
				{
					a[j] = 0;
				}
			}
		}
		
	}
	
	int clen = 0;
	
	for(int i = 0; i < alen; i++)
	{
		if(a[i] != 0)
		{
			c[clen++] = a[i];
		}
	}
	
	cout << c << endl;
	
	
	
	return 0;
}
