/*
	����: ��AΪ��׼�㣬����ǵ����ұ���˳��
		��������ĸ���˳�������� 
		��xΪ˳����-x����Ϊ���� 
	  
	ѭ������ΪA��λ�� 
*/
#include<iostream>

using namespace std;

int main()
{
	int n, m;
	
	cin >> n >> m;	
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			//λ��iΪ��׼�㣬�ұ߽���˳����߽��е��� 
			if(j >= i)
				cout << char(j - i + 'A'); 
			else
				cout << char(i - j + 'A');
		}
		
		cout << endl;
	}
	
	return 0;
} 
