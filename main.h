#ifndef GAME_H
# define GAME_H

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

# define FRAME_X 33		//����â ũ��
# define FRAME_Y 28

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
	int cx, cy;								//���� ��ǥ
	int oldx, oldy;							//���� ��ǥ
	char direction;							//����
	struct snake* next;						//���� ���
} SNAKE;

SNAKE* head_1, * tail_1;					//1P head, tail
SNAKE* head_2, * tail_2;					//2P head, tail

//�Լ� ����
void Init(void);							//�� �ʱ�ȭ
void GetPressedKey(int keys[256]);			//Ű �Է� ó��
void CountDown(void);						//ī��Ʈ�ٿ�
void gotoxy(int x, int y);					//��ǥ �̵�
void SetColor(int fontcolor);				//���ڻ� ����
void DrawTitle(void);					    //Ÿ��Ʋ ���
void CursorView(void);						//Ŀ�� �����
void DrawFrame(void);						//���� Ʋ
void DrawScore(void);						//������
int DrawSnake1(int keys[256]);				//1P �� ó��
int DrawSnake2(int keys[256]);				//2P �� ó��
void GameOver(int);							//���� ����
void GameRules(void);						//���� ���
void DrawFood(void);						//���� ����
int MenuDraw(void);							//�޴� ���
int DrawTime(void);							//�ð� ���
int Pause(int num);							//�Ͻ�����, Ÿ��Ʋ
SNAKE* AddSnake(SNAKE*);					//���� ��� �߰�
SNAKE* CoordMove(SNAKE*, SNAKE*);			//���� ��ǥ �̵�

//-------------------------------------- ���� ����
int map[FRAME_Y + 1][FRAME_X * 2 + 1];		//��
int score_1p, score_2p;						//����
int g_sec;									//�ð�
int keys[256];								//Ű �Է�
int food_cut, food_num;					    //����

//-------------------------------------- �ֿܼ��� ����� �� ����
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
