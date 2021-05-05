//게임의 대부분 기능
#include "main.h"

int g_sec; 
int positionX, positionY, direction;

//-------------------------------------- 초기화
void Init()
{
	system("cls");                                  //화면 지움
	g_sec = 100;                                     //시간 초기화
	int map[FRAME_Y + 1][FRAME_X * 2 + 1] = { 0 };  //맵을 0으로 초기화
	for (int y = 0; y < FRAME_Y - 1 ; y++)
	{
		for (int x = 0; x < FRAME_X * 2 + 2; x++)
		{
			if (y == 0 || y == FRAME_Y - 2 || x == 0 || x == 1 || x == FRAME_X * 2 || x == FRAME_X * 2 + 1)  //게임틀은 1로 초기화
				map[y][x] = 1;         
		}
	}
	positionX = 4;
	positionY = 16;
	direction = 2;
}

void DrawSnake()
{
	int inputLEFT, inputRIGHT, inputUP, inputDOWN, inputQ, inputESC;
	inputLEFT = GetAsyncKeyState(VK_LEFT) & 0x8000;
	inputRIGHT = GetAsyncKeyState(VK_RIGHT) & 0x8000;
	inputUP = GetAsyncKeyState(VK_UP) & 0x8000;
	inputDOWN = GetAsyncKeyState(VK_DOWN) & 0x8000;
	inputQ = GetAsyncKeyState(VK_Q) & 0x8000;
	inputESC = GetAsyncKeyState(VK_ESCAPE) & 0x8000;
	//inputW = GetAsyncKeyState(VK_LEFT) & 0x8000;
	//inputA = GetAsyncKeyState(VK_RIGHT) & 0x8000;
	//inputS = GetAsyncKeyState(VK_UP) & 0x8000;
	//inputD = GetAsyncKeyState(VK_DOWN) & 0x8000;

	if (inputESC)
		system("pause");
	if (inputQ)
		system("pause > null");
	switch (direction)
	{
	case 0:
	case 1:
		if (inputUP != inputDOWN)
		{
			if (inputUP) direction = 2;
			else direction = 3;
		}
		break;
	case 2:
	case 3:
		if (inputLEFT != inputRIGHT)
		{
			if (inputLEFT) direction = 0;
			else direction = 1;
		}
		break;
	}
	switch (direction)
	{
	case 0:
		positionX -= 2;
		break;
	case 1:
		positionX += 2;
		break;
	case 2:
		positionY--;
		break;
	case 3:
		positionY++;
		break;
	}
	gotoxy(positionX, positionY);
	printf("▣");

}

//-------------------------------------- 게임 방법
void GameRules()
{
	system("cls");
	printf("\t\t           \t\t\t||\t\t\t           \t\t\n");
	printf("\t\t           \t\t\t||\t\t\t           \t\t\n");
	printf("\t\t           \t\t\t||\t\t\t           \t\t\n");
	printf("\t\t  [1P 조작법]\t\t\t||\t\t      [2P 조작법]\t\t\n");
	printf("\t\t           \t\t\t||\t\t\t           \t\t\n");
	printf("\t\t           \t\t\t||\t\t\t           \t\t\n");
	printf("\t\t           \t\t\t||\t\t\t           \t\t\n");
	printf("\t\t [ W, S, A, D ]\t\t\t||\t\t   [ ↑, ↓, ←, → ]\t\t\n");
	printf("\t\t           \t\t\t||\t\t\t           \t\t\n");
	printf("\t\t           \t\t\t||\t\t\t           \t\t\n");
	printf("\t\t           \t\t\t||\t\t\t           \t\t\n");
	printf("\t\t           \t\t\t||\t\t\t           \t\t\n");
	printf("====================================================================================================\n");
	SetColor(RED);								//빨간색으로
	printf("\n\n                                            [GAME OVER]                      \n");
	SetColor(WHITE);							//흰색으로
	printf("\n\n                                         1. 서로 닿았을 때                \n");
	printf("\n\n                                         2. 벽에 닿았을 때                \n");
	printf("\n\n                                      3. 시간이 종료되었을 때                \n");
	gotoxy(79, 28);
	SetColor(YELLOW);							 //노란색으로
	printf("SPACE를 눌러주세요.");
	SetColor(WHITE);							//흰색으로
	while (1)
	{
		if (KeyControl() == SPACE) {			 //SPACE가 입력될 때까지 대기
			break;
		}
	}
}

//-------------------------------------- 게임 틀
void DrawFrame()
{
	system("cls");
	
	for (int i = 0; i <= FRAME_X; i++)			 //게임 틀의 첫 줄
	{
		SetColor(BLUE);
		printf("■");							//벽 프린트
	}
	printf("\n");
	
    for(int i=1; i<FRAME_Y-2; i++)				 //게임 틀의 첫 줄과 마지막 줄 사이
    {
        printf("■");
        gotoxy(66,i);
        printf("■");
        printf("\n");
    }
    for(int i = 0; i<= FRAME_X ; i++)			 // 게임 틀의 마지막 줄
        printf("■");
    printf("\n");
	SetColor(WHITE);
}
