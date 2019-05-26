#pragma once
void TextColor(int color_num);
void Speak(char speaking[]);
void Speak_C(char speaking[], int C);
char copy_str(char *dest, char *src);
int str_num(char *str); //snake 에서는 사용 안 함.
char compare(char *str1, char *str2);
void gotoxy(int x, int y, char *s);
void gotoxy_C(int x, int y, char *s, int Color);