//������ ��κ� ���
#include "main.h"

//-------------------------------------- �ʱ�ȭ
void Init()
{
	system("cls");                                  //ȭ�� ����
	g_sec = 60;                                    //�ð� �ʱ�ȭ
	int map[FRAME_Y + 1][FRAME_X * 2 + 1] = { 0 };  //���� 0���� �ʱ�ȭ
	for (int y = 0; y < FRAME_Y - 1; y++)
	{
		for (int x = 0; x < FRAME_X * 2 + 2; x++)
		{
			if (y == 0 || y == FRAME_Y - 2 || x == 0 || x == 1 || x == FRAME_X * 2 || x == FRAME_X * 2 + 1)  //����Ʋ�� 1�� �ʱ�ȭ
				map[y][x] = 1;                      //�� �׵θ��� 1�� �ʱ�ȭ
		}
	}

	head_2->cx = 50;                                //2P head x��ǥ �ʱ�ȭ
	head_2->cy = 15;                                //2P head x��ǥ �ʱ�ȭ
	head_2->index = 0;                              //head�� ��?
	head_2->direction = LEFT;                       //ó�� ���� ����
	tail_2 = head_2;                                //tail�� head�� �ʱ�ȭ

	for (int i = 0; i < 3; i++)                     //�� ���� �ʱ�ȭ
		AddSnake();

}

void CoordMove()                                         //��ǥ �̵� �Լ�
{
	SNAKE* current;                                 //current �����ͷ� ���ϱ� ����
	current = (SNAKE*)malloc(sizeof(SNAKE));        //����ü ���� �Ҵ�
	if (current == NULL)                            //�Ҵ翡 �����ϸ� ����
		exit(1);

	head_2->oldx = head_2->cx;                      //���� x��ǥ�� ���� x��ǥ�� ����
	head_2->oldy = head_2->cy;                      //���� y��ǥ�� ���� y��ǥ�� ����

	for (current = head_2->next; current != tail_2; current = current->next)  //tail�� ���� ���� ��ǥ �̵�
	{
		current->oldx = current->cx;                //���� x��ǥ�� ���� x��ǥ�� ����
		current->oldy = current->cy;                //���� y��ǥ�� ���� y��ǥ�� ����
	}

	current = head_2->next;                         //������ �ʱ�ȭ
	current->cx = head_2->oldx;                     //���� ���� x��ǥ�� ����� ���� x��ǥ
	current->cy = head_2->oldy;                     //���� ���� y��ǥ�� ����� ���� y��ǥ

	for (current = head_2->next; current != tail_2; current = current->next)   //tail�� ���� ���� ��ǥ �̵�
	{
		current->next->cx = current->oldx;          //���� ������ ���� x��ǥ�� �� ������ ���� x��ǥ
		current->next->cy = current->oldy;          //���� ������ ���� y��ǥ�� �� ������ ���� y��ǥ
	}
}

void AddSnake()                                     //���� ��� �߰�
{
	SNAKE* newnode;                                 //���ο� ��� 
	newnode = (SNAKE*)malloc(sizeof(SNAKE));        //����ü ���� �Ҵ�
	if (newnode == NULL)                            //�Ҵ翡 �����ϸ� ����
		exit(1);
	tail_2->next = newnode;                         //tail�� ���� ��� ����
	newnode->next = NULL;                           //���ο� ����� next�� NULL
	tail_2 = newnode;                               //tail ������ �̵�
	tail_2->index = -1;                             //tail�� �� ����
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
	printf("��");
	for (current = head_1->next; current != tail_1; current = current->next)
	{
		gotoxy(current->cx, current->cy);
		printf("��");
	}
	gotoxy(tail_1->cx, tail_1->cy);
	printf("  ");
}
*/

void DrawSnake2(int keys[256])
{
	SNAKE* current;
	current = (SNAKE*)malloc(sizeof(SNAKE));

	switch (head_2->direction)                          //head�� ���⿡ ���� �з�
	{
	case LEFT:                                          //����, �������� ��
	case RIGHT:
		if (keys[VK_UP] != keys[VK_DOWN])               //�� �Ʒ��� ���� �ԷµǴ� �� ����
		{
			if (keys[VK_UP]) head_2->direction = UP;    //�� ����Ű�� ������ head�� ���� ����
			else head_2->direction = DOWN;              //�Ʒ� ����Ű�� ������ head�� ���� ����
		}
		break;                                          //�� �Ʒ��� ���� �ԷµǸ� ����
	case UP:                                            //����, �Ʒ����� ��
	case DOWN:
		if (keys[VK_LEFT] != keys[VK_RIGHT])            //���� �������� ���� �ԷµǴ� �� ����
		{
			if (keys[VK_LEFT]) head_2->direction = LEFT;//���� ����Ű�� ������ head�� ���� ����
			else head_2->direction = RIGHT;             //������ ����Ű�� ������ head�� ���� ����
		}
		break;                                          //���� �������� ���� �ԷµǸ� ����
	}

	switch (head_2->direction)                          //head�� ���⿡ ���� �з�
	{
	case LEFT:                                          //���� ������ ��
		if (head_2->cx - 2 > 0)                         //�� ������ ����� �ʵ���
		{ 
			CoordMove();                                     //���� ��ǥ ����
			head_2->cx -= 2;                            //�������� �̵��ϱ� ������ -2 (Ư�� ���ڴ� 2ĭ ����)
		}
		break;                                          //�� ������ ����� ����
	case RIGHT:                                         //������ ������ ��
		if (head_2->cx + 2 <= FRAME_X*2)                //�� ������ ����� �ʵ���
		{
			CoordMove();                                     //���� ��ǥ ����
			head_2->cx += 2;                            //���������� �̵��ϱ� ������ +2 (Ư�� ���ڴ� 2ĭ ����)
		}
		break;                                          //�� ������ ����� ����
	case UP:                                            //���� ������ ��
		if (head_2->cy  > 0)                            //�� ������ ����� �ʵ���
		{
			CoordMove();                                     //���� ��ǥ ����
			head_2->cy--;                               //���� �̵��ϱ� ������ -1
		}
		break;                                          //�� ������ ����� ����
	case DOWN:                                          //�Ʒ��� ������ ��
		if (head_2->cy < FRAME_Y - 2)                   //�� ������ ����� �ʵ���
		{
			CoordMove();                                     //���� ��ǥ ����
			head_2->cy++;                               //�Ʒ��� �̵��ϱ� ������ +1
		}
		break;                                          //�� ������ ����� ����
	}

	gotoxy(head_2->cx, head_2->cy);                     //head�� ��ǥ�� �̵�
	printf("��");                                       //���
	for (current = head_2->next; current != tail_2; current = current->next)  //tail�� ���� �̵�
	{
		gotoxy(current->cx, current->cy);               //������ ��ǥ�� �̵�
		printf("��");                                   //���
	}
	gotoxy(tail_2->cx, tail_2->cy);                     //tail�� ��ǥ�� �̵�
	printf("  ");                                       //����

}

//-------------------------------------- ���� ���
void GameRules()
{
	system("cls");
	printf("\t\t           \t\t\t||\t\t\t           \t\t\n");
	printf("\t\t           \t\t\t||\t\t\t           \t\t\n");
	printf("\t\t           \t\t\t||\t\t\t           \t\t\n");
	printf("\t\t  [1P ���۹�]\t\t\t||\t\t      [2P ���۹�]\t\t\n");
	printf("\t\t           \t\t\t||\t\t\t           \t\t\n");
	printf("\t\t           \t\t\t||\t\t\t           \t\t\n");
	printf("\t\t           \t\t\t||\t\t\t           \t\t\n");
	printf("\t\t [ W, S, A, D ]\t\t\t||\t\t   [ ��, ��, ��, �� ]\t\t\n");
	printf("\t\t           \t\t\t||\t\t\t           \t\t\n");
	printf("\t\t           \t\t\t||\t\t\t           \t\t\n");
	printf("\t\t           \t\t\t||\t\t\t           \t\t\n");
	printf("\t\t           \t\t\t||\t\t\t           \t\t\n");
	printf("====================================================================================================\n");
	SetColor(RED);								         //����������
	printf("\n\n                                            [GAME OVER]                      \n");
	SetColor(WHITE);							         //�������
	printf("\n\n                                         1. ���� ����� ��                \n");
	printf("\n\n                                         2. ���� ����� ��                \n");
	printf("\n\n                                      3. �ð��� ����Ǿ��� ��                \n");
	gotoxy(79, 28);
	SetColor(YELLOW);							          //���������
	printf("SPACE�� �����ּ���.");
	SetColor(WHITE);			             			  //�������
	system("pause > null");
	GetPressedKey(keys);                                  //Ű �Է� ó��
	if (keys[VK_SPACE]) {                                 //SPACE�� �Էµ� ������ ���
		return;
	}
}

//-------------------------------------- ���� Ʋ
void DrawFrame()
{
	system("cls");

	for (int i = 0; i <= FRAME_X; i++)			          //���� Ʋ�� ù ��
	{
		SetColor(BLUE);
		printf("��");						 	          //�� ����Ʈ
	}
	printf("\n");

	for (int i = 1; i < FRAME_Y - 2; i++)				 //���� Ʋ�� ù �ٰ� ������ �� ����
	{
		printf("��");
		gotoxy(66, i);
		printf("��");
		printf("\n");
	}
	for (int i = 0; i <= FRAME_X; i++)			         //���� Ʋ�� ������ ��
		printf("��");
	printf("\n");
	SetColor(WHITE);
}