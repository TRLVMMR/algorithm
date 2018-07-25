/*
	表达式计算：使用逆波兰表达式 
	模拟底层数据的运作方式 
	输入一个表达式，如1+2*(3-4),输出它的值 
	
	思路，使用两个栈
	一个数据栈，一个运算符栈
	遇到小括号时，计算小括号的再把新数据呀栈
	
	需要倒着读 
	只有当前操作符的优先级高于操作符栈栈顶的操作符的优先级，才入栈，否则弹出操作符以及操作数进行计算直至栈顶操作符的优先级低于当前操作符
	，然后将当前操作符压栈。当所有的操作符处理完毕（即操作符栈为空时），操作数栈中剩下的唯一一个元素便是最终的表达式的值

*/
#include<iostream>
#include<stack>
#include<string>

using namespace std;

stack<int> data;
stack<char> oper;

//处理运算符优先级 
int priority(char symbol)
{
	switch(symbol)
	{
		case '+':
		case '-':
			return 1;
			
		case '*':
		case '/':
			return 2;
		case  '(':
			return 0;
		default:
			return -1;
		
	}
	
}

int calculate()
{
	char top = oper.top();
	oper.pop();
	//如果是'(', 返回0 
	if(top == '(')
		return 0; 
	
	int first = data.top();
	data.pop();
	int second = data.top();
	data.pop();
	
	if(top == '+')
		data.push(first + second);
	else if(top == '-')
		//由于倒过来了，second才是表达式中较前的数 
		data.push(second - first);
	else if(top == '*')
		data.push(first * second);
	else if(top == '/')
	{
	
		if(second == 0)
		{
			cout << "不能除以0" << endl;
			return -1;	
		} 
		data.push(second / first);
	}
	else
	{
		cout << oper.top();
		cout << "输入符号有误" << endl;
	}
	return 1;
} 


int main()
{
	string str;
	
	cin >> str;
	
	int len = str.length();
	int sum = 0;
	int carry = 10;
	bool open = true; //用于控制data的push开关。防止两个符号连续时push 0的问题 
	for(int i = 0; i < len; i++)
	{
		//处理数字 
		if(str[i] <= '9' && str[i] >= '0')
		{
			sum = str[i] - '0' + sum * carry;
			if(i == len - 1)
			{
				data.push(sum);
			}
			open = true;
		}
		//处理小数问题：遇到小数点后面每个位除以10 
		else if(str[i] == '.')
		{
			carry = 0.1;
		}
		else
		{	
			//处理两个符号连续的问题 
			if(open)
			{
				data.push(sum);
				
			}
			open = false;
			sum = 0;
			
			//遇到）时，先处理小括号内的值 
			if(str[i] == ')') 
			{
				//计算括号里的数据 
				while(calculate() != 0)
				{

				} 					
			}
			else
			{

				//当前运算符优先级比栈顶元素值大时，入栈, 否则先将前面的表达式计算结果后在加入栈 , 直到操作符优先级比栈顶大（括号优先级设为最低是因为方便计算） 
				while(str[i] != '(' && !oper.empty() && (priority(oper.top()) >= priority(str[i])))
				{
					calculate();
				} 
				oper.push(str[i]);
				
			}
		}

		
	}
	while(!oper.empty()) 
		calculate();
	
	cout << "结果是" << data.top() << endl;
	
	return 0;
} 
