#include"myfile.h"
#include<strsafe.h>
#include<iostream>
#include<string.h>

using namespace std;

//int map[20][20];//二维数组地图，自动初始化为0,0代表路，1代表蛇，2代表墙，3代表食物

//初始化蛇身
void Snake::InitSnake(HWND _hwnd, HDC _hdc)
{
	int i;

	hwnd = _hwnd;
	hdc = _hdc;


	//在y轴13的地方初始化4节蛇身
	for (i = 0; i < 4; i++)
	{
		Note temp;
		temp.x = 4 + i;
		temp.y = EDGE / 2;

		map[temp.x][temp.y] = BODY;
		SnakePrint(temp.x, temp.y, BODY);
		body.push(temp);

	}

	//初始化头结点的坐标
	head = body.back();
	tail = body.front();
	
	SnakePrint(head.x, head.y, HEAD);
	SnakePrint(tail.x, tail.y, TAIL);
}

//根据color打印蛇的不同部分
void Snake::SnakePrint(int _x, int _y, int color)
{
	RECT rect;	
	int a = _x * LEN;
	int b = _y * LEN;
	

	HBRUSH hBrush = hBrush1;
	if (this->hwnd != NULL)
	{
		switch (color)
		{
		case BODY:
			hBrush = hBrush1;
			break;
		case HEAD:
			hBrush = hBrush2;
			break;
		case TAIL:
			hBrush = hBrush1;
			break;
		case EMPTY:
			hBrush = hBrush4;
			break;
		}
		//	if(map[_x][_y] == BODY)
		//{
		rect.left = a;
		rect.top = b;
		rect.right = a + LEN - 1;//减1是为了能看到一格一格的效果
		rect.bottom = b + LEN - 1;
		FillRect(hdc, &rect, hBrush);
		//	}

		/*else if (map[_x][_y] == EMPTY)
		{
		rect.left = a;
		rect.top = b;
		rect.right = a + LEN-1;
		rect.bottom = b + LEN-1;
		FillRect(hdc, &rect, hBrush4);

		}*/
	}
}



//节点p的坐标加上s的方向
Note Snake::SnakeCur(Note q, int s)
{
	Note p = q;

	if(s == U)
	{
		p.y--;
	}
	else if(s == D)
	{
		p.y++;
	}
	else if(s == L)
	{
		p.x--;
	}
	else if(s == R)
	{
		p.x++;
	}
	
	return p;
}

//修复回头bug
//如果头结点回头，返回true，否则返回false
bool Snake::opposite()
{
	if(nextstatus == U && oldstatus == D)
		return true;
	else if(nextstatus == D && oldstatus == U)
		return true;
	else if(nextstatus == L && oldstatus == R)
		return true;
	else if(nextstatus == R && oldstatus == L)
		return true;
	else
		return false;
}


//蛇移动，并返回下一个节点的类型值
int Snake::SnakeMove(HDC _hdc)
{	
	hdc = _hdc;
	Note next = SnakeCur(head, nextstatus);

	map[tail.x][tail.y] = EMPTY;//先把尾巴变为空地，消除bug（正好咬到尾巴）
	//如果是空地，则向前走
	if(map[next.x][next.y] == EMPTY)
	{
		/*if( opposite() )
		{
			nextstatus = oldstatus;
			return SnakeMove(hdc);
		}*/
		
		//把最后一个点的坐标抹消
		map[tail.x][tail.y] = EMPTY;
		SnakePrint(tail.x, tail.y, EMPTY);
		//尾结点坐标改变
	//	tail = SnakeCur(tail, status.front());
		//status.pop();
		body.pop();
		tail = body.front();

		SnakePrint(head.x, head.y, BODY);
		//next点的坐标给头结点，
		map[next.x][next.y] = BODY;
		head = SnakeCur(head, nextstatus);
		//status.push(nextstatus);
		body.push(head);

		SnakePrint(head.x, head.y, HEAD);
		SnakePrint(tail.x, tail.y, TAIL);
		oldstatus = nextstatus;
		return EMPTY;
	}

	//如果是食物，把此点变蛇身，蛇长+1
	else if (map[next.x][next.y] == FOOD)
	{
		SnakePrint(head.x, head.y, BODY);
		map[next.x][next.y] = BODY;
		map[tail.x][tail.y] = BODY;
		head = SnakeCur(head, nextstatus);
		//status.push(nextstatus);
		body.push(head);
		SnakePrint(head.x, head.y, HEAD);
		//	game.ScoreAdd();
	//	food.CreatFood(hwnd, hdc);

		return FOOD;
	}
	//如果下一个节点是2，撞到墙
	else if (map[next.x][next.y] == WALL)
		return WALL;
	//EndGame(2, hwnd,hdc);

	//如果下一个节点是1,咬到自己(如果正好是尾巴不知道算不算bug)
	else
		return BODY;
	//	EndGame(1, hwnd,hdc);
}




void Food::CreatFood(HWND _hwnd, HDC _hdc, Snake& snake)
{
	hwnd = _hwnd;
	hdc = _hdc;
	
	int _x, _y;
	srand((unsigned)time(NULL));
	while (1)
	{
		_x = (rand() % 10 + 1);//第0跟第19是墙
		_y = (rand() % 10 + 1);

		if (snake.map[_x][_y] == EMPTY)//如果是空地,就改成食物
		{
			snake.map[_x][_y] = FOOD;
			x = _x;
			y = _y;
			SelectObject(hdc, hBrush3);
			SelectObject(hdc, Pen);
			Ellipse(hdc, x*LEN, y*LEN, x*LEN + LEN - 1, y*LEN + LEN - 1);
			return;
		}

	}
	//运气差的话容易栈溢出
	//else
		//CreatFood(hwnd,hdc);
	
}


void Game::GameStart(Snake& snake, Food& food, HWND _hwnd, HDC hdc)
{
	hwnd = _hwnd;
	InitMap(hdc, snake);
	snake.InitSnake(hwnd, hdc);
	food.CreatFood(hwnd, hdc, snake);
}

void Game::MapPrint(int x, int y, HDC hdc, Snake& snake)
{
	RECT rect;
	int a, b;
	a = x * LEN;
	b = y * LEN;
			
	if(snake.map[x][y] == WALL)
	{
		rect.left = a;
		rect.top = b;
		rect.right = a + LEN-1;
		rect.bottom = b + LEN-1;
		FillRect(hdc, &rect, hBrush2);
	}
}

//暂停函数
void Game::pause()
{


}

//初始化地图(先画墙)
void Game::InitMap(HDC hdc, Snake& snake)
{
	int i;
	for( i = 0; i < 12; i++ )
	{
		snake.map[i][0] = WALL;
		snake.map[i][11] = WALL;
		snake.map[0][i] = WALL;
		snake.map[11][i] = WALL;

		MapPrint(i, 0, hdc, snake);
		MapPrint(i, 11, hdc, snake);
		MapPrint(0, i, hdc, snake);
		MapPrint(11, i, hdc, snake);

	}

}

//结束游戏的操作
void Game::EndGame(int flag, HDC hdc)
{
	static bool boot = true;//记录现在是否是游戏状态

	if(boot == true)
	{
		boot = false;//设置为关机状态

		if (flag == BODY)
			MessageBox(hwnd, TEXT("对不起您咬到自己了，游戏结束"), TEXT("结束游戏"), MB_OK);

		else if (flag == WALL)
			MessageBox(hwnd, TEXT("对不起您撞墙了，游戏结束"), TEXT("结束游戏"), MB_OK);
		
		
		TCHAR subuff[256];
			StringCchPrintf(subuff, sizeof(subuff), TEXT("您的游戏得分为：%d分"), score);
			if (IDOK == MessageBox(hwnd, subuff, TEXT("得分情况"), MB_OK));
			SendMessage(hwnd, WM_DESTROY, 0, 0);
	}
	
}

void Game::ScoreAdd(HDC hdc)
{
	score += add;
	TCHAR subuff[256];
	memset(subuff, 0, sizeof(subuff));
	StringCchPrintf(subuff, sizeof(subuff), TEXT("score %d "), score);
	TextOut(hdc, 5 * LEN, 0 * LEN, subuff, 8);
}
//游戏处理，根据flag的值进行不同处理
void Game::Handle(Food& food, Snake& snake, int flag, HDC hdc)
{
	//找机会优化成枚举
	switch (flag)
	{
	case EMPTY:

		break;
	case BODY:
		EndGame(BODY, hdc);
		break;
	case WALL:
		EndGame(WALL, hdc);
		break;
	case FOOD:
		food.CreatFood(hwnd, hdc, snake);
		ScoreAdd(hdc);
		break;

	}

}

//调节游戏难度（速度）
void Game::Difficulty(int flag)
{
	if (flag == VK_F1)
	{
		//最高速度50
		if (sleeptime > 50)
		{
			sleeptime -= 50;
			add += 2;
		}
	}

	else if (flag == VK_F2)
	{

		//最低速度500
		if (sleeptime <= 500)
		{
			sleeptime += 50;
			add -= 2;
		}
	}

}