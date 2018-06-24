/*
	���⣺ 
	��n��Ӳ�ң�������һ���ٱң��������ټ����ܱ�֤�ҵ��ٱ� 
		����Ӳ�ң�
			��n % 3 == 0 : ��Ϊn/3, n/3, n/3 
			��n % 3 == 1: ��Ϊn/3, n/3, (n/3) + 1
			��n % 3 == 2�� ��Ϊn/3, (n/3)+1, (n/3) +1 
		
		�����漰�漰����ѭ������k^n��Ӧ���ǵ������n = 1ʱ������� ��3^n ��ȷ�3^n����
		 
		����ļ��ַ�����û�н����һ��ʼ��n=0��n=1�����⣬��Ϊ��û�����壬��ʱ����Ҫ�� 
*/
#include<iostream>
#include<cmath>

using namespace std;

int end1(int n)
{
	int ans = 0;
	
	//���nΪ3^n������n=9���ͻ���9/3 = 3, 3/3 = 1��ʹ��n--��һλ������n/3 < 1��C���԰������0�� 
	//�ô���3^n����ͨ3�ı��������Ա���ȷ����,��Ϊ 
	if(n % 3 == 0)
		n--;
	
	while(n > 0)
	{
		n /= 3;
		ans++;
	}
	
	return ans;
}

//��������Ǵ���� 
int end2(int n)
{
	int ans = 0;
	
	//���У��൱��n-1 > 0����n % 3 == 1�����ѣ���Ϊ����ø�ԭ�����n % 3 == 0һ������ 
	while(n > 1)
	{
		n /= 3;
		ans++;
	}
	
	return ans;
}

int end3(int n)
{
	int ans = 0;
	
	//������3^n, Ҳ���У����ٶ��� 
	if(n % 3 == 0)
		for(int i = 0; i < 100; i++)
		{
			int mark = pow(3, i);
			if(n < mark)  break;
			else if ( n == mark) ans--;
		}
		
	
	while(n > 0)
	{
		n /= 3;
		ans++;	
	}	
	
	return ans;
} 

int end4(int n)
{
	int ans = 0;
	 
	double temp = log(n) / log(3);
	/*
	 * ���log���������, ֤����3^n, ������1 
		if(int(temp) == temp) ans--;

	  С�����磬���Լ�1 
		ans += int(temp) + 1;
		�����淽����ͬ 
	*/
	
	//���log�������������������С�� 
	if(temp > int(temp))
		ans++;
	ans += int(temp);
	
	return ans;	
} 

int main()
{
	int n;
	
	cin >> n;
	for(int i = 2; i < n; i++)
	{
		if(end1(i) != end4(i))
		{
			cout << i << endl;
			cout << end1(i) << " != " << end4(i) << endl;  
		}
		
	}
	
	return 0;
} 
