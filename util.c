//������, �ð�, ����, ���ӿ���
#include "main.h"

//-------------------------------------- ��������
int food_num = 10;                                    //������ ���� ����
int food_cut = 0;                                     //���� ������ ���� ����
int g_sec;                                            //�ð� ����
int map[FRAME_Y + 1][FRAME_X * 2 + 1];                //��

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
		GetPressedKey(keys);        //����Ű�� �Է� ����
		if (keys[VK_UP])
		{
			if (y > 18)				// ���ӽ��� ���� �� ������
			{
				gotoxy(x - 2, y);
				printf("  ");		 // >�� �����
				gotoxy(x - 2, y -= 2);
				SetColor(BLUE);		 //�Ķ������� �ٽ� ��
				printf("��");
				SetColor(WHITE);
			}
			system("pause > null");
		}
		if (keys[VK_DOWN])
		{
			if (y < 22)				// �������� �Ʒ��� �� ������
			{
				gotoxy(x - 2, y);
				printf("  ");		// >�� �����
				gotoxy(x - 2, y += 2);
				SetColor(BLUE);		//�Ķ������� �ٽ� ��
				printf("��");
				SetColor(WHITE);
			}
			system("pause > null");
		}
		if (keys[VK_SPACE])            // 0(���ӽ���), 2(���ӹ��), 4(����)�� ��ȯ
			return y - 18;
	}
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

int Pause(int num)
{
	if (num == 2)						//q�� ��
	{
		gotoxy(77, 3);
		SetColor(RED);
		printf("��--------------�� ");
		gotoxy(77, 4);
		printf("�� �Ͻ����� ���¦� ");
		gotoxy(77, 5);
		printf("��--------------�� ");
		SetColor(WHITE);
		system("pause > null");			//�ý��� ���߱�(�ƹ��͵� ��� �� �ǰ�)
	}
	else if (num == 3)
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
		SetColor(WHITE);
		system("pause > null");			            //�ý��� ���߱�(�ƹ��͵� ��� �� �ǰ�)
		GetPressedKey(keys);
		if (keys['y'] || keys['Y'])                 //y�� ������ Ÿ��Ʋ�� �̵�
			return 1;
	}
	SetColor(BLACK);					            //q, esc�� �ƴϸ� ���������� ���
	gotoxy(77, 3);
	printf("                 ");
	gotoxy(77, 4);
	printf("                 ");
	gotoxy(77, 5);
	printf("                  ");
	gotoxy(77, 6);
	printf("                  ");
	SetColor(WHITE);

	return 0;
}

//-------------------------------------- �ð�, �Ͻ�����
int DrawTime()
{
	char tmp;
	gotoxy(79, 20);
	printf("�Ͻ� ���� : q");
	gotoxy(76, 22);
	printf("Ÿ��Ʋ�� �̵� : esc");

	if (g_sec >= 0)							//�ð��� �������� ��
	{
		gotoxy(77, 15);
		printf("���� �ð� : %3d ��", g_sec);
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
	SetColor(YELLOW);                             //���������
	printf("SPACE�� �����ּ���.");
	SetColor(WHITE);                              //�������

	system("pause > null");
	GetPressedKey(keys);                         //Ű �Է� ó��
	if (keys[VK_SPACE]) {                        //SPACE�� �Էµ� ������ ���
		return;
	}
}