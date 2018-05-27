#include<queue>
#include<cstdio>
#include<vector>
#include<algorithm> 

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


class pqueue : public priority_queue<typename _Tp, typename _Sequence = vector<_Tp>,
	   typename _Compare  = less<typename _Sequence::value_type> >
{
public:
	int x;
	

	bool find(_Tp num)
	{
		_Sequence::iterator it = c.begin();
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
	pqueue p<int>;
	
	for(int i = 0; i < 5; i++)
	{ 	
		p.push(i);	
	} 
	
	if(p.find(3))
	{
		printf("сп\n");
	}
	else
	{
		printf("ц╩сп\n");
	}


	
	while( !p.empty() )
	{
		int temp = p.top();
		printf("%d\n", temp);
		p.pop();
	}
	

	return 0;
} 
