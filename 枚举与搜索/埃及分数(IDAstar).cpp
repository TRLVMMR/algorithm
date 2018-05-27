/*

	2/3 = 1/2 + 1/6
	����Ϊ1
	��������Խ��Խ�ã�
	�������������ͬ�����ķ�ĸԽСԽ�ã�
	������������ͬ

*/

#include<stdio.h>
#include<string.h>
#define UNI int
//#define UNI unsigned int ����������unsigned��int��ת���г��ָ������߳��������Ȼ��������������ans����v���飬���Ա���
int ans[100],v[100];//ans��ŷ�ĸ���Ž⣬v��ŷ�ĸ
int maxd;

int max(int a,int b)
{
	return a > b ? a : b;
}

//շת��������������
int mult(int x, int y)
{
	int a = x, b = y, c;

	while(b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	
	return a;
}

//����1/c <= a/b��С��c��������Ǹ�������
int get_first(int a,int b)
{
	int mul;
	
	//��������
	mul = mult(a,b);
	a = a/mul;
	b = b/mul;

	for(int i = 1; ; i++)
	{
		if((1.0 / i) <= (a * 1.0)/(b * 1.0))//�˾�Ҳ�ɷ���forѭ���ж���
			  break;
	}

	return i;
}

//�������Ž������
bool better(int d)
{
	int i;
	//���õ��Ľ�v���Ÿ�ansÿ��Ԫ�رȽϣ������ansС������ansû�и��£�����true
	for( i = d; i >= 0; i--)
	{
		if(v[i] != ans[i])
		{
			return ans[i] == -1 || v[i] < ans[i];
		}
	}
	

	return false;
}

//��ǰ���d,��ĸ����С��from,ʣ�����֮��Ϊaa/bb
bool dfs(int d, int from, UNI aa, UNI bb)//aaΪ���ӣ�bbΪ��ĸ
{
	//�ݹ�߽�
	if(d == maxd)
	{
		//�����ǰ�������������Ϊ1��
		if(bb % aa)		return false;
		 v[d] = bb/aa;
		 //���Ǹ��õĽ⣬��v��ֵ��ans
		 if(better(d))
			 memcpy(ans,v,sizeof(UNI) * (d+1));//����v��ans
		 return true;
	}

	bool ok = false;
	from = max(from,get_first(aa,bb));
	for(int i = from;  ; i++)//��������Ը��ַ�ĸ
	{
		//�����Լ�֦����֮���������Ŵ��1/i,��СΪ(max+1-d)/i,�������aa/bbС���ͼ�֦
		if(bb * (maxd + 1 - d) <= i * aa) break;

		v[d] = i;//����ûָ�ȫ�ֱ�������¼�����d�����ݺ���Ϊͬ�㣬v[d]�ᱻ����
		// aa/bb - 1/i��Ȼ��Լ��
		UNI b2 = bb * i;
		UNI a2 = aa*i -bb;
		UNI g = mult(a2,b2);
		//����ɹ�����������һ��
		if(dfs(d+1,i+1,a2/g,b2/g))
			ok = true;
	
	}

	

	return ok;
}

int main()
{
	int ok = 0;
	int a,b;

	printf("�������a����ĸb\n");
	scanf("%d %d",&a,&b);

	//����������ֱ���ҵ����ʽⷵ�أ������ǵ����ģ��ҵ�һ���Ǽ������ٵĽ�
	for(maxd = 1; ; maxd++ )
	{
		memset(ans,-1,sizeof(ans));
		if(dfs(0, get_first(a,b), a, b))
		{
			ok = 1;
			break;
		}
	}

	if(ok)
	{	
		printf("%d/%d = ",a,b);
		for(int i = 0; i < maxd; i++)
			printf("1/%d + ",ans[i]);
		printf("1/%d\n",ans[i]);
	
	}
	getchar();
	getchar();
	return 0;
}