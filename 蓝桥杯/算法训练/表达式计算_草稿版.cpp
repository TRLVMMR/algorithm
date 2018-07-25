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
	//cout << "����" << endl;
	char top = oper.top();
	oper.pop();
	//cout <<"��ջ" << top << endl;
	if(top == '(')
		return 0; 
	
	int first = data.top();
	data.pop();
	int second = data.top();
	data.pop();

	cout << first << " " << second << endl;
	
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
	bool open = true; 
	for(int i = 0; i < len; i++)
	{
		//��û�����ַ�����ͷ�����ֵ����� 
		//��������ַ� 
		if(str[i] <= '9' && str[i] >= '0')
		{
			sum = str[i] - '0' + sum * carry;
			cout << sum << endl;
			if(i == len - 1)
			{
				data.push(sum);
				//cout << "����ջ" << sum << endl;
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
			//��������Ϊ����������ֻ��+(��Ȼ�󵥶�����(�󣬷��ֻ���)+,))�����⡣�����һ���Խ�����з����������� 
			if(open)
			{
				data.push(sum);
				
			}
			open = false;
			//cout << "����ջ" << sum << endl;
			//cout << sum << endl;
			//cout << str[i] << endl;
			sum = 0;
			
			if(str[i] == ')') 
			{
				//��������������� 
				while(calculate() != 0)
				{
					cout <<data.top() << oper.top() << endl; 
					//cout << "lalal"  << endl;; 
				} 					
				//cout << data.top() << oper.top() << endl;  
				//cout << "��ջ" << oper.top();
				//oper.pop();
			}
			else
			{

				//��ǰ��������ȼ���ջ��Ԫ��ֵ��ʱ����ջ, �����Ƚ�ǰ��ı��ʽ���������ڼ���ջ , ֱ�����������ȼ���ջ�����������ȼ���Ϊ�������Ϊ������㣩 
				while(str[i] != '(' && !oper.empty() && (priority(oper.top()) >= priority(str[i])))
				{
					//��������'('ʱ��������str[i] != '(', �����ջû���⡣������С����ʱ����������С�������ȼ�Ϊ��С�����ԣ�Ҳ��������ѭ����
					//���ۣ���ѭ���ڲ�������'(', ��˲���Ҫ���²���
					/* 
					if(calculate() == 0)
					{
						cout << "����(��" << endl;
						break;
					}
					*/
					calulate();
					//cout << "����" << endl; 
				} 
				//cout << oper.top() << endl;; 
				oper.push(str[i]);
				//cout << "��ջ" << str[i] << endl; 
				
			}
		}

		
	}
	cout << "start" << endl;
	while(!oper.empty()) 
		calculate();
	
	cout << data.top() << endl;
	cout << "end" << endl;
	
	return 0;
} 
