/*
	问题1:%s读取字符串时，遇到空格就结束，所以用puts 
	问题2：在关于j的for循环中把j的值改了，导致调试半天
	问题3：认为字符串最后一个字符是\0前一个字符， 其实是错的。这样的认为，让我多读一个字符导致出错 
	问题4:尝试把gets改成fgets，结果fgets是不吃空格的 
		 
*/
#define LOCAT 1
#include<stdio.h>
#include<string.h>


int main()
{
	#ifdef LOCAT
		freopen("1-2-1.in", "r", stdin);
	#endif
	char c[1001],d[1001];
	int n;
	scanf("%d",&n);
	getchar();
	
	for(int i = 0; i < n; i++)
	{
		int j, k = 0;
		memset(c, 0, sizeof(c));
		memset(d, 0, sizeof(d));
		
		//问题1： 
		gets(c); 
	//	fgets(c,1000,stdin);//问题4，fgets不吃空格，导致比我想要的多一个字符 
	
		for(j = 0; j < strlen(c); j++)
		{
			if(c[j] == ' ')
			{
				int temp = j;
				while(k < j)
				{
					d[k++] = c[--temp];
				}
				d[k++] = ' ';//单词最后加入空格 
				/*
					问题2： 
					一开始是写d[k++] = c[--j] 
					结果错了，原因在于我们把j改了，for循环就会变多次 
				*/
			}
			
		}
		//把最后一个空格到\0前的字符放入d 
		int temp = j;
		while(k < j)
		{
			d[k++] = c[--temp];
		}	
		/*
		问题3： 
		一开始是while(k <= j)看起来结果没错，提交后出现Presentation Error错误
		即多了或少了空白字符
		原因是我把最后一个单词前的空格也打印出来了，只看输出看不出来  
		是我的理解出错了，正确理解是：最后一个字符是\0，而不是\0前一个字符 
		*/
		puts(d);
	//	fputs(d,stdout);
	}
	
	return 0;
}
