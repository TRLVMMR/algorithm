/*
	���ʽ���㣺ʹ���沨�����ʽ 
	ģ��ײ����ݵ�������ʽ 
	����һ�����ʽ����1+2*(3-4),�������ֵ 
	
	˼·��ʹ������ջ
	һ������ջ��һ�������ջ
	����С����ʱ������С���ŵ��ٰ�������ѽջ
	
	��Ҫ���Ŷ� 
	ֻ�е�ǰ�����������ȼ����ڲ�����ջջ���Ĳ����������ȼ�������ջ�����򵯳��������Լ����������м���ֱ��ջ�������������ȼ����ڵ�ǰ������
	��Ȼ�󽫵�ǰ������ѹջ�������еĲ�����������ϣ���������ջΪ��ʱ����������ջ��ʣ�µ�Ψһһ��Ԫ�ر������յı��ʽ��ֵ

*/
#include<iostream>
#include<stack>
#include<string>

using namespace std;

stack<int> data;
stack<char> oper;

//������������ȼ� 
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
	//�����'(', ����0 
	if(top == '(')
		return 0; 
	
	int first = data.top();
	data.pop();
	int second = data.top();
	data.pop();
	
	if(top == '+')
		data.push(first + second);
	else if(top == '-')
		//���ڵ������ˣ�second���Ǳ��ʽ�н�ǰ���� 
		data.push(second - first);
	else if(top == '*')
		data.push(first * second);
	else if(top == '/')
	{
	
		if(second == 0)
		{
			cout << "���ܳ���0" << endl;
			return -1;	
		} 
		data.push(second / first);
	}
	else
	{
		cout << oper.top();
		cout << "�����������" << endl;
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
	bool open = true; //���ڿ���data��push���ء���ֹ������������ʱpush 0������ 
	for(int i = 0; i < len; i++)
	{
		//�������� 
		if(str[i] <= '9' && str[i] >= '0')
		{
			sum = str[i] - '0' + sum * carry;
			if(i == len - 1)
			{
				data.push(sum);
			}
			open = true;
		}
		//����С�����⣺����С�������ÿ��λ����10 
		else if(str[i] == '.')
		{
			carry = 0.1;
		}
		else
		{	
			//���������������������� 
			if(open)
			{
				data.push(sum);
				
			}
			open = false;
			sum = 0;
			
			//������ʱ���ȴ���С�����ڵ�ֵ 
			if(str[i] == ')') 
			{
				//��������������� 
				while(calculate() != 0)
				{

				} 					
			}
			else
			{

				//��ǰ��������ȼ���ջ��Ԫ��ֵ��ʱ����ջ, �����Ƚ�ǰ��ı��ʽ���������ڼ���ջ , ֱ�����������ȼ���ջ�����������ȼ���Ϊ�������Ϊ������㣩 
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
	
	cout << "�����" << data.top() << endl;
	
	return 0;
} 
