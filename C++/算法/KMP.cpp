/*
	��abƥ��ab���涨һ��ʱΪ-1 
	
	2018��3��7��17:32:05 
*/

#include<cstdio>
#include<cstring>
#define MAXV 256

int next[MAXV];

//��ȡnext���� 
void get_next(char pattern[], int len)
{

	/*
		ƥ��ԭ�����óɹ���������,���оͼ��̣�ֱ���ɹ���Ϊ0ʱ����ƥ��λi������ǰ��һ��ƥ�䣬�� 
		jΪ��ɹ����ĵĳ���-1(��Ϊ�������0��ʼ�ģ�, j + 1��ƥ��λi�ɹ�ʱ��= ��ƥ��λnext[i]��ֵ 
		next[]����������һ�����ʵ�ƥ��λ������ 
		�ɹ�����̺�Ĵ�Ҳ�ǳɹ������Ӵ�����ͣ���ʺ��Ӵ��γ�ѭ�� 
		 
	*/
	int j = -1;
	next[0] = -1;
	
	for(int i = 1; i < len; i++)
	{
		while(j != -1 && pattern[i] != pattern[j + 1])
		{
			//ƥ��ʧ�ܣ�����̳ɹ������ȣ���ǰ�ҵ����ʵĳɹ���ƥ�䣬ֱ�����ʧ�� 
			j = next[j];
		}
		
		//�����iλ�ɹ�ƥ��, j���ȼ�һ�� 
		if(pattern[i] == pattern[j + 1] )
		{
			j++;	
		} 
		
		//���iλƥ��ʧ��next[i]��Ϊ-1
		// �����ǳɹ�ƥ���ģ����Դ�ʱpattern[i] = pattern[j], 
		//����������������pattern[j + 1] != pattern[next[j] + 1]��������iλƥ�䣬������pattern[i + 1] != pattern[next[i] + 1]
		if( j == -1 || pattern[i + 1] != pattern[j + 1])
		{
			next[i] = j;
		}
		//ƥ��ɹ��� ��next[j + 1]��next[next[j] + 1]ֵһ������ǰ�ҵ���ͬ��,��Ϊ����һ��ƥ�䵽next[i]ʧ�ܣ�������ǰ��ʧ�� 
		else
		{
			next[i] = next[j];
		}
	}
	
}

//KMP�㷨��KMP�����Զ��� 
int KMP(char text[], char pattern[])
{
	int tlen = strlen(text);
	int plen = strlen(pattern);
	
	//������¼KMP�Զ������ܴ��� 
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
		
		//���KMP�Զ������� 
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
