/*
	输入n行单词 
	把单词改成，元音全部大写，辅音全部小写 

*/

#include<stdio.h>
#include<string.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i = 0; i < n; i++)
	{
		char a[51];
		scanf("%s",a);
		
		int alen = strlen(a);
		
		for(int j = 0; j < alen; j++)
		{
			//如果输入的是大写字母 
			if(a[j] >= 'A' && a[j] <= 'Z')
			{
			
				switch(a[j])
				{

					case 'A': case'E': case'I': case'O': case'U':
						break;
					
					default:
					{
						a[j] += 32;
						break;
					}
					
				}
			}
			else if(a[j] >= 'a' && a[j] <= 'z')
			{
				switch(a[j])
				{
					case 'a': case'e': case'i': case'o': case'u':
					{
						a[j] -= 32;
						break;
					}
					
				}			
				
			}
			
		}
		
		printf("%s\n",a);
		
	}
	
}
