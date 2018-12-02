#include<iostream>
#include<string>
#include<map>
using namespace std;


map<string, int> m;
int main()
{
	int n;
	string str;
	
	cin >> n;
	cin >> str;
	
	int str_len  = str.length();	
	if(n <= 0 || n > str_len) return 0;
	 
	//�������������ַ������ȣ����Ի��ռ�ռ䣬�ռ临�Ӷ�ΪO��len^2), ���ÿ����һ���жϣ��ռ临�Ӷ��ܼ���O(len) 
	
	//ö�����䳤�� 
	for(int len = n; len <= str_len; len++)
	{
		for(int left = 0; left <= str_len - len; left++)
		{
			//�����Ӵ� 
			string key = str.substr(left, len);
			
			//������Ŀ��str_len <= 60�������ú�����λ������������ֵ�λ��,�м���λ���Ƴ���, ǰ����λ�����ƴ������պ������������ȼ��� 
			if(m.count(key) > 0)
			{
				m[key] += 10000;
			}
			else
			{
				//�����ǿ���������ֵģ����������λ���Ը�����ʾ�������� �ȳ��ֵ��� > ����ֵ��� 
				m[key] = 10000 + len * 100 - left;
			}
		}
	}
	
	int max = -0x3fffffff;
	string result; 
	
	map<string, int>::iterator iter;
	for(iter = m.begin(); iter != m.end(); iter++)
	{
		if(iter->second > max)
		{
			max = iter->second; 
			result = iter->first;	
		}
	}
	
	cout << result;
	
	
	return 0;
 } 
