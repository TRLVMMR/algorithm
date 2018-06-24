/* 
	���ƹ�ʽ�� F(n) = (F(n-1) + m) % n 
	n�Ǵ�ʱ������������ m�ǽе��ڼ���������F(n)��ָn���˵Ļ���ʣ�µ��˵ĺ��� 
	
	�˹�ʽ����ÿȥ��һ���˺� ��һ����һ�ţ���ÿ��ǰ��m��λ��Ȼ��ȡ��n�ú���������[1, n]�ķ�Χ�� 

*/
#include<iostream>

using namespace std;

int joseph(int n, int m)
{
	return n == 1 ? 0 : (joseph(n-1, m) + m) % n;
}


int main()
{
	int n, m;
	
	cin >> n >> m;
	
	cout << joseph(n, m) << endl;
	
	return  0;
} 
