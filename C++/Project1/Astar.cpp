#include"myfile.h"
#include<math.h>

//extern int map[20][20];
extern Snake virsnake;

void Note::h_get(Note& goal)
{
	h = abs(x - goal.x) + abs(y - goal.y);
//	h = sqrt((x - goal->x) * (x - goal->x) + (y - goal->y) * (y - goal->y) );

}

int Snake::Astar(Note goal)
{
	if (head == goal)
	{
		//���������
		if (this->hwnd != NULL)
		{
			//����Ҳ���β�ͣ����ؿ�
			if (!Astar(tail))
				return false;
			else
				return true;
		}
		//�����������
		else
		{
			//����Ҳ���β�ͣ����ؿ�
			open.push(new Note(head.x, head.y));
			map[tail.x][tail.y] = EMPTY;
			if (Astar(tail) == -1)
			{
				map[tail.x][tail.y] = BODY;
				return 1;
			}
			else
			{
				map[tail.x][tail.y] = BODY;
				return 2;
			}
		}
		
	}
		//��ʼA*����
		while (!open.empty())
		{
			//��open����ȡ�����в�����������ŵ���close�� 
			Note *cur = open.top();
			cur->h_get(goal);
			open.pop();
			close.push(cur);


			//�Ե�ǰ�����ڵ�4���е�ÿһ�� 
			for (int i = U; i <= R; i++)
			{
				Note temp = SnakeCur(*cur, i);
				Note* ntry = new Note(temp.x, temp.y);
				ntry->h_get(goal);

				//����ͨ�� || �Ѿ�����close��
				if ( (map[ntry->x][ntry->y] == EMPTY || map[ntry->x][ntry->y] == FOOD) && !close.find(*ntry) )
				{

					//�������open����
					if (!open.find(*ntry))
					{
						ntry->father = cur;
						ntry->g = ntry->father->g + 1;
						ntry->f = ntry->g + ntry->h;
						ntry->status = i;
						open.push(ntry);

					}
					//����Ѿ���open���� 
					else
					{
						//����и���,����gֵ 
						if (cur->g + 1 < ntry->g)
						{
							ntry->g = cur->g + 1;
							ntry->father = cur;
							ntry->f = ntry->g + ntry->h;
							ntry->status = i;
						}

					}

					//���open���г���goal����֤�����ҵ� 
					Note *p = open.find(goal);
					if (p != NULL)
					{
						this->MovePath(p);
						if (this->hwnd != NULL)
							return true;
						else
							return 0;
					}




				}
			}

		}

		//���open��Ϊ�գ��򲻴���Ŀ��·�� 
		//��ʱ��Ϊ���ߣ�����false
		if (this->hwnd != NULL)
			return false;
		//��Ϊ�����ߣ�����
		else
			return -1;

}

//�õ����յ������·��ʱ������һ����·��
void Snake::MovePath(Note *end)
{
	//������·����ǰ�ҵ���ʼ����һ���ڵ�
	while (end->father != NULL)
	{
		if (end->father->father == NULL)
			end->father->status = end->status;
		end = end->father;
		
	}
	nextstatus = end->status;
	Clean();
	//����������ߣ���������һ��
	if (this->hwnd == NULL)
	{
		this->SnakeMove(NULL);
	}
	//��������ߣ����������һ��
	else
	{
		if (nextstatus == U)
			SendMessage(hwnd, WM_KEYDOWN, VK_UP, 0);
		else if (nextstatus == D)
			SendMessage(hwnd, WM_KEYDOWN, VK_DOWN, 0);
		else if (nextstatus == R)
			SendMessage(hwnd, WM_KEYDOWN, VK_RIGHT, 0);
		else if (nextstatus == L)
			SendMessage(hwnd, WM_KEYDOWN, VK_LEFT, 0);
	}
}

//����β����Զ��·��
bool Snake::TAstar()
{
	map[tail.x][tail.y] = EMPTY;
	while (!op.empty())
	{
		//��open����ȡ�����в�����������ŵ���close�� 
		Note *cur = op.top();
		cur->h_get(tail);
		op.pop();
		cl.push(cur);

		//�Ե�ǰ�����ڵ�4���е�ÿһ�� 
		for (int i = U; i <= R; i++)
		{
			Note temp = SnakeCur(*cur, i);
			Note* ntry = new Note(temp.x, temp.y);
			ntry->h_get(tail);

			//����ͨ�� || �Ѿ�����close��
			if ((map[ntry->x][ntry->y] == EMPTY || map[ntry->x][ntry->y] == FOOD) && !cl.find(*ntry))
			{

				//�������open����
				if (!op.find(*ntry))
				{
					ntry->father = cur;
					ntry->g = ntry->father->g + 1;
					ntry->f = ntry->g + ntry->h;
					ntry->status = i;
					op.push(ntry);

				}
				//����Ѿ���open���� 
				else
				{
					//����и���,����gֵ 
					if (cur->g + 1 > ntry->g)
					{
						ntry->g = cur->g + 1;
						ntry->father = cur;
						ntry->f = ntry->g + ntry->h;
						ntry->status = i;
					}

				}

				//���open���г���tail����֤�����ҵ� 
				Note *p = op.find(tail);
				if (p)
				{
					map[tail.x][tail.y] = BODY;
					MovePath(p);
					return true;
				}
			}
		}

	}
	//���op��Ϊ�գ���Ӧ�ý����� 
	//map[tail.x][tail.y] = BODY;
	return false;

}
/*
int Snake::virAstar(Note goal)
{
	if (head == goal)
	{
		//����Ҳ���β�ͣ����ؿ�
		open.push(new Note(head.x, head.y));
		map[tail.x][tail.y] = EMPTY;
		if (virAstar(tail) == -1)
		{
			map[tail.x][tail.y] = BODY;
			return 1;
		}
		else
		{
			map[tail.x][tail.y] = BODY;
			return 2;
		}
	}

	while (!open.empty())
	{
		//��open����ȡ�����в�����������ŵ���close�� 
		Note *cur = open.top();
		cur->h_get(goal);
		open.pop();
		close.push(cur);


		//�Ե�ǰ�����ڵ�4���е�ÿһ�� 
		for (int i = U; i <= R; i++)
		{
			Note temp = SnakeCur(*cur, i);
			Note* ntry = new Note(temp.x, temp.y);
			ntry->h_get(goal);

			//����ͨ�� || �Ѿ�����close��
			if ((map[ntry->x][ntry->y] == EMPTY || map[ntry->x][ntry->y] == FOOD) && !close.find(*ntry))
			{

				//�������open����
				if (!open.find(*ntry))
				{
					ntry->father = cur;
					ntry->g = ntry->father->g + 1;
					ntry->f = ntry->g + ntry->h;
					ntry->status = i;
					open.push(ntry);

				}
				//����Ѿ���open���� 
				else
				{
					//����и���,����gֵ 
					if (cur->g + 1 < ntry->g)
					{
						ntry->g = cur->g + 1;
						ntry->father = cur;
						ntry->f = ntry->g + ntry->h;
						ntry->status = i;
					}

				}

				//���open���г���goal����֤�����ҵ� 
				Note *p = open.find(goal);
				if (p)
				{
					this->MovePath(p);

					return 0;
				}
			}
		}

	}

	//���open��Ϊ�գ��򲻴���Ŀ��·�� 
		return -1;

}
*/
//���·��һ��
bool Snake::LenAstar(Note goal)
{
	
		//��open����ȡ�����в�����������ŵ���close�� 
		if (op.empty())
			return false;
		
		Note *cur = op.top();
		cur->h_get(goal);
		op.pop();
		

		//�Ե�ǰ�����ڵ�4���е�ÿһ�� 
		for (int i = U; i <= R; i++)
		{
			Note temp = SnakeCur(*cur, i);
			Note* ntry = new Note(temp.x, temp.y);
			ntry->h_get(goal);

		//	open.push(new Note(head.x, head.y));

			//����ͨ��
			if ( map[ntry->x][ntry->y] == EMPTY || map[ntry->x][ntry->y] == FOOD)
			{
					ntry->father = cur;
					ntry->g = ntry->father->g + 1;
					ntry->f = ntry->g + ntry->h;
					ntry->status = i;
					op.push(ntry);
				
			}
		}

		delete cur;
		while (!op.empty())
		{

			Note *next = op.top();
			
			while (!open.empty())
			{
				Note * q = open.top();
				delete q;
				open.pop();
			}

			//����ҵõ�β��
			virsnake = *this;
			virsnake.hwnd = NULL;
			virsnake.open.push(new Note(next->x, next->y));
			virsnake.map[tail.x][tail.y] = EMPTY;
			if (virsnake.Astar(tail) == 0)
			{
	
					//�������
			//		Clean();
					//���˷�����
					int temp = next->status;
					if (temp == U)
						SendMessage(hwnd, WM_KEYDOWN, VK_UP, 0);
					else if (temp == D)
						SendMessage(hwnd, WM_KEYDOWN, VK_DOWN, 0);
					else if (temp == R)
						SendMessage(hwnd, WM_KEYDOWN, VK_RIGHT, 0);
					else if (temp == L)
						SendMessage(hwnd, WM_KEYDOWN, VK_LEFT, 0);

					return true;
			}
	//		Clean();
			Note *dete = op.top();
			delete dete;
		//	if (!op.empty())
				op.pop();
			
		}
	//delete cur;
	return false;

}

//����mShort�Ƿ������·
int Snake::isp(Note goal, bool mShort)
{
	while (1)
	{
		open.push(new Note(head.x, head.y));

		int ok;
		//����������·��
		if (mShort)
			ok = Astar(goal);
		//��������·��



		//�Ҳ���ʳ��ʱ,������β��
		if (ok == -1)
		{
			open.push(new Note(head.x, head.y));
			map[tail.x][tail.y] = 3;
			int tok = Astar(tail);
			map[tail.x][tail.y] = 1;
			//����ҵõ�β��
			if (tok == 0)
			{
				ok = 4;
			}
			//ʳ��β�Ͷ��ҵ�����������3
			else if (tok == -1)
			{
				ok = 3;
			}
		}
		if (ok != 0)
		{
			Clean();

			//����Ե�ʳ�ﵫ�Ҳ���β�ͣ�okΪ1

			//����Ե�ʳ�����ҵõ�β��,okΪ2

			//����Ҳ���ʳ�����Ҳ���β�ͣ�okΪ3

			//����Ҳ���ʳ�ﵫ�ҵõ�β�ͣ�okΪ4

			return ok;
		}

	}
}

void Snake::Clean()
{
	while (!open.empty())
	{
		Note *q = open.top();
		open.pop();
		delete q;
		
	}
	while (!close.empty())
	{
		Note *q = close.top();
		close.pop();
		delete q;
		
	}
	while (!op.empty())
	{
		Note *q = op.top();
		op.pop();
		delete q;
		
	}
	while (!cl.empty())
	{
		Note *q = cl.top();
		cl.pop();
		delete q;
		
	}


}

/*
int Snake::FvirAstar(Note goal)
{
	if (head == goal)
	{
		//����Ҳ���β�ͣ����ؿ�
		open.push(new Note(head.x, head.y));
		map[tail.x][tail.y] = EMPTY;
		if (Astar(tail) == -1)
		{
			map[tail.x][tail.y] = BODY;
			return 1;
		}
		else
		{
			map[tail.x][tail.y] = BODY;
			return 2;
		}

	}

	while (!open.empty())
	{
		//��open����ȡ�����в�����������ŵ���close�� 
		Note *cur = open.top();
		cur->h_get(goal);
		open.pop();
		close.push(cur);


		//�Ե�ǰ�����ڵ�4���е�ÿһ�� 
		for (int i = R; i >= U; i--)
		{
			Note temp = SnakeCur(*cur, i);
			Note* ntry = new Note(temp.x, temp.y);
			ntry->h_get(goal);

			//����ͨ�� || �Ѿ�����close��
			if ((map[ntry->x][ntry->y] == EMPTY || map[ntry->x][ntry->y] == FOOD) && !close.find(*ntry))
			{

				//�������open����
				if (!open.find(*ntry))
				{
					ntry->father = cur;
					ntry->g = ntry->father->g + 1;
					ntry->f = ntry->g + ntry->h;
					ntry->status = i;
					open.push(ntry);

				}
				//����Ѿ���open���� 
				else
				{
					//����и���,����gֵ 
					if (cur->g + 1 < ntry->g)
					{
						ntry->g = cur->g + 1;
						ntry->father = cur;
						ntry->f = ntry->g + ntry->h;
						ntry->status = i;
					}

				}

				//���open���г���goal����֤�����ҵ� 
				Note *p = open.find(goal);
				if (p)
				{
					while (p->father != NULL)
					{
						if (p->father->father == NULL)
							p->father->status = p->status;
						p = p->father;

					}
					int temp1 = p->status;

					while (!open.empty())
					{
						//		delete open.top();
						open.pop();
					}
					while (!close.empty())
					{
						//			delete close.top();
						close.pop();
					}
					//	if (tail == goal)
					//	return 0;

					if (temp1 == U)
					{
						nextstatus = U;
						SnakeMove(NULL);
					}
					else if (temp1 == D)
					{
						nextstatus = D;
						SnakeMove(NULL);
					}
					else if (temp1 == R)
					{
						nextstatus = R;
						SnakeMove(NULL);
					}
					else if (temp1 == L)
					{
						nextstatus = L;
						SnakeMove(NULL);
					}

					return 0;
				}
			}
		}

	}

	//���open��Ϊ�գ��򲻴���Ŀ��·�� 
	return -1;

}*/
/*
bool Snake::fAstar(Note goal)
{
	if (head == goal)
	{
		//����Ҳ���β�ͣ����ؿ�
		if (!Astar(tail))
			return false;
		else
			return true;
	}


	while (!open.empty())
	{
		//��open����ȡ�����в�����������ŵ���close�� 
		Note *cur = open.top();
		cur->h_get(goal);
		open.pop();
		close.push(cur);


		//�Ե�ǰ�����ڵ�4���е�ÿһ�� 
		for (int i = R; i >= U; i--)
		{
			Note temp = SnakeCur(*cur, i);
			Note* ntry = new Note(temp.x, temp.y);
			ntry->h_get(goal);

			//����ͨ�� || �Ѿ�����close��
			if ((map[ntry->x][ntry->y] == EMPTY || map[ntry->x][ntry->y] == FOOD) && !close.find(*ntry))
			{

				//�������open����
				if (!open.find(*ntry))
				{
					ntry->father = cur;
					ntry->g = ntry->father->g + 1;
					ntry->f = ntry->g + ntry->h;
					ntry->status = i;
					open.push(ntry);

				}
				//����Ѿ���open���� 
				else
				{
					//����и���,����gֵ 
					if (cur->g + 1 < ntry->g)
					{
						ntry->g = cur->g + 1;
						ntry->father = cur;
						ntry->f = ntry->g + ntry->h;
						ntry->status = i;
					}

				}

				//���open���г���goal����֤�����ҵ� 
				Note *p = open.find(goal);
				if (p)
				{
					MovePath(p);
					return true;
				}
			}
		}

	}

	//���open��Ϊ�գ��򲻴���Ŀ��·�� 
	return false;

}*/