#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

#include"snake.h"
#include"Text.h"

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80 
#define PAUSE 112
#define ESC 27
#define HARD 104

#define MAP_ADJ_X 3 //그리는 라인과 맨 끝의 간격 X       좌측 끝 마진
#define MAP_ADJ_Y 2// 그리는 라인과 맨 끝의 간격 y       상단 마진

#define MAP_X 20 //다른 사람을 위한 주석: 정사각형의 X크기

#define MAP_Y 20// 정사각형의 Y 크기

#define MARGIN 1 // map의 간격으로 사용한 margin

#define MAP_X2 40  //길쭉한거(아래)
#define MAP_Y2 8 

#define MAP_Y4 10 //ㅁ..뭐더라 ?
#define MAP_Y3 14

#define MID_MARGIN_X 18  //중간 마진 

enum SW { off,on }; //off=0 on=1

enum COLOR {
	BLACK, BLUE, GREEN, OC, RED, JAJU, YELLOW, WHITE, GRAY
	, DEEP_BLUE, DEEP_GREEN, DEEP_OC, DEEP_RED, DEEP_JAJU, DEEP_YELLOW,
	DEEP_WHITE
}; 
/* TextColor 함수에서 쓸 Color 숫자로 보기 좋게 매칭해놓은 것이다. 궁금하면 C언어 텍스트 색깔 등으로 검색. */

enum Clover{green_clover=1,red_clover,jaju_clover,yellow_clover,oc_clover};//con EX: 빨강 클로버를 먹음 con=red_clover; 

struct food {

	int num;
	int x, y;
	int eat;



}clover, Red_clover, OC_clover, Jaju_clover, Yellow_clover;

struct FOOD { //음식 구조체를 가리키는 만능 포인터 구조체 집합.
	struct food *clover,*Red_clover,*OC_clover,*Yellow_clover,*Jaju_clover;
	
}FOOD;

int con; //con 변수 ex: con= red_clover
int x[150], y[150]; //스네이크의 좌표로 0은 머리를 의미한다.        4 3 2 1 (0) 요런 식으로 

/*좌표의 추가정보 : x,y, food_X , food_y 는 MAP_ADJ_X, MAP_ADJ_Y 의 공백을 제외하고 map내의 좌표로 생각한다. 

출력할때는 MAP_ADJ_X+food_X <- 이런 꼴로
*/
int food_x, food_y; //음식의 x,y 값 
int length;
int speed;
int score;
int best_score;
int last_score;
int dir;//이동 방향
int key; //dir 이전에 받는 변수 key 
int status_on; //스텟 함수에서 쓰는 스위치 변수 
int p;



int hard; //하드 모드
int potal_on;//포탈 생김 조건 변수 


//선언만 snake.c에서 데입



int main() {
	srand(time(NULL));
	system("mode con cols=135 lines=33  "); //CLI 크기
	system("title SNAKE FAKER ");//상단 이름 
	
	/* 각 클로버의 기본값
	
	num은 길이 증가+ 속도 증가에 필요한 양
	
	point는 먹을 때 마다의 점수 
	
	eat은 뱀이 먹은 횟수 */
	clover.num = 5;
	clover.eat = 0;


	Red_clover.num = 2;
	Red_clover.eat = 0;

	OC_clover.num = 1;
	OC_clover.eat = 0;

	Jaju_clover.num = 3;
	Jaju_clover.eat = 0;

	Yellow_clover.num = 1;
	Yellow_clover.eat = 0;
	 
	/*만능 구조체 !    
	
	함수내 사용방식. 

	struct FOOD *FOOD 구조체 포인터

	FOOD가 가리키는 구조체 FOOD (이름 동일하게 설정, FOOD는 포인터 만능 구조체, 인자값) 의 멤버 clover, Yello_clover 등등 (구조체 포인터) 가 가리키는 멤버

	num,eat등등 ex: FOOD->clover->eat 

	*/

	FOOD.clover = &clover;
	FOOD.Yellow_clover = &Yellow_clover;
	FOOD.Red_clover = &Red_clover;
	FOOD.OC_clover = &OC_clover;
	FOOD.Jaju_clover = &Jaju_clover;

	title(); 

	

	while (1)
	{
	
				if (_kbhit()) do { key = _getch(); } while (key == 224); 
				
				//누른 키가 있다면 key로 받고 224인지 확인 방향키를 누른 경우 2번째 인자를 받음. key=방향키 좌표  pause 이후에는 입력 x 로 넘어감.
				
				
		Sleep(speed);
		switch (key)
		{
	

		case LEFT:
		case RIGHT:
		case UP:
		case DOWN:
			
			if(dir==LEFT&& key!=RIGHT|| dir==RIGHT && key!= LEFT || dir== UP && key!= DOWN || dir==DOWN && key!= UP)
				
				//자기몸을 먹는 경우를 방지하기 위해 90도 회전을 한 경우만 인식함.
			dir = key; 
			
			//입력받은 방향키를 dir에 데입        위 조건을 만족하지 않는 경우 기본값으로 이동       자기 몸을 먹는 상황이 아닐 때 키값을 받아서 움직임.
			key = 0; //초기화
			break;
	
		case PAUSE: //p를 누름
			if (p == 0) p = 1;
			else p = 1;

			break;

		case 115:
			//s키 개발자용 상태      P와 S  매우 유용한 키로 이용된다. (확인용)

			if (status_on == 0) status_on = 1;
			else {
				status_on = 0;
				status_off(); //없애주고 on=0 off상태 
			}
			//이미 활성화된 상태에서 다시 누른 경우: 활성 해제.
			key = 0;
			break;

		case ESC:
			exit(0);


		}


		move(dir,&FOOD); 
		
		
		// 아무 값도 입력 x dir =LEFT 
		if (status_on == 1) status();
	
		if (p == 1) {
			pause(&p);//정지상태 이후 화면에  지워주고 p=0데입
			
		}
	

		

	}  
			system("pause");
	return 0;
}






