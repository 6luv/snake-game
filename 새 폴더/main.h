//����ϴ� ��� �������

#ifndef GAME_H
# define GAME_H

# define W 87
# define w 119
# define A 65
# define a 97
# define S 83
# define s 115
# define D 68
# define d 100
# define LEFT 75
# define RIGHT 77
# define UP 72     //��Ű
# define DOWN 80   //��Ű		
# define SPACE 3		//����Ű (�����̽���)
# define FRAME_X 33		//����â ũ��
# define FRAME_Y 30
# define ESC 27

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

//�Լ� ����

void Init();            //�� �ʱ�ȭ
void CountDown();          //���� ���� �� ī��Ʈ�ٿ�
void gotoxy(int x, int y); //���ϴ� ��ǥ�� �̵�
void SetColor(int);	       //���ڻ� ����
int KeyControl();          //����Ű �Է� �ޱ�
void DrawTitle();          //Ÿ��Ʋ ���
int MenuDraw();            //�޴� ���
void CursorView();         //Ŀ�� �����
void DrawFrame();          //���� Ʋ �����
void DrawScore();          //������
void DrawSnake();        //�� �����
void GameOver();           //���ӿ���
void DrawFood();           //���� ����
int DrawTime();

//-------------------------------------- ��� �ҽ����Ͽ��� ��� ������ ����
extern int map[FRAME_Y + 1][FRAME_X * 2 + 1];
extern int g_sec;



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