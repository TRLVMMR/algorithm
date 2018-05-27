/* 
	�����õ����������ģ����ǳ�ʱ�ˣ���������IDA*����벻���͹۹��ۺ����� 
	��Ŀ�涨ʱ��ֻ��1s��ȴ����6M�Ŀռ䣬��������bfs���� 
*/
#include<stdio.h>
#include<string.h>

typedef bool State[4][4];
int maxd;
State v[10000], ans[10000];
int dirt[1000];

bool dfs(int d, State& s)
{
	if(d == maxd)
	{
		int ok = 1;
		//���ͼ��ȫ��Ϊ-����true��������true�����򷵻�false 
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				if(s[i][j] == false)
				{	ok = 0;
					return false; 
				} 
			}
		}
		
		if(ok)
		{
		//	if(better(d))
		//������ans���Ǳ�Ҫ 
			memcpy(ans, v, sizeof(State) * (d+1) );
			return true;
		}
	
	}
	
	bool flag;
	//������任  
	for(int x = 0; x < 4; x++)
	{
		for(int y = 0; y < 4; y++)
		{
			//�͹۹��ۺ���OR�����Լ�֦���ģ����� û�У��� �ҵ���������� 
			State& t = v[d+1];
			memcpy(&t, &s, sizeof(s));
			
			//��x��y�е�״̬��ת 
			for(int i = 0; i < 4; i++)
			{
				t[x][i] = !t[x][i];
				
			}
			for(int i = 0; i < 4; i++)
			{
				t[i][y] = !t[i][y]; 
			}
			//���λ��ý�����t[x][y]�ı���� �����Ի���Ҫһ�� 
				t[x][y] = !t[x][y];
			
			//��x��y�����λ������ 
			dirt[d] = x * 10 + y;
			//������һ�α任 
			flag = dfs(d+1, t);
			
			//�ҵ��������жϣ��������Ҫ�ֵ�����С֮��ľͲ��������ж� 
			if(flag)
				return true;
		}
	}
	return false;
}


int main()
{
	//����ʼ״̬��ֵ 
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			char ch;
			ch = getchar();
			
			if(ch == '+')
				v[0][i][j] = false;
	
			else if(ch == '-')
				v[0][i][j] = true;
	
		}
		getchar();//�ո� 
	}
	//	scanf("%d", &v[0][i]);
	
	for(maxd = 0; ;maxd++)
	{
		memset(ans, 0, sizeof(ans));
		if(dfs(0, v[0]))
		{
			printf("%d\n", maxd);
			break;
		}
	}
	for(int i = 0; i < maxd; i++)
		printf("%d %d\n",dirt[i]/10 + 1, dirt[i]%10 + 1);
	
	return 0;
}
