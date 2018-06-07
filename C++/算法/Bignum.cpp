#ifndef BIG_NUM
#define BIG_NUM 

#include<cstring>
#include<iostream>
#define MAX_LEN 1000

#endif


/*
	һЩ��������
		* 1.
			[Error] 'int Bignum::len' is private
			[Error] within this context
			
		�˳�������������ԭ�� 
		 	a.û��ʹ����Ԫ
			b.���������ʵ�ֵĲ�����һ��
				�綨�� friend Bignum operator + ( Bignum& a, const Bignum& b);
				��ʵ�� friend Bignum operator + ( const Bignum& a, const Bignum& b);
				
		* 2.
		
			
*/


namespace bignum
{
	
//�������� 
class Bignum
{
	private:
		int len;//�ַ������� 
		char symbol;//����λ 
		char num[MAX_LEN];//�������0λΪ����λ��1λΪ��λ��2λΪ10λ 
		
		void sub(const Bignum& a, const Bignum& b);//���� 
		
		/*
			������const���ã�
			 
			* 1.const��ֹ�������󱻸ı�
			* 2.const�ó������Դ��ݽ���(ֻ���ò�const���������) 
			* 3.����ʹ�����ã����ñ������ϵͳ�����������ڴ棬��ʡʱ��ռ�
			* 4.����ֵ������ʹ�����ã� a.�������û���ø��ƹ��캯����Ч�ʵ�
									   b.��ֹ�������캯�����ֵĴ���
			 
		*/
		/*
			��Ԫ��
				���Է���˽�б��� 
		
		*/
		friend Bignum operator + (const Bignum& a, const Bignum& b);
		friend Bignum operator - (const Bignum& a, const Bignum& b);
		friend Bignum operator * (const Bignum& a, const long long b);
		friend Bignum operator / (const Bignum& a, const long long b);
		friend bool operator < (const Bignum& a, const Bignum& b);
		friend bool operator > (const Bignum& a, const Bignum& b);
		friend bool operator == (const Bignum& a, const Bignum& b);
		friend std::ostream& operator << (std::ostream& out, const Bignum& a);
		
		//������Ҫ���ı�ģ����Բ�����const���� 
		friend std::istream& operator >> (std::istream& in, Bignum &a);
		 

		
		void string_change(const char a[]);
		void number_change(long long a);
		
		
	public:
		
		/*
			��ֵ���� �� 
			
		 	* 1.��������Ӧ�Ŀ������캯���������ʼ��ʱ���ò���
			* 2.�����ж��Ƿ����Ը�ֵ�������˷�ʱ��ռ�
			* 3.�����жϷŵ����в�����ⲿ���ܵ��� 
			* 4.�����ǳ�Ա����,��������Ԫ���� 
			
		 */
		 
		Bignum& operator = (const long long a);
		Bignum& operator = (const char a[]);

		Bignum(const char a[])
		{ 
			string_change(a);
		}
		
		Bignum(const long long a)
		{ 
			number_change(a);
		}
	
		Bignum()
		{
			symbol = '+';
			memset(num, 0, sizeof(num));
			len = 0;
		
		}

	
};


//���ڽ��ַ�����ֵ��Bignum���� 
void Bignum::string_change(const char a[])
{
	memset(num, 0, sizeof(num));
	symbol = '+';
	int alen = len = strlen(a);
	
	int i = 0; // iΪa�����ָ�� 
	
	if(a[0] == '-')
	{
		i = 1;
		symbol = '-';
		alen--;
	}
	
	//�ų��ַ���ǰ���0,���ٱ���һλ
	while(a[i] == '0' && i != alen - 1)
	{
		i++;
		len--;
	}	
	
	int j = len - 1;//jΪnum�����ָ��
	 
	//��Ҫ���Ÿ�ֵ 
	while(j >= 0)
	{
		num[j--] = a[i++] - '0';
	}
}

//���ڽ��������͸�ֵ��Bignum���� 
void Bignum::number_change(long long a)
{	
	memset(num, 0, sizeof(num));
	len = 0;
	symbol = '+';

	if(a < 0)
		symbol = '-';
	else if(a == 0)
	{
		len = 1;
		num[0] = 0;
	}
	
	/*				
		��ȡĳ��λ����:
			��ȡ��λ, a / 1 % 10;
			��ȡʮλ��a / 10 % 10��
			��ȡ��λ: a / 100 % 10; 
			 
	*/
	
	while(a > 0)
	{
		int temp = a % 10;
		a /= 10;
		
		num[len++] = temp;
	}
	
}


Bignum& Bignum::operator = (const long long a) 
{
	this->number_change(a);
	
	return *this;
}

Bignum& Bignum::operator = (const char a[]) 
{
		
	this->string_change(a);
	
	return *this;
}


Bignum operator + (const Bignum& a, const Bignum& b)
{
	Bignum c;
	int carry = 0;
	
	for(int i = 0; i < a.len || i < b.len; i++)
	{
		//��b��a�����λ����ǰ���λ����0.������ӣ�����Ӱ���� 
		int temp = a.num[i] + b.num[i] + carry;
	
		
		c.num[c.len++] = temp % 10;
		carry = temp / 10; 

	}
		
	if(carry != 0)
	{
		c.num[c.len++] = carry / 10;
	}
	
	return c;
}

//�������� 
void Bignum::sub(const Bignum& a, const Bignum& b)
{
	Bignum& c = *this;
	Bignum atemp = a;
	 
	
	for(int i = 0; i < atemp.len || i < b.len; i++)
	{
		int temp;
		if(atemp.num[i] < b.num[i])
		{
			atemp.num[i] += 10;
			atemp.num[i + 1]--; 
		}
		
		c.num[c.len++] = atemp.num[i] - b.num[i];
		
	}
	
	//���Ӹ�λ��0����������һλ�� 
	while(c.len - 1 >= 1 && c.num[c.len - 1] == 0)
	{
		c.len--;
	}
	
}

Bignum operator - (const Bignum& a, const Bignum& b)
{
	Bignum c;
	
	if(a > b)
	{
		c.sub(a, b);
	}
	else
	{
		c.sub(b, a);
		c.symbol = '-';
	}
	
	return c;
}

Bignum operator * (const Bignum& a, const long long b)
{
	Bignum c;
	int carry = 0;
	
	for(int i = 0; i < a.len; i++)
	{
		int temp = a.num[i] * b + carry;
	
		c.num[c.len++] = temp % 10;
		carry = temp / 10; 

	}
		
	while(carry != 0)
	{
		c.num[c.len++] = carry % 10;
		carry /= 10;
	}
	
	return c;
	
}

Bignum operator / (const Bignum& a, const long long b)
{
	
	Bignum c;
	int r = 0;//���� 
	//������ÿһλ���̵�ÿһλһһ��Ӧ���������� 
	c.len = a.len;
	
	for(int i = a.len - 1; i >= 0; i--)
	{
		r = r * 10 + a.num[i];
		
		//����������λΪ0 
		if(r < b)
		{
			c.num[i] = 0;
		}
		else
		{
			c.num[i] = r / b;
			r = r % b;
		}
		
	}
	
	//���Ӹ�λ��0����������һλ�� 
	while(c.len - 1 >= 1 && c.num[c.len - 1] == 0)
	{
		c.len--;
	}
	
	
	return c; 
}


std::ostream& operator << (std::ostream& out, const Bignum& a)
{
	if(a.symbol == '-')
		out << '-';

	for(int i = a.len - 1; i >= 0; i--)
	{
		char temp = a.num[i] + '0';
		out << temp;
	}
	return out;
}

std::istream& operator >> (std::istream& in, Bignum& a)
{
	char temp[MAX_LEN];
	in >> temp;
	
	a = temp;
	
	return in;
}

bool operator < (const Bignum& a, const Bignum& b)
{
	if(a.len < b.len)
		return true;
	else if(a.len > b.len)
		return false;
	else 
	{
		for(int i = a.len - 1; i >= 0; i--)
		{
			if(a.num[i] == b.num[i])		continue;
			else if(a.num[i] < b.num[i])	return true;
			else 							return false;
		}
		
	}
	
	return false;
}

bool operator > (const Bignum& a, const Bignum& b)
{
	if(a.len > b.len)
		return true;
	else if(a.len < b.len)
		return false;
	else 
	{
		for(int i = a.len - 1; i >= 0; i--)
		{
			if(a.num[i] == b.num[i])		continue;
			else if(a.num[i] > b.num[i])	return true;
			else 							return false;
		}
		
	}
	
	return false;
	
}

bool operator == (const Bignum& a, const Bignum& b)
{
	if(a.len != b.len)
		return false;
	
	for(int i = a.len - 1; i >= 0; i--)
	{
		if(a.num[i] == b.num[i])		continue;
		else 							return false;
	}
	
	return true;
}


//�����ռ�ĩβ 
}


