#include "main.h" 

//-------------------------------------- Ŀ�� �����
void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, }; //����ü �����ϰ� ���ð��� ��
	cursorInfo.dwSize = 1;                   //Ŀ�� �β�
	cursorInfo.bVisible = FALSE;             //Ŀ�� ���� ����, Visible TRUE(����) FALSE(����)
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

void GetPressedKey(int keys[256])              //Ű �Է� ó��
{
	for (int i = 1; i <= 0xfe; i++)            //���� Ű���� �� 0x01~0xfe
	{
		if (GetAsyncKeyState(i) & 0x8000)      //Ű�� ���� �������ֳ� Ȯ��
			keys[i] = 1;                       //������ ������ 1
		else                                   //�ƴϸ� 0
			keys[i] = 0;
	}
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
			head_2 = (SNAKE*)malloc(sizeof(SNAKE));  //2P ���� �Ҵ�
			if (head_2 == NULL)                 //�Ҵ翡 �����ϸ� ����
				exit(1);
			Init();                             //�ʱ�ȭ
			int last_food_created = 0;          //���������� ���̰� ������ �ð� ����
			int last_time = 0;                  //�ð��� ���� ����
			//clock_t last_snake1 = 0;            //���������� 1P ���� ������ �ð�
			clock_t last_snake2 = 0;            //���������� 2P ���� ������ �ð�
			CountDown();                        //���� ���� �� ī��Ʈ�ٿ�
			DrawFrame();                        //����Ʋ 
			DrawScore();                        //������
			while (1)                           //���ѵ� �ð� ����
			{
				GetPressedKey(keys);            //Ű �Է� ó��
				if (keys['q'] || keys['Q'])     //Q�� ������ Pause(2) �Լ� ����
					Pause(2); 
				if (keys[VK_ESCAPE]) {          //�����̽��ٰ� ������
					if (Pause(3))               //Pause(3) �Լ� ����
						break;                  //1�� ��ȯ�Ǹ� ����
				}
				clock_t current_time = clock(); //���� �ð� ����
				/*if ((double)(current_time - last_snake1) / CLOCKS_PER_SEC >= 0.3) //0.3�ʸ��� �� ������
				{
					DrawSnake1(keys);            //WASDŰ�� ������ �� �׸���
					last_snake1 = current_time;  //���������� ������ �ð� ����
				}*/
				if ((double)(current_time - last_snake2) / CLOCKS_PER_SEC >= 0.3) //0.3�ʸ��� �� ������
				{
					DrawSnake2(keys);            //����Ű�� ������ �� �׸���
					last_snake2 = current_time;  //���������� ������ �ð� ����
				}
				if ((double)(current_time - last_food_created) / CLOCKS_PER_SEC >= 2) //2�ʸ��� ���� ����
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