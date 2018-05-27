/*
	题目描述：《算法竞赛入门经典》第210页
	使用方法：状态空间搜索，IDA* 
*/

#include<stdio.h>
#define MAXV 1000007
typedef int State[24]; 
State st[MAXV];

void dir(State& s, char c)
{
	switch(c)
	{
		case 'A':
		{
			
			int temp = s[22]; s[22] = s[0]; s[0] = s[2]; s[2] = s[6]; s[6] = s[11]; s[11] = s[15]; s[15] = s[20]; s[20] = temp;    
		
			break;
		}
		case 'B':
		{
		
			int temp = s[23]; s[23] = s[1]; s[1] = s[3]; s[3] = s[8]; s[8] = s[12]; s[12] = s[17]; s[17] = s[21]; s[21] = temp;
			
			break;
			
		}
		case 'C':
		{	
			int temp = s[10];
			int i;
			for(i = 10; i > 4; i--)
			{
				s[i] = s[i-1];
			}
			s[i] = temp;
		}
			break;
		case 'D':
		{
			
			int temp = s[19];
			int i;
			for(i = 19; i > 13; i--)
			{
				s[i] = s[i-1];
			}
			s[i] = temp;
			
			break;
		}
		case 'E':
		{
	
			int temp = s[1]; s[1] = s[23]; s[23] = s[21]; s[21] = s[17]; s[17] = s[12]; s[12] = s[8]; s[8] = s[3]; s[3]= temp;
			
			
			break;
		}
		case 'F':
		{
			
			int temp = s[0]; s[0] = s[22]; s[22] = s[20]; s[20] = s[15]; s[15] = s[11]; s[11] = s[6]; s[6] = s[2]; s[2] = temp;
			
			break;
		}
		case  'G':
		{
			
			int temp = s[13];
			int i;
			for(i = 13; i < 19; i++)
			{
				s[i] = s[i+1];
			}
			s[i] = temp;
			
			break;
		}
		case 'H':
		{
			
			int temp = s[4];
			int i;
			for(i = 4; i < 10; i++)
			{
				s[i] = s[i+1];
			}
			s[i] = temp;
			
			break;
	}
	}
	
}
bool goal(State s)
{
	if(s[6] == s[7] && s[7] == s[8] && s[8] == s[11])
		{
			if(s[11] == s[12] && s[12] == s[15] && s[15] == s[16] && s[16] == s[17])
				return true;
		}
	return false;
}


void init_hash()
{
	
}

int bfs()
{
	init_hash();
	int head = 1, tail = 2;
	
	while(head < tail)
	{
		State& s = st[head];
		if(goal(s))	return head;
		
		//穷举各种方式
		for(int i = 0; i < 8; i++)
		{
			dir(s, i+'A');
		}
		
		//剪枝与判重 
	}
}

int main()
{
	
	for(int i = 0; i < 24; i++)
	{
		scanf("%d", st[0][i]);
	} 
	
	
	return 0;
}


