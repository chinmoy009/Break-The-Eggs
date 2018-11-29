#include <stdio.h>
#include "graphics.h"
#include "game.h"

int l=0;
void click_handler_menu(int x, int y)
{

    if((x>=81 && x<=395) && (y>=143 && y<=201))
    {
        l=1;
    }

    else if((x>=74 && x<=442) && (y>=245 && y<=308)) l=2;
    else if((x>=87 && x<=231) && (y>=349 && y<=411)) l=3;
    else if((x>=90 && x<=296) && (y>=458 && y<=518)) l=4;
    else if((x>=99 && x<=231) && (y>=581 && y<=637)) l=5;


}
void click_handler_men_ex(int x, int y)
{
    int i;
      readimagefile("ZP.jpg",0,0,1562,1000);
      if((x>=81 && x<=395) && (y>=143 && y<=201))
      {
        rectangle(81,143,395,201);
        i=0;
      }
    else if((x>=74 && x<=442) && (y>=245 && y<=308))
    {
        rectangle(74,245,442,308);
        i=1;
    }
    else if((x>=87 && x<=231) && (y>=349 && y<=411))
    {
        rectangle(87,349,231,411);
        i=2;
    }
    else if((x>=90 && x<=296) && (y>=458 && y<=518))
    {
        rectangle(90,458,296,518);
        i=3;
    }
    else if((x>=99 && x<=231) && (y>=581 && y<=637))
    {
         rectangle(99,581,231,637);
         i=4;
    }

    setcolor(WHITE);


}
int menu()
{
    initwindow(1562,1000,"MENU");
    readimagefile("ZP.jpg",0,0,1562,1000);
    int y1[5]={143,245,349,458,581};
    int x2[5]={395,442,231,296,231};
    int y2[5]={201,308,411,518,637};
    int x1[5]={81,74,87,90,99};
    char ch;
    int i, f=0;
    rectangle(81,143,395,201);
    int x, y;
    registermousehandler(WM_LBUTTONDOWN, click_handler_menu);
    //registermousehandler(WM_MOUSEMOVE, click_handler_men_ex);
    l=0;
    i=0;
        while(l==0)
        {
            if(l!=0) break;
            if(kbhit()==true)
            {
            ch=getch();

            if(ch==KEY_DOWN)
            {
                printf("IN1\n");
                readimagefile("ZP.jpg",0,0,1562,1000);
                if(i==4)  i=0;
                else i++;
                rectangle(x1[i],y1[i],x2[i],y2[i]);
            }
            else if(ch==KEY_UP)
            {
                printf("IN2\n");
                readimagefile("ZP.jpg",0,0,1562,1000);
                if(i==0) i=4;
                else i--;
                rectangle(x1[i],y1[i],x2[i],y2[i]);

            }
            else if(ch=='\r')
            {


                printf("In3\n");
                if(i==0) l=1;
                else if(i==1) l=2;
                else if(i==2) l=3;
                else if(i==3) l=4;
                else if(i==4) l=5;
                printf("%d\n",l);
                break;
            }
            }


        }

    closegraph();
    if(l==1) level1();
    else if(l==2) leader_board();
    else if(l==4) credit_window();
    else if(l==3) help();
    else if(l==5)
        f=ex_window();

    return f;


}
