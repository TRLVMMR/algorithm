/* 
	输入一个数，转换成中文输出 
	
	特点： 个，万，亿位是标志位,特点就像到了一个周期 
	
	注意点：
		特殊值0：
				多个0只读一次，且不读出0相应的位数昵称，如: 1009读一千零九而不是一千零十九 
				个，万，亿等标志位的0不读
		特殊值1：
				在十位, 十万之类的时候不读
	 
*/
#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

map<int, string> num;//数字转换字典 
map<int, string> dig;//位数转换字典 
int number[256]; //存放数字 
//vector<int> sign; //存放标志位 

int main()
{
	/*
		预处理阶段，处理数字读音跟位数读音 
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
	
	//将万位亿位加入标志位 
	dig[5] = "wan";
//	sign.push_back(5);
	dig[9] = "yi"; 
//	sign.push_back(9);
	
/*	//遍历所有标志位 
	for(int i = 0; i < sign.size(); i++)
	{
		int tempSign = sign[i];
		//规则：从十位开始读，所以从2开始, 从1开始可读性更高但每次循环要多一次if判断 
		for(int j = 2; j < tempSign; j++)
		{
			//构造每个位的读法 
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
	

	//计算位数 
	int digit = 0;
	
	//将数字各位放到数组里 
	while(count)
	{
		digit += 1;
		number[digit] = count % 10;		
		count /= 10;
	}
	
	//输出数字跟位数, 从高位到低位 
	for(int i = digit; i > 1; i--)
	{
		//如果有多个0连着，只需读出低位的0 
		if(number[i] == 0)
		{
			//排除掉连续的0 
			if(number[i - 1] == 0)
				continue;
			
			//标志位的0不读	
			if(i != 5 || i != 9)
				cout << "ling" << " ";

		}
	
			 
		else
		{
			//如果i是1,且位于含十位的位置，则不读一 
			if(number[i] == 1 && ( i == 2 ||i == 6 || i == 10))
			{
				cout << dig[i] << " ";
				continue;
			}		
			
			//输出各位数字 
			//	cout << " " <<  num[number[i]] << " "; 第一个数会有空个
		 	cout <<  num[number[i]] << " ";
		 	//输出位数 
			cout << dig[i] << " ";
		}
		
	}
	//个位数字单独读出
	if(number[1] != 0)
		cout << num[number[1]] << endl;
	else
		cout << endl;	
	
	
	return 0;
 } 
