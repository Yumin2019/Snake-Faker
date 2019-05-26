#include <stdio.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include"Text.h"
#include"snake.h"

enum mode{easy=1, normal=3, hard_=5};

enum COLOR {
	BLACK, BLUE, GREEN, OC, RED, JAJU, YELLOW, WHITE, GRAY
	, DEEP_BLUE, DEEP_GREEN, DEEP_OC, DEEP_RED, DEEP_JAJU, DEEP_YELLOW,
	DEEP_WHITE
};

enum SW { off, on }; //off=0 on=1

enum Clover { green_clover = 1, red_clover, jaju_clover, yellow_clover, oc_clover };//���º�ȭ ���� ��ȯ ����ü �̸��� �޸����ֱ� ���� �ҹ��ڷθ�
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80 
#define PAUSE 112
#define ESC 27
#define HARD 104

#define MAP_ADJ_X 3
#define MAP_ADJ_Y 2
#define MAP_X 20 //�ƹ����� �� ���� ��ǥ�� ���̸� �ǹ��ϴ� �� �ϴ�.
#define MAP_Y 20
#define MARGIN 1 //Y ������ �ǹ��� 

#define MAP_X2 40
#define MAP_Y2 8 

#define MAP_Y4 10
#define MAP_Y3 14

#define MID_MARGIN_X 18

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80 
#define PAUSE 112
#define ESC 27
#define HARD 104
#define T 116
#define SET 118 //vŰ s�� status�� ��ħ ���� ��� ���� ����� �� ������..

#define MAP_ADJ_X 3
#define MAP_ADJ_Y 2
#define MAP_X 20 //�ƹ����� �� ���� ��ǥ�� ���̸� �ǹ��ϴ� �� �ϴ�.
#define MAP_Y 20
#define MARGIN 1 //Y ������ �ǹ��� 

#define MAP_X2 40
#define MAP_Y2 8 

#define MAP_Y4 10
#define MAP_Y3 14

#define MID_MARGIN_X 18


struct FOOD { //���� ����ü�� ����Ű�� ���� ������ ����ü ����.
	struct food *clover, *Red_clover, *OC_clover, *Yellow_clover, *Jaju_clover;

}FOOD;

struct food {

	int num;
	int x, y;
	int eat;



}clover, Red_clover, OC_clover, Jaju_clover, Yellow_clover;

int food_crush_on = 0;//���� ���� ������ ���ƴ��� Ȯ���ϴ� ���� 
int con = 0; //con ����
int x[150], y[150];
int food_x, food_y;
int length;
int speed;
int score;
int best_score = 0;
int last_score = 0;
int dir;
int key;
int status_on = 0;
int p = 0;

int mode = easy;
int hard = 0; //�ϵ� ���
int potal_on = off;

/* ���ȭ ���α׷������� ������ snake.c������ */


void number(int score) {  //���� ������ ���� ���� �Լ� 


	int a, b, c, d;

	a = score / 1000;//1000�ڸ� ��
	b = (score - a * 1000) / 100;//100�ڸ� ��
	c = (score - a * 1000 - b * 100) / 10;//10
	d = score - a * 1000 - b * 100 - c * 10;//1


	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 21, "                              ");//��� ��


	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 22, "       ");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 23, "        ");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 24, "        ");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 25, "        ");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 26, "        ");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 27, "       ");


	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 28, "                                     ");//�ϴ� 

																			   /*���ڰ� �� �ڸ��� û����. */


	TextColor(DEEP_GREEN);
	if (a == 1) //0000 ù�ڸ�. õ�ڸ��� ���� 0�� ��� �� ��.
	{
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 22, "  ���");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 23, "����");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 24, "  ���");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 25, "  ���");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 26, "  ���");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 27, "  ���");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 28, "  ���");
	}
	else if (a == 2)
	{
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 24, "    ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 26, "��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 27, "��  ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 28, "����");

	}
	else if (a == 3)
	{


		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 24, "    ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 26, "    ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 27, "��  ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 28, "����");

	}
	else if (a == 4)
	{

		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 22, "��   ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 23, "��   ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 24, "��   �� ");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 25, "��   ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 26, "������");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 27, "    ��  ");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 28, "    ��");


	}
	else if (a == 5)
	{


		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 23, "��  �� ");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 24, "��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 26, "    ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 27, "    ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 28, "����");

	}
	else if (a == 6)
	{
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 24, "��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 26, "��  ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 27, "��  ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 28, "����");

	}
	else if (a == 7)
	{

		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 24, "��  ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 25, "��  ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 26, "    ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 27, "    ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 28, "    ��");
	}
	else if (a == 8)
	{
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 24, "��  ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 26, "��  ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 27, "��  ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 28, "����");
	}
	else if (a == 9)
	{
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 24, "��  ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 26, "    ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 27, "��  ��");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 28, "����");
	}




	Sleep(100);


	TextColor(DEEP_OC);






	if (b == 1) //0000 2�ڸ�.
	{
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 22, "  ���");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 23, "����");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 24, "  ���");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 25, "  ���");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 26, "  ���");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 27, "  ���");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 28, "  ���");
	}
	else if (b == 2)
	{
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 24, "    ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 26, "��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 27, "��  ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 28, "����");

	}
	else if (b == 3)
	{


		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 24, "    ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 26, "    ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 27, "��  ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 28, "����");

	}
	else if (b == 4)
	{

		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 22, "��   ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 23, "��   ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 24, "��   �� ");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 25, "��   ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 26, "������");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 27, "    ��  ");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 28, "    ��");


	}
	else if (b == 5)
	{


		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 23, "��  �� ");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 24, "��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 26, "    ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 27, "    ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 28, "����");

	}
	else if (b == 6)
	{
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 24, "��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 26, "��  ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 27, "��  ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 28, "����");

	}
	else if (b == 7)
	{

		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 24, "��  ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 25, "��  ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 26, "    ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 27, "    ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 28, "    ��");



	}
	else if (b == 8)
	{
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 24, "��  ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 26, "��  ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 27, "��  ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 28, "����");
	}
	else if (b == 9)
	{
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 24, "��  ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 26, "    ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 27, "��  ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 28, "����");
	}
	else if (b == 0 && score >= 1000) //1023��ó�� 100�� �ڸ� ���� 0�� ��� 0�� ����.
	{
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 24, "��  ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 25, "��  ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 26, "��  ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 27, "��  ��");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 28, "����");
	}



	Sleep(100);
	TextColor(DEEP_JAJU);


	if (c == 1) //0000 3�ڸ�.
	{
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 22, "  ���");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 23, "����");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 24, "  ���");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 25, "  ���");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 26, "  ���");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 27, "  ���");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 28, "  ���");
	}
	else if (c == 2)
	{
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 24, "    ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 26, "��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 27, "��  ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 28, "����");

	}
	else if (c == 3)
	{


		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 24, "    ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 26, "    ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 27, "��  ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 28, "����");

	}
	else if (c == 4)
	{

		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 22, "��   ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 23, "��   ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 24, "��   �� ");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 25, "��   ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 26, "������");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 27, "    ��  ");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 28, "    ��");


	}
	else if (c == 5)
	{


		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 23, "��  �� ");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 24, "��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 26, "    ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 27, "    ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 28, "����");

	}
	else if (c == 6)
	{
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 24, "��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 26, "��  ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 27, "��  ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 28, "����");

	}
	else if (c == 7)
	{

		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 24, "��  ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 25, "��  ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 26, "    ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 27, "    ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 28, "    ��");
	}
	else if (c == 8)
	{
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 24, "��  ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 26, "��  ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 27, "��  ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 28, "����");
	}
	else if (c == 9)
	{
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 24, "��  ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 26, "    ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 27, "��  ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 28, "����");
	}
	else if (c == 0 && score >= 100) //0 203��ó�� 10�� �ڸ� ���� 0�� ��� 0�� ����.
	{
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 24, "��  ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 25, "��  ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 26, "��  ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 27, "��  ��");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 28, "����");
	}
	Sleep(100);

	TextColor(DEEP_YELLOW);

	if (d == 1) //0000 4�ڸ�.
	{
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 22, "  ���");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 23, "����");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 24, "  ���");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 25, "  ���");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 26, "  ���");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 27, "  ���");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 28, "����");
	}
	else if (d == 2)
	{
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 24, "    ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 26, "��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 27, "��  ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 28, "����");

	}
	else if (d == 3)
	{


		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 24, "    ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 26, "    ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 27, "��  ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 28, "����");

	}
	else if (d == 4)
	{

		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 22, "��   ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 23, "��   ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 24, "��   �� ");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 25, "��   ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 26, "������");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 27, "    ��  ");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 28, "    ��");


	}
	else if (d == 5)
	{


		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 23, "��  �� ");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 24, "��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 26, "    ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 27, "    ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 28, "����");

	}
	else if (d == 6)
	{
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 24, "��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 26, "��  ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 27, "��  ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 28, "����");

	}
	else if (d == 7)
	{

		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 24, "��  ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 25, "��  ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 26, "    ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 27, "    ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 28, "    ��");
	}
	else if (d == 8)
	{
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 24, "��  ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 26, "��  ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 27, "��  ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 28, "����");
	}
	else if (d == 9)
	{
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 24, "��  ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 25, "����");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 26, "    ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 27, "��  ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 28, "����");
	}
	else if (d == 0) //1�� �ڸ��� 0�� ��� �׳� 0����. 
	{
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 22, "����");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 23, "��  ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 24, "��  ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 25, "��  ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 26, "��  ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 27, "��  ��");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 28, "����");
	}
	
	Sleep(400);//�����ϰ� �Է¹��� 

	TextColor(DEEP_WHITE);



}
void potal() //potal _draw
{

	gotoxy(MAP_ADJ_X + MAP_X / 2 - 1, MAP_ADJ_Y, "����������");  //MAP1 ���  



	gotoxy(MAP_ADJ_X + MAP_X / 2 - 1, MAP_ADJ_Y + MAP_Y - 1, "����������");  //MAP1 �ϴ�



	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y / 2 - 2, "��"); //MAP1 left 
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y / 2 - 1, "��");
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y / 2, "��");

	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y / 2 + 1, "��");
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y / 2 + 2, "��");




	gotoxy(MAP_ADJ_X + MAP_X / 2 - 1, MAP_ADJ_Y + MAP_Y + 1, "����������");  //MAP2 ���

	gotoxy(MAP_ADJ_X + MAP_X + MAP_X / 2 - 1, MAP_ADJ_Y + MAP_Y + 1, "����������");  //MAP2 ��� 2��° 



	gotoxy(MAP_ADJ_X + MAP_X / 2 - 1, MAP_ADJ_Y + MAP_Y + MAP_Y2, "����������");  //MAP2 �ϴ�




	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y + MARGIN + MAP_Y2 - 3, "��"); //MAP2 left 
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y + MARGIN + MAP_Y2 - 4, "��"); //MAP2 left 
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y + MARGIN + MAP_Y2 - 5, "��"); //MAP2 left 

	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y + MARGIN + MAP_Y2 - 6, "��"); //MAP2 left 
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y + MARGIN + MAP_Y2 - 7, "��"); //MAP2 left 





	gotoxy(MAP_ADJ_X + MAP_X2 - 1, MAP_ADJ_Y + MAP_Y + MARGIN + MAP_Y2 - 3, "��"); //MAP2 right 
	gotoxy(MAP_ADJ_X + MAP_X2 - 1, MAP_ADJ_Y + MAP_Y + MARGIN + MAP_Y2 - 4, "��"); //MAP2 right 
	gotoxy(MAP_ADJ_X + MAP_X2 - 1, MAP_ADJ_Y + MAP_Y + MARGIN + MAP_Y2 - 5, "��"); //MAP2 right 


	gotoxy(MAP_ADJ_X + MAP_X2 - 1, MAP_ADJ_Y + MAP_Y + MARGIN + MAP_Y2 - 6, "��"); //MAP2 right 
	gotoxy(MAP_ADJ_X + MAP_X2 - 1, MAP_ADJ_Y + MAP_Y + MARGIN + MAP_Y2 - 7, "��"); //MAP2 right 






	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 / 2 - 1, "��"); //MAP3 left 
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 / 2, "��"); //MAP3 left 
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 / 2 + 1, "��"); //MAP3 left 

	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 / 2 + 2, "��"); //MAP3 left 
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 / 2 + 3, "��"); //MAP3 left 



	gotoxy(MAP_ADJ_X + MAP_X + MARGIN + MID_MARGIN_X, MAP_ADJ_Y, "����������"); //MAP3 ��� ��Ż



	gotoxy(MAP_ADJ_X + MAP_X + MARGIN * 2 + MID_MARGIN_X + MAP_X / 2, MAP_ADJ_Y + MAP_Y2, "����������"); //MAP3 �ϴ� ��Ż






	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN, MAP_ADJ_Y + MAP_Y, "��"); //MAP4 left 
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN, MAP_ADJ_Y + MAP_Y - 1, "��"); //MAP4  
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN, MAP_ADJ_Y + MAP_Y - 2, "��"); //MAP4  

	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN, MAP_ADJ_Y + MAP_Y - 3, "��"); //MAP4 left 
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN, MAP_ADJ_Y + MAP_Y - 4, "��"); //MAP4  


	gotoxy(MAP_ADJ_X + MAP_X + MARGIN * 2 + MID_MARGIN_X + MAP_X / 2, MAP_ADJ_Y + MAP_Y2 + 2, "����������"); //MAP4 ��� �µθ��� �������� +2



	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X - 1, MAP_ADJ_Y + MAP_Y, "��"); //MAP4 right 
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X - 1, MAP_ADJ_Y + MAP_Y - 1, "��"); //MAP4  
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X - 1, MAP_ADJ_Y + MAP_Y - 2, "��"); //MAP4  

	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X - 1, MAP_ADJ_Y + MAP_Y - 3, "��"); //MAP4 right 
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X - 1, MAP_ADJ_Y + MAP_Y - 4, "��"); //MAP4  

	/*
		map1: ��� ���簢�� 
		map2 �ϴ� ������
		map3 ��� ������
		map4 �ϴ� ���簢��
	
	
	*/




}
int potal_move() //��Ż ������ üũ�ϰ� �� ��� ó�����ָ� ó�� ���Ŀ��� �ٽ� �׷��ִ� �Լ�. ���� �Ӹ��� �̵��ϰ� + Move�� ���ؼ� ���� ���󰣴�.
{

	//���� ��ǥ�� ������, �װ� ��Ż�� ��ǥ���� �����Ͽ� ��Ż�̸� ó������.

	for (int i = 0; i < 5; i++) //�� ��Ż���� 3������ �ǹ���.
	{


		if (x[0] == 0 && y[0] == 8 + i) { //from map1 ���� to map4 right




			x[0] = MAP_X2 + MARGIN + MAP_X - 2; //i���� ���� 3�ڸ��� ��ġ�� ����. i�������� gg ��Ŀ ��Ż�� ��ġ�� �������ֵ� �� ��Ż�� Ÿ�� �ʵ��� x-2 -1�ϸ� 
												//�ݴ��� ��ŻŸ�� �ٽ� ���ƿͼ� �ڱ� �� ��� ����.
			y[0] = MAP_Y - 4 + i; 
								  //dir ���� �״��.

			return 1; //��Ż�� �ɷ��� �����. 



		}//��1 ���� pass 

		else if (x[0] == 60 && y[0] == 16 + i) {//map4 right ->map1 left 



			x[0] = 1; //��Ż�� �ٽ� Ÿ�� �ʵ��� �׸����� �����ؾ� ��.
			y[0] = 8 + i;
			//dir ������ �״�� 
			return 1;


		}//map4 right pass

		else if (x[0] == 9 + i && y[0] == 19 && i<3) {//map1 �ϴ� -> map3 ��� 


			x[0] = 39 + i; y[0] = 1;
			//�״�� dir
			return 1;

		}//�� 1 �ϴ� pass

		else if (x[0] == 39 + i  && y[0] == 0 && i<3) { //map3��� -> map1 �ϴ�


			x[0] = 9 + i; y[0] = 18;
			//�״��
			return 1;
		} // map3 ��� pass


		/* ���� ���� : ������ ������ǥ�� ������ �س��� MAP_X, MAP_Y���� define�� �����ϸ� ������ �� ���̴�. */


		else if (x[0] == 9 + i && y[0] == 0) {//map1 ��� -> map2�ϴ� 


			x[0] = MAP_X / 2 - 1 + i; y[0] = MAP_Y + MAP_Y2 - 1;
			//�״��
			return 1;


		}//��1 ���

		else if (x[0] == MAP_X / 2 - 1 + i && y[0] == MAP_Y + MAP_Y2) {//map2 �ϴ� -> map1 ��� 


			x[0] = MAP_X / 2 - 1 + i; y[0] = 1;
			//�״�� 
			return 1;

		} //map2 �ϴ� 



		else if (x[0] == MAP_X / 2 - 1 + i && y[0] == MAP_Y + 1) { //to map3 �ϴ�


			x[0] = MAP_X + MARGIN * 2 + MID_MARGIN_X + MAP_X / 2 + i; y[0] = MAP_Y2 - 1;
			//�״��
			return 1;


		} //��2 ��� 
		else if (x[0] == MAP_X + MARGIN * 2 + MID_MARGIN_X + MAP_X / 2 + i && y[0] == MAP_Y2) { //to ��2 ��� 


			x[0] = MAP_X / 2 - 1 + i; y[0] = MAP_Y + 2;
			return 1;
			//�״��


		} //map 3 �ϴ�



		else if (x[0] == 0 && y[0] == MAP_Y + MARGIN + MAP_Y2 - 3 - i) { //to map4 left


			x[0] = MAP_X2 + MARGIN + 1; y[0] = MAP_Y - i;
			dir = RIGHT;//���� -> ������ 

			return 1;


		}//map2 left


		else if (x[0] == MAP_X2 + MARGIN && y[0] == MAP_Y - i) {//tp map2 left

			x[0] = 1; y[0] = MAP_Y + MARGIN + MAP_Y2 - 3 - i;
			dir = RIGHT;//���� -> ������ 

			return 1;


		} //map4 left pass ---



		else if (x[0] == MAP_X2 - 1 && y[0] == MAP_Y + MARGIN + MAP_Y2 - 7 + i) {//to ��3 ����

			x[0] = MAP_X + MARGIN + 1; y[0] = MAP_Y2 / 2 - 1 + i;

			return 1;



			//�״��
		}//map2 right �н�



		else if (x[0] == MAP_X + MARGIN && y[0] == MAP_Y2 / 2 - 1 + i) {//to ��2 ������

			x[0] = MAP_X2 - 2; y[0] = MAP_Y + MARGIN + MAP_Y2 - 7 + i;


			return 1;

			//�״��
		}//��3 ����  �н�


		else if (x[0] == MAP_X + MARGIN * 2 + MID_MARGIN_X + MAP_X / 2 + i && y[0] == MAP_Y2 + 2) {//to map2 ��� 2��° 

			x[0] = MAP_X + MAP_X / 2 - 1 + i;
			y[0] = MAP_Y + 2;
			dir = DOWN; //up-> down

			return 1;


		} //mp4 ��� 



		else if (x[0] == MAP_X + MAP_X / 2 - 1 + i && y[0] == MAP_Y + 1) {//to map4 ��� 

			x[0] = MAP_X + MARGIN * 2 + MID_MARGIN_X + MAP_X / 2 + i; y[0] = MAP_Y2 + 3;
			dir = DOWN; //up->down
			return 1;

		}// //MAP2 ��� 2��° 


		Sleep(20); //��Ż �ֹ� ���ο� ?��������  
		potal();
	}
	return 0;
	// ��Ż�� �ɷ��� ���������� ó���� ��� 1 �ɸ��� ���� ��� 0

}
void game_over() //���� ���� ȭ�� 
{
	int input;
	system("cls");
	draw();
	//����� 
	gotoxy(15, 8, "                                                                                                            ");
	gotoxy(15, 9, "                                                                                                            ");
	TextColor(DEEP_OC);

	gotoxy(15, 10, "    �������            �����        ����          ����   ������������          "); Sleep(100);
	gotoxy(15, 11, "  ���                  ����    ����    �����      �����   �����"); Sleep(100); TextColor(DEEP_WHITE);
	gotoxy(15, 12, "���                  ����        ����  ������������   ������������        "); Sleep(100);
	gotoxy(15, 13, "���        ����    �����������  ������������   ������������        "); Sleep(100); TextColor(DEEP_OC);
	gotoxy(15, 14, "���          ���    ����        ����  ����  ����  ����   �����"); Sleep(100);
	gotoxy(15, 15, "  ���        ���    ����        ����  ����   ���   ����   ������������"); Sleep(100); TextColor(DEEP_WHITE);
	gotoxy(15, 16, "    ��������    ����        ����  ����   ���   ����   ������������"); Sleep(100);

	gotoxy(15, 17, "                                                                                                                  "); //����� 

	gotoxy(15, 18, "           ���������     ����    ����  ������������   ���������           "); Sleep(100); TextColor(DEEP_OC);
	gotoxy(15, 19, "         ���            ���   ����    ����  �����                ����         ����       "); Sleep(100);
	gotoxy(15, 20, "         ���            ���   ����    ����  ������������  ����          ����            "); Sleep(100); TextColor(DEEP_WHITE);
	gotoxy(15, 21, "         ���            ���   ����    ����  ������������  ����          ����            "); Sleep(100);
	gotoxy(15, 22, "         ���            ���   ����    ����  �����                ������������         "); Sleep(100); TextColor(DEEP_OC);
	gotoxy(15, 23, "         ���            ���     �������    ������������  �����    ������           "); Sleep(100);
	gotoxy(15, 24, "           ���������          ����       ������������  �����        ����           "); Sleep(100);

	gotoxy(15, 25, "                                                                                                             ");
	gotoxy(15, 26, "                                                                                                              "); //�����

	number(score);



	TextColor(DEEP_WHITE);
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 6, "�׸޴�: t "); //���� ����� 
	Sleep(200);
	if (score > best_score)
	{
		best_score = score;
		TextColor(DEEP_YELLOW);
		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 8, "��  BEST SCORE  ��"); Sleep(200);

	}

	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 10, MAP_ADJ_Y + 18, "                       "); //�ϵ����� ���� ����

	if (hard == on) {
		TextColor(DEEP_RED);
		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 10, MAP_ADJ_Y + 19, " ���� ����� ���   "); //�ϵ��忴�ٸ�.. 
	}

	gotoxy(MAP_ADJ_X + (MAP_X / 2) , MAP_ADJ_Y + 19, ""); //���� ���� ����� ���� ���� ��ġ 
	if (mode == easy)
	{
		TextColor(DEEP_GREEN);
		printf("[ ���� ]");
	}
	else if (mode == normal)
	{
		TextColor(DEEP_YELLOW);
		printf("[ ���� ]");


	}
	else if (mode == hard_)
	{
		TextColor(JAJU);
	printf("[ ����� ]");
	}
	while (_kbhit()) _getch(); //�̸� �Է��� ������ ���� game_over���� �� ������ ��츦 ������.

	game_over_press();//���� ���� ���߿�. ���⼭ �Է��ϰ� reset���� ��. h�� �����ٸ� ��� change

	input = _getch();//press���� �Է��� ���� ����.

	


	if (input == T) title(); // //t�� �Է��ϸ� title ->title�� reset -> move ���� -> �ٽ� Ű �ް�(���� ����)

	else reset(&FOOD); //h�̿��� ������Ű �Է½� �׳� ���� �׷��� reset

					   //������ reset ����

}
void game_over_press()
{

	while (1) //���� ���� ��¦�� 
	{
		
		
		TextColor(DEEP_JAJU);

		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 4, "��  Press Any Key to Start ��"); //���� �����  
		Sleep(200); if (_kbhit()) break; //Ű ������ �ν��ϰ� �Լ� ��.

		TextColor(DEEP_OC);

		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 4, "��  Press Any Key to Start ��"); //���� �����  
		Sleep(200); if (_kbhit()) break; //200 ���� �Է��� Ű�� �ִٸ� �Լ� ��.
		
		
	}	



}
void pause(int *p)
{



	if (*p == 1)
	{
		gotoxy(MAP_ADJ_X + MAP_X / 2 - 4, MAP_ADJ_Y + MAP_Y / 2, "�� �� �� �� �� ��");

	}
	while (1)
	{

		if (key == PAUSE) {
			_getch();
			gotoxy(MAP_ADJ_X + MAP_X / 2 - 4, MAP_ADJ_Y + MAP_Y / 2, "                  ");

			*p = 0;
			if (_kbhit()) do { key = _getch(); } while (key == 224); //����Ű�� �ν��Ͽ� key�� ����
			return;
		}
	}



}
void status()
{
	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 10, "head :");
	printf("%2d ,%2d", x[0], y[0]);

	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 11, "food :");
	printf("%2d,%2d", food_x, food_y);

	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 12, "length :");
	printf("%2d", length);

	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 13, "key :");
	printf("%3d", key);

	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 14, "speed :");
	printf("%3d", speed);

	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 15, "score :");
	printf("%3d", score);


}
void status_off()
{
	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y+10, "                  "); //status �ڸ� ����� 
	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 11, "                 ");
	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 12, "                 ");
	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 13, "                 ");
	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 14, "                ");
	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 15, "                ");
	
}

int death_line() //���� �ʴ��� 0 �ʴ�x = 1
{

	int i;
	if (x[0] == 60 || x[0] == 0 || y[0] == 0 || y[0] == 28) // ��ü���� ū �µθ��� �ǹ��ϹǷ� �� ��쿡�� �ʴ�ó��. �׷���, �̰� ����� �״� ��찡 �־ ������ ������.
		return 0;   //�н�


	if (y[0] == 19)
	{
		for (i = 0; i < MAP_X; i++)
		{
			if (x[0] == i) return 0;

		}


	}//map1 �ϴ� �н� 

	if (x[0] == 19)
	{
		for (i = 0; i < MAP_Y; i++)
		{
			if (y[0] == i) return 0;
		}


	}//map1 ������ �н� 

	if (y[0] == 21)
	{
		for (i = 0; i < MAP_X2; i++)
		{
			if (x[0] == i) return 0;
		}
		//map2 ��� ok

	}

	if (x[0] == 39)
	{
		for (i = 21; i < MAP_Y2 + 21; i++)
		{
			if (y[0] == i) return 0;
		}


	}//Map2 ������ ok

	if (x[0] == 41)
	{

		for (i = 10; i < 29; i++) //10 ~28
		{
			if (y[0] == i) return 0;
		}
	} //map4 left ok

	if (y[0] == 10)
	{

		for (i = 41; i < 61; i++)//y�� 10�϶� x�� ���� ���� �״´�.
		{
			if (x[0] == i) return 0;
		}

	}//map4 ��� ok

	if (x[0] == 21)
	{
		for (i = 0; i < MAP_Y2; i++)
		{
			if (y[0] == i) return 0;
		}

		//map3 ���� ok
	}

	if (y[0] == 8)
	{
		for (i = 21; i < 61; i++)
		{
			if (x[0] == i) return 0;
		}


	}//map3 �ϴ� ok


	 /* ������ �ʴ� ���� �а��Ͽ� �������ش�. ex y[0]==8 �϶� x�� ���ǿ� �´� ���鸸 ����. */

	return 1; //���� ��ħ 0 ��ȯ ��� ���̶� ���Ͽ� ��ġ�� ���� ���(�浹 x)���� ���� for�� �� ������ �����Ͽ� 1��ȯ.

}


void move(int dir, struct FOOD *FOOD)
{
	int i = 0; //�ϴ� �̿�X ����
	int last = length; //�������� length�� ���ϴ� �뵵.  ���� ���� �޾Ƶΰ�, ��ȭ�� ������ (���� ����) ������ ���� �����.

	

	if (x[0] == food_x && y[0] == food_y || food_crush_on == 1) //�Ӹ��� �� or ������ ���� ���� ����

		/* �߰� ����: ������ �Դ� ������� 2������ �ִ�. ���뿡 �ڵ����� ���� ���, �Ӹ��� �Դ� ���
														 �� food �Լ����� ����->move����        �� move (�̰�)���� ó��

														 move������ ����, �������� ���� ó���ϸ� �ٽ� ������ �������ش�.
		*/
	{
		//���� �� ���� 

		/* ȥ�� ���� ���̵��� ����
	FAKE ���� ����      �� �ӵ� ����	���̵��� title�� setting���� ���� ����.
		*/

		if (con == green_clover)
		{

			score += 1; FOOD->clover->eat += 1;
			if (FOOD->clover->eat % 5 == 0) {
				length += 1;

				if (speed >= 80) { //speed�� 80�̻��� ��츸 �ӵ��� ����. ex 79�� ���̸� ���� 
					if (mode == normal) speed -= 1;
					else if (mode == hard_) speed -= 2;
					speed -= 1;
				}

				//���̵��� ���� ������ �ش� ���� ����/�����  ���� 1 ����� 2 �� �� 

			
			}

			gotoxy(MAP_ADJ_X + MAP_X + 10, MAP_ADJ_Y + MAP_Y2 + MARGIN + 2, "1�� * "); printf("%d", FOOD->clover->eat);
		}
			else if (con == red_clover) {
				score += 5; FOOD->Red_clover->eat += 1;
				if (FOOD->Red_clover->eat % 2 == 0) {
					length += 1;

					if (speed >= 80) {
						if (mode == normal) speed -= 1;
						else if (mode == hard_) speed -= 2;
						speed -= 1;
					}

				}
				gotoxy(MAP_ADJ_X + MAP_X + 10, MAP_ADJ_Y + MAP_Y2 + MARGIN + 4, "5�� * "); printf("%d", FOOD->Red_clover->eat);



			}
			else if (con == jaju_clover) {
				score += 10; FOOD->Jaju_clover->eat += 1;
				if (FOOD->Jaju_clover->eat % 3 == 0) {
					length += 1;

					if (speed >= 80) {
						if (mode == normal) speed -= 1;
						else if (mode == hard_) speed -= 2;

						speed -= 1;
					}
				}
				gotoxy(MAP_ADJ_X + MAP_X + 10, MAP_ADJ_Y + MAP_Y2 + MARGIN + 8, "10�� * "); printf("%d", FOOD->Jaju_clover->eat);


			}
			else if (con == yellow_clover) {
				score += 25; FOOD->Yellow_clover->eat += 1;
				length += 1; 	

				if (speed >= 80) {

					speed -= 1;

					if (mode == normal) speed -= 1;
					else if (mode == hard_) speed -= 2;
				}
				gotoxy(MAP_ADJ_X + MAP_X + 10, MAP_ADJ_Y + MAP_Y2 + MARGIN + 10, "25�� * "); printf("%d", FOOD->Yellow_clover->eat);


			}
			else if (con == oc_clover) {
				score += 3; FOOD->OC_clover->eat += 1;

				if (FOOD->OC_clover->eat % 2 == 0) {
					length += 1;
					if (speed >= 80) {
						if (mode == normal) speed -= 1;
						else if (mode == hard_) speed -= 2;
						speed -= 1;
					}
				}
				gotoxy(MAP_ADJ_X + MAP_X + 10, MAP_ADJ_Y + MAP_Y2 + MARGIN + 6, "3�� X "); printf("%d", FOOD->OC_clover->eat);


			}
			//������ ���� + ���� ������ �°� n���� ���������� length+1 , ���� �� +1 

			if (hard == 1) {//ȥ�� ��� ����ũ ���� 
				for (i; i < length + 1; i++) food(FOOD); //ó�� ���� 6�� ���� length 1���� 1���� �� 

				/* �߰� ����:
				food�Լ������� Ŭ�ι��� ��ǥ�� �����Ͽ� Ŭ�ι��� ����ϴµ� ��ǥ�� food_x food_y�� �ϳ��� ���� �ȴ�.

				��ü������ Ŭ�ι��� 3���� ������ 2���� ������ ���� ���̰� �������� ���� Ŭ�ι��� ��ǥ�� food_x food_y�� ���� real clover�� �ȴ�.

				title ���� ����

				*/
			}
			else
			{ //�Ϲ� ��� ���� ����ũ 
				for (i; i < length - 3; i++) //ó�� 5�������� 2�� ���� length�� 1�����ϸ� 1���� �� ����.  
					food(FOOD); //�� ���� ���� + �ӵ� ����
			}

			if (last != length) //���̰� ������ ���
			{
				x[length - 1] = x[length - 2];
				y[length - 1] = y[length - 2];
				/* �߰� ����:

				�� �κ��� �׸� �׷��� �ѹ� �׷����� �ٷ� ������ �� �ִ� �κ����� ���� move�� �����ϸ� ������ �� �ִ�. �𸣰����� ��ȭ 010 6464 2211

				*/
			}

			if (score >= 20) //��Ż�� ���� �ٽ� �����ؼ� ����� ������. (������ real clover ���� �� ���� �Ӹ� ��� ���� ���� ������.
			{
				potal(); potal_on = on;
			}
		
		}


	
		if (death_line() == 0) //���� �ʴ� return 0;
		{
			if (potal_on == on)
			{

				i = potal_move();//��Ż�� ��ġ�� ������ ó��/ ���� ������ ó��X

			}

			if (i == 1)//��Ż�� �̿���.
			{

				return;
			}
			else
			{ //potal off �� ���� ��� else�� ��.  ��Ż�� ���ε� ���� ��� ��Ż�� �� ���� �ƴ϶�, ������ �� ��� i=0 else�� ���� GAme over

				game_over(); return;
			}
		}


		


		for (i = 1; i < length; i++)
		{
			if (x[0] == x[i] && y[0] == y[i])//�Ӹ��� ��ǥ�� ������ ��ǥ�� ����
			{
				game_over(); //�ڱ� ���� �Դ� 180�� ȸ���� �����ϰ� ���뿡 �ε����� ���
				return;

			}
		}


		gotoxy(MAP_ADJ_X + x[length - 1], MAP_ADJ_Y + y[length - 1], " ");//���� ������ �����

	
		for (i = length - 1; i > 0; i--) //������ ��ǥ �ű�� 
		{
			x[i] = x[i - 1];
			y[i] = y[i - 1];


		}


		TextColor(DEEP_RED);
		gotoxy(MAP_ADJ_X + x[0], MAP_ADJ_Y + y[0], "��");//���� �Ӹ� �ڸ� �� ��������  

		if (dir == LEFT) --x[0];
		if (dir == RIGHT) x[0]++;
		if (dir == UP) y[0]--;
		if (dir == DOWN) y[0]++;

		gotoxy(MAP_ADJ_X + x[0], MAP_ADJ_Y + y[0], "��");

		//���ο� �Ӹ��� �׸� �Ŀ� ���ο� ��ǥ�� �Ű� �Ӹ��׸���.
		TextColor(DEEP_WHITE);



	
}

void reset(struct FOOD *FOOD)//���� ���� �غ�
{
	int i;
	system("cls");
	draw(); //ȭ�� ����� �ʱ׸��� 

	while (_kbhit()) _getch(); //���� ���ֱ� 

	dir = LEFT; //�⺻���� ������ ����.

	if (hard == 1) speed = 110; //�ӵ� �ణ ���� ȥ�� ���
	else speed = 123; //�Ϲ� 

	length = 5;
	score = 0;
	potal_on = off;


	FOOD->clover->eat = 0; //�⺻ Ŭ�ι� ���� �ʱ�ȭ
	FOOD->Jaju_clover->eat = 0;//���� �ʱ�ȭ
	FOOD->OC_clover->eat = 0; //oc �ʱ�ȭ
	FOOD->Red_clover->eat = 0; //red
	FOOD->Yellow_clover->eat = 0;


	TextColor(DEEP_RED);
	for (i = 0; i < length; i++)
	{
		x[i] = MAP_X / 2 + i; //ó�� ��ġ�� ���� ���� +1  00000
		y[i] = MAP_Y / 2;// y���� ���� 
		gotoxy(MAP_ADJ_X + x[i], MAP_ADJ_Y + y[i], "��");//margin + x, marginn + y


	}
	gotoxy(MAP_ADJ_X + x[0], MAP_ADJ_Y + y[0], "��");//�� �Ӹ� 

	food(FOOD);//FOOD ����ü�� ����Ű�� ������(�ּҰ�)�� ����.
	TextColor(DEEP_WHITE);
}

void food(struct FOOD *FOOD)
{
	TextColor(DEEP_WHITE);
	int i;


	food_crush_on = 0; //food�� �⺻�� 
	

	int n = rand() % 5 + 1;// 1~5
						   //���� 
	TextColor(DEEP_OC);
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y - 1, "����: "); //���� ǥ�� 
	printf("%3d", score);
	TextColor(DEEP_JAJU);
	printf("  LAST SCORE: %3d", last_score);
	TextColor(DEEP_YELLOW);
	printf("  BEST SCORE: %3d", best_score);

	/*��� ���� */

	TextColor(DEEP_GREEN);
	gotoxy(MAP_ADJ_X + MAP_X + 15, MAP_ADJ_Y + MAP_Y2 + MARGIN + 2, "��");
	TextColor(DEEP_WHITE);
	printf(" X %03d", FOOD->clover->eat);

	TextColor(DEEP_RED);
	gotoxy(MAP_ADJ_X + MAP_X + 15, MAP_ADJ_Y + MAP_Y2 + MARGIN + 4, "��");
	TextColor(DEEP_WHITE);
	printf(" X %03d", FOOD->Red_clover->eat);

	TextColor(DEEP_OC);
	gotoxy(MAP_ADJ_X + MAP_X + 15, MAP_ADJ_Y + MAP_Y2 + MARGIN + 6, "��");
	TextColor(DEEP_WHITE);
	printf(" X %03d", FOOD->OC_clover->eat);

	TextColor(DEEP_JAJU);
	gotoxy(MAP_ADJ_X + MAP_X + 15, MAP_ADJ_Y + MAP_Y2 + MARGIN + 8, "��");
	TextColor(DEEP_WHITE);
	printf(" X %03d", FOOD->Jaju_clover->eat);

	TextColor(DEEP_YELLOW);
	gotoxy(MAP_ADJ_X + MAP_X + 15, MAP_ADJ_Y + MAP_Y2 + MARGIN + 10, "��");
	TextColor(DEEP_WHITE);
	printf(" X %03d", FOOD->Yellow_clover->eat);

	
	/* �߰� Ŭ�ι� ��� */

	if (n == 1 || score <= 20) 
	{//20 <=���� clover map1
		


		food_x = (rand() % (MAP_X - 2)) + 1; 
		food_y = (rand() % (MAP_Y - 2)) + 1; 
		/*
		�߰� ����: �̰� ��ǥ�� ���� �� ���� �׽��� �Լ��� ����� ��µ� Ȯ���غ��� �ʹٸ� blog.naver.com/lmj3322 �ҽ��� ����.
		
		*/


		for (i = 0; i < length; i++)
		{

			if (food_x == x[i] && food_y == y[i])//5���� ������ ��ġ�� food�� ���ƴ��� Ȯ���ؼ� (���۰� ���ÿ� ���� ������ ź��)
			{
				food_crush_on = 1;   //1���� �Ŀ� move�� ó�� con���º��� ���� ó���ϰ� food ���� 
				con = green_clover;
				return;
			}


		}




		TextColor(DEEP_GREEN);

		gotoxy(MAP_ADJ_X + food_x, MAP_ADJ_Y + food_y, "��");//���� Ŭ�ι�. 

		con = green_clover; //���Ŀ� realclover�� ��ǥ�� �Բ� ���Ǿ� �ش� Ŭ�ι��� ������ �ִ� �뵵
	}
	//�ʱ� 20 �� �������� (��Ż���� ����) clover�� �⺻������

	
	else //20�� ����  n==1�� ��� Ŭ�ι� ��,
	{

		if (n == 2)
		{ //red _ clover  map2
			

			FOOD->Red_clover->x = (rand() % (MAP_X2 - 2)) + 1; 
			FOOD->Red_clover->y = (rand() % (MAP_Y2 - 2)) + MAP_Y + MARGIN + 1; 


			for (i = 0; i < length; i++)
			{

				if (FOOD->Red_clover->x == x[i] && FOOD->Red_clover->y == y[i])
				{
					food_crush_on = 1;
					con = red_clover;
					return;
				}


			}


		

			TextColor(DEEP_RED);

			gotoxy(MAP_ADJ_X + FOOD->Red_clover->x, MAP_ADJ_Y + FOOD->Red_clover->y, "��");
			con = red_clover;
			food_x = FOOD->Red_clover->x; food_y = FOOD->Red_clover->y;

		}
		else if (n == 3) 
		{//jaju clover map3


	 

			FOOD->Jaju_clover->x = (rand() % (MAP_X2 - 2)) + 1;
		FOOD->Jaju_clover->y = (rand() % (MAP_Y2 - 1)) + 1;



			for (i = 0; i < length; i++)
			{

				if (FOOD->Jaju_clover->x == x[i] && FOOD->Jaju_clover->y == y[i])
				{
					food_crush_on = 1;
					con = jaju_clover;
					return;
				}


			}



			TextColor(DEEP_JAJU);

			gotoxy(MAP_ADJ_X + MAP_X + MARGIN + FOOD->Jaju_clover->x, FOOD->Jaju_clover->y + MAP_ADJ_Y, "��");

			con = jaju_clover;
			food_x = MAP_X + MARGIN + FOOD->Jaju_clover->x; food_y = FOOD->Jaju_clover->y;
		}
		else if (n == 4)
		{//��� Ŭ�ι� �� 4 


		


			FOOD->Yellow_clover->x = (rand() % (MAP_X - 2)) + 1;
			FOOD->Yellow_clover->y = (rand() % (MAP_Y - 3)) + 2;//1�� ���� ����.


			for (i = 0; i < length; i++)
			{

				if (FOOD->Yellow_clover->x == x[i] && FOOD->Yellow_clover->y == y[i])
				{
					food_crush_on = 1;
					con = yellow_clover;
					return;
				}


			}


			TextColor(DEEP_YELLOW);

			gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + FOOD->Yellow_clover->x, FOOD->Yellow_clover->y + MAP_ADJ_Y + MAP_Y2 + MARGIN, "��");

			con = yellow_clover;
			food_x = MAP_X2 + MARGIN + FOOD->Yellow_clover->x; food_y = FOOD->Yellow_clover->y + MAP_Y2 + MARGIN;
		}
		else if (n == 5) 
		{//oc clover ��4


			FOOD->OC_clover->x = (rand() % (MAP_X - 2)) + 1;
			FOOD->OC_clover->y = (rand() % (MAP_Y - 3)) + 2; 



			for (i = 0; i < length; i++)
			{

				if (FOOD->OC_clover->x == x[i] && FOOD->OC_clover->y == y[i])
				{
					food_crush_on = 1;
					con = oc_clover;
					return;
				}


			}


		
			TextColor(DEEP_OC);

			gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + FOOD->OC_clover->x, FOOD->OC_clover->y + MAP_ADJ_Y + MAP_Y2 + MARGIN, "��");
			con = oc_clover;
			food_x = MAP_X2 + MARGIN + FOOD->OC_clover->x; food_y = FOOD->OC_clover->y + MAP_Y2 + MARGIN;

		}



		

	}

	TextColor(DEEP_WHITE);
	
}

void Press() //�ʱ� Ÿ��Ʋ���� �����̴� ȸ�� ? (�ִϸ��̼� ����)
{
	int i = 1;
	while (1) {

		if (i == 1)
		{
			gotoxy_C(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 8, "��  < �ƹ� Ű�� �������� > ��", GRAY); //���� ����� 



			Sleep(800);

			if (_kbhit()) break;

			i++; //ó������ ����.
		}
		//Sleep ����  Ȥ�� Ű�� ���� ��� �Լ� Ż�� (���� �̰��� ���� ���� �ʴٴ� �ǰ��� ����)
		if (_kbhit()) break;

		/* 
		Ÿ��Ʋ �� �ִϸ��̼� �κп��� ����� ����
		
		*/
		TextColor(DEEP_WHITE);
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 10, MAP_ADJ_Y, "��"); //�� ���� ó������ �׳� ���� ����� ���Ŀ� ���� 
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 1, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 2, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "                        ");// ���� �ܻ� ���ֱ� 

		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 27, MAP_ADJ_Y + 5, "   ");


		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 20, MAP_ADJ_Y + 7, "   ");

		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 28, MAP_ADJ_Y + 4, "   "); //clover �ܻ�




		TextColor(GRAY);
		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 8, "�� PRESS ANY KEY TO START ��"); //���� ����� ��



		TextColor(DEEP_RED);
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "�ۡۡۡۡۡۡ�");
		TextColor(DEEP_GREEN);
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 10, MAP_ADJ_Y + 1, "��");

		TextColor(DEEP_OC);
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 13, MAP_ADJ_Y + 3, "��");

		TextColor(DEEP_OC);
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 13, MAP_ADJ_Y + 7, "��");

		Sleep(123); // title�� �ִ� �Ͱ� ����. (title�� ���� ������ �ϴ� ������ �� ���̷���/ ����ٰ� �� ���� �ִϸ��̼� �Ŀ� �ݺ��� �� �غ�. 
		if (_kbhit()) break;

		/* �ݺ� �ִϸ��̼� �غ� ��  ���� �Ʒ� */
		TextColor(DEEP_RED);
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "    �ۡۡۡۡۡ�");

		Sleep(123);
		if (_kbhit()) break;
		TextColor(DEEP_RED);
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "      �ۡۡۡۡۡ�");

		Sleep(123);
		if (_kbhit()) break;
		TextColor(DEEP_RED);
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "        �ۡۡۡۡۡ�");

		Sleep(123); //Sleep ���� ���� ���
		if (_kbhit()) break;
		TextColor(DEEP_RED);
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "          �ۡۡۡۡۡ�");

		TextColor(DEEP_JAJU);
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 27, MAP_ADJ_Y + 5, "��");


		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 20, MAP_ADJ_Y + 7, "��");

		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 28, MAP_ADJ_Y + 4, "��");
		Sleep(50);//��¦ term

		if (_kbhit()) break;
		TextColor(DEEP_RED);


		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "            �ۡۡۡۡۡ�");


		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "              �ۡۡۡۡ�");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "                      ��");


		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "                �ۡۡۡ�");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "                      ��");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "                      ��");



		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "                  �ۡۡ�");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "                      ��");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "                      ��");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "                      ��");



		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "                    �ۡ�");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "                      ��");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "                      ��");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "                      ��");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "                      ��");

		TextColor(DEEP_GREEN);
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "                    ��"); //������ ���� �Ӹ��� �� ������. ������.

		TextColor(DEEP_RED);

		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "                      ��");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "                      ��");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "                      ��");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "                      ��");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "                    �ߡ�");

		Sleep(123); if (_kbhit()) break;



		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "                      ��");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "                      ��");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "                      ��");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "                  �ߡۡ�");




		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "                      ��");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "                      ��");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "                �ߡۡۡ�");




		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "                      ��");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "              �ߡۡۡۡ�");


		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "              �ۡۡۡۡ�");



		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "              �ۡۡۡ�  ");



		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "              �ۡۡ�    ");





		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "              �ۡ�      ");



		Sleep(123); if (_kbhit()) break;

		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 2, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "              ��        ");



		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 1, "              ��          ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 2, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "                        ");



		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 10, MAP_ADJ_Y, "��"); //�����ٰ� ��! 
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 1, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 2, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "              ��        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "                        ");

		Sleep(123);

		if (_kbhit()) break;



		i = 2;

		if (i == 2)
		{
			TextColor(GRAY);
			gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 8, "��   WHY DON'T YOU PLAY   ��"); //�ٽ� ��� ��

			Sleep(1300); if (_kbhit()) break;
			i = 3;
		}


		if (i == 3)
		{
			TextColor(GRAY);
			gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 8, "��  S N A K E  F A K E R  ��"); //�ٽ� ��� ��

			Sleep(1300); if (_kbhit()) break;

		}
	}//press �ؽ�Ʈ�� �ѱ�ٰ� �ٽ� ������ũ �ִϸ��̼�  PRESS ���߿��� ������ �Է°��� �޾Ƽ� ������ �� �ִ�. �׳ɵθ� ���.


	TextColor(WHITE);
}

void draw()//���� �׸� 
{
	TextColor(DEEP_WHITE);
	int i;

	for (i = 0; i < MAP_X; i++)
	{
		gotoxy(MAP_ADJ_X + i, MAP_ADJ_Y, "��"); //��� map1 
											   /*����:

											   Ư�����ڴ� 2ĭ�� ������. �׷��� gotoxy���� *2�� �ϴ� ����. */



	}
	for (i = MAP_ADJ_Y + 1; i < MAP_ADJ_Y + MAP_Y - 1; i++) //map1 �߰� 
	{
		gotoxy(MAP_ADJ_X, i, "��");					
		gotoxy(MAP_ADJ_X + MAP_X - 1, i, "��");


	}
	for (i = 0; i < MAP_X; i++)
	{
		gotoxy(MAP_ADJ_X + i, MAP_ADJ_Y + MAP_Y - 1, "��"); //MAP_ADJ_Y ���� �������� ���� MAP_Y -1 ��ŭ �� ��� 


	}





	/* MAP 2 */

	for (i = 0; i < MAP_X2; i++)
	{
		gotoxy(MAP_ADJ_X + i, MAP_ADJ_Y + MAP_Y + MARGIN, "��");  //MAP2 ��� 



	}
	for (i = MAP_ADJ_Y + 1 + MARGIN + MAP_Y; i < MAP_ADJ_Y + MAP_Y - 1 + MARGIN + MAP_Y2; i++)  //��2 ��� ���� �ٴڱ��� 
	{
		gotoxy(MAP_ADJ_X, i, "��");
		gotoxy(MAP_ADJ_X + MAP_X2 - 1, i, "��");


	}

	for (i = 0; i < MAP_X2; i++)
	{
		gotoxy(MAP_ADJ_X + i, MAP_ADJ_Y + MAP_Y + MARGIN + MAP_Y2 - 1, "��"); //for�� ��ܰ� �״�� ��2 �ٴ�  -1�� �ʼ�


	}


	/* MAP 3 */


	for (i = 0; i < MAP_X2; i++)
	{
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + i, MAP_ADJ_Y, "��");  //MAP3 ��� 



	}
	for (i = MAP_ADJ_Y + 1; i < MAP_ADJ_Y + MAP_Y4 - 1; i++)  //��4 ��� ���� �ٴڱ��� 
	{
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN, i, "��");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + MAP_X2 - 1, i, "��");


	}

	for (i = 0; i < MAP_X2; i++)
	{
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + i, MAP_ADJ_Y + MAP_Y4 - 2, "��");  //MAP3 �ϴ� �Ʒ� MAP4 ��ܰ� ��ġ�Ƿ� -2�� �����.



	}




	/*MAP 4 */
	for (i = 0; i < MAP_X; i++)
	{
		gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + i, MAP_ADJ_Y + MAP_Y4 + MARGIN - 1, "��");  //MAP4 ��� 



	}
	for (i = MAP_ADJ_Y + MAP_Y4 + 1; i < MAP_ADJ_Y + MAP_Y4 + MAP_Y - 1; i++) // y���� �����ǹǷ� ��ġ�� �������� 0���� ������ ����� ����
	{
		gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN, i, "��");
		gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN - 1 + MAP_X, i, "��");


	}
	for (i = 0; i < MAP_X; i++)
	{
		gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + i, MAP_ADJ_Y + MAP_Y4 + MAP_Y - 2, "��");  //MAP4 �ϴ� 



	}
	


}


void title()
{
	system("cls");


	while (_kbhit()) _getch(); //���� �Ա�
							   //���� ���ֱ�.

	draw();

	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 / 2 - 1, "��"); //MAP3 left 
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 / 2, "��"); //MAP3 left 
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 / 2 + 1, "��"); //MAP3 left 

	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 / 2 + 2, "��"); //MAP3 left 
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 / 2 + 3, "��"); //MAP3 left 
																		 //��Ż ���� ����ֱ� 

																		 /*���� ���� �ڸ� ����� */
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 18, MAP_ADJ_Y + MAP_Y2 + MARGIN + 5, "                                                              ");
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 18, MAP_ADJ_Y + MAP_Y2 + MARGIN + 6, "                                                              ");
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 18, MAP_ADJ_Y + MAP_Y2 + MARGIN + 7, "                                                              ");
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 18, MAP_ADJ_Y + MAP_Y2 + MARGIN + 8, "                                                              ");
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 18, MAP_ADJ_Y + MAP_Y2 + MARGIN + 9, "                                                              ");
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 18, MAP_ADJ_Y + MAP_Y2 + MARGIN + 10, "                                                              ");
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 18, MAP_ADJ_Y + MAP_Y2 + MARGIN + 11, "                                                              ");
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 18, MAP_ADJ_Y + MAP_Y2 + MARGIN + 12, "                                                              ");
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 18, MAP_ADJ_Y + MAP_Y2 + MARGIN + 13, "                                                              ");
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 18, MAP_ADJ_Y + MAP_Y2 + MARGIN + 14, "                                                              ");
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 18, MAP_ADJ_Y + MAP_Y2 + MARGIN + 15, "                                                              ");
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 18, MAP_ADJ_Y + MAP_Y2 + MARGIN + 16, "                                                              ");
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 18, MAP_ADJ_Y + MAP_Y2 + MARGIN + 17, "                                                              ");
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 18, MAP_ADJ_Y + MAP_Y2 + MARGIN + 18, "                                                              ");

	/*���� ���� ���� */

	TextColor(DEEP_YELLOW);
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 4, MAP_ADJ_Y + MAP_Y2 + MARGIN + 4, "�� ���� ���� ��");

	TextColor(DEEP_WHITE);
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 15, MAP_ADJ_Y + MAP_Y2 + MARGIN + 7, "�� �� ������ �⺻���� ������ũ ����� �����ϴ�.");

	TextColor(GRAY);
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 15, MAP_ADJ_Y + MAP_Y2 + MARGIN + 8, "(�ӵ� ���� X)");

	TextColor(DEEP_WHITE);

	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 15, MAP_ADJ_Y + MAP_Y2 + MARGIN + 10, "�� Real clover�� ������ ������ �����մϴ�.");

	TextColor(GRAY);
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 15, MAP_ADJ_Y + MAP_Y2 + MARGIN + 11, "(���Ŀ� ���� ���� Ŭ�ι� �� �ϳ���");
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 7, MAP_ADJ_Y + MAP_Y2 + MARGIN + 12, " Real clover �� �˴ϴ� / �������� FAKE)");
	TextColor(DEEP_WHITE);

	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 15, MAP_ADJ_Y + MAP_Y2 + MARGIN + 13, "�� Ŭ�ι��� ���� ���� �ٸ� ������ �ο��˴ϴ�.");

	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 15, MAP_ADJ_Y + MAP_Y2 + MARGIN + 16, "�� 20���� �Ǹ� ��Ż�� �����Ǿ� �ٸ� �������� ");
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 + 5, MAP_ADJ_Y + MAP_Y2 + MARGIN + 17, " �� �� �ֽ��ϴ�.");

	/* ������ũ �⺻ �� */

	TextColor(DEEP_JAJU);
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 + MARGIN + 1, "[ ������ũ �⺻ ]");

	TextColor(DEEP_WHITE);

	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 + MARGIN + 4, "�� �Դ´�.");

	TextColor(GRAY);
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 + MARGIN + 5, "(�ڽ��� ������ Game Over)");

	TextColor(DEEP_WHITE);

	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 + MARGIN + 7, "�� (������) �������.");


	TextColor(GRAY);
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 + MARGIN + 8, "(�� ���ӿ����� Ŭ�ι��� ���� ���� ���� �������)");

	TextColor(DEEP_WHITE);

	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 + MARGIN + 10, "�� ���� �ε����� �״´�.");



	TextColor(DEEP_WHITE);
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 3, "������������������������������������������������������");
	gotoxy_C(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 4, "��       SNAKE FAKER       ��", DEEP_OC);
	TextColor(DEEP_WHITE);
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 5, "������������������������������������������������������");


	gotoxy_C(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 10, "�� ��: �����", DEEP_WHITE);
	gotoxy_C(MAP_ADJ_X + (MAP_X / 2) + 2, MAP_ADJ_Y + 10, "�� ��:   p", DEEP_WHITE);
	gotoxy_C(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 12, "ȥ�� ��� : h  ", DEEP_RED);

	if (hard == on) //ȥ�� ��尡 ���� �ִ� ���¸� ǥ�� 
	{
		TextColor(GRAY);
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 13,     "[ O N ]"); //���� reset�̳� �ٽ� title���� �� �ڸ��� �������� .
	}
	else
	{
		TextColor(GRAY);
		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 13, "[ OFF ]");
	}
	
	gotoxy_C(MAP_ADJ_X + (MAP_X / 2) + 2, MAP_ADJ_Y + 12, "�� ��:  ESC ", DEEP_WHITE);
	TextColor(DEEP_WHITE);
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 6, MAP_ADJ_Y + 17, "  Copyright ��2018-Yumin ");

	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 25, "  References : blog.naver.com/AZURE0777 (Snake Game)");


	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 8, MAP_ADJ_Y + 23, "            ���̵� ����: v");
	TextColor(DEEP_GREEN);
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 8, MAP_ADJ_Y + 23, "[ Setting ]");


	gotoxy(MAP_ADJ_X + (MAP_X / 2) +7, MAP_ADJ_Y + 23, "");//Ŭ�ι� ��ġ�� ���� ���� mode ����� ���� ����.
	
	TextColor(GRAY);
	printf("����:");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) + 10, MAP_ADJ_Y + 23, "");
	if (mode == easy)
	{
		
		printf("[ ���� ]");
	}
	else if (mode == normal)
	{
		
		printf("[ ���� ]");

	}
	else if (mode == hard_)
	{
	
		printf("[ ����� ]"); //���� title, reset������ ����� 
	}
	/* �ٸ��ֱ� */
	TextColor(DEEP_GREEN);
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 6, MAP_ADJ_Y + 17, "��");

	TextColor(DEEP_YELLOW);
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 17, "��");

	//copy ���� 


	TextColor(DEEP_OC);
	gotoxy(MAP_ADJ_X + (MAP_X / 2) + 6, MAP_ADJ_Y + 17, "��");


	TextColor(DEEP_JAJU);
	gotoxy(MAP_ADJ_X + (MAP_X / 2) + 7, MAP_ADJ_Y + 17, "��");

	//copy ������ 

	TextColor(DEEP_RED);
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 8, MAP_ADJ_Y + 25, "��"); //���۷��� 


															  /* ������ũ ���ϸ��̼� �غ�*/
	TextColor(DEEP_RED);
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "�ۡۡۡۡۡۡ�");
	TextColor(DEEP_GREEN);
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 10, MAP_ADJ_Y + 1, "��");

	TextColor(DEEP_OC);
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 13, MAP_ADJ_Y + 3, "��");

	TextColor(DEEP_OC);
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 13, MAP_ADJ_Y + 7, "��");
	

	while (_kbhit()) _getch(); //�̸� �Է��� ������ ����

	Press(); //���� ���Ϲ��̶� �߰��� ����� ���Ŀ� ǥ�ð� �� �� press���� �Է¹ް� �װ��� key�� �ν�
	
	while (1)
	{
		if (key = _getch())//�Է��� �ִٸ� ? 

			if (key == ESC) exit(0); //���� �Է½� ���� ������ ���� 
			else if (key == HARD) { //h�� �Է���.
				

					if (hard == 0) hard = 1; //�븻 -> �ϵ�
					else hard = 0; //�ϵ� -> �븻        

				

					title(); return;
					
				 }//h �Է½� �ϵ��� �� 
		    else if (key == SET) { User_set(); title(); return; }//v �Է� setting�ϰ� Ű �Է� reset return ���� ���� 
			else break; //�ƴ϶�� ���� ���� ����������.
	}

	reset(&FOOD);

}
void User_set()
{
	char input[15];
	system("cls");
	
	draw();
	//�⺻ DEEP_WHITE
	gotoxy(MAP_ADJ_X+3 , MAP_ADJ_Y + MARGIN+MAP_Y+3, "�̰��� �ӵ� �������� �����ϴ� �����Դϴ�."); TextColor(GRAY);
	gotoxy(MAP_ADJ_X+3, MAP_ADJ_Y + MARGIN + MAP_Y + 5, "  (����: A / ����: B / �����: C / ������: Q �Է�)");
	gotoxy_C(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 10, "���� ���̵��� ", DEEP_WHITE); 

	TextColor(GRAY);
	if (mode == easy)	printf("����");
	else if (mode == normal) 	printf("����");
	else if (mode == hard_) printf("�����");
		

	
	TextColor(DEEP_WHITE);
	
	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 13, ">  "); //���콺 ��ġ ���� 
	
	while (1)
	{

		gotoxy(MAP_ADJ_X + MAP_X + 2, MAP_ADJ_Y + 13, "               ");//�Է��� �ڸ� 

		TextColor(DEEP_WHITE); //���� ���� ������ ���ֱ� ���� 
		gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 13, ">  "); //�ݺ��ϱ� ���� ��ġ (�޴� ��ġ�� ����)
		

		scanf_s("%s", input, sizeof(input));



		TextColor(GRAY);
		
		
		gotoxy(MAP_ADJ_X + MAP_X + 8, MAP_ADJ_Y + 10, ""); //����� ��ġ ����  

		if (input[0]=='a' || input[0]=='A')
		{//������ ������ ����ȴ�.

			gotoxy(MAP_ADJ_X + MAP_X + 8, MAP_ADJ_Y + 10, "           "); //���� ���̵��� (    ) ����� �ٽ� ���.  ����� 3���� .. ���� 2���� ������ �Ұ�.
			
			gotoxy(MAP_ADJ_X + MAP_X + 8, MAP_ADJ_Y + 10, "����"); Sleep(200);
			mode = easy;
		}
		else if (input[0] == 'b' || input[0] == 'B')
		{
			gotoxy(MAP_ADJ_X + MAP_X + 8, MAP_ADJ_Y + 10, "          ");
			gotoxy(MAP_ADJ_X + MAP_X + 8, MAP_ADJ_Y + 10, "����"); Sleep(200);
			mode = normal;
		}
		else if (input[0] == 'c' || input[0] == 'C')
		{
			gotoxy(MAP_ADJ_X + MAP_X + 8, MAP_ADJ_Y + 10, "           ");
			gotoxy(MAP_ADJ_X + MAP_X + 8, MAP_ADJ_Y + 10, "�����"); Sleep(200);
			mode = hard_;
		}
		else if (input[0] == 'q' || input[0] == 'Q')
		{ 

			break; //Ÿ��Ʋ�� �̵�
		}
		else//???
		{
			gotoxy_C(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 16, "�ٽ� �Է�", DEEP_RED); 
			Sleep(250);
			gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 16, "         ");
			
		}
			
	/*a b c �� �Է��� ��쿡�� ����/ �����  else�� �״�� �α�.*/


	}
	
}