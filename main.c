#include "main.h" 

//-------------------------------------- 커서 숨기기
void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, }; //구조체 선언하고 세팅값을 줌
	cursorInfo.dwSize = 1; //커서 두께
	cursorInfo.bVisible = FALSE; //커서 노출 여부, Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo); //콘솔창에서 커서의 형태 설정
}

//-------------------------------------- 컬러 지정
void SetColor(int fontcolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fontcolor); //콘솔창의 색을 변경해줌
}

//-------------------------------------- 좌표 이동
void gotoxy(int x, int y) 
{
	COORD Cur;                                 //콘솔 화면에서 좌표를 정의
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur); //콘솔창에서 원하는 위치로 커서 이동
}

int main()
{
	CursorView();                              //커서 지우는 함수
	
	while (1)
	{
		DrawTitle();                           //타이틀 표시
		int menu = MenuDraw();                 //메뉴 표시
//-------------------------------------- 게임 시작
		if (menu == 0)
		{
			Init();                             //초기화
			int last_food_created = 0;          //마지막으로 먹이가 생성된 시간 변수
			int last_time = 0;                  //시간을 위한 변수
			clock_t last_snake = 0;
			CountDown();                        //게임 시작 전 카운트다운
			DrawFrame();                        //게임틀 
			DrawScore();                        //점수판
			while (1)                           //제한된 시간 동안
			{
				clock_t current_time = clock(); //현재 시간 저장
				if ((double)(current_time - last_snake) / CLOCKS_PER_SEC >= 0.3) //0.5초마다 뱀 움직임
				{
					DrawSnake();                 //이동
					last_snake = current_time;  //마지막으로 움직인 시간 저장
				}
				if ((double)(current_time - last_food_created)/CLOCKS_PER_SEC >= 2) //2초마다 먹이 생성
				{
					DrawFood();                 //먹이 생성
					last_food_created = current_time;  //마지막으로 생성된 시간 저장
				}
				if ((double)(current_time - last_time) / CLOCKS_PER_SEC >= 1) //1초마다 시간 체크
				{
					if (DrawTime())             //시간이 남아있을 경우
						last_time = current_time;  //마지막 시간 저장
					else                        //시간이 끝났을 경우
						break;                  //종료
				}
			}			
		}
//-------------------------------------- 게임 방법
		else if (menu == 2)  
		{
			GameRules();       //게임 방법
		}
//-------------------------------------- 게임 종료
		else
		{
			gotoxy(68, 29);    //좌표로 이동
			exit(1);           //게임 종료
		}
		system("cls");         //화면 지움
	}
	return 0;
}