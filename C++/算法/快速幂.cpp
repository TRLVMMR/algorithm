/*
	����a^b % m��ֵ:
	 
	*1.һ������ȡ��
	 
		a^b % m��ֵ���� (a^n % m * a^(b-n)) % m 	(n < b)��ֵ
		 
	*2.�����ݣ�
	
		@������aΪ����ʱ���ۼ� 
				 	
			ԭ��
			*	  bΪ������a^b = a^(b-1) * a
			*	  bΪż��: a^b = a^(b/2) * a^(b/2)
			*	����һ�����Ϳ��Բ��ϲ�ֵ���Ϊ0Ϊֹ
				 
			*	һ����Ҳ�����ö����Ʊ�ʾ��Ȼ���� 
			*	b���ϱ�С������ʹbҲ�г�Ϊ������ʱ�򣬼�2^0 = 1	  
			*	ʵ���ǲ��Ϸ���,���������ǰ�ÿ����Ҫ��ֵһ��������� 
			 
	 
*/
#include<cstdio>
#define LL long long 

/* 
	������ԭ�����Ϸ��Σ� 
*/
int quick_pow(LL base, LL pow, const int m)
{
	
	int ans = 1;
	
	while(pow > 0)
	{
		//���pow������ 
		if(pow & 1)
		{
			ans = ans * base % m; 
			
		}
		base = base * base % m;
		
		pow >>= 1; // b����һλ 
		
	}
	
}


int main()
{
	
	
	return 0;
}
