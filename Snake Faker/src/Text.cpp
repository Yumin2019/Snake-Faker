#include<windows.h>
#include <stdio.h>
#include<time.h>
#include<windows.h>
#include<conio.h>

#include"Text.h"


enum COLOR {
	BLACK, BLUE, GREEN, OC, RED, JAJU, YELLOW, WHITE, GRAY
	, DEEP_BLUE, DEEP_GREEN, DEEP_OC, DEEP_RED, DEEP_JAJU, DEEP_YELLOW,
	DEEP_WHITE
};

char compare(char *str1, char *str2) //비교 함수 같으면 1 틀리면 0
{
	while (*str1)
	{
		if (*str1 != *str2)
		{
			return 0;
		}
		str1++;
		str2++;
	}
	if (*str2 == '\0')
		return 1;
	return 0;
}
//복사 함수
char copy_str(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return 1;
}
void gotoxy(int x, int y, char *s) //x를 받아서 2*x 바로 문자열을 데입할 수 있도록 printf함수 데입 이 친구는 그냥 다 떠있는 상태로 
{
	COORD pos;

	pos.X = 2 * x;//2배의 x 좌표
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	printf("%s", s);


}
void gotoxy_C(int x, int y, char *s, int Color) //x를 받아서 2*x 바로 문자열을 데입할 수 있도록 printf함수 데입 위 함수와 비슷하지만, 하나씩 ㅇㅇㅇㅇ 색 받아서.
{
	COORD pos;

	pos.X = 2 * x;//2배의 x 좌표
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	Speak_C(s, Color); //받은 문자열을 받은 색깔로 하나씩 출력 자연스럽게 


}



void Speak(char speaking[])
//그냥 무색의 또박 또박 히힛 
{
	int i = 0;


	TextColor(DEEP_WHITE);

	for (; i < str_num(speaking); i++)
	{
		printf("%c", speaking[i]); Sleep(25);
	}



}
//흰색을 지정하고 싶지 않을 때 (나는 TextColor의 색을 지정하고 싶어)
void Speak_C(char speaking[], int C)
{
	int i = 0;


	TextColor(C);

	for (; i < str_num(speaking); i++)
	{
		printf("%c", speaking[i]); Sleep(25);
	}



}
void TextColor(int color_num)  /*텍스트 컬러 함수   */
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_num);


}

/* 배열의 문자수 확인 */
int str_num(char *str)
{
	int i = 0;
	while (1)
	{

		if (*(str + i) == NULL)
			break;


		if (*(str + i) != NULL)
			i++;

	}

	return i; // 문자열의 수 출력 

}