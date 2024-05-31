//#include<windows.h>
//#include<conio.h>
//#include<iostream>
//
//using namespace std;
//
//
//// ��
//class Point
//{
//private:
//	COORD pos;	// ����̨�ϵ�����
//public:
//	Point() { pos.X = 0; pos.Y = 0; }
//
//	Point(UINT x, UINT y)
//	{
//		pos.X = x;
//		pos.Y = y;
//	}
//
//	Point(const Point& p) : pos(p.pos)
//	{
//	}
//
//	void setPos(UINT x, UINT y)
//	{
//		pos.X = x;
//		pos.Y = y;
//	}
//
//	void setPosPoint(const Point& p) { pos = p.pos; }
//
//	void setPosRandom(int isHead = 0)
//		//�������λ�õĵ㣬��Ҫ�����ߵĳ�ʼ����ʳ�������
//		//��ʳ�ﲻͬ����ͷ���������ԣ������ܹ��ڿ�����ͼ�ı�Ե���������������isHead����
//		//��isHead����ʱĬ��Ϊ�㣬��ʱ��������ʳ���λ��
//		//��isHead�������Ϊ1ʱ������ͷλ��
//	{
//		if (isHead == 1)
//		{
//			srand(time(NULL));
//			pos.X = rand() % 18 + 1;
//			pos.Y = rand() % 10 + 7;
//		}
//		else
//		{
//			srand(time(NULL));
//			pos.X = rand() % 18 + 1;
//			pos.Y = rand() % 18 + 1;
//		}
//	}
//
//	void movePoint(int d)
//	{
//		if (d == 1)
//		{
//			pos.Y--;
//		}
//		else if (d == 2)
//		{
//			pos.Y++;
//		}
//		else if (d == 3)
//		{
//			pos.X--;
//		}
//		else if (d == 4)
//		{
//			pos.X++;
//		}
//	}
//
//	COORD getPos(void)
//	{
//		return pos;
//	}
//
//	void printPoint(char c)
//	{
//		HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//		SetConsoleCursorPosition(hOutput, pos);
//		cout << c;
//	}
//};
//
//// ��
//class Snake
//{
//private:
//	Point p[400];
//	int dirction;//��Ŀǰ���˶����� 1��2��3��4��
//	int lenth;//�ߵĳ���
//	friend class Game;
//public:
//	Snake()
//	{
//		lenth = 3;
//		p[0].setPosRandom(1);
//		p[1].setPos(p[0].getPos().X, p[0].getPos().Y + 1);
//		p[2].setPos(p[1].getPos().X, p[1].getPos().Y + 1);
//		dirction = 1;
//	}
//};
//
//// ��Ϸ
//class Game
//{
//private:
//	Snake s;
//	int map[20][20] = { 0 };//0Ϊ�յ� 1Ϊ���� 2Ϊʳ�� -1Ϊǽ
//	Point food;
//	int score;
//public:
//	Game()
//	{
//		for (int i = 0; i < 20; i++)//�����ʼ��ǽ���ڿ���̨��ӡ����
//		{
//			Point p1(UINT(i), UINT(0));
//			map[i][0] = -1;
//			p1.printPoint('=');
//			Point p2(UINT(i), UINT(19));
//			map[i][19] = -1;
//			p2.printPoint('=');
//			Point p3(UINT(0), UINT(i));
//			map[0][i] = -1;
//			p3.printPoint('=');
//			Point p4(UINT(19), UINT(i));
//			map[19][i] = -1;
//			p4.printPoint('=');
//			Sleep(50);//��������������һ�ֶ�����Ч��
//		}
//		for (int i = 0; i < s.lenth; i++)//������map�б�Ǻ���
//		{
//			map[s.p[i].getPos().X][s.p[i].getPos().Y] = 1;
//		}
//		for (int i = 0; i < 3; i++)//�ڿ���̨��ӡ����
//		{
//			s.p[i].printPoint('O');
//		}
//		score = 0;
//	}
//
//	void creatFood(void)
//	{
//		Point food;
//		while (map[food.getPos().X][food.getPos().Y] != 0)//ֻ�е�������ɵ�λ����map��Ϊ0��Ҳ����Ϊ�յ�ʱ�Ž�����һ������
//		{
//			food.setPosRandom();
//		}
//		map[food.getPos().X][food.getPos().Y] = 2;
//		food.printPoint('$');
//	}
//
//	void eatFood(void)
//	{
//		score = score + 100;
//		Point temph(s.p[0]);
//		Point tempt(s.p[s.lenth - 1]);
//		s.p[0].movePoint(s.dirction);
//		map[s.p[0].getPos().X][s.p[0].getPos().Y] = 1;
//		s.p[0].printPoint('O');
//		for (int i = s.lenth - 1; i > 1; i--)
//		{
//			s.p[i].setPosPoint(s.p[i - 1]);
//		}
//		s.p[1].setPosPoint(temph);
//		s.lenth++;
//		s.p[s.lenth - 1].setPosPoint(tempt);
//		Sleep(500);
//	}
//
//	void snakeGo(void)
//	{
//		Point temp(s.p[0]);
//		s.p[0].movePoint(s.dirction);
//		map[s.p[0].getPos().X][s.p[0].getPos().Y] = 1;
//		s.p[0].printPoint('O');
//		map[s.p[s.lenth - 1].getPos().X][s.p[s.lenth - 1].getPos().Y] = 0;
//		s.p[s.lenth - 1].printPoint(' ');
//		for (int i = s.lenth - 1; i > 1; i--)
//		{
//			s.p[i].setPosPoint(s.p[i - 1]);
//		}
//		s.p[1].setPosPoint(temp);
//		Sleep(500);
//	}
//
//	int isEatorEnd(Point q, int dirc)
//		//������ͷ����ʹ�ʱ���н��ķ���Ȼ���ж�����һ���˶����Ƿ�Ե�ʳ���ײ��ǽ�ڻ�������������map�����ж�
//	{
//		q.movePoint(dirc);
//		if (map[q.getPos().X][q.getPos().Y] == -1 || map[q.getPos().X][q.getPos().Y] == 1)
//		{
//			return -1;
//		}
//		else if (map[q.getPos().X][q.getPos().Y] == 2)
//		{
//			return 1;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//
//	void setDirection(char d)
//		//ע�⵽�����˶������в���ֱ���򷴷����ƶ�
//		//���統��������ʱֻ��������ת������ֱ�����ת
//	{
//		if (d == 'w' && s.dirction != 2)
//		{
//			s.dirction = 1;
//		}
//		else if (d == 's' && s.dirction != 1)
//		{
//			s.dirction = 2;
//		}
//		else if (d == 'a' && s.dirction != 4)
//		{
//			s.dirction = 3;
//		}
//		else if (d == 'd' && s.dirction != 3)
//		{
//			s.dirction = 4;
//		}
//		else
//		{
//			return;
//		}
//	}
//
//	Point& getHead(void) { return s.p[0]; }
//
//	int getDirc(void) { return s.dirction; }
//
//	int getPoint(void) { return score; }
//
//	int getLenth(void) { return s.lenth; }
//};
//
//int main()
//{
//	cout << "            ���ã���ӭ����̰����           " << endl;
//	cout << "������ͨ��'w''a''s''d'�������ߵ����������ƶ�" << endl;
//	system("pause");
//	system("cls");
//	Game g;
//	g.creatFood();
//	while (1)
//	{
//		while (!_kbhit())
//		{
//			int i = g.isEatorEnd(g.getHead(), g.getDirc());
//			if (i == 1)
//			{
//				g.eatFood();
//				if (g.getLenth() == 361)
//				{
//					goto L;
//				}
//				g.creatFood();
//				continue;
//			}
//			else if (i == -1)
//			{
//				goto L;
//			}
//			g.snakeGo();
//		}
//		char d = _getch();
//		g.setDirection(d);
//	}
//L:system("cls");
//	cout << "��Ϸ���������ĵ÷�Ϊ" << g.getPoint() << endl;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
////// ��ָ��λ�ô�ӡͼ��
////// ������x���� y���� ��Ҫ��ӡ���ַ���
////// �޷���ֵ
////void MyPrintf(int iPosX, int iPosY, char* szSymbol)
////{
////	// ���ù��λ�� SetConsoleCursorPosition����
////	// ��һ������Ϊ����̨�ľ�� ���� GetStdHandle�����õ�  STD_OUTPUT_HANDLEΪ���
////	// �ڶ�������Ϊ����ṹ��
////	COORD pos;											// �����ṹ��pos
////	pos.X = iPosX;										// �ṹ���Ա��ֵ
////	pos.Y = iPosY;
////
////	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);	// �õ����ھ��
////
////	SetConsoleCursorPosition(hOutput, pos);				// ���ù��λ��
////	printf(szSymbol);
////}