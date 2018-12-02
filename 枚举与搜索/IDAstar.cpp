#include<iostream>
#include<cmath>
using namespace std;

const int maxn = 100;
const int inf = 0x3fffffff;
//1����ǽ��0����յأ�2�����յ� 
int G[maxn][maxn];
int n, m;

//�ƶ�ʱ������ı��� 
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1}; 

int endx, endy;
int maxd;
//���˸�d��¼��� 
bool dfs(int x, int y, int d)
{
	//�����������򷵻� 
	if(d == maxd)
	{
		//�ҵ��յ㷵��true������false 
		if(G[x][y] == 2)
			return true;
		return false;
	}
		
	//Ԥ��֦������ɲ���������̾��룬 ֱ�ӷ��� 
	if(abs(x - endx) + abs(y - endy) > maxd - d)
		return false; 
		
	//������������,���ϣ�������
	for(int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		//����Խ�磬Ҳ�������ϰ��� 
		if(next_x >= n || next_x < 0 || next_y >= m || next_y < 0 || G[next_x][next_y] == 1)
			continue;
		
		//ֻҪ��һ������true 
		if(dfs(next_x, next_y, d+1))
		{
			return true;
		}
	} 
	return false;
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
			//�����յ� 
			if(G[i][j] == 2)
			{
				endx = i;
				endy = j;
			}
		}
		
	}

	//ö�ٲ��������ٶ��ٲ��ܵ���Ŀ�� 
	for(maxd = 1; ;maxd++)
	{
		if(dfs(0, 0, 0))
		{
			cout << maxd << endl; 
			break;
		}
	}
	
	return 0;
 } 
