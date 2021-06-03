#include "main.h"

//-------------------------------------- ���� Ÿ��Ʋ
void DrawTitle()
{
	system("title SNAKE GAME | mode con cols=100 lines=30");    //�ܼ�â ũ��� �ܼ�â ����
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
	SetColor(BLUE);
	printf("��");
	SetColor(WHITE);
	printf(" ���ӽ���");
	gotoxy(x, y + 2);
	printf(" ���ӹ��");
	gotoxy(x, y + 4);
	printf(" ��������");
	gotoxy(68, 28);
	SetColor(YELLOW);
	printf("������ (�ֿ���, �����, ������)");
	SetColor(WHITE);
	while (1)
	{
		GetPressedKey(keys);                             //����Ű�� �Է� ����
		if (keys[VK_UP])                                 //��Ű�� ������ ��
		{
			if (y > 18)				                     //���ӽ��� ���� �� ������ ���� ����
			{
				gotoxy(x - 2, y);
				printf("  ");		                     //>�� �����
				gotoxy(x - 2, y -= 2);
				SetColor(BLUE);
				printf("��");                            //�Ķ������� �ٽ� ���
				SetColor(WHITE);
			}
			system("pause > null");
		}
		if (keys[VK_DOWN])                               //��Ű�� ������ ��
		{
			if (y < 22)				                     //�������� �Ʒ��� �� ������ ���� ����
			{
				gotoxy(x - 2, y);
				printf("  ");	             	         //>�� �����
				gotoxy(x - 2, y += 2);
				SetColor(BLUE);		                     //�Ķ������� �ٽ� ���
				printf("��");
				SetColor(WHITE);
			}
			system("pause > null");
		}
		if (keys[VK_SPACE])                              //0(���ӽ���), 2(���ӹ��), 4(����)�� ��ȯ
			return y - 18;
	}
}

//-------------------------------------- ������
void DrawScore()
{
	gotoxy(73, 10);
	printf("  [ 1P ]         [ 2P ]");
	gotoxy(73, 12);
	printf("   %3d       :    %3d", score_1p, score_2p);
}

int Pause(int num)
{
	if (num == 2)						                //Q�� ������ ��
	{
		gotoxy(77, 3);
		SetColor(RED);
		printf("��--------------�� ");
		gotoxy(77, 4);
		printf("�� �Ͻ����� ���¦� ");
		gotoxy(77, 5);
		printf("��--------------�� ");
		SetColor(WHITE);
		system("pause > null");			                //�ý��� ���߱� (�ƹ��͵� ��� �� ��)
	}
	else if (num == 3)                                  //ESC�� ������ ��
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
		system("pause > null");			               //�ý��� ���߱�(�ƹ��͵� ��� �� �ǰ�)
		GetPressedKey(keys);
		if (keys['y'] || keys['Y'])                    //y�� ������ Ÿ��Ʋ�� �̵�
			return 1;
	}
	SetColor(BLACK);
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
	printf("�Ͻ� ���� : Q");
	gotoxy(76, 22);
	printf("Ÿ��Ʋ�� �̵� : ESC");

	if (g_sec >= 0)							           //�ð��� �������� �� ���
	{
		gotoxy(77, 15);
		printf("���� �ð� : %3d ��", g_sec);
		g_sec--;
	}
	else                                               //�ð��� ����Ǹ�
	{
		if (score_1p > score_2p)                       //1P�� ������ �� ũ��
			GameOver(1);                               //1P �¸�
		else if (score_1p == score_2p)                 //������ ������
			GameOver(0);                               //���º�
		else                                           //2P�� ������ �� ũ��
			GameOver(2);                               //2P �¸�
		return 0;							           //0�� ��ȯ
	}
	return 1;								           //1�� ��ȯ
}

//-------------------------------------- ���� ���� Ȯ��
void DrawFood_Continue()
{
	if (food_cut < food_num)                           //���ѵ� ���� ������ ������
		DrawFood();                                    //���� ����
}

//-------------------------------------- ���� ���
void DrawFood()
{
	int food_x, food_y;
	srand(time(NULL));						          //������ ����

	food_x = (rand() % 64) + 1;				          //x��ǥ ���
	food_y = (rand() % 27) + 1;                       //y��ǥ ���
	if (!map[food_y][food_y])                         //���� ���� 0�� ������ ���� ����
	{
		if (food_x % 2 == 1)			       		 //��ǥ�� Ȧ���� ��
		{
			map[food_y][food_x + 1] = 2;             //��� 2����Ʈ�� 1�߰�
			map[food_y][food_x + 2] = 2;             //���̰� �����Ǵ� ���� 2�� �ʱ�ȭ
			food_x += 1;							 //Ȧ���� x��ǥ�� 1�� ����
		}
		else										//x��ǥ�� ¦���� ��
		{
			map[food_y][food_x] = 2;				//2�� �ʱ�ȭ
			map[food_y][food_x + 1] = 2;			//��� 2����Ʈ�� 1���� ���� �ʱ�ȭ
		}

		gotoxy(food_x, food_y);						//��ǥ�� ���� ���� ���
		SetColor(YELLOW);
		printf("��");
		SetColor(WHITE);
		food_cut++;									//������ ���� ���� �߰�
	}
	else
		return;
}

//-------------------------------------- ���� ����
void GameOver(int winner)
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

	if (winner == 1)
	{
		SetColor(BLUE);
		printf("\t\t\t    ��-----------------------------------------�� \n");
		printf("\t\t\t    ��     *****   ******* **      **      **  �� \n");
		printf("\t\t\t    ��    **  **   **   **  **    ****    **   �� \n");
		printf("\t\t\t    ��        **   *******  **   **  **   **   �� \n");
		printf("\t\t\t    ��        **   **        **  **  **  **    �� \n");
		printf("\t\t\t    ��   ********* **         *****   *****    �� \n");
		printf("\t\t\t    ��-----------------------------------------�� \n");
		SetColor(WHITE);

		printf("\n\t\t\t\t\t   Score : %3d \n", score_1p);
	}
	else if (winner == 2)
	{
		SetColor(BLUE);
		printf("\t\t\t    ��-----------------------------------------�� \n");
		printf("\t\t\t    ��    *****   ******* **      **       **  �� \n");
		printf("\t\t\t    ��   **   **  **   **  **    ****     **   �� \n");
		printf("\t\t\t    ��       **   *******  **   **  **    **   �� \n");
		printf("\t\t\t    ��      **    **        **  **  **   **    �� \n");
		printf("\t\t\t    ��  ********  **         *****   *****     �� \n");
		printf("\t\t\t    ��-----------------------------------------�� \n");
		SetColor(WHITE);

		printf("\n\t\t\t\t\t   Score : %3d \n", score_2p);
	}
	else
	{
		SetColor(BLUE);
		printf("\t\t\t    ��-----------------------------------------�� \n");
		printf("\t\t\t    ��     ******    *****     ***   **  **  **�� \n");
		printf("\t\t\t    ��    **    **  **   **  **  ** **  **  ** �� \n");
		printf("\t\t\t    ��   **     ** ******   ****** **  **  **  �� \n");
		printf("\t\t\t    ��  **     ** **    ** **   ** ** ** **    �� \n");
		printf("\t\t\t    �� ********  **     ****   **  *** ***     �� \n");
		printf("\t\t\t    ��-----------------------------------------�� \n");
		SetColor(WHITE);

		printf("\n\t\t\t\t\t   Score : %3d \n", score_1p);
	}

	gotoxy(79, 28);
	SetColor(YELLOW);
	printf("SPACE�� �����ּ���.");
	SetColor(WHITE);

	system("pause > null");
	GetPressedKey(keys);                                      //Ű �Է� ó��
	if (keys[VK_SPACE]) {                                     //SPACE�� �Էµ� ������ ���
		return;
	}
}
