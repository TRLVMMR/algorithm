#include<iostream>
#include<stack> 
using namespace std;

const int maxn = 100;
const int inf = 0x3fffffff;
//1����ǽ��0����յأ�2�����յ� 
int G[maxn][maxn];
//�������¼���˽ڵ����С����������dp��ͬʱ�������� 
int book[maxn][maxn];
int n, m;

struct Node
{
	int x;
	int y;
	int k;//���Ʒ��� 
	Node(int x, int y, int k):x(x), y(y), k(k){};
};

//�ƶ�ʱ������ı��� 
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1}; 

//dfsջʵ�֣��ǵݹ� 
int dfs(int sx, int sy)
{	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			book[i][j] = inf;
		}
	}
	book[sx][sy] = 0;
	
	stack<Node> s;
	Node temp(sx, sy, 0);
	s.push(temp);
	while(!s.empty())
	{
		Node u = s.top();
		s.pop();
		int x = u.x;
		int y = u.y;
		//������������,���ϣ������� 
		if(u.k < 4)
		{
			int next_x = x + dx[u.k];
			int next_y  = y + dy[u.k]; 
			//��ԭջ֡k+1������ջ����ΪC++��ջ��Ԫ��ò���ǲ��ɱ����ݽṹ����ı�top��kֵ���´�topʱ����ԭ����kֵ�� 
			Node tmp(x, y, u.k + 1);
			s.push(tmp);
			//����Խ�磬Ҳ�������ϰ��� 
			u.k = u.k + 1;
			if(next_x >= n || next_x < 0 || next_y >= m || next_y < 0 || G[next_x][next_y] == 1)
				continue;
			
			//��������ߣ����Ƿ�֮ǰ�߹�
			if(book[next_x][next_y] == inf)
			{
				//�Ӵ˵������չ 
				Node temp(next_x, next_y, 0);
				s.push(temp);
				
				//���²���
				book[next_x][next_y] = book[x][y] + 1; 
			}
			else
			{
				//���²���
				book[next_x][next_y] = min(book[next_x][next_y], book[x][y] + 1);
			} 
			
			if(G[next_x][next_y] == 2)
			{
				return book[next_x][next_y];
			} 
		}
	} 
	
	return -1; 
} 


int main()
{
	cin >> n >> m;
	cout << "������һ��" << n << "*" << m << "�ĵ�ͼ" << endl; 
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> G[i][j];
		}
		
	}
	
	cout << dfs(0, 0) << endl;
	

	return 0;
 } 
