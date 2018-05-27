/*
	优先队列里，比较类返回false，则第一个优先（放顶上），返回true，则第二个优先 


*/
#include<queue>
#include<cstdio>
#include<vector>

using namespace std;



class Point
{
private:
	
	int xdir[4] = {-1, 1, 0, 0};
	int ydir[4] = {0, 0, -1, 1};
	
public:
	int x, y;
	int f, g, h;
	Point *father;
	int status;
	
	Point(int _x, int _y, int _status)
	{
		x = _x;
		y = _y;
		f = g = h = _x;
		status = _status;
		father = NULL;
	}	
	Point(){}
	
	//重载小于号却用大于号，是为用优先队列
	/*friend bool operator < (Point a, Point b)
	{
		return a.f > b.f; 
	} */
	friend bool operator == (Point a, Point b)
	{
		if(a.x == b.x && a.y == b.y)
			return true;
		else
			return false;
	} 
	
};
struct cmp
{
	//用于构造最小堆,false则第一个优先，true则第二个优先
	bool operator () (Point a, Point b)
	{
		//a的优先级大于b,放上面
		if (a.f == b.f)
		{
			if (a.father != NULL && b.father != NULL)
			{
				if (a.father == b.father)
				{
					//如果b的跟父亲的方向一样

					//如果b的方向跟父亲方向一样
					if (b.status == b.father->status)
						return true;
					else if (a.status == a.father->status)
						return false;

				}
			}
			return a.f > b.f;
		}
		else
			return a.f > b.f;
	}
};

class pqueue : public priority_queue<Point, vector<Point>, cmp >
{
public:
	int x;
	
	bool find(Point num)
	{
		std::vector<Point, std::allocator<Point> >::iterator it = c.begin();
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
	
	Point *fa;
	fa = new Point(0, 0, 3);
	for(int i = 0; i < 5; i++)
	{ 
		Point temp(1, 1, i);
		temp.father = fa;
		p.push(temp);
	
	} 
	for(int i = 0; i < 5; i++)
	{ 
		Point temp(2, 2, i);
		temp.father = fa;
		p.push(temp);
	
	} 

//	Point a(5, 5);
	
/*	if(p.find(a))
	{
		printf("有\n");
	}
	else
	{
		printf("没有\n");
	}
	*/
	while( !p.empty() )
	{
		Point temp = p.top();
		printf("%d %d %d\n", temp.x, temp.y, temp.status);
		p.pop();
	}
	
	return 0;
}
