#ifndef MY_H
#define MY_H 0
#include<queue>
#include<windows.h>
#include<time.h>
#include<vector>
#include<string.h>

//蛇的状态，U上，D下
#define U 1
#define D 2
#define L 3
#define R 4			
//二维数组中值的表示
#define EMPTY 0
#define BODY 1
#define WALL 2
#define FOOD 3
#define HEAD 4
#define TAIL 5

#define EDGE 12//边长,即长宽有几个格子
#define LEN 56 //每个格子的像素长度
#define ID__BUTTON1 10001

//上下左右四个方向的数组
const int xdir[5] = {0, -1, 1, 0, 0 };
const int ydir[5] = {0, 0, 0, -1, 1 };

class Note
{
public:
	int x;
	int y;
	double f, g, h;
	Note *father;
	int status;

	Note(int _x, int _y)
	{
		x = _x;
		y = _y;
		f = g = h = 0;
		father = NULL;
	}
	Note()
	{
		f = g = h = 0;
	}

	friend bool operator == (Note a, Note b)
	{
		if (a.x == b.x && a.y == b.y)
			return true;
		else
			return false;
	}
	void Note::h_get(Note& goal);
};

//用来使用优先队列的结构
struct cmp
{
	bool operator () (Note *a, Note *b)
	{
		return this->pri_queue(a, b);
		
	}

	//用于构造最小堆,false则第一个优先，true则第二个优先
	bool pri_queue(Note *a, Note *b)
	{
		//a的优先级大于b,放上面
		if (a->f == b->f)
		{
			if (a->father != NULL && b->father != NULL)
			{
				if (a->father == b->father)
				{
					//如果b的跟父亲的方向一样

					//如果b的方向跟父亲方向一样
					if (b->status == b->father->status)
						return true;
					else if (a->status == a->father->status)
						return false;
				}
			}
			return a->f > b->f;
		}
		else
			return a->f > b->f;
	}
};



//构造最大堆
struct Bcmp: cmp
{
	bool operator() (Note *a, Note *b)
	{
		//唯一的问题就是，不能走跟父亲同向的路,只是方案变差而已
		return !(this->pri_queue(a, b));
	}
	
};


//优先队列类（加入了find函数）
class pqueue : public std::priority_queue<Note *, std::vector<Note *>, cmp>
{
public:
	int x;

	Note* find(Note num)
	{
		std::vector<Note* >::iterator it = c.begin();
		while (it != c.end())
		{
			if ((*(*it)) == num)
				return (*it);
			it++;
		}
		return NULL;
	}
};

class qqueue : public std::priority_queue<Note *, std::vector<Note *>,Bcmp>
{
public:
	int x;

	Note* find(Note num)
	{
		std::vector<Note* >::iterator it = c.begin();
		while (it != c.end())
		{
			if ((*(*it)) == num)
				return (*it);
			it++;
		}
		return NULL;
	}
};


class Snake
{
private:
//	enum xDir{ 0, -1, 1, 0, 0 } xd;
//	enum yDir{ 0, 0, 0, -1, 1 } yd;
	
	
	HBRUSH hBrush1 = CreateSolidBrush(RGB(0, 130, 30));//蛇身用刷
	HBRUSH hBrush2 = CreateSolidBrush(RGB(0, 160, 200));//蛇头
	HBRUSH hBrush3 = CreateSolidBrush(RGB(0, 130, 30));//蛇尾
	HBRUSH hBrush4 = (HBRUSH)GetStockObject(WHITE_BRUSH);

	
	HDC hdc;
	bool opposite();
	Note SnakeCur(Note q, int s);
	void SnakePrint(int _x, int _y, int color);
	//void EndGame(int flag, HWND hwnd, HDC hdc);
	

public:	
	pqueue open;//A*所用，最小堆
	pqueue close;//A*所有，最小堆
	qqueue op;//A*所用，最大堆
	qqueue cl;//A*所用，最大堆
	int map[EDGE][EDGE];
	HWND hwnd;

	Note head, tail;
	//Note goal;
	Snake()
	{
		memset(map, 0, sizeof(map) );
		nextstatus = U;
		oldstatus = R;
	}
	int nextstatus;//临时存放
	int oldstatus;
	std::queue<Note>body;//蛇的队列，每个节点存放刚走的方向
//	std::queue<int>status;//蛇的队列，每个节点存放刚走的方向
	int SnakeMove(HDC _hdc);
	void InitSnake(HWND _hwnd, HDC _hdc);
	int Astar(Note goal);
	void MovePath(Note *p);
	bool TAstar();
	int isp(Note goal, bool mShort = true);
	bool LenAstar(Note goal);
	void Clean();
	//int FvirAstar(Note goal);
	//bool fAstar(Note goal);
};

class Food
{
private:
	HWND hwnd;
	HDC hdc;
	HBRUSH hBrush3 = CreateSolidBrush(RGB(255, 130, 30));//食物用刷
	HPEN Pen = CreatePen(PS_SOLID,//实线画笔，要空画笔改成PS_NULL
		1, RGB(255, 107, 5));//食物用画笔

public:	
	int x;
	int y;
	void CreatFood(HWND hwnd, HDC hdc, Snake& snake);


};

class Game
{
private:
	HBRUSH hBrush2 = CreateSolidBrush(RGB(100, 100, 100));//墙用刷
	HWND hwnd;
	int score;
	int add;//每次加分

	void InitMap(HDC hdc, Snake& snake);
	void MapPrint(int x, int y, HDC hdc, Snake& snake);
	void EndGame(int flag,  HDC hdc);
	void ScoreAdd(HDC hdc);

public:
	Game()
	{
		score = 0;
		add = 1;
		sleeptime = 300;
	}
	int sleeptime;

	void Difficulty(int flag);
	void pause();
	void GameStart(Snake& snake, Food& food, HWND _hwnd, HDC hdc);
	void Handle(Food& food, Snake& snake, int flag, HDC hdc);

};


#endif


