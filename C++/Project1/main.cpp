#include"myfile.h"

using namespace std;

//static int cxChar,cyChar;
static Snake snake;
static Game game;
static Food food;
Snake virsnake;//�����ߣ���Ҫ����������߲�Ҫ��hdc

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
	
		hwndButton = CreateWindow(TEXT("button"),TEXT("��ʼ��Ϸ"),WS_CHILD|
		WS_VISIBLE|//��ʼʱ�ǿɼ���
		BS_PUSHBUTTON,
		300,300,100,100,
		hwnd,(HMENU)ID__BUTTON1,//��ťID
		((LPCREATESTRUCT)lParam)->hInstance,NULL);
		break;
	case WM_TIMER:

		hdc = GetDC(hwnd);
		//virsnake.open.push(new Note(snake.head.x, snake.head.y));
		//Note goal(food.x, food.y);
		//�������ʳ������ҵ�ʳ����Ҳ���β��
		//if (!virsnake.Astar(goal))
		{
			//����β����Զ����

		}
	//	virsnake = snake;
		//virsnake.open.push(new Note(snake.head.x, snake.head.y) );
		
		//����Ե�ʳ���Ҳ��õ�β��
		virsnake = snake;
		virsnake.hwnd = NULL;
		ok = virsnake.isp(goal);
		//����Ե�ʳ�ﵫ�Ҳ���β�ͣ�okΪ1,

		//����Ե�ʳ�����ҵõ�β��,okΪ2

		//����Ҳ���ʳ�����Ҳ���β�ͣ�okΪ3

		//����Ҳ���ʳ�ﵫ�ҵõ�β�ͣ�okΪ4
		
		//����Ե�ʳ�ﵫ�Ҳ���β�ͣ����߳�β���ߣ���ʱ������
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
		//����Ե�ʳ�����ҵõ�β��,��������
		else if (ok == 2)
		{
			snake.open.push(new Note(snake.head.x, snake.head.y));
			snake.Astar(goal);
			snake.Clean();
		}
		//����Ҳ���ʳ�����Ҳ���β�ͣ����߸�β����
		else if (ok == 3)
		{
			//�����
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
		//����Ҳ���ʳ�ﵫ�ҵõ�β�ͣ������ȳ�β���ߣ��ȴ�ʱ��
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
		if(IDYES == MessageBox(hwnd, TEXT("�Ƿ�Ҫ�����رճ���"), TEXT("����"), MB_YESNO))
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
	wndcls.lpszClassName = TEXT("̰����");
	wndcls.lpszMenuName = NULL;
	wndcls.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndcls);

	HWND hwnd;
	hwnd = CreateWindow(TEXT("̰����"),TEXT("̰����С��Ϸ"),
		WS_DLGFRAME|WS_SYSMENU,//�ĳ������޷��϶����ڣ�ԭ����ʽWS_OVERLAPPEDWINDOW
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



