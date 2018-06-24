/* 
	递推公式： F(n) = (F(n-1) + m) % n 
	n是此时环的总人数， m是叫到第几个结束，F(n)是指n个人的环中剩下的人的号数 
	
	此公式即，每去除一个人后， 下一个是一号，即每人前移m个位。然后取余n让号数限制在[1, n]的范围里 

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
