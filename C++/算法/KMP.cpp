/*
	若ab匹配ab，规定一样时为-1 
	
	2018年3月7日17:32:05 
*/

#include<cstdio>
#include<cstring>
#define MAXV 256

int next[MAXV];

//获取next数组 
void get_next(char pattern[], int len)
{

	/*
		匹配原则是让成功串尽量长,不行就减短，直到成功串为0时，待匹配位i就与最前的一个匹配，若 
		j为最长成功串的的长度-1(因为是数组从0开始的）, j + 1（匹配位i成功时）= 此匹配位next[i]的值 
		next[]是用来找下一个合适的匹配位的数组 
		成功串变短后的串也是成功串的子串，不停找适合子串形成循环 
		 
	*/
	int j = -1;
	next[0] = -1;
	
	for(int i = 1; i < len; i++)
	{
		while(j != -1 && pattern[i] != pattern[j + 1])
		{
			//匹配失败，则减短成功串长度，往前找到合适的成功串匹配，直到最后失败 
			j = next[j];
		}
		
		//如果到i位成功匹配, j长度加一， 
		if(pattern[i] == pattern[j + 1] )
		{
			j++;	
		} 
		
		//如果i位匹配失败next[i]则为-1
		// 由于是成功匹配后的，所以此时pattern[i] = pattern[j], 
		//这句的真正含义是想pattern[j + 1] != pattern[next[j] + 1]，由于在i位匹配，所以是pattern[i + 1] != pattern[next[i] + 1]
		if( j == -1 || pattern[i + 1] != pattern[j + 1])
		{
			next[i] = j;
		}
		//匹配成功后， 若next[j + 1]跟next[next[j] + 1]值一样，往前找到不同的,因为这样一旦匹配到next[i]失败，继续往前必失败 
		else
		{
			next[i] = next[j];
		}
	}
	
}

//KMP算法，KMP有限自动机 
int KMP(char text[], char pattern[])
{
	int tlen = strlen(text);
	int plen = strlen(pattern);
	
	//用来记录KMP自动机接受次数 
	int ans = 0;
	
	get_next(pattern, plen);
	
	int j = -1;
	
	for(int i = 1; i < tlen; i++)
	{
		while(j != -1 && text[i] != pattern[j + 1])
		{
			j = next[j];
		}
		
		if(text[i] == pattern[j + 1] )
		{
			j++;	
		} 
		
		//如果KMP自动机接受 
		if(j == plen - 1)
		{ 
			ans++;
			j = next[j];
		}
		
	}
	
	return ans;
}



int main()
{
	
	
	return 0;
}
