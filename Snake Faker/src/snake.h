#pragma once
void game_over_press();
void draw();
void title();
void Press(); //Press Any key
void reset(struct FOOD *FOOD);//게임 시작 준비
void food(struct FOOD *FOOD);
void move(int dir, struct FOOD *FOOD);
void game_over();
void pause(int *p);
void status();
void status_off();
void potal();
int potal_move();
void number(int score);//점수 출력 ㅁㅁㅁ
void User_set(); //s 입력 세팅함수 

int death_line(); //벽과 겹침.