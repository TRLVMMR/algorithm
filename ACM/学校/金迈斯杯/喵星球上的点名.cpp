#include<stdio.h>
#include<string>
#include<iostream>


using namespace std;

struct Name
{
	string lname;
	string fname;
	int sum;
	Name(){sum = 0;}
};
Name name[20000];
//string dname[50000];

int main()
{
	int n, m;
	
	freopen("111.txt", "r", stdin);
	
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < n; i++)
	{
		int l,f;
		
		scanf("%d", &f);
		while(f--)
		{
			int temp;
			scanf("%d", &temp);
			name[i].fname += (temp + 'a');
		}
		
		scanf("%d", &l);
		while(l--)
		{
			int temp;
			scanf("%d", &temp);
			name[i].lname += (temp + 'a');
		}
		
	}
	
	for(int i = 0; i < m; i++)
	{
		int l, sum = 0;
		string dname;
		
		scanf("%d", &l);
		while(l--)
		{
			int temp;
			scanf("%d", &temp);
			dname += (temp + 'a');
		}
		
		for(int i = 0; i < n; i++)
		{
			
			if(name[i].fname.find(dname) != string::npos)
			{
				sum++;
				name[i].sum++;
			}
			else if(name[i].lname.find(dname) != string::npos)
			{
				sum++;
				name[i].sum++;
			}
		}
		printf("%d\n",sum);
	}
	
	for(int i = 0; i < n; i++)
		printf("%d", name[i].sum);
//	printf("\n");
	return 0;
}
