/* 
	����һ������ת����������� 
	
	�ص㣺 ��������λ�Ǳ�־λ,�ص������һ������ 
	
	ע��㣺
		����ֵ0��
				���0ֻ��һ�Σ��Ҳ�����0��Ӧ��λ���ǳƣ���: 1009��һǧ��Ŷ�����һǧ��ʮ�� 
				�������ڵȱ�־λ��0����
		����ֵ1��
				��ʮλ, ʮ��֮���ʱ�򲻶�
	 
*/
#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

map<int, string> num;//����ת���ֵ� 
map<int, string> dig;//λ��ת���ֵ� 
int number[256]; //������� 
//vector<int> sign; //��ű�־λ 

int main()
{
	/*
		Ԥ����׶Σ��������ֶ�����λ������ 
	*/
	num[0] = "ling";
	num[1] =  "yi";
	num[2] =  "er";
	num[3] =  "san";
	num[4] =  "si";
	num[5] =  "wu";
	num[6] =  "liu";
	num[7] =  "qi";
	num[8] =  "ba";
	num[9] =  "jiu";
	
	dig[2] = "shi";
	dig[3] = "bai";
	dig[4] = "qian";
	
	//����λ��λ�����־λ 
	dig[5] = "wan";
//	sign.push_back(5);
	dig[9] = "yi"; 
//	sign.push_back(9);
	
/*	//�������б�־λ 
	for(int i = 0; i < sign.size(); i++)
	{
		int tempSign = sign[i];
		//���򣺴�ʮλ��ʼ�������Դ�2��ʼ, ��1��ʼ�ɶ��Ը��ߵ�ÿ��ѭ��Ҫ��һ��if�ж� 
		for(int j = 2; j < tempSign; j++)
		{
			//����ÿ��λ�Ķ��� 
			dig[tempSign + i - 1] = dig[i];
		}
		

		*/
	
	 
	for(int i = 2; i < 5; i++)
	{
		dig[4 + i] = dig[i]; 
	}
	for(int i = 2; i < 9; i++)
	{
		dig[8 + i] = dig[i];
	}

	int count;
	
	cin >> count;
	

	//����λ�� 
	int digit = 0;
	
	//�����ָ�λ�ŵ������� 
	while(count)
	{
		digit += 1;
		number[digit] = count % 10;		
		count /= 10;
	}
	
	//������ָ�λ��, �Ӹ�λ����λ 
	for(int i = digit; i > 1; i--)
	{
		//����ж��0���ţ�ֻ�������λ��0 
		if(number[i] == 0)
		{
			//�ų���������0 
			if(number[i - 1] == 0)
				continue;
			
			//��־λ��0����	
			if(i != 5 || i != 9)
				cout << "ling" << " ";

		}
	
			 
		else
		{
			//���i��1,��λ�ں�ʮλ��λ�ã��򲻶�һ 
			if(number[i] == 1 && ( i == 2 ||i == 6 || i == 10))
			{
				cout << dig[i] << " ";
				continue;
			}		
			
			//�����λ���� 
			//	cout << " " <<  num[number[i]] << " "; ��һ�������пո�
		 	cout <<  num[number[i]] << " ";
		 	//���λ�� 
			cout << dig[i] << " ";
		}
		
	}
	//��λ���ֵ�������
	if(number[1] != 0)
		cout << num[number[1]] << endl;
	else
		cout << endl;	
	
	
	return 0;
 } 
