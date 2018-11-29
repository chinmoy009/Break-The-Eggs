#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

void click_handler(int x, int y);
void click_handler_menu(int x, int y);
void click_handler_men_ex(int x, int y);
void click_handler_res1(int x, int y);
void click_handler_exit(int x, int y);
void click_handler_gameover(int x, int y);
void res1();
int new_menu();
void leader_board();
void name_entry(int p);
void game_over(char s[],int p);
void level_2_bck(char s[], char st[], int q);
void level_1_bck(char s[], char st[], int q);
void level1();
int ex_window();
int  menu();
int start();
void credit_window();
void help();
void level2(int q,int p, char s[], int sp);
void level3(int q,int p, char s[], int sp);
void level4(int q,int p, char s[], int sp);




#endif // GAME_H_INCLUDED







