/*	
	�������ڵ������ַ���ʹ����ɻ��Ĵ���������ٽ����Ĵ���
	
	˼·��
		���ҵ��⼸���ַ�������ɵĻ��Ĵ� 
	
	
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;


//������ţ��ַ�����λ�ø����� 
int letter[26];
char a[10000];

int main()
{
	int n;
	
//	freopen("input8.txt", "r", stdin);
	
	cin >> n;
	
	
	//int len = a.size();
	
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		int pos = a[i] - 'a';
		letter[pos]++;
	}
	
	bool flag = false; 
	 
	//�ж��Ƿ��ǻ��Ĵ������Ĵ�ֻ�ܴ���һ���ַ����ִ����ǵ��� 
	for(int i = 0; i < 26; i++)
	{
		if(letter[i] & 1)
		{
			if(flag)
			{
				cout << "Impossible" << endl;
				return 0;
			}
			flag = true;
		}
	}
	
	int sum = 0;//���� 
	int end = n - 1;//���һ��Ԫ�� 
	int alone = -1;//��¼�����Ǹ������� 

	//ѭ��һ�߾���,�ұ߷����������
	//ÿ�ε�����һ����Χ���������߿��� 
	for(int i = 0; i < n / 2; i++ )
	{		
		bool phave = false;//�Ƿ���ͬ�� 
		for(int j = end; j > i; j--)
		{
			if(a[j] == a[i])
			{
				while(j != end)
				{
					swap(a[j],a[j+1]);
					j++;
					sum++;
				}
				//���ǵ����ַ���������ٵ��������ұ��ַ�Ҫ�ȷź� 
				end--;
				phave = true; 
				break;
			}
	
		}
		
		//���û�ҵ���ͬ�� �������Ǹ����� 
		if(!phave)
		{
			alone = i;
		}
	
	} 
	
	//�����ڵ���,�������м� 
	if(alone != -1)
	{
		while(alone != n / 2)
		{
			swap(a[alone],a[alone+1]);
			alone++;
			sum++;
		}
	}
	
/*	bool fl = true;
	for(int i = 0; i < n; i++)
	{
		int j = n - 1 - i;
		if(a[i] != a[j])
		{
			cout << "false" << endl;;
			fl = false;
			break;
		}
		
	}
	if(fl)
	cout << "true" << endl;*/
	
	cout << sum << endl;
	
	return 0;
}
