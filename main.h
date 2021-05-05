//사용하는 모든 헤더파일

#ifndef GAME_H
# define GAME_H

# define UP 1			//↑키
# define DOWN 2			//↓키
# define SPACE 3		//선택키 (스페이스바)
# define FRAME_X 33		//게임창 크기
# define FRAME_Y 30

#endif

#ifndef STDIO_H
# define STDIO_H

#include <stdio.h>

#endif
#ifndef STDLIB_H
# define STDLIB_H

#include <stdlib.h>

#endif

#ifndef STRING_H
# define STRING_H

#include <string.h>

#endif

#ifndef CONIO_H
# define CONIO_H

#include <conio.h>

#endif

#ifndef WINDOWS_H
# define WINDOWS_H

#include <Windows.h>

#endif

#ifndef TIME_H
# define TIME_H

#include <time.h>

#endif

#define VK_Q 0x51


//함수 선언
void Init();            //맵 초기화
void CountDown();          //게임 시작 전 카운트다운
void gotoxy(int x, int y); //원하는 좌표로 이동
void SetColor(int);	       //글자색 설정
int KeyControl();          //방향키 입력 받기
void DrawTitle();          //타이틀 출력
int MenuDraw();            //메뉴 출력
void CursorView();         //커서 지우기
void DrawFrame();          //게임 틀 만들기
void DrawScore();          //점수판
void DrawSnake();        //뱀 만들기
void GameOver();           //게임오버
void DrawFood();           //먹이 생성
int DrawTime();

//-------------------------------------- 모든 소스파일에서 사용 가능한 변수
extern int map[FRAME_Y + 1][FRAME_X * 2 + 1];
extern int g_sec;

//-------------------------------------- 콘솔에서 사용할 색 선언
enum { 
	BLACK,
	D_BLUE,
	D_GREEN,
	D_SKYBLUE,
	D_RED,
	D_VIOLET,
	D_YELLOW,
	GRAY,
	D_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};