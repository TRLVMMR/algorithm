#ifndef BIG_NUM
#define BIG_NUM 

#include<cstring>
#include<iostream>
#define MAX_LEN 1000

#endif


/*
	一些常见错误：
		* 1.
			[Error] 'int Bignum::len' is private
			[Error] within this context
			
		此程序出现这个错误原因： 
		 	a.没有使用友元
			b.函数定义跟实现的参数不一样
				如定义 friend Bignum operator + ( Bignum& a, const Bignum& b);
				而实现 friend Bignum operator + ( const Bignum& a, const Bignum& b);
				
		* 2.
		
			
*/


namespace bignum
{
	
//大整数类 
class Bignum
{
	private:
		int len;//字符串长度 
		char symbol;//符号位 
		char num[MAX_LEN];//存放数，0位为符号位，1位为个位，2位为10位 
		
		void sub(const Bignum& a, const Bignum& b);//减法 
		
		/*
			引用与const引用：
			 
			* 1.const防止参数对象被改变
			* 2.const让常数可以传递进来(只引用不const的情况不行) 
			* 3.参数使用引用：引用避免操作系统拷贝参数的内存，节省时间空间
			* 4.返回值尽可能使用引用： a.返回引用会调用复制构造函数，效率低
									   b.防止拷贝构造函数出现的错误
			 
		*/
		/*
			友元：
				可以访问私有变量 
		
		*/
		friend Bignum operator + (const Bignum& a, const Bignum& b);
		friend Bignum operator - (const Bignum& a, const Bignum& b);
		friend Bignum operator * (const Bignum& a, const long long b);
		friend Bignum operator / (const Bignum& a, const long long b);
		friend bool operator < (const Bignum& a, const Bignum& b);
		friend bool operator > (const Bignum& a, const Bignum& b);
		friend bool operator == (const Bignum& a, const Bignum& b);
		friend std::ostream& operator << (std::ostream& out, const Bignum& a);
		
		//输入是要啊改变的，所以不能用const引用 
		friend std::istream& operator >> (std::istream& in, Bignum &a);
		 

		
		void string_change(const char a[]);
		void number_change(long long a);
		
		
	public:
		
		/*
			赋值重载 ： 
			
		 	* 1.必须有相应的拷贝构造函数，否则初始化时调用不了
			* 2.必须判断是否是自赋值，避免浪费时间空间
			* 3.必须判断放到共有部分里，外部才能调用 
			* 4.必须是成员函数,不能是友元函数 
			
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


//用于将字符串赋值给Bignum类型 
void Bignum::string_change(const char a[])
{
	memset(num, 0, sizeof(num));
	symbol = '+';
	int alen = len = strlen(a);
	
	int i = 0; // i为a数组的指针 
	
	if(a[0] == '-')
	{
		i = 1;
		symbol = '-';
		alen--;
	}
	
	//排除字符串前面的0,至少保留一位
	while(a[i] == '0' && i != alen - 1)
	{
		i++;
		len--;
	}	
	
	int j = len - 1;//j为num数组的指针
	 
	//需要倒着赋值 
	while(j >= 0)
	{
		num[j--] = a[i++] - '0';
	}
}

//用于将整数类型赋值给Bignum类型 
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
		获取某个位的数:
			获取个位, a / 1 % 10;
			获取十位：a / 10 % 10；
			获取百位: a / 100 % 10; 
			 
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
		//当b或a到最高位后，它前面的位都是0.可以相加，不会影响结果 
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

//正数减法 
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
	
	//忽视高位的0，保留最少一位数 
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
	int r = 0;//余数 
	//被除数每一位跟商的每一位一一对应，先令长度相等 
	c.len = a.len;
	
	for(int i = a.len - 1; i >= 0; i--)
	{
		r = r * 10 + a.num[i];
		
		//不够除，该位为0 
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
	
	//忽视高位的0，保留最少一位数 
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


//命名空间末尾 
}


