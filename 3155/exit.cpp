#include <stdio.h>
#include "graphics.h"
#include "game.h"

int k=0;
void click_handler_exit(int x, int y)
{
    if((x>=124 && x<=219) && (y>=235 && y<=273))
        k=1;
    else if((x>=124 && x<=210) && (y>=354 && y<=391)) k=2;
}
int ex_window()
{
    initwindow(1024,768,"TRY");
    k=0;
    char  ch;
    int v=0;
    int f;
    readimagefile("ext.jpg",0,0,1024,768);
    setcolor(BROWN);
    rectangle(129,235,219,273);
    int y1[]={235,354};
    int x2[]={219,210};
    int y2[]={273,391};
    registermousehandler(WM_LBUTTONDOWN, click_handler_exit);
    while(k==0)
    {
        if(kbhit()==true)
        {
            ch=getch();
            if(ch==KEY_DOWN)
            {

                readimagefile("ext.jpg",0,0,1024,768);
                if(v==1)  v=0;
                else v++;
                rectangle(124,y1[v],x2[v],y2[v]);
            }
            else if(ch==KEY_UP)
            {

                readimagefile("ext.jpg",0,0,1024,768);
                if(v==0) v=1;
                else v--;
                rectangle(124,y1[v],x2[v],y2[v]);

            }
            else if(ch=='\r')
            {


                if(v==0) k=1;
                else if(v==1) k=2;
                break;
            }

        }
    }
    if(k==1) f=1;
    else if(k==2) f=2;
    closegraph();
    return f;
}
