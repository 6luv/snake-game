#include "main.h"

//-------------------------------------- 초기화
void Init()
{
	system("cls");										//화면 지움
	g_sec = 60;											//시간 초기화
	for (int y = 0; y < FRAME_Y + 1; y++)				//맵 초기화
	{
		for (int x = 0; x < FRAME_X * 2 + 1; x++)
			map[y][x] = 0;
	}

	score_1p = 0;										//1P 점수 초기화
	score_2p = 0;										//2P 점수 초기화

	food_cut = 0;										//먹이 개수 카운트
	food_num = 5;										//먹이 개수 제한

	head_1 = (SNAKE*)malloc(sizeof(SNAKE));				//1P 동적 할당
	if (head_1 == NULL)									//할당에 실패하면 종료
		exit(1);
	head_2 = (SNAKE*)malloc(sizeof(SNAKE));				//2P 동적 할당
	if (head_2 == NULL)									//할당에 실패하면 종료
		exit(1);

	head_1->cx = 10;									//1P head x좌표 초기화
	head_1->cy = 15;									//1P head x좌표 초기화
	head_1->direction = UP;								//처음 시작 방향
	tail_1 = head_1;									//tail은 head로 초기화

	head_2->cx = 50;									//2P head x좌표 초기화
	head_2->cy = 15;									//2P head x좌표 초기화
	head_2->direction = DOWN;							//처음 시작 방향
	tail_2 = head_2;									//tail은 head로 초기화

	for (int i = 0; i < 3; i++)							//몸 길이 초기화
	{
		tail_1 = AddSnake(tail_1);						//1P 몸통 생성
		tail_2 = AddSnake(tail_2);						//2P 몸통 생성
	}
}

//-------------------------------------- 뱀 좌표 이동
SNAKE* CoordMove(SNAKE* head, SNAKE* tail)
{
	SNAKE* current;										//current 포인터로 비교하기 위해
	current = (SNAKE*)malloc(sizeof(SNAKE));			//구조체 동적 할당
	if (current == NULL)								//할당에 실패하면 종료
		exit(1);

	head->oldx = head->cx;								//이전 x좌표는 현재 x좌표를 받음
	head->oldy = head->cy;								//이전 y좌표는 현재 y좌표를 받음

	for (current = head->next; current != tail; current = current->next)  //tail전 까지 몸통 좌표 이동
	{
		current->oldx = current->cx;					//이전 x좌표는 현재 x좌표를 받음
		current->oldy = current->cy;					//이전 y좌표는 현재 y좌표를 받음
	}

	current = head->next;								//포인터 초기화
	current->cx = head->oldx;							//몸통 현재 x좌표는 헤드의 이전 x좌표
	current->cy = head->oldy;							//몸통 현재 y좌표는 헤드의 이전 y좌표

	for (current = head->next; current != tail; current = current->next)   //tail전 까지 몸통 좌표 이동
	{
		current->next->cx = current->oldx;				//다음 몸통의 현재 x좌표는 전 몸통의 이전 x좌표
		current->next->cy = current->oldy;				//다음 몸통의 현재 y좌표는 전 몸통의 이전 y좌표
	}
	return head;
}

//-------------------------------------- 뱀 몸통 노드 생성
SNAKE* AddSnake(SNAKE* tail)
{
	SNAKE* newnode;										//새로운 노드
	newnode = (SNAKE*)malloc(sizeof(SNAKE));			//구조체 동적 할당
	if (newnode == NULL)								//할당에 실패하면 종료
		exit(1);
	tail->next = newnode;								//tail의 다음 노드 연결
	newnode->cx = 2;									//x 좌표 초기화
	newnode->cy = 1;									//y 좌표 초기화
	newnode->next = NULL;								//새로운 노드의 next는 NULL
	tail = newnode;										//tail 포인터 이동
	return tail;
}

//-------------------------------------- 1P 뱀 처리
int DrawSnake1(int keys[256])
{
	SNAKE* current;
	current = (SNAKE*)malloc(sizeof(SNAKE));			//구조체 동적 할당

	switch (head_1->direction)							//head의 방향에 따라 분류
	{
	case LEFT:
	case RIGHT:											//왼쪽, 오른쪽일 때
		if (keys['W'] != keys['S'])						//위 아래가 같이 입력되면 종료
		{
			if (keys['W'])								//위 방향키가 눌리면 head의 방향 변경
				head_1->direction = UP;
			else										//아래 방향키가 눌리면 head의 방향 변경
				head_1->direction = DOWN;
		}
		break;
	case UP:
	case DOWN:											//위쪽, 아래쪽일 때
		if (keys['A'] != keys['D'])						//왼쪽 오른쪽이 같이 입력되면 종료
		{
			if (keys['A'])								//왼쪽 방향키가 눌리면 head의 방향 변경
				head_1->direction = LEFT;
			else									    //오른쪽 방향키가 눌리면 head의 방향 변경
				head_1->direction = RIGHT;
		}
		break;
	}

	switch (head_1->direction)						    //head의 방향에 따라 분류
	{
	case LEFT:										    //왼쪽 방향일 때
		if (head_1->cx >= 0)						    //맵 범위를 벗어나지 않도록
		{
			head_1 = CoordMove(head_1, tail_1);		    //뱀의 좌표 이동
			head_1->cx -= 2;						    //왼쪽으로 이동하기 때문에 -2 (특수 문자는 2칸 차지)
		}
		break;
	case RIGHT:										    //오른쪽 방향일 때
		if (head_1->cx <= FRAME_X * 2)				    //맵 범위를 벗어나지 않도록
		{
			head_1 = CoordMove(head_1, tail_1);		    //뱀의 좌표 이동
			head_1->cx += 2;						    //오른쪽으로 이동하기 때문에 +2 (특수 문자는 2칸 차지)
		}
		break;
	case UP:											//위쪽 방향일 때
		if (head_1->cy >= 0)							//맵 범위를 벗어나지 않도록
		{
			head_1 = CoordMove(head_1, tail_1);		    //뱀의 좌표 이동
			head_1->cy--;						        //위로 이동하기 때문에 -1
		}
		break;
	case DOWN:								            //아래쪽 방향일 때
		if (head_1->cy <= FRAME_Y)		                //맵 범위를 벗어나지 않도록
		{
			head_1 = CoordMove(head_1, tail_1);         //뱀의 좌표 이동
			head_1->cy++;                               //아래로 이동하기 때문에 +1
		}
		break;
	}

	gotoxy(head_1->cx, head_1->cy);                     //head의 좌표로 이동
	printf("□");
	for (current = head_1->next; current != tail_1; current = current->next)  //tail전 까지 이동
	{
		gotoxy(current->cx, current->cy);               //몸통의 좌표로 이동
        map[current->cy][current->cx] = 1;          //몸통 초기화
		printf("□");
	}
	gotoxy(tail_1->cx, tail_1->cy);                     //tail의 좌표로 이동
    map[tail_1->cy][tail_1->cx] = 0;                //꼬리 초기화

	printf("  ");

	if (map[head_1->cy][head_1->cx] == 2)               //먹이와 만나면
	{
		tail_1 = AddSnake(tail_1);                      //노드 하나 추가
		score_1p += 10;                                 //점수 추가
		food_cut--;                                     //먹이 카운트 감소
	}
	if (map[head_1->cy][head_1->cx] == 1)               //벽, 몸통과 만나면
	{
		GameOver(2);                                    //2P 승리
		return 0;                                       //종료
	}
	return 1;
}

//-------------------------------------- 2P 뱀 처리
int DrawSnake2(int keys[256])
{
	SNAKE* current;
	current = (SNAKE*)malloc(sizeof(SNAKE));

	switch (head_2->direction)                          //head의 방향에 따라 분류
	{
	case LEFT:                                          //왼쪽, 오른쪽일 때
	case RIGHT:
		if (keys[VK_UP] != keys[VK_DOWN])               //위 아래가 같이 입력되면 종료
		{
			if (keys[VK_UP])
				head_2->direction = UP;                 //위 방향키가 눌리면 head의 방향 변경
			else
				head_2->direction = DOWN;               //아래 방향키가 눌리면 head의 방향 변경
		}
		break;
	case UP:                                            //위쪽, 아래쪽일 때
	case DOWN:
		if (keys[VK_LEFT] != keys[VK_RIGHT])            //왼쪽 오른쪽이 같이 입력되면 종료
		{
			if (keys[VK_LEFT])                          //왼쪽 방향키가 눌리면 head의 방향 변경
				head_2->direction = LEFT;
			else                                        //오른쪽 방향키가 눌리면 head의 방향 변경
				head_2->direction = RIGHT;
		}
		break;
	}

	switch (head_2->direction)                          //head의 방향에 따라 분류
	{
	case LEFT:                                          //왼쪽 방향일 때
		if (head_2->cx >= 0)                            //맵 범위를 벗어나지 않도록
		{
			head_2 = CoordMove(head_2, tail_2);         //뱀의 좌표 이동
			head_2->cx -= 2;                            //왼쪽으로 이동하기 때문에 -2 (특수 문자는 2칸 차지)
		}
		break;
	case RIGHT:                                         //오른쪽 방향일 때
		if (head_2->cx <= FRAME_X * 2)                  //맵 범위를 벗어나지 않도록
		{
			head_2 = CoordMove(head_2, tail_2);         //뱀의 좌표 변경
			head_2->cx += 2;                            //오른쪽으로 이동하기 때문에 +2 (특수 문자는 2칸 차지)
		}
		break;
	case UP:                                            //위쪽 방향일 때
		if (head_2->cy >= 0)                            //맵 범위를 벗어나지 않도록
		{
			head_2 = CoordMove(head_2, tail_2);         //뱀의 좌표 변경
			head_2->cy--;                               //위로 이동하기 때문에 -1
		}
		break;
	case DOWN:                                          //아래쪽 방향일 때
		if (head_2->cy <= FRAME_Y)                      //맵 범위를 벗어나지 않도록
		{
			head_2 = CoordMove(head_2, tail_2);         //뱀의 좌표 변경
			head_2->cy++;                               //아래로 이동하기 때문에 +1
		}
		break;
	}

	gotoxy(head_2->cx, head_2->cy);                     //head의 좌표로 이동
	printf("▣");                                       //출력
	for (current = head_2->next; current != tail_2; current = current->next)  //tail전 까지 이동
	{
		gotoxy(current->cx, current->cy);               //몸통의 좌표로 이동
        map[current->cy][current->cx] = 1;          //몸통 초기화
		printf("▣");                                   //출력
	}

	gotoxy(tail_2->cx, tail_2->cy);                     //tail의 좌표로 이동
    map[tail_2->cy][tail_2->cx] = 0;                //꼬리 초기화

	printf("  ");                                       //마지막 꼬리 지움
	if (map[head_2->cy][head_2->cx] == 2)               //먹이와 만나면
	{
		tail_2 = AddSnake(tail_2);                      //노드 하나 추가
		score_2p += 10;                                 //점수 추가
		food_cut--;                                     //먹이 카운트 감소
	}
	if (map[head_2->cy][head_2->cx] == 1)               //벽, 몸통과 만나면
	{
		GameOver(1);                                    //1P 승리
		return 0;                                       //종료
	}
	if (head_1->cx == head_2->cx && head_1->cy == head_2->cy)  //서로의 머리가 만나면 점수가 더 높은 뱀이 승리
	{
		if (score_1p > score_2p)                        //1P의 점수가 높으면 1P 승리
			GameOver(1);
		else if (score_1p == score_2p)                  //1P와 2P의 점수가 같으면 무승부
			GameOver(0);
		else                                            //2P의 점수가 높으면 2P 승리
			GameOver(2);
		return 0;                                       //종료
	}
	return 1;
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
	SetColor(RED);
	printf("\n\n                                            [GAME OVER]                      \n");
	SetColor(WHITE);
	printf("\n\n                                         1. 서로 닿았을 때                \n");
	printf("\n\n                                         2. 벽에 닿았을 때                \n");
	printf("\n\n                                      3. 시간이 종료되었을 때                \n");
	gotoxy(79, 28);
	SetColor(YELLOW);
	printf("SPACE를 눌러주세요.");
	SetColor(WHITE);
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
		SetColor(BLUE);                                   //파란색 벽
		printf("■");						 	          //벽 프린트
	}

	for (int i = 0; i <= FRAME_X * 2; i++)			      //위의 벽 초기화
		map[0][i] = 1;
	printf("\n");

	for (int i = 0; i <= FRAME_Y-1; i++)	       		  //게임 틀의 첫 줄과 마지막 줄 사이
	{
		printf("■");						 	          //벽 프린트
		map[i][0] = 1;                                    //왼쪽 벽 초기화
		map[i][1] = 1;			                          //왼쪽 벽 초기화
		gotoxy(FRAME_X * 2, i);                           //오른쪽 벽으로 이동
		printf("■");						 	          //벽 프린트
		map[i][FRAME_X * 2 - 1] = 1;                      //오른쪽 벽 초기화
		map[i][FRAME_X * 2] = 1;                          //오른쪽 벽 초기화
		printf("\n");
	}

	for (int i = 0; i <= FRAME_X; i++)			          //게임 틀의 마지막 줄
		printf("■");						 	          //벽 프린트

	for (int i = 0; i <= FRAME_X * 2; i++)
		map[FRAME_Y][i] = 1;                              //아래 벽 초기화
	SetColor(WHITE);
}
