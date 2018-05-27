#include<stdio.h>

struct Note
{
	char name[20];
	bool flag;
};

int main()
{
	int n;
	Note chil[100];
	
	scanf("%d", &n);
	
	for(int i = 1 ; i <= n; i++)
	{
		scanf("%s", chil[i].name);
		chil[i].flag = false;
	}
	
	scanf("%d,%d", &w, &s);
	
	int temp = w;
	while(n >= s)
	{
		if(chil[temp + s - 1])
		{
			temp + 
		}
		
	}
	
	return 0;
}
