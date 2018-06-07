#ifndef MY_H
#define MY_H 0
#include<queue>
#include<windows.h>
#include<time.h>
#include<vector>
#include<string.h>

//�ߵ�״̬��U�ϣ�D��
#define U 1
#define D 2
#define L 3
#define R 4			
//��ά������ֵ�ı�ʾ
#define EMPTY 0
#define BODY 1
#define WALL 2
#define FOOD 3
#define HEAD 4
#define TAIL 5

#define EDGE 12//�߳�,�������м�������
#define LEN 56 //ÿ�����ӵ����س���
#define ID__BUTTON1 10001

//���������ĸ����������
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

//����ʹ�����ȶ��еĽṹ
struct cmp
{
	bool operator () (Note *a, Note *b)
	{
		return this->pri_queue(a, b);
		
	}

	//���ڹ�����С��,false���һ�����ȣ�true��ڶ�������
	bool pri_queue(Note *a, Note *b)
	{
		//a�����ȼ�����b,������
		if (a->f == b->f)
		{
			if (a->father != NULL && b->father != NULL)
			{
				if (a->father == b->father)
				{
					//���b�ĸ����׵ķ���һ��

					//���b�ķ�������׷���һ��
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



//��������
struct Bcmp: cmp
{
	bool operator() (Note *a, Note *b)
	{
		//Ψһ��������ǣ������߸�����ͬ���·,ֻ�Ƿ���������
		return !(this->pri_queue(a, b));
	}
	
};


//���ȶ����ࣨ������find������
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
	
	
	HBRUSH hBrush1 = CreateSolidBrush(RGB(0, 130, 30));//������ˢ
	HBRUSH hBrush2 = CreateSolidBrush(RGB(0, 160, 200));//��ͷ
	HBRUSH hBrush3 = CreateSolidBrush(RGB(0, 130, 30));//��β
	HBRUSH hBrush4 = (HBRUSH)GetStockObject(WHITE_BRUSH);

	
	HDC hdc;
	bool opposite();
	Note SnakeCur(Note q, int s);
	void SnakePrint(int _x, int _y, int color);
	//void EndGame(int flag, HWND hwnd, HDC hdc);
	

public:	
	pqueue open;//A*���ã���С��
	pqueue close;//A*���У���С��
	qqueue op;//A*���ã�����
	qqueue cl;//A*���ã�����
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
	int nextstatus;//��ʱ���
	int oldstatus;
	std::queue<Note>body;//�ߵĶ��У�ÿ���ڵ��Ÿ��ߵķ���
//	std::queue<int>status;//�ߵĶ��У�ÿ���ڵ��Ÿ��ߵķ���
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
	HBRUSH hBrush3 = CreateSolidBrush(RGB(255, 130, 30));//ʳ����ˢ
	HPEN Pen = CreatePen(PS_SOLID,//ʵ�߻��ʣ�Ҫ�ջ��ʸĳ�PS_NULL
		1, RGB(255, 107, 5));//ʳ���û���

public:	
	int x;
	int y;
	void CreatFood(HWND hwnd, HDC hdc, Snake& snake);


};

class Game
{
private:
	HBRUSH hBrush2 = CreateSolidBrush(RGB(100, 100, 100));//ǽ��ˢ
	HWND hwnd;
	int score;
	int add;//ÿ�μӷ�

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


