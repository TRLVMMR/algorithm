/*
	string���������char��������ʹ��
	�������ԣ���char��ֵ��string���󣬵��ǲ����ǳ�ʼ������Ϊû���ַ��Ĺ��캯��
	 
	 ������insert(pos, string) 
	 ������Ҫ��һ��д����ʱ������Ҫ���幹����iterato��ֻ����begin��end�Ӽ�����
	 ����һ�в��ÿ�����ʵ�õ��������ģ�ֻ��Ҫ�����ִ������ 
	 find��str��pos�����������Ӵ���ʧ��ʱ����string:npos ֵΪ -1
	 
	 �滻��replace(pos, len, str)�� 
	 ɾ����erase(pos, len) 

*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str1;
	string str2;
	
	getline(cin, str1);
	getline(cin, str2);
	
	
	int len = str2.size();
	for(int i = 0; i < len; i++)
	{
		string temp;
		temp = str2[i];
		
		str1.erase(str1.find(temp), 1);
	}
	
	
	
	cout << str1 << endl;
	
	
	return 0;
}
