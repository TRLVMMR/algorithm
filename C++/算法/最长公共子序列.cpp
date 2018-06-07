/*
	����������У�
	 
		��������a, b�� ���������г���Ϊk 
		ʹ��������
			��a�ַ����ֳɸ�����ϣ���������C��alen - k��(alen)�Ŀ����� �ٳ���blen�ģ����Ӷ��൱�� 
		ʹ��dp��
			���Ӷ�Ϊalen * blen �� ��Ϊalenÿ�μ�1����Ҫɨ��һ��b�ַ��� 
		dpΪʲôʹ���Ӷȱ���ˣ�
			 
	
	
		״̬��
			 dp[i][j]�����a[i]Ϊֹ�� b[j]Ϊֹ������������г��� 
	
		�����ӽṹ�� 
					���ʱ��������Ҫ 
					1. dp[i-1][j-1] + 1   a[i] == b[j]
					
						����ʱ����������һ�������п�������µ����� 
					2. dp[i][j-1]       a[i] != b[j]
						��dp[i-1][j] 
						
					3.�����׺��Ե�
						i = 0��j = 0ʱ��dp = 0,���ݹ��յ� 
		 
		״̬ת�Ʒ���ͬ�ϡ�
				
		 
	ע����� dp�߽���i = 0��j = 0ʱ 
	i - 1�Ȳ��֣�i = 0ʱ������ . �����������1��ʼ 
		 
*/

#include<iostream>
#include<string>
#include<algorithm> 
#define MAXV 256

using namespace std;


int dp[MAXV][MAXV];

//���԰棬���ܿ���һ������ 
void maxPubLen()
{
	string a, b;
	
	cin >> a;
	cin >> b;
	
	int alen = a.length();
	int blen = b.length();
	 
	
	for(int i = 0; i < alen; i++)
	{
		for(int j = 0; j < blen; j++)
		{	
			//0λ�����⴦�� 
			if(i == 0 || j == 0)
			{
				dp[i][j] = 0;
				
				if(a[i] == b[j])
				{
					dp[i][j] = 1;
				}
				else
				{
					if(i != 0)
					{
						dp[i][j] = max(dp[i - 1][j], 0);
					}
					else if(j != 0)
					{
						dp[i][j] = max(dp[i][j - 1], 0);
					}
				}
				cout << dp[i][j]; 
				continue;
			}
			
			if(a[i] == b[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			
			cout << dp[i][j]; 
		}	
		cout << endl;
	}
} 

//������Ż��� 
void maxPublicLen()
{
		string a, b;
	
	cin >> a;
	cin >> b;
	
	int alen = a.length();
	int blen = b.length();
	 
	//��ʼ��0�и�0�е���Ϊ0�� ��i = 0��j = 0������ 
	for(int i = 0; i < alen; i++)
	{
		dp[0][i] = 0;
		dp[i][0] = 0;
	}
	
	//Ϊ��Ҫ+1����Ϊ1��alen+1�����ַ���a�ĳ��� 
	for(int i = 1; i < alen + 1; i++)
	{
		for(int j = 1; j < blen + 1; j++)
		{	
			//�ַ����Ǵ�0��ʼ�ģ��㷨���۵���������x1��ʼ�� ��������һ�¾��ܹ����������ַ����ַ���  
			if(a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			
			cout << dp[i][j]; 
		}	
		cout << endl;
	}
	
	
} 
int main()
{
	

	
	/*
	int ans = 0;
	for(int i = 0; (i < a.length())&& (i < b.length()); i++)
	{
		for(int j = 0; (j < a.length())&& (j < b.length()); j++)
			ans = max(ans, dp[i][j]);
		
	}
	
	cout << ans << endl;*/
	
	return 0;
} 
