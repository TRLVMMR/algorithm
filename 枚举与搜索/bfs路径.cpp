#include<iostream>
#include<queue>
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
	Node(int x, int y):x(x), y(y){} 
};

//�ƶ�ʱ������ı��� 
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1}; 

//bfsѰ�����·���������ڷ���-1 
int bfs(int sx, int sy)
{	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			book[i][j] = inf;
		}
	}
	book[sx][sy] = 0;
	
	queue<Node> q;
	Node temp(sx, sy);
	q.push(temp);
	while(!q.empty())
	{
		Node u = q.front();
		q.pop();
		int x = u.x;
		int y = u.y;
		//������������,���ϣ������� 
		for(int k = 0; k < 4; k++)
		{
			int next_x = x + dx[k];
			int next_y  = y + dy[k]; 
			//����Խ�磬Ҳ�������ϰ��� 
			if(next_x >= n || next_x < 0 || next_y >= m || next_y < 0 || G[next_x][next_y] == 1)
				continue;
			
			//��������ߣ����Ƿ�֮ǰ�߹�
			if(book[next_x][next_y] == inf)
			{
				//�Ӵ˵������չ 
				Node temp(next_x, next_y);
				q.push(temp);
				
				//���²���,��ʵ������Բ��ã���Ϊ��bfsԭ�����Ǵӽ���Զ���ϴ�һ���������Զ 
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
	
	cout << bfs(0, 0);
	
	
	return 0;
 } 
