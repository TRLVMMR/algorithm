/* 
	题目；输入数字，打印它的中文读音
	
	0要做特殊处理，因为0读出来不会加位数。且多个0连续时只读一次
	1要做特殊处理，遇到十时，不读。十亿。不是一十亿， 
	位数的特殊情况：全为0时可以不读，如1亿，不全为0时一定要读，如1亿1千万 
	
	如果位数不够过标志位的4位，就用剩余位数
*/
#include<iostream>
#include<string>
#include<algorithm>

using namespace std; 

int main()
{
	string digits[10] = {"", "shi", "bai", "qian", "wan", "shi", "bai", "qian", "yi", "shi"};
	string number[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	
	string str;
	cin >> str;
	
	int len = str.length();
	for(int i = 0; i < len; i++)//字符串开始是0 
	{
		int num = str[i] - '0';//得到相应的数字
		int nowdig = len - i - 1;	//使用倒序，得到正确的位数下标 
		  
		//0要做特殊处理，
		if(num == 0)
		{	
			//处理方式：连续几个0时只读最后一个0的读音。
			 //处理0的数问题。如果有下一个数， 且下一个数不是0 
			if(i + 1 < len && str[i + 1] != '0')
				cout << number[num] << " ";
				
			//处理0的位问题： 
			if((nowdig) % 4 == 0)	 //当为个，万, 亿位时 
			{
				//如果标志位前面够4位，就取4位，否则取到最高位, 由于后面要兼容最高位需要<=，所以这里应该是4-1=3 
				int count = min(i, 3);
				
				bool allzero = true;	//标志着是否全为0 
				for(int j = 0; j <= count ; j++)
				{
					if(str[i - j] != '0')
					{
						allzero = false;
						break;	
					}  
					
				}
				
				if(allzero)
					continue;	
				else
					cout << digits[nowdig] << " ";
				
				
			}
		}
		//在每到需要读1的时候，遇到shi就不读 
		else if(num == 1 && (nowdig == 1 || nowdig == 5 || nowdig == 9))
		{
			cout << digits[nowdig] << " ";
		}
		else
		{	
			cout << number[num] << " " << digits[nowdig] << " ";				
		}
		
	}	
	
	cout << endl;
	
	return 0;
}
