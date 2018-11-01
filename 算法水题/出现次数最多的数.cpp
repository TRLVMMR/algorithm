#include<iostream>
#include<map>

using namespace std;

map<int, int> m;

int main()
{
	int n;
	cin >> n;
	
	if(n <= 0)
		return 0;
	
	for(int i = 0; i < n; i++)
	{
		// keyΪ�������ݣ�valueΪ����5���� 
		int key;
		cin >> key;
		
		// ����ֵ���ڣ���+1 
		if(m.count(key) > 0)
			m[key]++; 
		else 
			m[key] = 1;
	}
	
	int max = -0x3fffffff;
	int max_key = -0x3fffffff;
	
	map<int, int>::iterator iter;
	for(iter = m.begin();iter != m.end(); iter++)
	{
		//�ҵ�����ļ�ֵ������ 
		if(iter->second > max)
		{
			max = iter->second;
			max_key = iter->first;
		}
		else if(iter->second == max)
		{
			// ���ҵ���С�ļ�ֵ������ 
			if(max_key > iter->first)
				max_key = iter->first;	
		}
	}
	
	cout << max_key << endl;
	
	return 0;	
 } 
