#include <stdio.h>
#include "graphics.h"
#include "game.h"
int l=0;
void click_handler_res1(int x, int y)
{
    if((x>=9 && x<=148) && (y>=258 && y<=281)) l=1;
    else if((x>=9 && x<=343)&& (y>=349 && y<=376)) l=2;
    else if((x>=9 && x<=78) && (y>=441 && y<=467)) l=3;
}

void click_handler_gameover(int x, int y)
{
    if((x>=21 && x<=150) && (y>=81 && y<=113))
        l=1;
    else if((x>=21 && x<=374) && (y>=171 && y<=199)) l=2;
    else if((x>=21 && x<=103) && (y>=262 && y<=290)) l=3;
}
void credit_window()
{
    initwindow(1880,1050,"CREDIT");
    readimagefile("cre1.jpg",0,0,1680,1050);
    delay(3000);
    readimagefile("cre2.jpg",0,0,1880,1050);
    while(getch()!=27);
    closegraph();
    menu();
}
void  help()
{
    initwindow(1024,500,"HELP");
    readimagefile("K.jpg",0,0,1024,500);
    while(getch()!=27);
    closegraph();
    menu();
}
void res1()
{
    readimagefile("res1.jpg",0,0,1042,768);
    int y1[]= {257,348,436};
    int x2[]= {146,357,80};
    int y2[]= {288,375,466};
    char ch;
    setcolor(BROWN);
    rectangle(6,257,146,288);
    int x, y;
    registermousehandler(WM_LBUTTONDOWN, click_handler_res1);
    //registermousehandler(WM_MOUSEMOVE, click_handler_re);
    l=0;
    int v=0;
    while(l==0)
    {
        registermousehandler(WM_LBUTTONDOWN, click_handler_res1);
        if(l!=0) break;
        if(kbhit()==true)
        {
            ch=getch();

            if(ch==KEY_DOWN)
            {

                readimagefile("res1.jpg",0,0,1042,768);
                if(v==2)  v=0;
                else v++;
                setcolor(BROWN);
                rectangle(6,y1[v],x2[v],y2[v]);
            }
            else if(ch==KEY_UP)
            {

                readimagefile("res1.jpg",0,0,1042,768);
                if(v==0) v=2;
                else v--;
                rectangle(6,y1[v],x2[v],y2[v]);

            }
            else if(ch=='\r')
            {


                if(v==0) l=1;
                else if(v==1) l=2;
                else if(v==2) l=3;
                break;
            }
            else if(ch==27)
            {
                l=1;
                break;
            }
        }
    }



}
void leader_board()
{
    FILE *fp1;
    int j,k;
    typedef struct
    {
        int h;
        char name[100];
    }high_score;
    high_score a[5];
    initwindow(1500,1000,"LEADER BOARD");
readimagefile("video1.jpg",0,0,1500,1000);
char sc[50];
fp1=fopen("h.txt","r");
for(j=0;j<5;j++)
{
    fscanf(fp1,"%s",&a[j].name);
    fscanf(fp1,"%d",&a[j].h);
}
k=342;
for(j=0;j<5;j++)
{
    outtextxy(378,k,a[j].name);
    sprintf(sc,"%d",a[j].h);
    outtextxy(1116,k,sc);
    k+=100;
}
while(getch()!=27);
fclose(fp1);
closegraph();
menu();
}
int new_menu()
{
    initwindow(1024,768,"Next Menu");
    l=0;
    char ch;
    int  v=0, f=0;
    readimagefile("new_menu.jpg",0,0,1024,768);
    rectangle(21,81,150,113);
    int y1[3]={81,171,262};
    int x2[3]={150,374,103};
    int y2[3]={113,199,290};
    registermousehandler(WM_LBUTTONDOWN, click_handler_gameover);
    while(l==0)
    {
        if(l!=0) break;
        if(kbhit()==true)
        {
            ch=getch();
            if(ch==KEY_DOWN)
            {
                readimagefile("new_menu.jpg",0,0,1024,768);
                if(v==2) v=0;
                else v++;
                rectangle(21,y1[v],x2[v],y2[v]);
            }
            else if(ch==KEY_UP)
            {
                readimagefile("new_menu.jpg",0,0,1024,768);
                if(v==0) v=2;
                else v--;
                rectangle(21,y1[v],x2[v],y2[v]);
            }
            else if(ch=='\r')
            {
                if(v==0) l=1;
                else if(v==1) l=2;
                else if(v==2) l=3;
                break;
            }
        }
    }
    if(l==1) level1();
    else if(l==2) menu();
    else if (l==3) f=ex_window();
        closegraph();
        return f;
}
void name_entry(int p)
{
    initwindow(1000,500,"high_score");
    printf("%d\n",p);
    FILE *fp1,*fp2;
fp1=fopen("h.txt","r");
typedef struct
{
    int h;
    char name[100];

} high_score;
high_score a[5];
int j;

for(j=0;j<5;j++)
{
    fscanf(fp1,"%s",&a[j].name);
    fscanf(fp1,"%d",&a[j].h);
}
fclose(fp1);
char user_name[100];
char tmpc;
outtextxy(50,50,"PLZ DON'T USE BACKSPACE OR ESC KEY WHILE ENTERING YOUR NAME");
outtextxy(500,200,"ENTER YOUR NAME");

j=0;
while(j<10)
{
    user_name[j]=getch();
    if(user_name[j]=='\r' || user_name[j]==' ') break;
       user_name[j+1]='\0';
       outtextxy(650,200,user_name);
       j++;
}
user_name[j]='\0';
printf("%s\n",user_name);
for(j=0;j<5;j++)
{
  if(p>a[j].h){
    printf("greater\n");
    break;
  }
}
int k=j;
printf("%d\n",k);
fp1=fopen("h.txt","w");
if(k==0) fprintf(fp1,"%s %d\n",user_name,p);
for(j=0;j<4;j++)
{

    fprintf(fp1,"%s %d\n",a[j].name,a[j].h);
    if(j==(k-1)) fprintf(fp1,"%s %d\n",user_name,p);
}
fclose(fp1);
closegraph();
initwindow(1500,1000,"LEADER BOARD");
readimagefile("video1.jpg",0,0,1500,1000);
char sc[50];
fp1=fopen("h.txt","r");
for(j=0;j<5;j++)
{
    fscanf(fp1,"%s",&a[j].name);
    fscanf(fp1,"%d",&a[j].h);
}
k=342;
for(j=0;j<5;j++)
{
    outtextxy(378,k,a[j].name);
    sprintf(sc,"%d",a[j].h);
    outtextxy(1116,k,sc);
    k+=100;
}
getch();
fclose(fp1);
closegraph();
new_menu();
}
void game_over(char s[], int p)
{
    initwindow(1000,500,"Game Over");
    readimagefile("gameover.jpg",0,0,1000,500);
    delay(3000);
    setbkcolor(BLACK);
    setcolor(WHITE);
    settextstyle(1,HORIZ_DIR,100);
    outtextxy(450,450,"YOUR SCORE");
    outtextxy(650,450,s);
    delay(3000);
    closegraph();
    name_entry(p);
}
int start()
{
    initwindow(1470,900,"WELCOME");
    int x, y, f;
    readimagefile("bck26.jpg",0,0,1470,900);
    delay(1000);
    readimagefile("bck20.jpg",0,0,1470,900);
    delay(1000);
    readimagefile("bck35.jpg",0,0,1470,900);
    delay(3000);
    closegraph();
    initwindow(1000,650,"STRORY LINE");
    readimagefile("d.jpg",0,0,1000,650);
    delay(5000);
    closegraph();
    f=menu();
    if(f==2) f=menu();
    return f;
}
