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

char compare(char *str1, char *str2) //�� �Լ� ������ 1 Ʋ���� 0
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
//���� �Լ�
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
void gotoxy(int x, int y, char *s) //x�� �޾Ƽ� 2*x �ٷ� ���ڿ��� ������ �� �ֵ��� printf�Լ� ���� �� ģ���� �׳� �� ���ִ� ���·� 
{
	COORD pos;

	pos.X = 2 * x;//2���� x ��ǥ
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	printf("%s", s);


}
void gotoxy_C(int x, int y, char *s, int Color) //x�� �޾Ƽ� 2*x �ٷ� ���ڿ��� ������ �� �ֵ��� printf�Լ� ���� �� �Լ��� ���������, �ϳ��� �������� �� �޾Ƽ�.
{
	COORD pos;

	pos.X = 2 * x;//2���� x ��ǥ
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	Speak_C(s, Color); //���� ���ڿ��� ���� ����� �ϳ��� ��� �ڿ������� 


}



void Speak(char speaking[])
//�׳� ������ �ǹ� �ǹ� ���� 
{
	int i = 0;


	TextColor(DEEP_WHITE);

	for (; i < str_num(speaking); i++)
	{
		printf("%c", speaking[i]); Sleep(25);
	}



}
//����� �����ϰ� ���� ���� �� (���� TextColor�� ���� �����ϰ� �;�)
void Speak_C(char speaking[], int C)
{
	int i = 0;


	TextColor(C);

	for (; i < str_num(speaking); i++)
	{
		printf("%c", speaking[i]); Sleep(25);
	}



}
void TextColor(int color_num)  /*�ؽ�Ʈ �÷� �Լ�   */
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_num);


}

/* �迭�� ���ڼ� Ȯ�� */
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

	return i; // ���ڿ��� �� ��� 

}