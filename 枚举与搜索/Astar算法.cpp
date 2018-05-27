#include<cstdio>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int xdir[4] = {-1, 1, 0, 0};
int ydir[4] = {0, 0, -1, 1};

int map[6][6] = 
{
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0},
	{0, 0, 0, 1, 0, 0},
	{0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0}
};

typedef class Point
{
private:
	

	
public:
	int x, y;
	double f, g, h;
	Point *father;
	
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
		f = g = h = 0;
		father = NULL;
	}	
	Point(){}
	
	friend bool operator < (Point a, Point b)
	{
		return a.f > b.f; 
	} 
	friend bool operator == (Point a, Point b)
	{
		if(a.x == b.x && a.y == b.y)
			return true;
		else
			return false;
	} 
	void point_select(); 
	
}*pPoint;


struct cmp
{
	bool operator () (Point *a,  Point *b)
	{
		return a->f > b->f;
	}
};


class pqueue : public priority_queue< pPoint, vector<pPoint> ,cmp>
{
public:
	int x;
	
	bool find(Point num)
	{
		vector<pPoint>::iterator it = c.begin();
		while(it != c.end())
		{
			if((*(*it)) == num)
				return true;
			it++;
		}
		return false;
	}	
	
};

pqueue open;
pqueue close;

class Astar
{

public:

	pPoint cur;
	Point goal;
	Astar(pPoint _cur, Point _goal)
	{
		cur = _cur;
		goal = _goal; 
		
	}
	void h_get(Point& a);
	Point* A_main();
	void cur_select();
	void path_print();
};
 


void Astar::h_get(Point& a)
{
	//a.h = abs(a.x - goal.x) + abs(a.y - goal.y);
	a.h = sqrt( (a.x - goal.x) * (a.x - goal.x) + (a.y - goal.y) * (a.y - goal.y) );
}


//��cur��������4�������open�� 
void Point::point_select()
{
	for(int i = 0; i < 4; i++)
	{
		Point temp(x, y);
		temp.x += xdir[i];
		temp.y += ydir[i];
	}
}


Point* Astar::A_main()
{
	while(!open.empty())
	{
		//��open����ȡ�����в�����������ŵ���close�� 
		cur = open.top(); 	
		h_get(*cur);
		open.pop();
		close.push(cur);
		
		//�Ե�ǰ�����ڵ�4���е�ÿһ�� 
		for(int i = 0; i < 4; i++)
		{
			pPoint _try = new Point(cur->x + xdir[i], cur->y + ydir[i]);
			h_get(*_try);
			
			//������ͨ�� || �Ѿ��� "�ر��б�" ��
			if(map[_try->x][_try->y] == 1 || close.find(*_try))
			{
				continue;
			}
			
			//�������open����
			if(!open.find(*_try))
			{ 
				_try->father = cur;
				_try->g = _try->father->g + 1;
				_try->f = _try->g + _try->h;
				open.push(_try);
				
			}
			//����Ѿ���open���� 
			else
			{
				//����и���,����gֵ 
				if(cur->g + 1 < _try->g)
				{
					_try->g = cur->g + 1;
					_try->father = cur;
					_try->f = _try->g + _try->h;
				} 
				
			}
			
			//���open���г���goal����֤�����ҵ� 
			if(open.find(goal))
			{
				return _try;
			}
			
		}
	
	}
	
	//���open��Ϊ�գ��򲻴���Ŀ��·�� 
	return NULL;
}

void Astar::path_print()
{
	pPoint p = A_main();
	while(p != NULL)
	{
		printf("%d %d\n", p->x, p->y);
		p = p->father;	
	}
	
}

int main()
{
	
	pPoint start = new Point(3, 1);
	pPoint end = new Point(3, 4);
	
	Astar a(start, *end);
	a.h_get(*start);
	start->f = start->g + start->h;
	
	open.push(start);
	a.path_print();
	
	return 0;
} 
