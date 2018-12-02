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
	 
	//这种做法由于字符串长度，所以会很占空间，空间复杂度为O（len^2), 如果每层做一次判断，空间复杂度能减到O(len) 
	
	//枚举区间长度 
	for(int len = n; len <= str_len; len++)
	{
		for(int left = 0; left <= str_len - len; left++)
		{
			//拷贝子串 
			string key = str.substr(left, len);
			
			//由于题目中str_len <= 60，所以用后面两位数控制最早出现的位置,中间两位控制长度, 前面两位数控制次数（刚好是条件的优先级） 
			if(m.count(key) > 0)
			{
				m[key] += 10000;
			}
			else
			{
				//由于是控制最早出现的，所以最后两位数以负数表示，才能让 先出现的数 > 后出现的数 
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
