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
		//如果是真蛇
		if (this->hwnd != NULL)
		{
			//如果找不到尾巴，返回空
			if (!Astar(tail))
				return false;
			else
				return true;
		}
		//如果是虚拟蛇
		else
		{
			//如果找不到尾巴，返回空
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
		//开始A*搜索
		while (!open.empty())
		{
			//把open表里取出进行操作，操作后放到给close表 
			Note *cur = open.top();
			cur->h_get(goal);
			open.pop();
			close.push(cur);


			//对当前格相邻的4格中的每一个 
			for (int i = U; i <= R; i++)
			{
				Note temp = SnakeCur(*cur, i);
				Note* ntry = new Note(temp.x, temp.y);
				ntry->h_get(goal);

				//它可通过 || 已经不在close中
				if ( (map[ntry->x][ntry->y] == EMPTY || map[ntry->x][ntry->y] == FOOD) && !close.find(*ntry) )
				{

					//如果不在open表中
					if (!open.find(*ntry))
					{
						ntry->father = cur;
						ntry->g = ntry->father->g + 1;
						ntry->f = ntry->g + ntry->h;
						ntry->status = i;
						open.push(ntry);

					}
					//如果已经在open表中 
					else
					{
						//如果有更好,更新g值 
						if (cur->g + 1 < ntry->g)
						{
							ntry->g = cur->g + 1;
							ntry->father = cur;
							ntry->f = ntry->g + ntry->h;
							ntry->status = i;
						}

					}

					//如果open表中出现goal，则证明已找到 
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

		//如果open表为空，则不存在目标路径 
		//此时若为真蛇，返回false
		if (this->hwnd != NULL)
			return false;
		//若为虚拟蛇，返回
		else
			return -1;

}

//得到到终点的完整路径时，走下一步的路径
void Snake::MovePath(Note *end)
{
	//从完整路径往前找到开始的下一个节点
	while (end->father != NULL)
	{
		if (end->father->father == NULL)
			end->father->status = end->status;
		end = end->father;
		
	}
	nextstatus = end->status;
	Clean();
	//如果是虚拟蛇，则虚拟下一步
	if (this->hwnd == NULL)
	{
		this->SnakeMove(NULL);
	}
	//如果是真蛇，则真的走下一步
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

//走离尾巴最远的路线
bool Snake::TAstar()
{
	map[tail.x][tail.y] = EMPTY;
	while (!op.empty())
	{
		//把open表里取出进行操作，操作后放到给close表 
		Note *cur = op.top();
		cur->h_get(tail);
		op.pop();
		cl.push(cur);

		//对当前格相邻的4格中的每一个 
		for (int i = U; i <= R; i++)
		{
			Note temp = SnakeCur(*cur, i);
			Note* ntry = new Note(temp.x, temp.y);
			ntry->h_get(tail);

			//它可通过 || 已经不在close中
			if ((map[ntry->x][ntry->y] == EMPTY || map[ntry->x][ntry->y] == FOOD) && !cl.find(*ntry))
			{

				//如果不在open表中
				if (!op.find(*ntry))
				{
					ntry->father = cur;
					ntry->g = ntry->father->g + 1;
					ntry->f = ntry->g + ntry->h;
					ntry->status = i;
					op.push(ntry);

				}
				//如果已经在open表中 
				else
				{
					//如果有更好,更新g值 
					if (cur->g + 1 > ntry->g)
					{
						ntry->g = cur->g + 1;
						ntry->father = cur;
						ntry->f = ntry->g + ntry->h;
						ntry->status = i;
					}

				}

				//如果open表中出现tail，则证明已找到 
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
	//如果op表为空，则应该结束了 
	//map[tail.x][tail.y] = BODY;
	return false;

}
/*
int Snake::virAstar(Note goal)
{
	if (head == goal)
	{
		//如果找不到尾巴，返回空
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
		//把open表里取出进行操作，操作后放到给close表 
		Note *cur = open.top();
		cur->h_get(goal);
		open.pop();
		close.push(cur);


		//对当前格相邻的4格中的每一个 
		for (int i = U; i <= R; i++)
		{
			Note temp = SnakeCur(*cur, i);
			Note* ntry = new Note(temp.x, temp.y);
			ntry->h_get(goal);

			//它可通过 || 已经不在close中
			if ((map[ntry->x][ntry->y] == EMPTY || map[ntry->x][ntry->y] == FOOD) && !close.find(*ntry))
			{

				//如果不在open表中
				if (!open.find(*ntry))
				{
					ntry->father = cur;
					ntry->g = ntry->father->g + 1;
					ntry->f = ntry->g + ntry->h;
					ntry->status = i;
					open.push(ntry);

				}
				//如果已经在open表中 
				else
				{
					//如果有更好,更新g值 
					if (cur->g + 1 < ntry->g)
					{
						ntry->g = cur->g + 1;
						ntry->father = cur;
						ntry->f = ntry->g + ntry->h;
						ntry->status = i;
					}

				}

				//如果open表中出现goal，则证明已找到 
				Note *p = open.find(goal);
				if (p)
				{
					this->MovePath(p);

					return 0;
				}
			}
		}

	}

	//如果open表为空，则不存在目标路径 
		return -1;

}
*/
//朝最长路走一步
bool Snake::LenAstar(Note goal)
{
	
		//把open表里取出进行操作，操作后放到给close表 
		if (op.empty())
			return false;
		
		Note *cur = op.top();
		cur->h_get(goal);
		op.pop();
		

		//对当前格相邻的4格中的每一个 
		for (int i = U; i <= R; i++)
		{
			Note temp = SnakeCur(*cur, i);
			Note* ntry = new Note(temp.x, temp.y);
			ntry->h_get(goal);

		//	open.push(new Note(head.x, head.y));

			//它可通过
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

			//如果找得到尾巴
			virsnake = *this;
			virsnake.hwnd = NULL;
			virsnake.open.push(new Note(next->x, next->y));
			virsnake.map[tail.x][tail.y] = EMPTY;
			if (virsnake.Astar(tail) == 0)
			{
	
					//清理操作
			//		Clean();
					//按此方向走
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

//参数mShort是否是最短路
int Snake::isp(Note goal, bool mShort)
{
	while (1)
	{
		open.push(new Note(head.x, head.y));

		int ok;
		//如果是走最短路的
		if (mShort)
			ok = Astar(goal);
		//如果是走最长路的



		//找不到食物时,尝试找尾巴
		if (ok == -1)
		{
			open.push(new Note(head.x, head.y));
			map[tail.x][tail.y] = 3;
			int tok = Astar(tail);
			map[tail.x][tail.y] = 1;
			//如果找得到尾巴
			if (tok == 0)
			{
				ok = 4;
			}
			//食物尾巴都找到不到，返回3
			else if (tok == -1)
			{
				ok = 3;
			}
		}
		if (ok != 0)
		{
			Clean();

			//如果吃到食物但找不到尾巴，ok为1

			//如果吃到食物且找得到尾巴,ok为2

			//如果找不到食物且找不到尾巴，ok为3

			//如果找不到食物但找得到尾巴，ok为4

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
		//如果找不到尾巴，返回空
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
		//把open表里取出进行操作，操作后放到给close表 
		Note *cur = open.top();
		cur->h_get(goal);
		open.pop();
		close.push(cur);


		//对当前格相邻的4格中的每一个 
		for (int i = R; i >= U; i--)
		{
			Note temp = SnakeCur(*cur, i);
			Note* ntry = new Note(temp.x, temp.y);
			ntry->h_get(goal);

			//它可通过 || 已经不在close中
			if ((map[ntry->x][ntry->y] == EMPTY || map[ntry->x][ntry->y] == FOOD) && !close.find(*ntry))
			{

				//如果不在open表中
				if (!open.find(*ntry))
				{
					ntry->father = cur;
					ntry->g = ntry->father->g + 1;
					ntry->f = ntry->g + ntry->h;
					ntry->status = i;
					open.push(ntry);

				}
				//如果已经在open表中 
				else
				{
					//如果有更好,更新g值 
					if (cur->g + 1 < ntry->g)
					{
						ntry->g = cur->g + 1;
						ntry->father = cur;
						ntry->f = ntry->g + ntry->h;
						ntry->status = i;
					}

				}

				//如果open表中出现goal，则证明已找到 
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

	//如果open表为空，则不存在目标路径 
	return -1;

}*/
/*
bool Snake::fAstar(Note goal)
{
	if (head == goal)
	{
		//如果找不到尾巴，返回空
		if (!Astar(tail))
			return false;
		else
			return true;
	}


	while (!open.empty())
	{
		//把open表里取出进行操作，操作后放到给close表 
		Note *cur = open.top();
		cur->h_get(goal);
		open.pop();
		close.push(cur);


		//对当前格相邻的4格中的每一个 
		for (int i = R; i >= U; i--)
		{
			Note temp = SnakeCur(*cur, i);
			Note* ntry = new Note(temp.x, temp.y);
			ntry->h_get(goal);

			//它可通过 || 已经不在close中
			if ((map[ntry->x][ntry->y] == EMPTY || map[ntry->x][ntry->y] == FOOD) && !close.find(*ntry))
			{

				//如果不在open表中
				if (!open.find(*ntry))
				{
					ntry->father = cur;
					ntry->g = ntry->father->g + 1;
					ntry->f = ntry->g + ntry->h;
					ntry->status = i;
					open.push(ntry);

				}
				//如果已经在open表中 
				else
				{
					//如果有更好,更新g值 
					if (cur->g + 1 < ntry->g)
					{
						ntry->g = cur->g + 1;
						ntry->father = cur;
						ntry->f = ntry->g + ntry->h;
						ntry->status = i;
					}

				}

				//如果open表中出现goal，则证明已找到 
				Note *p = open.find(goal);
				if (p)
				{
					MovePath(p);
					return true;
				}
			}
		}

	}

	//如果open表为空，则不存在目标路径 
	return false;

}*/