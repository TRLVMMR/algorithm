#include<queue>
#include<cstdio>
#include<vector>

using namespace std;

class Point
{
private:
	
//	int xdir[4] = {-1, 1, 0, 0};
//	int ydir[4] = {0, 0, -1, 1};
	
public:
	int x, y;
	int f, g, h;
	Point *father;
	
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
		f = g = h = 0;
	}	
	Point(){}
	
	friend bool operator < (Point a, Point b)
	{
		return a.f < b.f; 
	} 
	friend bool operator == (Point a, Point b)
	{
		if(a.x == b.x && a.y == b.y)
			return true;
		else
			return false;
	} 
	
};


class pqueue : public priority_queue<int>
{
public:
	int x;
	

	bool find(int num)
	{
		vector<int>::iterator it = c.begin();
		while(it != c.end())
		{
			if((*it) == num)
				return true;
			it++;
		}
		return false;
	}	
	
};

int main()
{
	pqueue p;
	for(int i = 0; i < 5; i++)
	{ 	
		p.push(i);	
	} 
	
	
	if(p.find(3))
	{
		printf("��\n");
	}
	else
	{
		printf("û��\n");
	}


	
	while( !p.empty() )
	{
		int temp = p.top();
		printf("%d\n", temp);
		p.pop();
	}
	

	return 0;
} 
