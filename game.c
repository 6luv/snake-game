#include "main.h"

//-------------------------------------- �ʱ�ȭ
void Init()
{
	system("cls");										//ȭ�� ����
	g_sec = 60;											//�ð� �ʱ�ȭ
	for (int y = 0; y < FRAME_Y + 1; y++)				//�� �ʱ�ȭ
	{
		for (int x = 0; x < FRAME_X * 2 + 1; x++)
			map[y][x] = 0;
	}

	score_1p = 0;										//1P ���� �ʱ�ȭ
	score_2p = 0;										//2P ���� �ʱ�ȭ

	food_cut = 0;										//���� ���� ī��Ʈ
	food_num = 5;										//���� ���� ����

	head_1 = (SNAKE*)malloc(sizeof(SNAKE));				//1P ���� �Ҵ�
	if (head_1 == NULL)									//�Ҵ翡 �����ϸ� ����
		exit(1);
	head_2 = (SNAKE*)malloc(sizeof(SNAKE));				//2P ���� �Ҵ�
	if (head_2 == NULL)									//�Ҵ翡 �����ϸ� ����
		exit(1);

	head_1->cx = 10;									//1P head x��ǥ �ʱ�ȭ
	head_1->cy = 15;									//1P head x��ǥ �ʱ�ȭ
	head_1->direction = UP;								//ó�� ���� ����
	tail_1 = head_1;									//tail�� head�� �ʱ�ȭ

	head_2->cx = 50;									//2P head x��ǥ �ʱ�ȭ
	head_2->cy = 15;									//2P head x��ǥ �ʱ�ȭ
	head_2->direction = DOWN;							//ó�� ���� ����
	tail_2 = head_2;									//tail�� head�� �ʱ�ȭ

	for (int i = 0; i < 3; i++)							//�� ���� �ʱ�ȭ
	{
		tail_1 = AddSnake(tail_1);						//1P ���� ����
		tail_2 = AddSnake(tail_2);						//2P ���� ����
	}
}

//-------------------------------------- �� ��ǥ �̵�
SNAKE* CoordMove(SNAKE* head, SNAKE* tail)
{
	SNAKE* current;										//current �����ͷ� ���ϱ� ����
	current = (SNAKE*)malloc(sizeof(SNAKE));			//����ü ���� �Ҵ�
	if (current == NULL)								//�Ҵ翡 �����ϸ� ����
		exit(1);

	head->oldx = head->cx;								//���� x��ǥ�� ���� x��ǥ�� ����
	head->oldy = head->cy;								//���� y��ǥ�� ���� y��ǥ�� ����

	for (current = head->next; current != tail; current = current->next)  //tail�� ���� ���� ��ǥ �̵�
	{
		current->oldx = current->cx;					//���� x��ǥ�� ���� x��ǥ�� ����
		current->oldy = current->cy;					//���� y��ǥ�� ���� y��ǥ�� ����
	}

	current = head->next;								//������ �ʱ�ȭ
	current->cx = head->oldx;							//���� ���� x��ǥ�� ����� ���� x��ǥ
	current->cy = head->oldy;							//���� ���� y��ǥ�� ����� ���� y��ǥ

	for (current = head->next; current != tail; current = current->next)   //tail�� ���� ���� ��ǥ �̵�
	{
		current->next->cx = current->oldx;				//���� ������ ���� x��ǥ�� �� ������ ���� x��ǥ
		current->next->cy = current->oldy;				//���� ������ ���� y��ǥ�� �� ������ ���� y��ǥ
	}
	return head;
}

//-------------------------------------- �� ���� ��� ����
SNAKE* AddSnake(SNAKE* tail)
{
	SNAKE* newnode;										//���ο� ���
	newnode = (SNAKE*)malloc(sizeof(SNAKE));			//����ü ���� �Ҵ�
	if (newnode == NULL)								//�Ҵ翡 �����ϸ� ����
		exit(1);
	tail->next = newnode;								//tail�� ���� ��� ����
	newnode->cx = 2;									//x ��ǥ �ʱ�ȭ
	newnode->cy = 1;									//y ��ǥ �ʱ�ȭ
	newnode->next = NULL;								//���ο� ����� next�� NULL
	tail = newnode;										//tail ������ �̵�
	return tail;
}

//-------------------------------------- 1P �� ó��
int DrawSnake1(int keys[256])
{
	SNAKE* current;
	current = (SNAKE*)malloc(sizeof(SNAKE));			//����ü ���� �Ҵ�

	switch (head_1->direction)							//head�� ���⿡ ���� �з�
	{
	case LEFT:
	case RIGHT:											//����, �������� ��
		if (keys['W'] != keys['S'])						//�� �Ʒ��� ���� �ԷµǸ� ����
		{
			if (keys['W'])								//�� ����Ű�� ������ head�� ���� ����
				head_1->direction = UP;
			else										//�Ʒ� ����Ű�� ������ head�� ���� ����
				head_1->direction = DOWN;
		}
		break;
	case UP:
	case DOWN:											//����, �Ʒ����� ��
		if (keys['A'] != keys['D'])						//���� �������� ���� �ԷµǸ� ����
		{
			if (keys['A'])								//���� ����Ű�� ������ head�� ���� ����
				head_1->direction = LEFT;
			else									    //������ ����Ű�� ������ head�� ���� ����
				head_1->direction = RIGHT;
		}
		break;
	}

	switch (head_1->direction)						    //head�� ���⿡ ���� �з�
	{
	case LEFT:										    //���� ������ ��
		if (head_1->cx >= 0)						    //�� ������ ����� �ʵ���
		{
			head_1 = CoordMove(head_1, tail_1);		    //���� ��ǥ �̵�
			head_1->cx -= 2;						    //�������� �̵��ϱ� ������ -2 (Ư�� ���ڴ� 2ĭ ����)
		}
		break;
	case RIGHT:										    //������ ������ ��
		if (head_1->cx <= FRAME_X * 2)				    //�� ������ ����� �ʵ���
		{
			head_1 = CoordMove(head_1, tail_1);		    //���� ��ǥ �̵�
			head_1->cx += 2;						    //���������� �̵��ϱ� ������ +2 (Ư�� ���ڴ� 2ĭ ����)
		}
		break;
	case UP:											//���� ������ ��
		if (head_1->cy >= 0)							//�� ������ ����� �ʵ���
		{
			head_1 = CoordMove(head_1, tail_1);		    //���� ��ǥ �̵�
			head_1->cy--;						        //���� �̵��ϱ� ������ -1
		}
		break;
	case DOWN:								            //�Ʒ��� ������ ��
		if (head_1->cy <= FRAME_Y)		                //�� ������ ����� �ʵ���
		{
			head_1 = CoordMove(head_1, tail_1);         //���� ��ǥ �̵�
			head_1->cy++;                               //�Ʒ��� �̵��ϱ� ������ +1
		}
		break;
	}

	gotoxy(head_1->cx, head_1->cy);                     //head�� ��ǥ�� �̵�
	printf("��");
	for (current = head_1->next; current != tail_1; current = current->next)  //tail�� ���� �̵�
	{
		gotoxy(current->cx, current->cy);               //������ ��ǥ�� �̵�
        map[current->cy][current->cx] = 1;          //���� �ʱ�ȭ
		printf("��");
	}
	gotoxy(tail_1->cx, tail_1->cy);                     //tail�� ��ǥ�� �̵�
    map[tail_1->cy][tail_1->cx] = 0;                //���� �ʱ�ȭ

	printf("  ");

	if (map[head_1->cy][head_1->cx] == 2)               //���̿� ������
	{
		tail_1 = AddSnake(tail_1);                      //��� �ϳ� �߰�
		score_1p += 10;                                 //���� �߰�
		food_cut--;                                     //���� ī��Ʈ ����
	}
	if (map[head_1->cy][head_1->cx] == 1)               //��, ����� ������
	{
		GameOver(2);                                    //2P �¸�
		return 0;                                       //����
	}
	return 1;
}

//-------------------------------------- 2P �� ó��
int DrawSnake2(int keys[256])
{
	SNAKE* current;
	current = (SNAKE*)malloc(sizeof(SNAKE));

	switch (head_2->direction)                          //head�� ���⿡ ���� �з�
	{
	case LEFT:                                          //����, �������� ��
	case RIGHT:
		if (keys[VK_UP] != keys[VK_DOWN])               //�� �Ʒ��� ���� �ԷµǸ� ����
		{
			if (keys[VK_UP])
				head_2->direction = UP;                 //�� ����Ű�� ������ head�� ���� ����
			else
				head_2->direction = DOWN;               //�Ʒ� ����Ű�� ������ head�� ���� ����
		}
		break;
	case UP:                                            //����, �Ʒ����� ��
	case DOWN:
		if (keys[VK_LEFT] != keys[VK_RIGHT])            //���� �������� ���� �ԷµǸ� ����
		{
			if (keys[VK_LEFT])                          //���� ����Ű�� ������ head�� ���� ����
				head_2->direction = LEFT;
			else                                        //������ ����Ű�� ������ head�� ���� ����
				head_2->direction = RIGHT;
		}
		break;
	}

	switch (head_2->direction)                          //head�� ���⿡ ���� �з�
	{
	case LEFT:                                          //���� ������ ��
		if (head_2->cx >= 0)                            //�� ������ ����� �ʵ���
		{
			head_2 = CoordMove(head_2, tail_2);         //���� ��ǥ �̵�
			head_2->cx -= 2;                            //�������� �̵��ϱ� ������ -2 (Ư�� ���ڴ� 2ĭ ����)
		}
		break;
	case RIGHT:                                         //������ ������ ��
		if (head_2->cx <= FRAME_X * 2)                  //�� ������ ����� �ʵ���
		{
			head_2 = CoordMove(head_2, tail_2);         //���� ��ǥ ����
			head_2->cx += 2;                            //���������� �̵��ϱ� ������ +2 (Ư�� ���ڴ� 2ĭ ����)
		}
		break;
	case UP:                                            //���� ������ ��
		if (head_2->cy >= 0)                            //�� ������ ����� �ʵ���
		{
			head_2 = CoordMove(head_2, tail_2);         //���� ��ǥ ����
			head_2->cy--;                               //���� �̵��ϱ� ������ -1
		}
		break;
	case DOWN:                                          //�Ʒ��� ������ ��
		if (head_2->cy <= FRAME_Y)                      //�� ������ ����� �ʵ���
		{
			head_2 = CoordMove(head_2, tail_2);         //���� ��ǥ ����
			head_2->cy++;                               //�Ʒ��� �̵��ϱ� ������ +1
		}
		break;
	}

	gotoxy(head_2->cx, head_2->cy);                     //head�� ��ǥ�� �̵�
	printf("��");                                       //���
	for (current = head_2->next; current != tail_2; current = current->next)  //tail�� ���� �̵�
	{
		gotoxy(current->cx, current->cy);               //������ ��ǥ�� �̵�
        map[current->cy][current->cx] = 1;          //���� �ʱ�ȭ
		printf("��");                                   //���
	}

	gotoxy(tail_2->cx, tail_2->cy);                     //tail�� ��ǥ�� �̵�
    map[tail_2->cy][tail_2->cx] = 0;                //���� �ʱ�ȭ

	printf("  ");                                       //������ ���� ����
	if (map[head_2->cy][head_2->cx] == 2)               //���̿� ������
	{
		tail_2 = AddSnake(tail_2);                      //��� �ϳ� �߰�
		score_2p += 10;                                 //���� �߰�
		food_cut--;                                     //���� ī��Ʈ ����
	}
	if (map[head_2->cy][head_2->cx] == 1)               //��, ����� ������
	{
		GameOver(1);                                    //1P �¸�
		return 0;                                       //����
	}
	if (head_1->cx == head_2->cx && head_1->cy == head_2->cy)  //������ �Ӹ��� ������ ������ �� ���� ���� �¸�
	{
		if (score_1p > score_2p)                        //1P�� ������ ������ 1P �¸�
			GameOver(1);
		else if (score_1p == score_2p)                  //1P�� 2P�� ������ ������ ���º�
			GameOver(0);
		else                                            //2P�� ������ ������ 2P �¸�
			GameOver(2);
		return 0;                                       //����
	}
	return 1;
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
	SetColor(RED);
	printf("\n\n                                            [GAME OVER]                      \n");
	SetColor(WHITE);
	printf("\n\n                                         1. ���� ����� ��                \n");
	printf("\n\n                                         2. ���� ����� ��                \n");
	printf("\n\n                                      3. �ð��� ����Ǿ��� ��                \n");
	gotoxy(79, 28);
	SetColor(YELLOW);
	printf("SPACE�� �����ּ���.");
	SetColor(WHITE);
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
		SetColor(BLUE);                                   //�Ķ��� ��
		printf("��");						 	          //�� ����Ʈ
	}

	for (int i = 0; i <= FRAME_X * 2; i++)			      //���� �� �ʱ�ȭ
		map[0][i] = 1;
	printf("\n");

	for (int i = 0; i <= FRAME_Y-1; i++)	       		  //���� Ʋ�� ù �ٰ� ������ �� ����
	{
		printf("��");						 	          //�� ����Ʈ
		map[i][0] = 1;                                    //���� �� �ʱ�ȭ
		map[i][1] = 1;			                          //���� �� �ʱ�ȭ
		gotoxy(FRAME_X * 2, i);                           //������ ������ �̵�
		printf("��");						 	          //�� ����Ʈ
		map[i][FRAME_X * 2 - 1] = 1;                      //������ �� �ʱ�ȭ
		map[i][FRAME_X * 2] = 1;                          //������ �� �ʱ�ȭ
		printf("\n");
	}

	for (int i = 0; i <= FRAME_X; i++)			          //���� Ʋ�� ������ ��
		printf("��");						 	          //�� ����Ʈ

	for (int i = 0; i <= FRAME_X * 2; i++)
		map[FRAME_Y][i] = 1;                              //�Ʒ� �� �ʱ�ȭ
	SetColor(WHITE);
}
