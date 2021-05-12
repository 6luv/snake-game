//사용하는 모든 헤더파일

#ifndef GAME_H
# define GAME_H

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

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

typedef struct snake {
	int cx, cy;                //현재 좌표
	int oldx, oldy;            //이전 좌표
	int index;                 //먹이, 맵 구분하기 위해
	char direction;            //방향
	struct snake* next;        //다음 노드
} SNAKE;

//SNAKE* head_1, * tail_1;     //1P head, tail
SNAKE* head_2, * tail_2;       //2P head, tail

//함수 선언
void Init(void);               //맵 초기화
void GetPressedKey(int keys[256]);   //키 입력 처리
void CountDown(void);          //게임 시작 전 카운트다운
void gotoxy(int x, int y);     //원하는 좌표로 이동
void SetColor(int fontcolor);  //글자색 설정
void DrawTitle(void);          //타이틀 출력
void CursorView(void);         //커서 지우기
void DrawFrame(void);          //게임 틀 만들기
void DrawScore(void);          //점수판
//void DrawSnake1(int keys[256]);        //뱀 만들기
void DrawSnake2(int keys[256]);        //2P 뱀 만들기
void GameOver(void);           //게임오버
void GameRules(void);          //게임방법
void DrawFood(void);           //먹이 생성
void AddSnake();           //뱀의 길이 늘리는 함수
int MenuDraw(void);            //메뉴 출력
int DrawTime(void);            //남은 시간
int Pause(int num);            //일시정지, 타이틀로
void CoordMove(void);               //뱀의 좌표 이동

//-------------------------------------- 전역 변수
int map[FRAME_Y + 1][FRAME_X * 2 + 1];   //맵
int g_sec;                               //시간
int keys[256];                           //키 입력 처리


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