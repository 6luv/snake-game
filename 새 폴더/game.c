//������ ��κ� ���
#include "main.h"

int g_sec;


//-------------------------------------- �ʱ�ȭ
void Init()
{
	system("cls");                                  //ȭ�� ����
	g_sec = 10;                                     //�ð� �ʱ�ȭ
	
	int map[FRAME_Y + 1][FRAME_X * 2 + 1] = { 0 };  //���� 0���� �ʱ�ȭ
	for (int y = 0; y < FRAME_Y - 1 ; y++)
	{
		for (int x = 0; x < FRAME_X * 2 + 2; x++)
		{
			if (y == 0 || y == FRAME_Y - 2 || x == 0 || x == 1 || x == FRAME_X * 2 || x == FRAME_X * 2 + 1)  //����Ʋ�� 1�� �ʱ�ȭ
				map[y][x] = 1;         
		}
	}	

}

void DrawSnake()
{

	gotoxy(33, 30);
	printf("5");
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
	SetColor(RED);								//����������
	printf("\n\n                                            [GAME OVER]                      \n");
	SetColor(WHITE);							//�������
	printf("\n\n                                         1. ���� ����� ��                \n");
	printf("\n\n                                         2. ���� ����� ��                \n");
	printf("\n\n                                      3. �ð��� ����Ǿ��� ��                \n");
	gotoxy(79, 28);
	SetColor(YELLOW);							 //���������
	printf("SPACE�� �����ּ���.");
	SetColor(WHITE);							//�������
	while (1)
	{
		if (KeyControl() == SPACE) {			 //SPACE�� �Էµ� ������ ���
			break;
		}
	}
}

//-------------------------------------- ���� Ʋ
void DrawFrame()
{
	system("cls");
	
	for (int i = 0; i <= FRAME_X; i++)			 //���� Ʋ�� ù ��
	{
		SetColor(BLUE);
		printf("��");							//�� ����Ʈ
	}
	printf("\n");
	
    for(int i=1; i<FRAME_Y-2; i++)				 //���� Ʋ�� ù �ٰ� ������ �� ����
    {
        printf("��");
        gotoxy(66,i);
        printf("��");
        printf("\n");
    }
    for(int i = 0; i<= FRAME_X ; i++)			 // ���� Ʋ�� ������ ��
        printf("��");
    printf("\n");
	SetColor(WHITE);
}

