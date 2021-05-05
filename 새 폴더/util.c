//������, �ð�, ����, ���ӿ���
#include "main.h"

//-------------------------------------- ��������
int food_num = 10; //������ ���� ����
int food_cut = 0;  //���� ������ ���� ����
int g_sec;    //�ð� ����
int map[FRAME_Y + 1][FRAME_X * 2 + 1]; //��

//-------------------------------------- ���� Ÿ��Ʋ
void DrawTitle()
{
	system("title SNAKE GAME | mode con cols=100 lines=30"); //�ܼ�â ũ��� �ܼ�â ����
	printf("\n\n\n\n\n\n");
	SetColor(RED);
	printf("\t\t              ############    ## ######   ##   ## ################# \n");
	printf("\t\t             ##       ####   ## ##   ##  ##  ##  ##  \n");
	printf("\t\t              ###    ## ##  ## #######  ######  ###### \n");
	printf("\t\t               ##   ##  ## ## ##    ## ##   ## ##\n");
	printf("\t\t################   ##   #### ##    ## ##     ########\n");
	SetColor(WHITE);
}

//-------------------------------------- ī��Ʈ�ٿ�
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

//-------------------------------------- �޴�
int MenuDraw()
{
	int x = 46;
	int y = 18;
	gotoxy(x - 2, y);
	SetColor(BLUE);					//�Ķ�������
	printf("��");
	SetColor(WHITE);				//�������
	printf(" ���ӽ���");
	gotoxy(x, y + 2);
	printf(" ���ӹ��");
	gotoxy(x, y + 4);
	printf(" ��������");
	gotoxy(68, 28);
	SetColor(YELLOW);				//���������
	printf("������ (�ֿ���, �����, ������)");
	SetColor(WHITE);				//�������
	while (1)
	{
		int n = KeyControl();		 //����Ű�� �Է� ����
		switch (n)
		{
		case UP: {					// ��Ű�� �Էµ��� ��
			if (y > 18)				// ���ӽ��� ���� �� ������
			{
				gotoxy(x - 2, y);
				printf("  ");		 // >�� �����
				gotoxy(x - 2, y -= 2);
				SetColor(BLUE);		 //�Ķ������� �ٽ� ��
				printf("��");
				SetColor(WHITE);
			}
			break;
		}
		case DOWN: {				 // ��Ű�� �Էµ��� ��
			if (y < 22)				// �������� �Ʒ��� �� ������
			{
				gotoxy(x - 2, y);
				printf("  ");		// >�� �����
				gotoxy(x - 2, y += 2);
				SetColor(BLUE);		//�Ķ������� �ٽ� ��
				printf("��");
				SetColor(WHITE);
			}
			break;
		}
		case SPACE:
			return y - 18;			 // 0(���ӽ���), 2(���ӹ��), 4(����)�� ��ȯ
		}
	}
}

//-------------------------------------- ����Ű �Է�
int KeyControl()
{
	if (_kbhit())					//������ Ű�� �ֳ� Ȯ��
	{
		char tmp = _getch();		 //����Ű �Է� 
		if (tmp == -32)				//Ư��Ű�̸� (����Ű)
		{
			tmp = _getch();			//Ư��Ű�� ���� �ΰ��̱� ������ �ٽ� �� ����
			if (tmp == UP)			// �谡 ���� �Ǿ��� ��
				return	UP;
			else if (tmp == DOWN)		// �鰡 ���� �Ǿ��� ��
				return DOWN;
		}
		else if (tmp == ' ')		//�����̽��� ���� �Ǿ��� ��
			return SPACE;
	}
	return 0;						//������ Ű�� ������
}

//-------------------------------------- ������
void DrawScore()
{
	int score_1p = 0, score_2p = 0;  //�ʱ�ȭ
	
	gotoxy(73, 10);
	printf("  [ 1P ]         [ 2P ]");
	gotoxy(73, 12);
	printf("   %2d       :     %2d", score_1p, score_2p);
	

}




//-------------------------------------- �ð�, �Ͻ�����
int DrawTime()
{
	char tmp;
	gotoxy(79, 20);
	printf("�Ͻ� ���� : q");
	gotoxy(76, 22);
	printf("Ÿ��Ʋ�� �̵� : esc");
	if (_kbhit())							//�Էµ� Ű�� �ֳ� Ȯ��
	{
		tmp = _getch();						//�Է��� ������
		if (tmp == 'q' || tmp == 'Q')						//q�� ��
		{
			gotoxy(77, 3);
			SetColor(RED);
			printf("��--------------�� ");
			gotoxy(77, 4);
			printf("�� �Ͻ����� ���¦� ");
			gotoxy(77, 5);
			printf("��--------------�� ");
			system("pause > null");			//�ý��� ���߱�(�ƹ��͵� ��� �� �ǰ�)
		}
		else if (tmp == ESC)                 //esc�� ��
		{
			gotoxy(77, 3);
			SetColor(BLUE);
			printf("��--------------�� ");
			gotoxy(77, 4);
			printf("�� Ÿ��Ʋ�� �̵��� ");
			gotoxy(77, 5);
			printf("��--------------�� ");
			gotoxy(77, 6);
			printf(" YES : y  NO : n ");
			system("pause > null");			//�ý��� ���߱�(�ƹ��͵� ��� �� �ǰ�)
			tmp = _getch();
			if (tmp == 'y' || tmp == 'Y')                 //y�� ������ Ÿ��Ʋ�� �̵�
				return 0;
		}
		SetColor(BLACK);					//q�� �ƴϸ� ���������� ���
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
	if (g_sec >= 0)							//�ð��� �������� ��
	{
		gotoxy(77, 15);	
		printf("���� �ð� : %2d ��", g_sec);	
		Sleep(1000);						//1��
		g_sec--;			
	}
	else                                    //�ð��� ����Ǹ�  
	{
		GameOver();							//���� ����
		return 0;							//0�� ��ȯ
	}
	return 1;								//1�� ��ȯ
}

//-------------------------------------- ���� ���
void DrawFood()
{
	int food_x, food_y;
	srand(time(NULL));						//������ ����

	food_x = (rand() % 64) + 1;				//x��ǥ ���
	food_y = (rand() % 27) + 1;             //y��ǥ ���
	
	if (food_x % 2 == 1)					//��ǥ�� Ȧ���� ��
	{
		map[food_y][food_x + 1] = 2;        //��� 2����Ʈ�� 1�߰�   
		map[food_y][food_x + 2] = 2;        //���̰� �����Ǵ� ���� 2�� �ʱ�ȭ
		food_x += 1;                        //Ȧ���� x��ǥ�� 1�� ����
	}
	else                                    //x��ǥ�� ¦���� ��
	{
		map[food_y][food_x] = 2;            //2�� �ʱ�ȭ
		map[food_y][food_x + 1] = 2;        //��� 2����Ʈ�� 1���� ���� �ʱ�ȭ
	}
	
	gotoxy(food_x, food_y);                 //��ǥ�� ���� ���� ���
	SetColor(YELLOW);
	printf("��");	 
	SetColor(WHITE);
	food_cut += 1;							//������ ���� ���� �߰�
	food_num -= 1;							//�� ���� ���� ����
}

//-------------------------------------- ���� ����
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
	printf("\t\t\t    ��-----------------------------------------�� \n");
	printf("\t\t\t    ��     *****   ******* **      **      **  �� \n");
	printf("\t\t\t    ��    **  **   **   **  **    ****    **   �� \n");
	printf("\t\t\t    ��        **   *******  **   **  **   **   �� \n");
	printf("\t\t\t    ��        **   **        **  **  **  **    �� \n");
	printf("\t\t\t    ��   ********* **         *****   *****    �� \n");
	printf("\t\t\t    ��-----------------------------------------�� \n");
	SetColor(WHITE);
	*/
	/*
	SetColor(BLUE);
	printf("\t\t\t    ��-----------------------------------------�� \n");
	printf("\t\t\t    ��    ****   ******* **      **      **    �� \n");
	printf("\t\t\t    ��   **  **  **   **  **    ****    **     �� \n");
	printf("\t\t\t    ��      **   *******  **   **  **   **     �� \n");
	printf("\t\t\t    ��     **    **        **  **  **  **      �� \n");
	printf("\t\t\t    ��  *******  ***        *****   *****      �� \n");
	printf("\t\t\t    ��-----------------------------------------�� \n");
	SetColor(WHITE);
	*/

	SetColor(BLUE);
	printf("\t\t\t    ��-----------------------------------------�� \n");
	printf("\t\t\t    ��     ******    *****     ***   **  **  **�� \n");
	printf("\t\t\t    ��    **    **  **   **  **  ** **  **  ** �� \n");
	printf("\t\t\t    ��   **     ** ******   ****** **  **  **  �� \n");
	printf("\t\t\t    ��  **     ** **    ** **   ** ** ** **    �� \n");
	printf("\t\t\t    �� ********  **     ****   **  *** ***     �� \n");
	printf("\t\t\t    ��-----------------------------------------�� \n");
	SetColor(WHITE);

	printf("\n\t\t\t\t\t      Score : \n");


	gotoxy(79, 28);
	SetColor(YELLOW); //���������
	printf("SPACE�� �����ּ���.");
	SetColor(WHITE); //�������
	while (1)
	{
		if (KeyControl() == SPACE) {   //SPACE�� �Էµ� ������ ���
			break;
		}
	}
}