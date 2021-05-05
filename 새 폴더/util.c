//점수판, 시간, 먹이, 게임오버
#include "main.h"

//-------------------------------------- 전역변수
int food_num = 10; //생성될 먹이 개수
int food_cut = 0;  //현재 생성된 먹이 개수
int g_sec;    //시간 제한
int map[FRAME_Y + 1][FRAME_X * 2 + 1]; //맵

//-------------------------------------- 게임 타이틀
void DrawTitle()
{
	system("title SNAKE GAME | mode con cols=100 lines=30"); //콘솔창 크기와 콘솔창 제목
	printf("\n\n\n\n\n\n");
	SetColor(RED);
	printf("\t\t              ############    ## ######   ##   ## ################# \n");
	printf("\t\t             ##       ####   ## ##   ##  ##  ##  ##  \n");
	printf("\t\t              ###    ## ##  ## #######  ######  ###### \n");
	printf("\t\t               ##   ##  ## ## ##    ## ##   ## ##\n");
	printf("\t\t################   ##   #### ##    ## ##     ########\n");
	SetColor(WHITE);
}

//-------------------------------------- 카운트다운
void CountDown()
{
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t         ########## \n");
	printf("\t\t\t\t\t                ##  \n");
	printf("\t\t\t\t\t       ##########   \n");
	printf("\t\t\t\t\t              ##    \n");
	printf("\t\t\t\t\t     ##########     \n");
	Sleep(1000);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t          ########    \n");
	printf("\t\t\t\t\t        ###     ##    \n");
	printf("\t\t\t\t\t             ###      \n");
	printf("\t\t\t\t\t          ###         \n");
	printf("\t\t\t\t\t     ############     \n");
	Sleep(1000);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t          #####    \n");
	printf("\t\t\t\t\t        ###   ##    \n");
	printf("\t\t\t\t\t             ##     \n");
	printf("\t\t\t\t\t           ###      \n");
	printf("\t\t\t\t\t     ############   \n");
	Sleep(1000);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	SetColor(RED);
	printf("\t\t               ####### #########  #####   ###### ######### \n");
	printf("\t\t             ##           ##    ##   ##  ##   ##    ##  \n");
	printf("\t\t              ####       ##    ######## #######    ## \n");
	printf("\t\t                 ##     ##    ##    ## ##    ##   ## \n");
	printf("\t\t           #######     ##    ##    ## ##     ##  ##  \n");
	Sleep(1000);
	SetColor(WHITE);
}

//-------------------------------------- 메뉴
int MenuDraw()
{
	int x = 46;
	int y = 18;
	gotoxy(x - 2, y);
	SetColor(BLUE);					//파란색으로
	printf("→");
	SetColor(WHITE);				//흰색으로
	printf(" 게임시작");
	gotoxy(x, y + 2);
	printf(" 게임방법");
	gotoxy(x, y + 4);
	printf(" 게임종료");
	gotoxy(68, 28);
	SetColor(YELLOW);				//노란색으로
	printf("민쥬진 (최우진, 장민주, 김지우)");
	SetColor(WHITE);				//흰색으로
	while (1)
	{
		int n = KeyControl();		 //방향키를 입력 받음
		switch (n)
		{
		case UP: {					// ↑키가 입력됐을 때
			if (y > 18)				// 게임시작 위로 못 가도록
			{
				gotoxy(x - 2, y);
				printf("  ");		 // >을 지우고
				gotoxy(x - 2, y -= 2);
				SetColor(BLUE);		 //파란색으로 다시 씀
				printf("→");
				SetColor(WHITE);
			}
			break;
		}
		case DOWN: {				 // ↓키가 입력됐을 때
			if (y < 22)				// 게임종료 아래로 못 가도록
			{
				gotoxy(x - 2, y);
				printf("  ");		// >을 지우고
				gotoxy(x - 2, y += 2);
				SetColor(BLUE);		//파란색으로 다시 씀
				printf("→");
				SetColor(WHITE);
			}
			break;
		}
		case SPACE:
			return y - 18;			 // 0(게임시작), 2(게임방법), 4(종료)를 반환
		}
	}
}

//-------------------------------------- 방향키 입력
int KeyControl()
{
	if (_kbhit())					//눌러진 키가 있나 확인
	{
		char tmp = _getch();		 //방향키 입력 
		if (tmp == -32)				//특수키이면 (방향키)
		{
			tmp = _getch();			//특수키는 값이 두개이기 때문에 다시 값 저장
			if (tmp == UP)			// ↑가 선택 되었을 때
				return	UP;
			else if (tmp == DOWN)		// ↓가 선택 되었을 때
				return DOWN;
		}
		else if (tmp == ' ')		//스페이스바 선택 되었을 때
			return SPACE;
	}
	return 0;						//눌러진 키가 없으면
}

//-------------------------------------- 점수판
void DrawScore()
{
	int score_1p = 0, score_2p = 0;  //초기화
	
	gotoxy(73, 10);
	printf("  [ 1P ]         [ 2P ]");
	gotoxy(73, 12);
	printf("   %2d       :     %2d", score_1p, score_2p);
	

}




//-------------------------------------- 시간, 일시정지
int DrawTime()
{
	char tmp;
	gotoxy(79, 20);
	printf("일시 정지 : q");
	gotoxy(76, 22);
	printf("타이틀로 이동 : esc");
	if (_kbhit())							//입력된 키가 있나 확인
	{
		tmp = _getch();						//입력이 들어오면
		if (tmp == 'q' || tmp == 'Q')						//q일 때
		{
			gotoxy(77, 3);
			SetColor(RED);
			printf("┌--------------┐ ");
			gotoxy(77, 4);
			printf("│ 일시정지 상태│ ");
			gotoxy(77, 5);
			printf("└--------------┘ ");
			system("pause > null");			//시스템 멈추기(아무것도 출력 안 되게)
		}
		else if (tmp == ESC)                 //esc일 때
		{
			gotoxy(77, 3);
			SetColor(BLUE);
			printf("┌--------------┐ ");
			gotoxy(77, 4);
			printf("│ 타이틀로 이동│ ");
			gotoxy(77, 5);
			printf("└--------------┘ ");
			gotoxy(77, 6);
			printf(" YES : y  NO : n ");
			system("pause > null");			//시스템 멈추기(아무것도 출력 안 되게)
			tmp = _getch();
			if (tmp == 'y' || tmp == 'Y')                 //y가 들어오면 타이틀로 이동
				return 0;
		}
		SetColor(BLACK);					//q가 아니면 검정색으로 출력
		gotoxy(77, 3);
		printf("                 ");
		gotoxy(77, 4);
		printf("                 ");
		gotoxy(77, 5);
		printf("                  ");
		gotoxy(77, 6);
		printf("                  ");
		SetColor(WHITE);
		
	}
	if (g_sec >= 0)							//시간이 남아있을 때
	{
		gotoxy(77, 15);	
		printf("남은 시간 : %2d 초", g_sec);	
		Sleep(1000);						//1초
		g_sec--;			
	}
	else                                    //시간이 종료되면  
	{
		GameOver();							//게임 종료
		return 0;							//0을 반환
	}
	return 1;								//1을 반환
}

//-------------------------------------- 먹이 출력
void DrawFood()
{
	int food_x, food_y;
	srand(time(NULL));						//난수를 위해

	food_x = (rand() % 64) + 1;				//x좌표 계산
	food_y = (rand() % 27) + 1;             //y좌표 계산
	
	if (food_x % 2 == 1)					//좌표가 홀수일 때
	{
		map[food_y][food_x + 1] = 2;        //■는 2바이트라서 1추가   
		map[food_y][food_x + 2] = 2;        //먹이가 생성되는 곳은 2로 초기화
		food_x += 1;                        //홀수면 x좌표에 1을 더함
	}
	else                                    //x좌표가 짝수일 때
	{
		map[food_y][food_x] = 2;            //2로 초기화
		map[food_y][food_x + 1] = 2;        //■는 2바이트라서 1더한 곳에 초기화
	}
	
	gotoxy(food_x, food_y);                 //좌표로 가서 먹이 출력
	SetColor(YELLOW);
	printf("◎");	 
	SetColor(WHITE);
	food_cut += 1;							//생성된 먹이 개수 추가
	food_num -= 1;							//총 먹이 개수 감소
}

//-------------------------------------- 게임 종료
void GameOver()
{
	system("cls");
	printf("\n\n\n\n\n");
	SetColor(RED);
	printf("\t\t  #######  #####     ### ###   #######  ####### ##    ## ###### ######      \n");
	printf("\t\t ##       ##  ##    ## ## ##   ##      ##    ## ##   ## ##     ##   ##     \n");
	printf("\t\t##  ###  #######   ##  ## ##  ######  ##     ## ##  ## ###### #######        \n");
	printf("\t\t##   ## ##    ##  ##   #  ##  ##      ##    ##  ## ## ##     ##   ##      \n");
	printf("\t\t###### ##     ## ##       ## ######   #######   #### ###### ##    ##  \n");
	SetColor(WHITE);
	printf("\n\n\n\n");
	/*
	SetColor(BLUE);
	printf("\t\t\t    ┌-----------------------------------------┐ \n");
	printf("\t\t\t    │     *****   ******* **      **      **  │ \n");
	printf("\t\t\t    │    **  **   **   **  **    ****    **   │ \n");
	printf("\t\t\t    │        **   *******  **   **  **   **   │ \n");
	printf("\t\t\t    │        **   **        **  **  **  **    │ \n");
	printf("\t\t\t    │   ********* **         *****   *****    │ \n");
	printf("\t\t\t    └-----------------------------------------┘ \n");
	SetColor(WHITE);
	*/
	/*
	SetColor(BLUE);
	printf("\t\t\t    ┌-----------------------------------------┐ \n");
	printf("\t\t\t    │    ****   ******* **      **      **    │ \n");
	printf("\t\t\t    │   **  **  **   **  **    ****    **     │ \n");
	printf("\t\t\t    │      **   *******  **   **  **   **     │ \n");
	printf("\t\t\t    │     **    **        **  **  **  **      │ \n");
	printf("\t\t\t    │  *******  ***        *****   *****      │ \n");
	printf("\t\t\t    └-----------------------------------------┘ \n");
	SetColor(WHITE);
	*/

	SetColor(BLUE);
	printf("\t\t\t    ┌-----------------------------------------┐ \n");
	printf("\t\t\t    │     ******    *****     ***   **  **  **│ \n");
	printf("\t\t\t    │    **    **  **   **  **  ** **  **  ** │ \n");
	printf("\t\t\t    │   **     ** ******   ****** **  **  **  │ \n");
	printf("\t\t\t    │  **     ** **    ** **   ** ** ** **    │ \n");
	printf("\t\t\t    │ ********  **     ****   **  *** ***     │ \n");
	printf("\t\t\t    └-----------------------------------------┘ \n");
	SetColor(WHITE);

	printf("\n\t\t\t\t\t      Score : \n");


	gotoxy(79, 28);
	SetColor(YELLOW); //노란색으로
	printf("SPACE를 눌러주세요.");
	SetColor(WHITE); //흰색으로
	while (1)
	{
		if (KeyControl() == SPACE) {   //SPACE가 입력될 때까지 대기
			break;
		}
	}
}