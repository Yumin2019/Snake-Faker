#pragma once
void game_over_press();
void draw();
void title();
void Press(); //Press Any key
void reset(struct FOOD *FOOD);//���� ���� �غ�
void food(struct FOOD *FOOD);
void move(int dir, struct FOOD *FOOD);
void game_over();
void pause(int *p);
void status();
void status_off();
void potal();
int potal_move();
void number(int score);//���� ��� ������
void User_set(); //s �Է� �����Լ� 

int death_line(); //���� ��ħ.