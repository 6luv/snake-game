#include "main.h" 

//-------------------------------------- Ŀ�� �����
void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, }; //����ü �����ϰ� ���ð��� ��
	cursorInfo.dwSize = 1; //Ŀ�� �β�
	cursorInfo.bVisible = FALSE; //Ŀ�� ���� ����, Visible TRUE(����) FALSE(����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo); //�ܼ�â���� Ŀ���� ���� ����
}

//-------------------------------------- �÷� ����
void SetColor(int fontcolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fontcolor); //�ܼ�â�� ���� ��������
}

//-------------------------------------- ��ǥ �̵�
void gotoxy(int x, int y) 
{
	COORD Cur;                                 //�ܼ� ȭ�鿡�� ��ǥ�� ����
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur); //�ܼ�â���� ���ϴ� ��ġ�� Ŀ�� �̵�
}

int main()
{
	CursorView();                              //Ŀ�� ����� �Լ�
	
	while (1)
	{
		DrawTitle();                           //Ÿ��Ʋ ǥ��
		int menu = MenuDraw();                 //�޴� ǥ��
//-------------------------------------- ���� ����
		if (menu == 0)
		{
			Init();                             //�ʱ�ȭ
			int last_food_created = 0;          //���������� ���̰� ������ �ð� ����
			int last_time = 0;                  //�ð��� ���� ����
			clock_t last_snake = 0;
			CountDown();                        //���� ���� �� ī��Ʈ�ٿ�
			DrawFrame();                        //����Ʋ 
			DrawScore();                        //������
			while (1)                           //���ѵ� �ð� ����
			{
				clock_t current_time = clock(); //���� �ð� ����
				if ((double)(current_time - last_snake) / CLOCKS_PER_SEC >= 0.3) //0.5�ʸ��� �� ������
				{
					DrawSnake();                 //�̵�
					last_snake = current_time;  //���������� ������ �ð� ����
				}
				if ((double)(current_time - last_food_created)/CLOCKS_PER_SEC >= 2) //2�ʸ��� ���� ����
				{
					DrawFood();                 //���� ����
					last_food_created = current_time;  //���������� ������ �ð� ����
				}
				if ((double)(current_time - last_time) / CLOCKS_PER_SEC >= 1) //1�ʸ��� �ð� üũ
				{
					if (DrawTime())             //�ð��� �������� ���
						last_time = current_time;  //������ �ð� ����
					else                        //�ð��� ������ ���
						break;                  //����
				}
			}			
		}
//-------------------------------------- ���� ���
		else if (menu == 2)  
		{
			GameRules();       //���� ���
		}
//-------------------------------------- ���� ����
		else
		{
			gotoxy(68, 29);    //��ǥ�� �̵�
			exit(1);           //���� ����
		}
		system("cls");         //ȭ�� ����
	}
	return 0;
}