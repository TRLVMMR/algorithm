#include<stdio.h>

int max(int x, int y)
{
	return x > y ? x : y;
}

struct Note
{
	int son;
	int dp;
	int color;
	Note(int x=0, int y=0,int z=0):son(x), dp(y), color(z){};
};

Note a[10000];

void create_tree(int p, int flag)
{
	int s;
	char ch;
	if(scanf("%c", &ch) && ch == '\n')
		return;
		
	a[p].son = (int)ch - (int)'0';
	 
	
	if(a[p].son == 0 && flag == 1)
	{ 
		//���������ȣ�������Ϊ������������˭�䶼һ�� 
		a[p].dp = 1;
	}
	else if(a[p].son == 1)
	{
		create_tree( p * 2, 1 );
	}
	else
	{
		create_tree( p * 2, 1 );
		create_tree( p * 2 + 1, 0);
	}
	
	//״̬ת�Ʒ��̣�dpүү = max(���ж���+1�����и���)
	a[p].dp = max(a[p*4].dp + a[p*4 + 1].dp + a[(p*2+1) * 2].dp + a[(p*2+1) * 2 + 1].dp + 1, a[p*2].dp + a[p*2+1].dp);
	
	 return;
}

int main()
{
	create_tree(1,1);
	
	printf("%d\n", a[1].dp);
	
	return 0;
}
