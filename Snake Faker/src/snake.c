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

enum Clover { green_clover = 1, red_clover, jaju_clover, yellow_clover, oc_clover };//상태변화 색깔 변환 구조체 이름과 달리해주기 위해 소문자로만
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80 
#define PAUSE 112
#define ESC 27
#define HARD 104

#define MAP_ADJ_X 3
#define MAP_ADJ_Y 2
#define MAP_X 20 //아무래도 이 값은 좌표의 길이를 의미하는 듯 하다.
#define MAP_Y 20
#define MARGIN 1 //Y 마진을 의미함 

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
#define SET 118 //v키 s는 status랑 겹침 물론 상관 없이 사용할 수 있지만..

#define MAP_ADJ_X 3
#define MAP_ADJ_Y 2
#define MAP_X 20 //아무래도 이 값은 좌표의 길이를 의미하는 듯 하다.
#define MAP_Y 20
#define MARGIN 1 //Y 마진을 의미함 

#define MAP_X2 40
#define MAP_Y2 8 

#define MAP_Y4 10
#define MAP_Y3 14

#define MID_MARGIN_X 18


struct FOOD { //음식 구조체를 가리키는 만능 포인터 구조체 집합.
	struct food *clover, *Red_clover, *OC_clover, *Yellow_clover, *Jaju_clover;

}FOOD;

struct food {

	int num;
	int x, y;
	int eat;



}clover, Red_clover, OC_clover, Jaju_clover, Yellow_clover;

int food_crush_on = 0;//몸통 위에 음식이 겹쳤는지 확인하는 변수 
int con = 0; //con 변수
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
int hard = 0; //하드 모드
int potal_on = off;

/* 모듈화 프로그래밍으로 데입은 snake.c에서만 */


void number(int score) {  //게임 끝나고 점수 띄우는 함수 


	int a, b, c, d;

	a = score / 1000;//1000자리 몫
	b = (score - a * 1000) / 100;//100자리 몫
	c = (score - a * 1000 - b * 100) / 10;//10
	d = score - a * 1000 - b * 100 - c * 10;//1


	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 21, "                              ");//상단 위


	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 22, "       ");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 23, "        ");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 24, "        ");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 25, "        ");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 26, "        ");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 27, "       ");


	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 28, "                                     ");//하단 

																			   /*숫자가 뜰 자리를 청소함. */


	TextColor(DEEP_GREEN);
	if (a == 1) //0000 첫자리. 천자리가 몫이 0인 경우 안 씀.
	{
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 22, "  ■■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 23, "■■■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 24, "  ■■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 25, "  ■■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 26, "  ■■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 27, "  ■■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 28, "  ■■");
	}
	else if (a == 2)
	{
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 24, "    ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 26, "■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 27, "■  ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 28, "■■■");

	}
	else if (a == 3)
	{


		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 24, "    ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 26, "    ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 27, "■  ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 28, "■■■");

	}
	else if (a == 4)
	{

		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 22, "■   ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 23, "■   ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 24, "■   ■ ");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 25, "■   ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 26, "■■■■■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 27, "    ■  ");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 28, "    ■");


	}
	else if (a == 5)
	{


		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 23, "■  ■ ");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 24, "■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 26, "    ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 27, "    ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 28, "■■■");

	}
	else if (a == 6)
	{
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 24, "■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 26, "■  ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 27, "■  ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 28, "■■■");

	}
	else if (a == 7)
	{

		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 24, "■  ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 25, "■  ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 26, "    ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 27, "    ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 28, "    ■");
	}
	else if (a == 8)
	{
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 24, "■  ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 26, "■  ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 27, "■  ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 28, "■■■");
	}
	else if (a == 9)
	{
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 24, "■  ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 26, "    ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 27, "■  ■");
		gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 28, "■■■");
	}




	Sleep(100);


	TextColor(DEEP_OC);






	if (b == 1) //0000 2자리.
	{
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 22, "  ■■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 23, "■■■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 24, "  ■■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 25, "  ■■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 26, "  ■■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 27, "  ■■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 28, "  ■■");
	}
	else if (b == 2)
	{
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 24, "    ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 26, "■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 27, "■  ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 28, "■■■");

	}
	else if (b == 3)
	{


		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 24, "    ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 26, "    ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 27, "■  ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 28, "■■■");

	}
	else if (b == 4)
	{

		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 22, "■   ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 23, "■   ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 24, "■   ■ ");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 25, "■   ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 26, "■■■■■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 27, "    ■  ");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 28, "    ■");


	}
	else if (b == 5)
	{


		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 23, "■  ■ ");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 24, "■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 26, "    ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 27, "    ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 28, "■■■");

	}
	else if (b == 6)
	{
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 24, "■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 26, "■  ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 27, "■  ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 28, "■■■");

	}
	else if (b == 7)
	{

		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 24, "■  ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 25, "■  ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 26, "    ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 27, "    ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 28, "    ■");



	}
	else if (b == 8)
	{
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 24, "■  ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 26, "■  ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 27, "■  ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 28, "■■■");
	}
	else if (b == 9)
	{
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 24, "■  ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 26, "    ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 27, "■  ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 28, "■■■");
	}
	else if (b == 0 && score >= 1000) //1023점처럼 100의 자리 몫이 0인 경우 0을 써줌.
	{
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 24, "■  ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 25, "■  ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 26, "■  ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 27, "■  ■");
		gotoxy(MAP_ADJ_X + 3, MAP_ADJ_Y + 28, "■■■");
	}



	Sleep(100);
	TextColor(DEEP_JAJU);


	if (c == 1) //0000 3자리.
	{
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 22, "  ■■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 23, "■■■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 24, "  ■■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 25, "  ■■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 26, "  ■■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 27, "  ■■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 28, "  ■■");
	}
	else if (c == 2)
	{
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 24, "    ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 26, "■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 27, "■  ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 28, "■■■");

	}
	else if (c == 3)
	{


		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 24, "    ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 26, "    ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 27, "■  ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 28, "■■■");

	}
	else if (c == 4)
	{

		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 22, "■   ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 23, "■   ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 24, "■   ■ ");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 25, "■   ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 26, "■■■■■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 27, "    ■  ");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 28, "    ■");


	}
	else if (c == 5)
	{


		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 23, "■  ■ ");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 24, "■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 26, "    ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 27, "    ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 28, "■■■");

	}
	else if (c == 6)
	{
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 24, "■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 26, "■  ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 27, "■  ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 28, "■■■");

	}
	else if (c == 7)
	{

		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 24, "■  ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 25, "■  ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 26, "    ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 27, "    ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 28, "    ■");
	}
	else if (c == 8)
	{
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 24, "■  ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 26, "■  ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 27, "■  ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 28, "■■■");
	}
	else if (c == 9)
	{
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 24, "■  ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 26, "    ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 27, "■  ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 28, "■■■");
	}
	else if (c == 0 && score >= 100) //0 203점처럼 10의 자리 몫이 0인 경우 0을 써줌.
	{
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 24, "■  ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 25, "■  ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 26, "■  ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 27, "■  ■");
		gotoxy(MAP_ADJ_X + 8, MAP_ADJ_Y + 28, "■■■");
	}
	Sleep(100);

	TextColor(DEEP_YELLOW);

	if (d == 1) //0000 4자리.
	{
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 22, "  ■■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 23, "■■■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 24, "  ■■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 25, "  ■■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 26, "  ■■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 27, "  ■■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 28, "■■■");
	}
	else if (d == 2)
	{
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 24, "    ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 26, "■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 27, "■  ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 28, "■■■");

	}
	else if (d == 3)
	{


		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 24, "    ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 26, "    ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 27, "■  ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 28, "■■■");

	}
	else if (d == 4)
	{

		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 22, "■   ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 23, "■   ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 24, "■   ■ ");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 25, "■   ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 26, "■■■■■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 27, "    ■  ");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 28, "    ■");


	}
	else if (d == 5)
	{


		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 23, "■  ■ ");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 24, "■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 26, "    ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 27, "    ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 28, "■■■");

	}
	else if (d == 6)
	{
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 24, "■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 26, "■  ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 27, "■  ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 28, "■■■");

	}
	else if (d == 7)
	{

		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 24, "■  ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 25, "■  ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 26, "    ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 27, "    ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 28, "    ■");
	}
	else if (d == 8)
	{
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 24, "■  ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 26, "■  ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 27, "■  ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 28, "■■■");
	}
	else if (d == 9)
	{
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 24, "■  ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 25, "■■■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 26, "    ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 27, "■  ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 28, "■■■");
	}
	else if (d == 0) //1의 자리가 0인 경우 그냥 0써줌. 
	{
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 22, "■■■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 23, "■  ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 24, "■  ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 25, "■  ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 26, "■  ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 27, "■  ■");
		gotoxy(MAP_ADJ_X + 13, MAP_ADJ_Y + 28, "■■■");
	}
	
	Sleep(400);//지연하고 입력받음 

	TextColor(DEEP_WHITE);



}
void potal() //potal _draw
{

	gotoxy(MAP_ADJ_X + MAP_X / 2 - 1, MAP_ADJ_Y, "─────");  //MAP1 상단  



	gotoxy(MAP_ADJ_X + MAP_X / 2 - 1, MAP_ADJ_Y + MAP_Y - 1, "─────");  //MAP1 하단



	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y / 2 - 2, "│"); //MAP1 left 
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y / 2 - 1, "│");
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y / 2, "│");

	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y / 2 + 1, "│");
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y / 2 + 2, "│");




	gotoxy(MAP_ADJ_X + MAP_X / 2 - 1, MAP_ADJ_Y + MAP_Y + 1, "─────");  //MAP2 상단

	gotoxy(MAP_ADJ_X + MAP_X + MAP_X / 2 - 1, MAP_ADJ_Y + MAP_Y + 1, "─────");  //MAP2 상단 2번째 



	gotoxy(MAP_ADJ_X + MAP_X / 2 - 1, MAP_ADJ_Y + MAP_Y + MAP_Y2, "─────");  //MAP2 하단




	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y + MARGIN + MAP_Y2 - 3, "│"); //MAP2 left 
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y + MARGIN + MAP_Y2 - 4, "│"); //MAP2 left 
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y + MARGIN + MAP_Y2 - 5, "│"); //MAP2 left 

	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y + MARGIN + MAP_Y2 - 6, "│"); //MAP2 left 
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y + MARGIN + MAP_Y2 - 7, "│"); //MAP2 left 





	gotoxy(MAP_ADJ_X + MAP_X2 - 1, MAP_ADJ_Y + MAP_Y + MARGIN + MAP_Y2 - 3, "│"); //MAP2 right 
	gotoxy(MAP_ADJ_X + MAP_X2 - 1, MAP_ADJ_Y + MAP_Y + MARGIN + MAP_Y2 - 4, "│"); //MAP2 right 
	gotoxy(MAP_ADJ_X + MAP_X2 - 1, MAP_ADJ_Y + MAP_Y + MARGIN + MAP_Y2 - 5, "│"); //MAP2 right 


	gotoxy(MAP_ADJ_X + MAP_X2 - 1, MAP_ADJ_Y + MAP_Y + MARGIN + MAP_Y2 - 6, "│"); //MAP2 right 
	gotoxy(MAP_ADJ_X + MAP_X2 - 1, MAP_ADJ_Y + MAP_Y + MARGIN + MAP_Y2 - 7, "│"); //MAP2 right 






	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 / 2 - 1, "│"); //MAP3 left 
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 / 2, "│"); //MAP3 left 
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 / 2 + 1, "│"); //MAP3 left 

	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 / 2 + 2, "│"); //MAP3 left 
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 / 2 + 3, "│"); //MAP3 left 



	gotoxy(MAP_ADJ_X + MAP_X + MARGIN + MID_MARGIN_X, MAP_ADJ_Y, "─────"); //MAP3 상단 포탈



	gotoxy(MAP_ADJ_X + MAP_X + MARGIN * 2 + MID_MARGIN_X + MAP_X / 2, MAP_ADJ_Y + MAP_Y2, "─────"); //MAP3 하단 포탈






	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN, MAP_ADJ_Y + MAP_Y, "│"); //MAP4 left 
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN, MAP_ADJ_Y + MAP_Y - 1, "│"); //MAP4  
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN, MAP_ADJ_Y + MAP_Y - 2, "│"); //MAP4  

	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN, MAP_ADJ_Y + MAP_Y - 3, "│"); //MAP4 left 
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN, MAP_ADJ_Y + MAP_Y - 4, "│"); //MAP4  


	gotoxy(MAP_ADJ_X + MAP_X + MARGIN * 2 + MID_MARGIN_X + MAP_X / 2, MAP_ADJ_Y + MAP_Y2 + 2, "─────"); //MAP4 상단 태두리로 가기위해 +2



	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X - 1, MAP_ADJ_Y + MAP_Y, "│"); //MAP4 right 
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X - 1, MAP_ADJ_Y + MAP_Y - 1, "│"); //MAP4  
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X - 1, MAP_ADJ_Y + MAP_Y - 2, "│"); //MAP4  

	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X - 1, MAP_ADJ_Y + MAP_Y - 3, "│"); //MAP4 right 
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X - 1, MAP_ADJ_Y + MAP_Y - 4, "│"); //MAP4  

	/*
		map1: 상단 정사각형 
		map2 하단 길쭉이
		map3 상단 길쭉이
		map4 하단 정사각형
	
	
	*/




}
int potal_move() //포탈 범위를 체크하고 들어간 경우 처리해주며 처리 이후에는 다시 그려주는 함수. 들어가면 머리가 이동하고 + Move로 인해서 몸이 따라간다.
{

	//벽의 좌표랑 같은데, 그게 포탈의 좌표인지 구분하여 포탈이면 처리해줌.

	for (int i = 0; i < 5; i++) //한 포탈에서 3부위를 의미함.
	{


		if (x[0] == 0 && y[0] == 8 + i) { //from map1 왼쪽 to map4 right




			x[0] = MAP_X2 + MARGIN + MAP_X - 2; //i값에 따라 3자리의 위치가 변함. i기준으로 gg 앵커 포탈의 위치를 지정해주되 또 포탈을 타지 않도록 x-2 -1하면 
												//반대편 포탈타고 다시 돌아와서 자기 몸 밟고 죽음.
			y[0] = MAP_Y - 4 + i; 
								  //dir 왼쪽 그대로.

			return 1; //포탈에 걸려서 실행됨. 



		}//맵1 왼쪽 pass 

		else if (x[0] == 60 && y[0] == 16 + i) {//map4 right ->map1 left 



			x[0] = 1; //포탈을 다시 타지 않도록 그림으로 이해해야 함.
			y[0] = 8 + i;
			//dir 오른쪽 그대로 
			return 1;


		}//map4 right pass

		else if (x[0] == 9 + i && y[0] == 19 && i<3) {//map1 하단 -> map3 상단 


			x[0] = 39 + i; y[0] = 1;
			//그대로 dir
			return 1;

		}//맵 1 하단 pass

		else if (x[0] == 39 + i  && y[0] == 0 && i<3) { //map3상단 -> map1 하단


			x[0] = 9 + i; y[0] = 18;
			//그대로
			return 1;
		} // map3 상단 pass


		/* 참고 사항 : 위에는 절대좌표로 데입을 해놔서 MAP_X, MAP_Y등의 define을 변경하면 오류가 뜰 것이다. */


		else if (x[0] == 9 + i && y[0] == 0) {//map1 상단 -> map2하단 


			x[0] = MAP_X / 2 - 1 + i; y[0] = MAP_Y + MAP_Y2 - 1;
			//그대로
			return 1;


		}//맵1 상단

		else if (x[0] == MAP_X / 2 - 1 + i && y[0] == MAP_Y + MAP_Y2) {//map2 하단 -> map1 상단 


			x[0] = MAP_X / 2 - 1 + i; y[0] = 1;
			//그대로 
			return 1;

		} //map2 하단 



		else if (x[0] == MAP_X / 2 - 1 + i && y[0] == MAP_Y + 1) { //to map3 하단


			x[0] = MAP_X + MARGIN * 2 + MID_MARGIN_X + MAP_X / 2 + i; y[0] = MAP_Y2 - 1;
			//그대로
			return 1;


		} //맵2 상단 
		else if (x[0] == MAP_X + MARGIN * 2 + MID_MARGIN_X + MAP_X / 2 + i && y[0] == MAP_Y2) { //to 맵2 상단 


			x[0] = MAP_X / 2 - 1 + i; y[0] = MAP_Y + 2;
			return 1;
			//그대로


		} //map 3 하단



		else if (x[0] == 0 && y[0] == MAP_Y + MARGIN + MAP_Y2 - 3 - i) { //to map4 left


			x[0] = MAP_X2 + MARGIN + 1; y[0] = MAP_Y - i;
			dir = RIGHT;//왼쪽 -> 오른쪽 

			return 1;


		}//map2 left


		else if (x[0] == MAP_X2 + MARGIN && y[0] == MAP_Y - i) {//tp map2 left

			x[0] = 1; y[0] = MAP_Y + MARGIN + MAP_Y2 - 3 - i;
			dir = RIGHT;//왼쪽 -> 오른쪽 

			return 1;


		} //map4 left pass ---



		else if (x[0] == MAP_X2 - 1 && y[0] == MAP_Y + MARGIN + MAP_Y2 - 7 + i) {//to 맵3 왼쪽

			x[0] = MAP_X + MARGIN + 1; y[0] = MAP_Y2 / 2 - 1 + i;

			return 1;



			//그대로
		}//map2 right 패스



		else if (x[0] == MAP_X + MARGIN && y[0] == MAP_Y2 / 2 - 1 + i) {//to 맵2 오른쪽

			x[0] = MAP_X2 - 2; y[0] = MAP_Y + MARGIN + MAP_Y2 - 7 + i;


			return 1;

			//그대로
		}//맵3 왼쪽  패스


		else if (x[0] == MAP_X + MARGIN * 2 + MID_MARGIN_X + MAP_X / 2 + i && y[0] == MAP_Y2 + 2) {//to map2 상단 2번째 

			x[0] = MAP_X + MAP_X / 2 - 1 + i;
			y[0] = MAP_Y + 2;
			dir = DOWN; //up-> down

			return 1;


		} //mp4 상단 



		else if (x[0] == MAP_X + MAP_X / 2 - 1 + i && y[0] == MAP_Y + 1) {//to map4 상단 

			x[0] = MAP_X + MARGIN * 2 + MID_MARGIN_X + MAP_X / 2 + i; y[0] = MAP_Y2 + 3;
			dir = DOWN; //up->down
			return 1;

		}// //MAP2 상단 2번째 


		Sleep(20); //포탈 멀미 슬로우 ?ㅋㅋㅋㅋ  
		potal();
	}
	return 0;
	// 포탈에 걸려서 정상적으로 처리된 경우 1 걸리지 않은 경우 0

}
void game_over() //게임 오버 화면 
{
	int input;
	system("cls");
	draw();
	//지우기 
	gotoxy(15, 8, "                                                                                                            ");
	gotoxy(15, 9, "                                                                                                            ");
	TextColor(DEEP_OC);

	gotoxy(15, 10, "    □□□□□□            □□□□        □□□          □□□   □□□□□□□□□□□          "); Sleep(100);
	gotoxy(15, 11, "  □□                  □□□    □□□    □□□□      □□□□   □□□□"); Sleep(100); TextColor(DEEP_WHITE);
	gotoxy(15, 12, "□□                  □□□        □□□  □□□□□□□□□□□   □□□□□□□□□□□        "); Sleep(100);
	gotoxy(15, 13, "□□        □□□    □□□□□□□□□□  □□□□□□□□□□□   □□□□□□□□□□□        "); Sleep(100); TextColor(DEEP_OC);
	gotoxy(15, 14, "□□          □□    □□□        □□□  □□□  □□□  □□□   □□□□"); Sleep(100);
	gotoxy(15, 15, "  □□        □□    □□□        □□□  □□□   □□   □□□   □□□□□□□□□□□"); Sleep(100); TextColor(DEEP_WHITE);
	gotoxy(15, 16, "    □□□□□□□    □□□        □□□  □□□   □□   □□□   □□□□□□□□□□□"); Sleep(100);

	gotoxy(15, 17, "                                                                                                                  "); //지우기 

	gotoxy(15, 18, "           □□□□□□□□     □□□    □□□  □□□□□□□□□□□   □□□□□□□□           "); Sleep(100); TextColor(DEEP_OC);
	gotoxy(15, 19, "         □□            □□   □□□    □□□  □□□□                □□□         □□□       "); Sleep(100);
	gotoxy(15, 20, "         □□            □□   □□□    □□□  □□□□□□□□□□□  □□□          □□□            "); Sleep(100); TextColor(DEEP_WHITE);
	gotoxy(15, 21, "         □□            □□   □□□    □□□  □□□□□□□□□□□  □□□          □□□            "); Sleep(100);
	gotoxy(15, 22, "         □□            □□   □□□    □□□  □□□□                □□□□□□□□□□□         "); Sleep(100); TextColor(DEEP_OC);
	gotoxy(15, 23, "         □□            □□     □□□□□□    □□□□□□□□□□□  □□□□    □□□□□           "); Sleep(100);
	gotoxy(15, 24, "           □□□□□□□□          □□□       □□□□□□□□□□□  □□□□        □□□           "); Sleep(100);

	gotoxy(15, 25, "                                                                                                             ");
	gotoxy(15, 26, "                                                                                                              "); //지우기

	number(score);



	TextColor(DEEP_WHITE);
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 6, "§메뉴: t "); //두줄 띄워서 
	Sleep(200);
	if (score > best_score)
	{
		best_score = score;
		TextColor(DEEP_YELLOW);
		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 8, "★  BEST SCORE  ★"); Sleep(200);

	}

	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 10, MAP_ADJ_Y + 18, "                       "); //하드모드의 위를 지움

	if (hard == on) {
		TextColor(DEEP_RED);
		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 10, MAP_ADJ_Y + 19, " 混沌 모드의 기록   "); //하드모드였다면.. 
	}

	gotoxy(MAP_ADJ_X + (MAP_X / 2) , MAP_ADJ_Y + 19, ""); //쉬움 보통 어려움 띄우기 위한 위치 
	if (mode == easy)
	{
		TextColor(DEEP_GREEN);
		printf("[ 쉬움 ]");
	}
	else if (mode == normal)
	{
		TextColor(DEEP_YELLOW);
		printf("[ 보통 ]");


	}
	else if (mode == hard_)
	{
		TextColor(JAJU);
	printf("[ 어려움 ]");
	}
	while (_kbhit()) _getch(); //미리 입력한 값들은 무시 game_over에서 막 누르는 경우를 방지함.

	game_over_press();//무한 와일 나중에. 여기서 입력하고 reset으로 들어감. h를 눌렀다면 모드 change

	input = _getch();//press에서 입력한 값을 받음.

	


	if (input == T) title(); // //t를 입력하면 title ->title내 reset -> move 종료 -> 다시 키 받고(게임 시작)

	else reset(&FOOD); //h이외의 나머지키 입력시 그냥 설정 그래로 reset

					   //누르면 reset 실행

}
void game_over_press()
{

	while (1) //게임 오버 빤짝이 
	{
		
		
		TextColor(DEEP_JAJU);

		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 4, "☆  Press Any Key to Start ☆"); //두줄 띄워서  
		Sleep(200); if (_kbhit()) break; //키 받으면 인식하고 함수 끝.

		TextColor(DEEP_OC);

		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 4, "☆  Press Any Key to Start ☆"); //두줄 띄워서  
		Sleep(200); if (_kbhit()) break; //200 동안 입력한 키가 있다면 함수 끝.
		
		
	}	



}
void pause(int *p)
{



	if (*p == 1)
	{
		gotoxy(MAP_ADJ_X + MAP_X / 2 - 4, MAP_ADJ_Y + MAP_Y / 2, "『 정 지 상 태 』");

	}
	while (1)
	{

		if (key == PAUSE) {
			_getch();
			gotoxy(MAP_ADJ_X + MAP_X / 2 - 4, MAP_ADJ_Y + MAP_Y / 2, "                  ");

			*p = 0;
			if (_kbhit()) do { key = _getch(); } while (key == 224); //방향키를 인식하여 key에 저장
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
	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y+10, "                  "); //status 자리 지우기 
	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 11, "                 ");
	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 12, "                 ");
	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 13, "                 ");
	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 14, "                ");
	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 15, "                ");
	
}

int death_line() //벽에 꽈당은 0 꽈당x = 1
{

	int i;
	if (x[0] == 60 || x[0] == 0 || y[0] == 0 || y[0] == 28) // 전체적인 큰 태두리를 의미하므로 이 경우에는 꽈당처리. 그런데, 이걸 벗어나서 죽는 경우가 있어서 범위로 지정함.
		return 0;   //패스


	if (y[0] == 19)
	{
		for (i = 0; i < MAP_X; i++)
		{
			if (x[0] == i) return 0;

		}


	}//map1 하단 패스 

	if (x[0] == 19)
	{
		for (i = 0; i < MAP_Y; i++)
		{
			if (y[0] == i) return 0;
		}


	}//map1 오른쪽 패스 

	if (y[0] == 21)
	{
		for (i = 0; i < MAP_X2; i++)
		{
			if (x[0] == i) return 0;
		}
		//map2 상단 ok

	}

	if (x[0] == 39)
	{
		for (i = 21; i < MAP_Y2 + 21; i++)
		{
			if (y[0] == i) return 0;
		}


	}//Map2 오른쪽 ok

	if (x[0] == 41)
	{

		for (i = 10; i < 29; i++) //10 ~28
		{
			if (y[0] == i) return 0;
		}
	} //map4 left ok

	if (y[0] == 10)
	{

		for (i = 41; i < 61; i++)//y가 10일때 x의 범위 에서 죽는다.
		{
			if (x[0] == i) return 0;
		}

	}//map4 상단 ok

	if (x[0] == 21)
	{
		for (i = 0; i < MAP_Y2; i++)
		{
			if (y[0] == i) return 0;
		}

		//map3 왼쪽 ok
	}

	if (y[0] == 8)
	{
		for (i = 21; i < 61; i++)
		{
			if (x[0] == i) return 0;
		}


	}//map3 하단 ok


	 /* 보이지 않는 벽을 분간하여 무시해준다. ex y[0]==8 일때 x의 조건에 맞는 값들만 잡음. */

	return 1; //벽과 겹침 0 반환 모든 벽이랑 비교하여 겹치지 않은 경우(충돌 x)에는 위의 for문 다 돌리고 무시하여 1반환.

}


void move(int dir, struct FOOD *FOOD)
{
	int i = 0; //일단 이용X 상태
	int last = length; //이전값과 length를 비교하는 용도.  이전 값을 받아두고, 변화가 있으면 (길이 증가) 마지막 몸통 지우기.

	

	if (x[0] == food_x && y[0] == food_y || food_crush_on == 1) //머리로 냠 or 음식이 몸통 위에 생성

		/* 추가 정보: 음식을 먹는 방법에는 2가지가 있다. 몸통에 자동으로 생긴 경우, 머리로 먹는 경우
														 ㄴ food 함수에서 변수->move에서        ㄴ move (이곳)에서 처리

														 move내에서 점수, 길이증가 등을 처리하며 다시 음식을 생성해준다.
		*/
	{
		//음식 냠 개수 

		/* 혼란 모드는 난이도와 별개
	FAKE 개수 증가      ㄴ 속도 증가	난이도는 title의 setting으로 변경 가능.
		*/

		if (con == green_clover)
		{

			score += 1; FOOD->clover->eat += 1;
			if (FOOD->clover->eat % 5 == 0) {
				length += 1;

				if (speed >= 80) { //speed가 80이상인 경우만 속도를 높임. ex 79면 길이만 증가 
					if (mode == normal) speed -= 1;
					else if (mode == hard_) speed -= 2;
					speed -= 1;
				}

				//난이도에 따라 쉬움은 해당 없음 보통/어려움  보통 1 어려움 2 씩 더 

			
			}

			gotoxy(MAP_ADJ_X + MAP_X + 10, MAP_ADJ_Y + MAP_Y2 + MARGIN + 2, "1점 * "); printf("%d", FOOD->clover->eat);
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
				gotoxy(MAP_ADJ_X + MAP_X + 10, MAP_ADJ_Y + MAP_Y2 + MARGIN + 4, "5점 * "); printf("%d", FOOD->Red_clover->eat);



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
				gotoxy(MAP_ADJ_X + MAP_X + 10, MAP_ADJ_Y + MAP_Y2 + MARGIN + 8, "10점 * "); printf("%d", FOOD->Jaju_clover->eat);


			}
			else if (con == yellow_clover) {
				score += 25; FOOD->Yellow_clover->eat += 1;
				length += 1; 	

				if (speed >= 80) {

					speed -= 1;

					if (mode == normal) speed -= 1;
					else if (mode == hard_) speed -= 2;
				}
				gotoxy(MAP_ADJ_X + MAP_X + 10, MAP_ADJ_Y + MAP_Y2 + MARGIN + 10, "25점 * "); printf("%d", FOOD->Yellow_clover->eat);


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
				gotoxy(MAP_ADJ_X + MAP_X + 10, MAP_ADJ_Y + MAP_Y2 + MARGIN + 6, "3점 X "); printf("%d", FOOD->OC_clover->eat);


			}
			//각각의 점수 + 먹은 개수에 맞게 n개씩 먹을때마다 length+1 , 먹은 수 +1 

			if (hard == 1) {//혼란 모드 훼이크 많이 
				for (i; i < length + 1; i++) food(FOOD); //처음 기준 6번 이후 length 1증가 1번씩 더 

				/* 추가 정보:
				food함수에서는 클로버의 좌표를 설정하여 클로버를 출력하는데 좌표는 food_x food_y에 하나만 들어가게 된다.

				구체적으로 클로버가 3개가 나오면 2개는 이전에 찍어둔 것이고 마지막에 생긴 클로버의 좌표가 food_x food_y에 들어가서 real clover가 된다.

				title 설명 참조

				*/
			}
			else
			{ //일반 모드 적게 훼이크 
				for (i; i < length - 3; i++) //처음 5기준으로 2번 이후 length가 1증가하면 1번씩 더 생김.  
					food(FOOD); //새 음식 생성 + 속도 증가
			}

			if (last != length) //길이가 증가한 경우
			{
				x[length - 1] = x[length - 2];
				y[length - 1] = y[length - 2];
				/* 추가 정보:

				이 부분은 그림 그려서 한번 그려보면 바로 이해할 수 있는 부분으로 다음 move를 생각하면 이해할 수 있다. 모르겠으면 전화 010 6464 2211

				*/
			}

			if (score >= 20) //포탈의 조건 다시 생성해서 모양을 지워줌. (적당히 real clover 먹을 때 마다 머리 모양 생긴 것을 지워줌.
			{
				potal(); potal_on = on;
			}
		
		}


	
		if (death_line() == 0) //벽에 꽈당 return 0;
		{
			if (potal_on == on)
			{

				i = potal_move();//포탈과 위치가 같으면 처리/ 같지 않으면 처리X

			}

			if (i == 1)//포탈을 이용함.
			{

				return;
			}
			else
			{ //potal off 로 죽은 경우 else로 감.  포탈이 온인데 죽은 경우 포탈로 간 것이 아니라, 벽으로 간 경우 i=0 else로 가서 GAme over

				game_over(); return;
			}
		}


		


		for (i = 1; i < length; i++)
		{
			if (x[0] == x[i] && y[0] == y[i])//머리의 좌표가 몸통의 좌표와 같다
			{
				game_over(); //자기 몸을 먹는 180도 회전을 제외하고 몸통에 부딪히는 경우
				return;

			}
		}


		gotoxy(MAP_ADJ_X + x[length - 1], MAP_ADJ_Y + y[length - 1], " ");//몸통 마지막 지우기

	
		for (i = length - 1; i > 0; i--) //몸통의 좌표 옮기기 
		{
			x[i] = x[i - 1];
			y[i] = y[i - 1];


		}


		TextColor(DEEP_RED);
		gotoxy(MAP_ADJ_X + x[0], MAP_ADJ_Y + y[0], "○");//이전 머리 자리 를 몸통으로  

		if (dir == LEFT) --x[0];
		if (dir == RIGHT) x[0]++;
		if (dir == UP) y[0]--;
		if (dir == DOWN) y[0]++;

		gotoxy(MAP_ADJ_X + x[0], MAP_ADJ_Y + y[0], "◆");

		//새로운 머리를 그린 후에 새로운 좌표로 옮겨 머리그리기.
		TextColor(DEEP_WHITE);



	
}

void reset(struct FOOD *FOOD)//게임 시작 준비
{
	int i;
	system("cls");
	draw(); //화면 지우고 맵그리기 

	while (_kbhit()) _getch(); //버퍼 없애기 

	dir = LEFT; //기본으로 왼쪽을 향함.

	if (hard == 1) speed = 110; //속도 약간 차이 혼란 모드
	else speed = 123; //일반 

	length = 5;
	score = 0;
	potal_on = off;


	FOOD->clover->eat = 0; //기본 클로버 개수 초기화
	FOOD->Jaju_clover->eat = 0;//자주 초기화
	FOOD->OC_clover->eat = 0; //oc 초기화
	FOOD->Red_clover->eat = 0; //red
	FOOD->Yellow_clover->eat = 0;


	TextColor(DEEP_RED);
	for (i = 0; i < length; i++)
	{
		x[i] = MAP_X / 2 + i; //처음 위치는 맵의 절반 +1  00000
		y[i] = MAP_Y / 2;// y축의 절반 
		gotoxy(MAP_ADJ_X + x[i], MAP_ADJ_Y + y[i], "○");//margin + x, marginn + y


	}
	gotoxy(MAP_ADJ_X + x[0], MAP_ADJ_Y + y[0], "◆");//뱀 머리 

	food(FOOD);//FOOD 구조체를 가리키는 포인터(주소값)을 대입.
	TextColor(DEEP_WHITE);
}

void food(struct FOOD *FOOD)
{
	TextColor(DEEP_WHITE);
	int i;


	food_crush_on = 0; //food의 기본값 
	

	int n = rand() % 5 + 1;// 1~5
						   //난수 
	TextColor(DEEP_OC);
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y - 1, "점수: "); //점수 표시 
	printf("%3d", score);
	TextColor(DEEP_JAJU);
	printf("  LAST SCORE: %3d", last_score);
	TextColor(DEEP_YELLOW);
	printf("  BEST SCORE: %3d", best_score);

	/*상단 점수 */

	TextColor(DEEP_GREEN);
	gotoxy(MAP_ADJ_X + MAP_X + 15, MAP_ADJ_Y + MAP_Y2 + MARGIN + 2, "♧");
	TextColor(DEEP_WHITE);
	printf(" X %03d", FOOD->clover->eat);

	TextColor(DEEP_RED);
	gotoxy(MAP_ADJ_X + MAP_X + 15, MAP_ADJ_Y + MAP_Y2 + MARGIN + 4, "♧");
	TextColor(DEEP_WHITE);
	printf(" X %03d", FOOD->Red_clover->eat);

	TextColor(DEEP_OC);
	gotoxy(MAP_ADJ_X + MAP_X + 15, MAP_ADJ_Y + MAP_Y2 + MARGIN + 6, "♧");
	TextColor(DEEP_WHITE);
	printf(" X %03d", FOOD->OC_clover->eat);

	TextColor(DEEP_JAJU);
	gotoxy(MAP_ADJ_X + MAP_X + 15, MAP_ADJ_Y + MAP_Y2 + MARGIN + 8, "♧");
	TextColor(DEEP_WHITE);
	printf(" X %03d", FOOD->Jaju_clover->eat);

	TextColor(DEEP_YELLOW);
	gotoxy(MAP_ADJ_X + MAP_X + 15, MAP_ADJ_Y + MAP_Y2 + MARGIN + 10, "♧");
	TextColor(DEEP_WHITE);
	printf(" X %03d", FOOD->Yellow_clover->eat);

	
	/* 중간 클로버 모양 */

	if (n == 1 || score <= 20) 
	{//20 <=점수 clover map1
		


		food_x = (rand() % (MAP_X - 2)) + 1; 
		food_y = (rand() % (MAP_Y - 2)) + 1; 
		/*
		추가 정보: 이거 좌표는 나도 잘 몰라서 테스팅 함수를 만들어 썼는데 확인해보고 싶다면 blog.naver.com/lmj3322 소스를 참고.
		
		*/


		for (i = 0; i < length; i++)
		{

			if (food_x == x[i] && food_y == y[i])//5개의 몸통의 위치와 food가 겹쳤는지 확인해서 (시작과 동시에 몸통 위에서 탄생)
			{
				food_crush_on = 1;   //1데입 후에 move로 처리 con상태보고 점수 처리하고 food 생성 
				con = green_clover;
				return;
			}


		}




		TextColor(DEEP_GREEN);

		gotoxy(MAP_ADJ_X + food_x, MAP_ADJ_Y + food_y, "♧");//음식 클로버. 

		con = green_clover; //이후에 realclover의 좌표와 함께 사용되어 해당 클로버의 점수를 주는 용도
	}
	//초기 20 점 이전에는 (포탈생성 이전) clover만 기본적으로

	
	else //20점 이후  n==1인 경우 클로버 위,
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

			gotoxy(MAP_ADJ_X + FOOD->Red_clover->x, MAP_ADJ_Y + FOOD->Red_clover->y, "♧");
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

			gotoxy(MAP_ADJ_X + MAP_X + MARGIN + FOOD->Jaju_clover->x, FOOD->Jaju_clover->y + MAP_ADJ_Y, "♧");

			con = jaju_clover;
			food_x = MAP_X + MARGIN + FOOD->Jaju_clover->x; food_y = FOOD->Jaju_clover->y;
		}
		else if (n == 4)
		{//노랑 클로버 맵 4 


		


			FOOD->Yellow_clover->x = (rand() % (MAP_X - 2)) + 1;
			FOOD->Yellow_clover->y = (rand() % (MAP_Y - 3)) + 2;//1개 개수 줄임.


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

			gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + FOOD->Yellow_clover->x, FOOD->Yellow_clover->y + MAP_ADJ_Y + MAP_Y2 + MARGIN, "♧");

			con = yellow_clover;
			food_x = MAP_X2 + MARGIN + FOOD->Yellow_clover->x; food_y = FOOD->Yellow_clover->y + MAP_Y2 + MARGIN;
		}
		else if (n == 5) 
		{//oc clover 맵4


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

			gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + FOOD->OC_clover->x, FOOD->OC_clover->y + MAP_ADJ_Y + MAP_Y2 + MARGIN, "♧");
			con = oc_clover;
			food_x = MAP_X2 + MARGIN + FOOD->OC_clover->x; food_y = FOOD->OC_clover->y + MAP_Y2 + MARGIN;

		}



		

	}

	TextColor(DEEP_WHITE);
	
}

void Press() //초기 타이틀에서 움직이는 회색 ? (애니메이션 역할)
{
	int i = 1;
	while (1) {

		if (i == 1)
		{
			gotoxy_C(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 8, "☆  < 아무 키나 누르세요 > ☆", GRAY); //두줄 띄워서 



			Sleep(800);

			if (_kbhit()) break;

			i++; //처음에만 실행.
		}
		//Sleep 동안  혹시 키를 누른 경우 함수 탈출 (나는 이것을 보고 싶지 않다는 의견을 존중)
		if (_kbhit()) break;

		/* 
		타이틀 뱀 애니메이션 부분에서 사용할 설정
		
		*/
		TextColor(DEEP_WHITE);
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 10, MAP_ADJ_Y, "□"); //벽 복구 처음에는 그냥 덮어 씌우기 이후에 복구 
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 1, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 2, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "                        ");// 남은 잔상 없애기 

		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 27, MAP_ADJ_Y + 5, "   ");


		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 20, MAP_ADJ_Y + 7, "   ");

		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 28, MAP_ADJ_Y + 4, "   "); //clover 잔상




		TextColor(GRAY);
		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 8, "← PRESS ANY KEY TO START →"); //덮어 씌우는 것



		TextColor(DEEP_RED);
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "○○○○○○◆");
		TextColor(DEEP_GREEN);
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 10, MAP_ADJ_Y + 1, "♧");

		TextColor(DEEP_OC);
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 13, MAP_ADJ_Y + 3, "♧");

		TextColor(DEEP_OC);
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 13, MAP_ADJ_Y + 7, "♧");

		Sleep(123); // title에 있던 것과 같다. (title에 쓰는 이유는 일단 시작할 때 보이려고/ 여기다가 한 것은 애니메이션 후에 반복할 때 준비. 
		if (_kbhit()) break;

		/* 반복 애니메이션 준비 끝  시작 아래 */
		TextColor(DEEP_RED);
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "    ○○○○○◆");

		Sleep(123);
		if (_kbhit()) break;
		TextColor(DEEP_RED);
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "      ○○○○○◆");

		Sleep(123);
		if (_kbhit()) break;
		TextColor(DEEP_RED);
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "        ○○○○○◆");

		Sleep(123); //Sleep 동안 받은 경우
		if (_kbhit()) break;
		TextColor(DEEP_RED);
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "          ○○○○○◆");

		TextColor(DEEP_JAJU);
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 27, MAP_ADJ_Y + 5, "♧");


		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 20, MAP_ADJ_Y + 7, "♧");

		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 28, MAP_ADJ_Y + 4, "♧");
		Sleep(50);//살짝 term

		if (_kbhit()) break;
		TextColor(DEEP_RED);


		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "            ○○○○○◆");


		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "              ○○○○○");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "                      ◆");


		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "                ○○○○");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "                      ○");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "                      ◆");



		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "                  ○○○");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "                      ○");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "                      ○");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "                      ◆");



		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "                    ○○");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "                      ○");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "                      ○");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "                      ○");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "                      ◆");

		TextColor(DEEP_GREEN);
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "                    ♧"); //공백을 빼야 머리가 안 없어짐. 위에서.

		TextColor(DEEP_RED);

		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "                      ○");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "                      ○");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "                      ○");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "                      ○");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "                    ◆○");

		Sleep(123); if (_kbhit()) break;



		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "                      ○");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "                      ○");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "                      ○");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "                  ◆○○");




		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "                      ○");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "                      ○");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "                ◆○○○");




		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "                      ○");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "              ◆○○○○");


		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "              ◆        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "              ○○○○○");



		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "              ◆        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "              ○        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "              ○○○○  ");



		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "              ◆        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "              ○        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "              ○        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "              ○○○    ");





		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "              ◆        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "              ○        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "              ○        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "              ○        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "              ○○      ");



		Sleep(123); if (_kbhit()) break;

		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 2, "              ◆        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "              ○        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "              ○        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "              ○        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "              ○        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "              ○        ");



		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 1, "              ◆          ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 2, "              ○        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "              ○        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "              ○        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "              ○        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "              ○        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "                        ");



		Sleep(123); if (_kbhit()) break;
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 10, MAP_ADJ_Y, "◆"); //벽에다가 꽝! 
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 1, "              ○        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 2, "              ○        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "              ○        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 4, "              ○        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 5, "              ○        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 6, "                        ");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 7, "                        ");

		Sleep(123);

		if (_kbhit()) break;



		i = 2;

		if (i == 2)
		{
			TextColor(GRAY);
			gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 8, "←   WHY DON'T YOU PLAY   →"); //다시 띄울 것

			Sleep(1300); if (_kbhit()) break;
			i = 3;
		}


		if (i == 3)
		{
			TextColor(GRAY);
			gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 8, "←  S N A K E  F A K E R  →"); //다시 띄울 것

			Sleep(1300); if (_kbhit()) break;

		}
	}//press 텍스트만 넘기다가 다시 스네이크 애니메이션  PRESS 도중에는 언제나 입력값을 받아서 실행할 수 있다. 그냥두면 뱅뱅.


	TextColor(WHITE);
}

void draw()//맵을 그림 
{
	TextColor(DEEP_WHITE);
	int i;

	for (i = 0; i < MAP_X; i++)
	{
		gotoxy(MAP_ADJ_X + i, MAP_ADJ_Y, "□"); //상단 map1 
											   /*참고:

											   특수문자는 2칸씩 차지함. 그래서 gotoxy에서 *2를 하는 이유. */



	}
	for (i = MAP_ADJ_Y + 1; i < MAP_ADJ_Y + MAP_Y - 1; i++) //map1 중간 
	{
		gotoxy(MAP_ADJ_X, i, "■");					
		gotoxy(MAP_ADJ_X + MAP_X - 1, i, "■");


	}
	for (i = 0; i < MAP_X; i++)
	{
		gotoxy(MAP_ADJ_X + i, MAP_ADJ_Y + MAP_Y - 1, "□"); //MAP_ADJ_Y 위에 기준으로 길이 MAP_Y -1 만큼 띄어서 출력 


	}





	/* MAP 2 */

	for (i = 0; i < MAP_X2; i++)
	{
		gotoxy(MAP_ADJ_X + i, MAP_ADJ_Y + MAP_Y + MARGIN, "□");  //MAP2 상단 



	}
	for (i = MAP_ADJ_Y + 1 + MARGIN + MAP_Y; i < MAP_ADJ_Y + MAP_Y - 1 + MARGIN + MAP_Y2; i++)  //맵2 상단 부터 바닥까지 
	{
		gotoxy(MAP_ADJ_X, i, "■");
		gotoxy(MAP_ADJ_X + MAP_X2 - 1, i, "■");


	}

	for (i = 0; i < MAP_X2; i++)
	{
		gotoxy(MAP_ADJ_X + i, MAP_ADJ_Y + MAP_Y + MARGIN + MAP_Y2 - 1, "□"); //for는 상단과 그대로 맵2 바닥  -1이 필수


	}


	/* MAP 3 */


	for (i = 0; i < MAP_X2; i++)
	{
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + i, MAP_ADJ_Y, "□");  //MAP3 상단 



	}
	for (i = MAP_ADJ_Y + 1; i < MAP_ADJ_Y + MAP_Y4 - 1; i++)  //맵4 상단 부터 바닥까지 
	{
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN, i, "■");
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + MAP_X2 - 1, i, "■");


	}

	for (i = 0; i < MAP_X2; i++)
	{
		gotoxy(MAP_ADJ_X + MAP_X + MARGIN + i, MAP_ADJ_Y + MAP_Y4 - 2, "□");  //MAP3 하단 아래 MAP4 상단과 겹치므로 -2로 띄워줌.



	}




	/*MAP 4 */
	for (i = 0; i < MAP_X; i++)
	{
		gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + i, MAP_ADJ_Y + MAP_Y4 + MARGIN - 1, "□");  //MAP4 상단 



	}
	for (i = MAP_ADJ_Y + MAP_Y4 + 1; i < MAP_ADJ_Y + MAP_Y4 + MAP_Y - 1; i++) // y값이 연동되므로 위치와 연동시켜 0에서 ㅇ까지 제대로 데입
	{
		gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN, i, "■");
		gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN - 1 + MAP_X, i, "■");


	}
	for (i = 0; i < MAP_X; i++)
	{
		gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + i, MAP_ADJ_Y + MAP_Y4 + MAP_Y - 2, "□");  //MAP4 하단 



	}
	


}


void title()
{
	system("cls");


	while (_kbhit()) _getch(); //버퍼 먹기
							   //버퍼 없애기.

	draw();

	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 / 2 - 1, "│"); //MAP3 left 
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 / 2, "│"); //MAP3 left 
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 / 2 + 1, "│"); //MAP3 left 

	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 / 2 + 2, "│"); //MAP3 left 
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 / 2 + 3, "│"); //MAP3 left 
																		 //포탈 예시 들어주기 

																		 /*게임 설명 자리 지우기 */
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

	/*게임 설명 시작 */

	TextColor(DEEP_YELLOW);
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 4, MAP_ADJ_Y + MAP_Y2 + MARGIN + 4, "［ 게임 설명 ］");

	TextColor(DEEP_WHITE);
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 15, MAP_ADJ_Y + MAP_Y2 + MARGIN + 7, "㉮ 이 게임은 기본적인 스네이크 방식을 따릅니다.");

	TextColor(GRAY);
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 15, MAP_ADJ_Y + MAP_Y2 + MARGIN + 8, "(속도 증가 X)");

	TextColor(DEEP_WHITE);

	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 15, MAP_ADJ_Y + MAP_Y2 + MARGIN + 10, "㉯ Real clover를 먹으면 점수가 증가합니다.");

	TextColor(GRAY);
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 15, MAP_ADJ_Y + MAP_Y2 + MARGIN + 11, "(이후에 새로 생긴 클로버 중 하나가");
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 7, MAP_ADJ_Y + MAP_Y2 + MARGIN + 12, " Real clover 가 됩니다 / 나머지는 FAKE)");
	TextColor(DEEP_WHITE);

	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 15, MAP_ADJ_Y + MAP_Y2 + MARGIN + 13, "㉰ 클로버의 색에 따라 다른 점수가 부여됩니다.");

	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 - 15, MAP_ADJ_Y + MAP_Y2 + MARGIN + 16, "㉱ 20점이 되면 포탈이 생성되어 다른 지역으로 ");
	gotoxy(MAP_ADJ_X + MAP_X2 + MARGIN + MAP_X / 2 + 5, MAP_ADJ_Y + MAP_Y2 + MARGIN + 17, " 갈 수 있습니다.");

	/* 스네이크 기본 룰 */

	TextColor(DEEP_JAJU);
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 + MARGIN + 1, "[ 스네이크 기본 ]");

	TextColor(DEEP_WHITE);

	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 + MARGIN + 4, "㉠ 먹는다.");

	TextColor(GRAY);
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 + MARGIN + 5, "(자신을 먹으면 Game Over)");

	TextColor(DEEP_WHITE);

	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 + MARGIN + 7, "㉡ (먹으면) 길어진다.");


	TextColor(GRAY);
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 + MARGIN + 8, "(이 게임에서는 클로버를 먹은 수에 따라 길어진다)");

	TextColor(DEEP_WHITE);

	gotoxy(MAP_ADJ_X + MAP_X + MARGIN, MAP_ADJ_Y + MAP_Y2 + MARGIN + 10, "㉢ 벽에 부딪히면 죽는다.");



	TextColor(DEEP_WHITE);
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 3, "＃─────────────────────────＃");
	gotoxy_C(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 4, "★       SNAKE FAKER       ★", DEEP_OC);
	TextColor(DEEP_WHITE);
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 5, "＃─────────────────────────＃");


	gotoxy_C(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 10, "조 작: ←↑↓→", DEEP_WHITE);
	gotoxy_C(MAP_ADJ_X + (MAP_X / 2) + 2, MAP_ADJ_Y + 10, "정 지:   p", DEEP_WHITE);
	gotoxy_C(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 12, "혼돈 모드 : h  ", DEEP_RED);

	if (hard == on) //혼란 모드가 켜져 있는 상태면 표시 
	{
		TextColor(GRAY);
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 13,     "[ O N ]"); //이후 reset이나 다시 title에서 이 자리는 지워버림 .
	}
	else
	{
		TextColor(GRAY);
		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 13, "[ OFF ]");
	}
	
	gotoxy_C(MAP_ADJ_X + (MAP_X / 2) + 2, MAP_ADJ_Y + 12, "종 료:  ESC ", DEEP_WHITE);
	TextColor(DEEP_WHITE);
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 6, MAP_ADJ_Y + 17, "  Copyright ⓒ2018-Yumin ");

	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 25, "  References : blog.naver.com/AZURE0777 (Snake Game)");


	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 8, MAP_ADJ_Y + 23, "            난이도 설정: v");
	TextColor(DEEP_GREEN);
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 8, MAP_ADJ_Y + 23, "[ Setting ]");


	gotoxy(MAP_ADJ_X + (MAP_X / 2) +7, MAP_ADJ_Y + 23, "");//클로버 위치랑 영향 없고 mode 띄워줄 때만 사용됨.
	
	TextColor(GRAY);
	printf("현재:");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) + 10, MAP_ADJ_Y + 23, "");
	if (mode == easy)
	{
		
		printf("[ 쉬움 ]");
	}
	else if (mode == normal)
	{
		
		printf("[ 보통 ]");

	}
	else if (mode == hard_)
	{
	
		printf("[ 어려움 ]"); //또한 title, reset에서는 사라짐 
	}
	/* 꾸며주기 */
	TextColor(DEEP_GREEN);
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 6, MAP_ADJ_Y + 17, "♧");

	TextColor(DEEP_YELLOW);
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 17, "♧");

	//copy 왼쪽 


	TextColor(DEEP_OC);
	gotoxy(MAP_ADJ_X + (MAP_X / 2) + 6, MAP_ADJ_Y + 17, "♧");


	TextColor(DEEP_JAJU);
	gotoxy(MAP_ADJ_X + (MAP_X / 2) + 7, MAP_ADJ_Y + 17, "♧");

	//copy 오른쪽 

	TextColor(DEEP_RED);
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 8, MAP_ADJ_Y + 25, "♧"); //레퍼런스 


															  /* 스네이크 에니메이션 준비*/
	TextColor(DEEP_RED);
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 3, MAP_ADJ_Y + 3, "○○○○○○◆");
	TextColor(DEEP_GREEN);
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 10, MAP_ADJ_Y + 1, "♧");

	TextColor(DEEP_OC);
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 13, MAP_ADJ_Y + 3, "♧");

	TextColor(DEEP_OC);
	gotoxy(MAP_ADJ_X + MAP_X + MARGIN + 13, MAP_ADJ_Y + 7, "♧");
	

	while (_kbhit()) _getch(); //미리 입력한 값들은 무시

	Press(); //무한 와일문이라 중간에 실행시 이후에 표시가 안 됌 press에서 입력받고 그것이 key로 인식
	
	while (1)
	{
		if (key = _getch())//입력이 있다면 ? 

			if (key == ESC) exit(0); //종료 입력시 종료 나머지 실행 
			else if (key == HARD) { //h를 입력함.
				

					if (hard == 0) hard = 1; //노말 -> 하드
					else hard = 0; //하드 -> 노말        

				

					title(); return;
					
				 }//h 입력시 하드모드 온 
		    else if (key == SET) { User_set(); title(); return; }//v 입력 setting하고 키 입력 reset return 게임 시작 
			else break; //아니라면 무한 와일 빠져나오기.
	}

	reset(&FOOD);

}
void User_set()
{
	char input[15];
	system("cls");
	
	draw();
	//기본 DEEP_WHITE
	gotoxy(MAP_ADJ_X+3 , MAP_ADJ_Y + MARGIN+MAP_Y+3, "이곳은 속도 증가량을 설정하는 공간입니다."); TextColor(GRAY);
	gotoxy(MAP_ADJ_X+3, MAP_ADJ_Y + MARGIN + MAP_Y + 5, "  (쉬움: A / 보통: B / 어려움: C / 나가기: Q 입력)");
	gotoxy_C(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 10, "현재 난이도는 ", DEEP_WHITE); 

	TextColor(GRAY);
	if (mode == easy)	printf("쉬움");
	else if (mode == normal) 	printf("보통");
	else if (mode == hard_) printf("어려움");
		

	
	TextColor(DEEP_WHITE);
	
	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 13, ">  "); //마우스 위치 설정 
	
	while (1)
	{

		gotoxy(MAP_ADJ_X + MAP_X + 2, MAP_ADJ_Y + 13, "               ");//입력한 자리 

		TextColor(DEEP_WHITE); //이전 색의 영향을 없애기 위함 
		gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 13, ">  "); //반복하기 위한 위치 (받는 위치의 고정)
		

		scanf_s("%s", input, sizeof(input));



		TextColor(GRAY);
		
		
		gotoxy(MAP_ADJ_X + MAP_X + 8, MAP_ADJ_Y + 10, ""); //출력할 위치 지정  

		if (input[0]=='a' || input[0]=='A')
		{//같으면 참으로 실행된다.

			gotoxy(MAP_ADJ_X + MAP_X + 8, MAP_ADJ_Y + 10, "           "); //현재 난이도는 (    ) 지우고 다시 출력.  어려움 3글자 .. 쉬움 2글자 덮어씌우기 불가.
			
			gotoxy(MAP_ADJ_X + MAP_X + 8, MAP_ADJ_Y + 10, "쉬움"); Sleep(200);
			mode = easy;
		}
		else if (input[0] == 'b' || input[0] == 'B')
		{
			gotoxy(MAP_ADJ_X + MAP_X + 8, MAP_ADJ_Y + 10, "          ");
			gotoxy(MAP_ADJ_X + MAP_X + 8, MAP_ADJ_Y + 10, "보통"); Sleep(200);
			mode = normal;
		}
		else if (input[0] == 'c' || input[0] == 'C')
		{
			gotoxy(MAP_ADJ_X + MAP_X + 8, MAP_ADJ_Y + 10, "           ");
			gotoxy(MAP_ADJ_X + MAP_X + 8, MAP_ADJ_Y + 10, "어려움"); Sleep(200);
			mode = hard_;
		}
		else if (input[0] == 'q' || input[0] == 'Q')
		{ 

			break; //타이틀로 이동
		}
		else//???
		{
			gotoxy_C(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 16, "다시 입력", DEEP_RED); 
			Sleep(250);
			gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 16, "         ");
			
		}
			
	/*a b c 를 입력한 경우에만 공백/ 씌우기  else는 그대로 두기.*/


	}
	
}