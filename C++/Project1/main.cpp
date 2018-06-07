#include"myfile.h"

using namespace std;

//static int cxChar,cyChar;
static Snake snake;
static Game game;
static Food food;
Snake virsnake;//虚拟蛇，不要给他句柄或者不要给hdc

LRESULT CALLBACK WinSunProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	TEXTMETRIC tm;
	static int i;
	static HWND hwndButton;
//	RECT rect;
	HBRUSH hBrush = (HBRUSH)GetStockObject(BLACK_BRUSH);
	HDC hdc;
	int ok = -1;
	int fok = -1;
//	static UINT_PTR iTimerID;
	Note goal(food.x , food.y);
	switch(uMsg)
	{
	case WM_CREATE:
	
		hwndButton = CreateWindow(TEXT("button"),TEXT("开始游戏"),WS_CHILD|
		WS_VISIBLE|//初始时是可见的
		BS_PUSHBUTTON,
		300,300,100,100,
		hwnd,(HMENU)ID__BUTTON1,//按钮ID
		((LPCREATESTRUCT)lParam)->hInstance,NULL);
		break;
	case WM_TIMER:

		hdc = GetDC(hwnd);
		//virsnake.open.push(new Note(snake.head.x, snake.head.y));
		//Note goal(food.x, food.y);
		//如果不到食物或者找到食物后找不到尾巴
		//if (!virsnake.Astar(goal))
		{
			//找离尾巴最远的走

		}
	//	virsnake = snake;
		//virsnake.open.push(new Note(snake.head.x, snake.head.y) );
		
		//如果吃到食物且不得到尾巴
		virsnake = snake;
		virsnake.hwnd = NULL;
		ok = virsnake.isp(goal);
		//如果吃到食物但找不到尾巴，ok为1,

		//如果吃到食物且找得到尾巴,ok为2

		//如果找不到食物且找不到尾巴，ok为3

		//如果找不到食物但找得到尾巴，ok为4
		
		//如果吃到食物但找不到尾巴，真蛇朝尾巴走，等时机到来
		if (ok == 1)
		{
			snake.op.push(new Note(snake.head.x, snake.head.y));
			if (!snake.LenAstar(goal))
			{
				snake.Clean();
				snake.op.push(new Note(snake.head.x, snake.head.y));
				snake.TAstar();
				snake.Clean();
			}
		//	virsnake.Clean();
		//	virsnake.FvirAstar(Note goal)
		/*	fok = virsnake.isf(goal);
	
			if (fok == 2)
			{
				snake.open.push(new Note(snake.head.x, snake.head.y));
				snake.fAstar(goal);
				snake.Clean();

			}
			*/
			else
			{
			/*	virsnake.op.push(new Note(snake.head.x, snake.head.y));
				if (!virsnake.TAstar())
				{
					snake.op.push(new Note(snake.head.x, snake.head.y));
					snake.LenAstar(goal);
				}
				else
				{
					snake.op.push(new Note(snake.head.x, snake.head.y));
					snake.TAstar();
				}
				snake.Clean();
				*/
				snake.op.push(new Note(snake.head.x, snake.head.y));
				if (!snake.LenAstar(goal))
				{
					snake.Clean();
					snake.op.push(new Note(snake.head.x, snake.head.y));
					snake.TAstar();
					snake.Clean();
				}

			}
		}
		//如果吃到食物且找得到尾巴,真蛇走起
		else if (ok == 2)
		{
			snake.open.push(new Note(snake.head.x, snake.head.y));
			snake.Astar(goal);
			snake.Clean();
		}
		//如果找不到食物且找不到尾巴，真蛇跟尾巴走
		else if (ok == 3)
		{
			//随便走
			snake.op.push(new Note(snake.head.x, snake.head.y));
			if (!snake.LenAstar(goal))
			{
				snake.Clean();
				snake.op.push(new Note(snake.head.x, snake.head.y));
				snake.TAstar();
				snake.Clean();
			}
		/*	for (int i = 1; i <= 4; i++)
			{
				if (snake.map[snake.head.x + ydir[i]][snake.head.y + xdir[i]] == EMPTY)
				{
					snake.nextstatus = i;
					game.Handle(food, snake, snake.SnakeMove(hdc), hdc);
				}
			}
			*/
		//	snake.op.push(new Note(snake.head.x, snake.head.y));
		//	snake.TAstar();

		}
		//如果找不到食物但找得到尾巴，真蛇先朝尾巴走，等待时机
		else if (ok == 4)
		{
			snake.op.push(new Note(snake.head.x, snake.head.y));
			if (!snake.LenAstar(goal))
			{
				snake.Clean();
				snake.op.push(new Note(snake.head.x, snake.head.y));
				snake.TAstar();
				snake.Clean();
			}
		}
		ReleaseDC(hwnd,hdc);
	
		return 0;

	case WM_COMMAND:
		
		hdc = GetDC(hwnd);
		switch(LOWORD(wParam))
		{
		case ID__BUTTON1:

			DestroyWindow(hwndButton);
			game.GameStart(snake, food, hwnd, hdc);
			SetTimer(hwnd, 0, 50, NULL);
			SetFocus(hwnd);
			Note * p = new Note(snake.head.x, snake.head.y);
			virsnake = snake;
			//virsnake.hwnd = NULL;
			//snake.open.push(p);

			//virsnake.Astar(goal);
			ReleaseDC(hwnd, hdc);
			break;
		}
	case WM_PAINT:
		
		HDC hdc1;
		PAINTSTRUCT ps;
		hdc1 = BeginPaint(hwnd,&ps);
		GetTextMetrics(hdc1,&tm);
	//	cxChar = tm.tmAveCharWidth;
	//	cyChar = tm.tmHeight + tm.tmExternalLeading;
		

		EndPaint(hwnd,&ps);	
		break;
	case WM_KEYDOWN:
		hdc = GetDC(hwnd);
		switch(wParam)
		{
		case VK_DOWN:
		//	if( snake.oldstatus != U )
		//	{
				snake.nextstatus = D;
				game.Handle(food, snake, snake.SnakeMove(hdc), hdc);
				ReleaseDC(hwnd, hdc);
		//	}
			break;
		case VK_UP:
			//if( snake.oldstatus != D )
		//	{
				snake.nextstatus = U;
				game.Handle(food, snake, snake.SnakeMove(hdc), hdc);
				ReleaseDC(hwnd, hdc);
			//}
			break;
		case VK_LEFT:
		//	if( snake.oldstatus != R )
		//	{
				snake.nextstatus = L;
				game.Handle(food, snake, snake.SnakeMove(hdc), hdc);
				ReleaseDC(hwnd, hdc);
		//	}
			break;
		case VK_RIGHT:
		//	if( snake.oldstatus != L )
		//	{
				snake.nextstatus = R;
				game.Handle(food, snake, snake.SnakeMove(hdc), hdc);
				ReleaseDC(hwnd, hdc);
		//	}
			break;
		case VK_SPACE:
			game.pause();
			break;
		case VK_F1:
			game.Difficulty(VK_F1);
			break;
		case VK_F2:
			game.Difficulty(VK_F2);
			break;
		}
		
	
		break;
	case WM_CLOSE:
		if(IDYES == MessageBox(hwnd, TEXT("是否要结束关闭程序"), TEXT("警告"), MB_YESNO))
		{
			DestroyWindow(hwnd);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

}

int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine,
				   int nShowCmd)
{
	WNDCLASS wndcls;

	wndcls.cbClsExtra = 0;
	wndcls.cbWndExtra = 0;
	wndcls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndcls.hCursor = LoadCursor(NULL,IDC_CROSS);
	wndcls.hIcon = LoadIcon(NULL,IDI_INFORMATION);
	wndcls.hInstance = hInstance;
	wndcls.lpfnWndProc = WinSunProc;
	wndcls.lpszClassName = TEXT("贪吃蛇");
	wndcls.lpszMenuName = NULL;
	wndcls.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndcls);

	HWND hwnd;
	hwnd = CreateWindow(TEXT("贪吃蛇"),TEXT("贪吃蛇小游戏"),
		WS_DLGFRAME|WS_SYSMENU,//改成这样无法拖动窗口，原本样式WS_OVERLAPPEDWINDOW
		0,0,800,750,NULL,NULL,hInstance,NULL);

	ShowWindow(hwnd,SW_SHOWNORMAL);

	UpdateWindow(hwnd);

	MSG msg;
		
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	
	}
	return 0;

}



