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


//把cur上下左右4个点加入open表 
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
		//把open表里取出进行操作，操作后放到给close表 
		cur = open.top(); 	
		h_get(*cur);
		open.pop();
		close.push(cur);
		
		//对当前格相邻的4格中的每一个 
		for(int i = 0; i < 4; i++)
		{
			pPoint _try = new Point(cur->x + xdir[i], cur->y + ydir[i]);
			h_get(*_try);
			
			//它不可通过 || 已经在 "关闭列表" 中
			if(map[_try->x][_try->y] == 1 || close.find(*_try))
			{
				continue;
			}
			
			//如果不在open表中
			if(!open.find(*_try))
			{ 
				_try->father = cur;
				_try->g = _try->father->g + 1;
				_try->f = _try->g + _try->h;
				open.push(_try);
				
			}
			//如果已经在open表中 
			else
			{
				//如果有更好,更新g值 
				if(cur->g + 1 < _try->g)
				{
					_try->g = cur->g + 1;
					_try->father = cur;
					_try->f = _try->g + _try->h;
				} 
				
			}
			
			//如果open表中出现goal，则证明已找到 
			if(open.find(goal))
			{
				return _try;
			}
			
		}
	
	}
	
	//如果open表为空，则不存在目标路径 
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
