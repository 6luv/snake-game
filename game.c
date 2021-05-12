//게임의 대부분 기능
#include "main.h"

//-------------------------------------- 초기화
void Init()
{
	system("cls");                                  //화면 지움
	g_sec = 60;                                    //시간 초기화
	int map[FRAME_Y + 1][FRAME_X * 2 + 1] = { 0 };  //맵을 0으로 초기화
	for (int y = 0; y < FRAME_Y - 1; y++)
	{
		for (int x = 0; x < FRAME_X * 2 + 2; x++)
		{
			if (y == 0 || y == FRAME_Y - 2 || x == 0 || x == 1 || x == FRAME_X * 2 || x == FRAME_X * 2 + 1)  //게임틀은 1로 초기화
				map[y][x] = 1;                      //맵 테두리를 1로 초기화
		}
	}

	head_2->cx = 50;                                //2P head x좌표 초기화
	head_2->cy = 15;                                //2P head x좌표 초기화
	head_2->index = 0;                              //head의 값?
	head_2->direction = LEFT;                       //처음 시작 방향
	tail_2 = head_2;                                //tail은 head로 초기화

	for (int i = 0; i < 3; i++)                     //몸 길이 초기화
		AddSnake();

}

void CoordMove()                                         //좌표 이동 함수
{
	SNAKE* current;                                 //current 포인터로 비교하기 위해
	current = (SNAKE*)malloc(sizeof(SNAKE));        //구조체 동적 할당
	if (current == NULL)                            //할당에 실패하면 종료
		exit(1);

	head_2->oldx = head_2->cx;                      //이전 x좌표는 현재 x좌표를 받음
	head_2->oldy = head_2->cy;                      //이전 y좌표는 현재 y좌표를 받음

	for (current = head_2->next; current != tail_2; current = current->next)  //tail전 까지 몸통 좌표 이동
	{
		current->oldx = current->cx;                //이전 x좌표는 현재 x좌표를 받음
		current->oldy = current->cy;                //이전 y좌표는 현재 y좌표를 받음
	}

	current = head_2->next;                         //포인터 초기화
	current->cx = head_2->oldx;                     //몸통 현재 x좌표는 헤드의 이전 x좌표
	current->cy = head_2->oldy;                     //몸통 현재 y좌표는 헤드의 이전 y좌표

	for (current = head_2->next; current != tail_2; current = current->next)   //tail전 까지 몸통 좌표 이동
	{
		current->next->cx = current->oldx;          //다음 몸통의 현재 x좌표는 전 몸통의 이전 x좌표
		current->next->cy = current->oldy;          //다음 몸통의 현재 y좌표는 전 몸통의 이전 y좌표
	}
}

void AddSnake()                                     //몸통 노드 추가
{
	SNAKE* newnode;                                 //새로운 노드 
	newnode = (SNAKE*)malloc(sizeof(SNAKE));        //구조체 동적 할당
	if (newnode == NULL)                            //할당에 실패하면 종료
		exit(1);
	tail_2->next = newnode;                         //tail의 다음 노드 연결
	newnode->next = NULL;                           //새로운 노드의 next는 NULL
	tail_2 = newnode;                               //tail 포인터 이동
	tail_2->index = -1;                             //tail의 값 설정
}
/*
void DrawSnake1(int keys[256])
{
	SNAKE* current;
	current = (SNAKE*)malloc(sizeof(SNAKE));

	switch (head_1->direction)
	{
	case LEFT:
	case RIGHT:
		if (keys[VK_UP] != keys[VK_DOWN])
		{
			if (keys[VK_UP]) head_1->direction = UP;
			else head_1->direction = DOWN;
		}
		break;
	case UP:
	case DOWN:
		if (keys[VK_LEFT] != keys[VK_RIGHT])
		{
			if (keys[VK_LEFT]) head_1->direction = LEFT;
			else head_1->direction = RIGHT;
		}
		break;
	}

	switch (head_1->direction)
	{
	case LEFT:
		if (head_1->cx - 2 > 0)
		{
			CoordMove();
			head_1->cx -= 2;
		}
		break;
	case RIGHT:
		if (head_1->cx + 2 <= FRAME_X*2)
		{
			CoordMove();
			head_1->cx += 2;
		}
		break;
	case UP:
		if (head_1->cy  > 0)
		{
			CoordMove();
			head_1->cy--;
		}
		break;
	case DOWN:
		if (head_1->cy < FRAME_Y - 2)
		{
			CoordMove();
			head_1->cy++;
		}
		break;
	}

	gotoxy(head_1->cx, head_1->cy);
	printf("▣");
	for (current = head_1->next; current != tail_1; current = current->next)
	{
		gotoxy(current->cx, current->cy);
		printf("▣");
	}
	gotoxy(tail_1->cx, tail_1->cy);
	printf("  ");
}
*/

void DrawSnake2(int keys[256])
{
	SNAKE* current;
	current = (SNAKE*)malloc(sizeof(SNAKE));

	switch (head_2->direction)                          //head의 방향에 따라 분류
	{
	case LEFT:                                          //왼쪽, 오른쪽일 때
	case RIGHT:
		if (keys[VK_UP] != keys[VK_DOWN])               //위 아래가 같이 입력되는 거 방지
		{
			if (keys[VK_UP]) head_2->direction = UP;    //위 방향키가 눌리면 head의 방향 변경
			else head_2->direction = DOWN;              //아래 방향키가 눌리면 head의 방향 변경
		}
		break;                                          //위 아래가 같이 입력되면 종료
	case UP:                                            //위쪽, 아래쪽일 때
	case DOWN:
		if (keys[VK_LEFT] != keys[VK_RIGHT])            //왼쪽 오른쪽이 같이 입력되는 거 방지
		{
			if (keys[VK_LEFT]) head_2->direction = LEFT;//왼쪽 방향키가 눌리면 head의 방향 변경
			else head_2->direction = RIGHT;             //오른쪽 방향키가 눌리면 head의 방향 변경
		}
		break;                                          //왼쪽 오른쪽이 같이 입력되면 종료
	}

	switch (head_2->direction)                          //head의 방향에 따라 분류
	{
	case LEFT:                                          //왼쪽 방향일 때
		if (head_2->cx - 2 > 0)                         //맵 범위를 벗어나지 않도록
		{ 
			CoordMove();                                     //뱀의 좌표 변경
			head_2->cx -= 2;                            //왼쪽으로 이동하기 때문에 -2 (특수 문자는 2칸 차지)
		}
		break;                                          //맵 범위를 벗어나면 종료
	case RIGHT:                                         //오른쪽 방향일 때
		if (head_2->cx + 2 <= FRAME_X*2)                //맵 범위를 벗어나지 않도록
		{
			CoordMove();                                     //뱀의 좌표 변경
			head_2->cx += 2;                            //오른쪽으로 이동하기 때문에 +2 (특수 문자는 2칸 차지)
		}
		break;                                          //맵 범위를 벗어나면 종료
	case UP:                                            //위쪽 방향일 때
		if (head_2->cy  > 0)                            //맵 범위를 벗어나지 않도록
		{
			CoordMove();                                     //뱀의 좌표 변경
			head_2->cy--;                               //위로 이동하기 때문에 -1
		}
		break;                                          //맵 범위를 벗어나면 종료
	case DOWN:                                          //아래쪽 방향일 때
		if (head_2->cy < FRAME_Y - 2)                   //맵 범위를 벗어나지 않도록
		{
			CoordMove();                                     //뱀의 좌표 변경
			head_2->cy++;                               //아래로 이동하기 때문에 +1
		}
		break;                                          //맵 범위를 벗어나면 종료
	}

	gotoxy(head_2->cx, head_2->cy);                     //head의 좌표로 이동
	printf("▣");                                       //출력
	for (current = head_2->next; current != tail_2; current = current->next)  //tail전 까지 이동
	{
		gotoxy(current->cx, current->cy);               //몸통의 좌표로 이동
		printf("▣");                                   //출력
	}
	gotoxy(tail_2->cx, tail_2->cy);                     //tail의 좌표로 이동
	printf("  ");                                       //지움

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
	SetColor(RED);								         //빨간색으로
	printf("\n\n                                            [GAME OVER]                      \n");
	SetColor(WHITE);							         //흰색으로
	printf("\n\n                                         1. 서로 닿았을 때                \n");
	printf("\n\n                                         2. 벽에 닿았을 때                \n");
	printf("\n\n                                      3. 시간이 종료되었을 때                \n");
	gotoxy(79, 28);
	SetColor(YELLOW);							          //노란색으로
	printf("SPACE를 눌러주세요.");
	SetColor(WHITE);			             			  //흰색으로
	system("pause > null");
	GetPressedKey(keys);                                  //키 입력 처리
	if (keys[VK_SPACE]) {                                 //SPACE가 입력될 때까지 대기
		return;
	}
}

//-------------------------------------- 게임 틀
void DrawFrame()
{
	system("cls");

	for (int i = 0; i <= FRAME_X; i++)			          //게임 틀의 첫 줄
	{
		SetColor(BLUE);
		printf("■");						 	          //벽 프린트
	}
	printf("\n");

	for (int i = 1; i < FRAME_Y - 2; i++)				 //게임 틀의 첫 줄과 마지막 줄 사이
	{
		printf("■");
		gotoxy(66, i);
		printf("■");
		printf("\n");
	}
	for (int i = 0; i <= FRAME_X; i++)			         //게임 틀의 마지막 줄
		printf("■");
	printf("\n");
	SetColor(WHITE);
}