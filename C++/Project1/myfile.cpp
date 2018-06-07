#include"myfile.h"
#include<strsafe.h>
#include<iostream>
#include<string.h>

using namespace std;

//int map[20][20];//��ά�����ͼ���Զ���ʼ��Ϊ0,0����·��1�����ߣ�2����ǽ��3����ʳ��

//��ʼ������
void Snake::InitSnake(HWND _hwnd, HDC _hdc)
{
	int i;

	hwnd = _hwnd;
	hdc = _hdc;


	//��y��13�ĵط���ʼ��4������
	for (i = 0; i < 4; i++)
	{
		Note temp;
		temp.x = 4 + i;
		temp.y = EDGE / 2;

		map[temp.x][temp.y] = BODY;
		SnakePrint(temp.x, temp.y, BODY);
		body.push(temp);

	}

	//��ʼ��ͷ��������
	head = body.back();
	tail = body.front();
	
	SnakePrint(head.x, head.y, HEAD);
	SnakePrint(tail.x, tail.y, TAIL);
}

//����color��ӡ�ߵĲ�ͬ����
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
		rect.right = a + LEN - 1;//��1��Ϊ���ܿ���һ��һ���Ч��
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



//�ڵ�p���������s�ķ���
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

//�޸���ͷbug
//���ͷ����ͷ������true�����򷵻�false
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


//���ƶ�����������һ���ڵ������ֵ
int Snake::SnakeMove(HDC _hdc)
{	
	hdc = _hdc;
	Note next = SnakeCur(head, nextstatus);

	map[tail.x][tail.y] = EMPTY;//�Ȱ�β�ͱ�Ϊ�յأ�����bug������ҧ��β�ͣ�
	//����ǿյأ�����ǰ��
	if(map[next.x][next.y] == EMPTY)
	{
		/*if( opposite() )
		{
			nextstatus = oldstatus;
			return SnakeMove(hdc);
		}*/
		
		//�����һ���������Ĩ��
		map[tail.x][tail.y] = EMPTY;
		SnakePrint(tail.x, tail.y, EMPTY);
		//β�������ı�
	//	tail = SnakeCur(tail, status.front());
		//status.pop();
		body.pop();
		tail = body.front();

		SnakePrint(head.x, head.y, BODY);
		//next��������ͷ��㣬
		map[next.x][next.y] = BODY;
		head = SnakeCur(head, nextstatus);
		//status.push(nextstatus);
		body.push(head);

		SnakePrint(head.x, head.y, HEAD);
		SnakePrint(tail.x, tail.y, TAIL);
		oldstatus = nextstatus;
		return EMPTY;
	}

	//�����ʳ��Ѵ˵�������߳�+1
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
	//�����һ���ڵ���2��ײ��ǽ
	else if (map[next.x][next.y] == WALL)
		return WALL;
	//EndGame(2, hwnd,hdc);

	//�����һ���ڵ���1,ҧ���Լ�(���������β�Ͳ�֪���㲻��bug)
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
		_x = (rand() % 10 + 1);//��0����19��ǽ
		_y = (rand() % 10 + 1);

		if (snake.map[_x][_y] == EMPTY)//����ǿյ�,�͸ĳ�ʳ��
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
	//������Ļ�����ջ���
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

//��ͣ����
void Game::pause()
{


}

//��ʼ����ͼ(�Ȼ�ǽ)
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

//������Ϸ�Ĳ���
void Game::EndGame(int flag, HDC hdc)
{
	static bool boot = true;//��¼�����Ƿ�����Ϸ״̬

	if(boot == true)
	{
		boot = false;//����Ϊ�ػ�״̬

		if (flag == BODY)
			MessageBox(hwnd, TEXT("�Բ�����ҧ���Լ��ˣ���Ϸ����"), TEXT("������Ϸ"), MB_OK);

		else if (flag == WALL)
			MessageBox(hwnd, TEXT("�Բ�����ײǽ�ˣ���Ϸ����"), TEXT("������Ϸ"), MB_OK);
		
		
		TCHAR subuff[256];
			StringCchPrintf(subuff, sizeof(subuff), TEXT("������Ϸ�÷�Ϊ��%d��"), score);
			if (IDOK == MessageBox(hwnd, subuff, TEXT("�÷����"), MB_OK));
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
//��Ϸ��������flag��ֵ���в�ͬ����
void Game::Handle(Food& food, Snake& snake, int flag, HDC hdc)
{
	//�һ����Ż���ö��
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

//������Ϸ�Ѷȣ��ٶȣ�
void Game::Difficulty(int flag)
{
	if (flag == VK_F1)
	{
		//����ٶ�50
		if (sleeptime > 50)
		{
			sleeptime -= 50;
			add += 2;
		}
	}

	else if (flag == VK_F2)
	{

		//����ٶ�500
		if (sleeptime <= 500)
		{
			sleeptime += 50;
			add -= 2;
		}
	}

}