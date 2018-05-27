/*
	˼·��ʮ������ת��������ת�˽��� 
 
*/
#include<stdio.h>
#include<string.h>

char h[100001];
char b[500000];
char o[200020];

//ʮ������תʮ����z��ת������ 
void htob()
{
	memset(b,0 ,sizeof(b));
	int len = strlen(h);
	//��ʮ�����Ƶ��ַ�ת�ɶ�Ӧ��10������ 
	for(int i = 0; i < len; i++)
	{
		int sum;
		if(h[i] >= '0' && h[i] <= '9')
		{
			sum = h[i] - '0';
		}	
		else if(h[i] >= 'A' && h[i] <= 'F')
		{
			sum = h[i] - 'A' + 10;
		}
		
		//ʮ����ת������ ,ʮ������1��λ��Ӧ������4��λ  
		for(int j = 1; j <= 4; j++)
		{
			//λ��������0 
			if(sum == 0)
			{
				b[(i+1) * 4 - j] = '0';
			}
			else
			{
				b[(i+1) * 4 - j] = sum % 2 + '0';
				sum /= 2;
			}

		}
			
	}
	
}

//������ת�˽��� 
void btoo()
{
	memset(o, 0,sizeof(o));
	int len = strlen(b);
	//λ�����ܲ���3�ı���������Ҫ������(����ȡǰһ��λ������λ����) 
	int temp = len % 3; 
	int sum = 0;
	
	if(temp == 0) 
		temp = 3;
		
	for(int i = 0; i < temp; i++)
		sum  = sum * 2 + b[i] - '0';
	o[0] = sum + '0';


	int k = 1;//���ڰ˽��Ƶ�0λ�Ѿ����ˣ���1λ��ʼ 
	for(int i = temp; i < len; i+=3)
	{
		sum = 0;
		//j��ƫ���� 
		for(int j = 0; j < 3; j++)
		{
			sum = sum * 2 + b[i + j] - '0';
		}
		
		o[k] = sum + '0';
		k++;
	}
	

	
}

int main()
{
	int n;
	
	scanf("%d", &n);
	
	for(int j = 0; j < n; j++)
	{
		memset(h, 0, sizeof(h));
		scanf("%s", h);	
		
		htob();	//16ת2 
		btoo();//2ת8 
		
		//�ҵ���һ����Ϊ0�ĵ�λ��ʼ��� 
		int olen = strlen(o);
		int ok = 1;
		for(int i = 0; i < olen; i++)
		{
			if(o[i] != '0')
			{
				printf("%s\n", &o[i]);
				ok = 0;
				break;
			}
		}
		//�������λ��Ϊ0�������0 
		if(ok)
		{
			printf("0\n");
		}
		
	}
	
	
	return 0;
} 
