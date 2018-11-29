#include <stdio.h>
#include "graphics.h"
#include "game.h"
int l=0;
void click_handler(int x, int y)
{

    if(getpixel(x,y)==WHITE)
        l=1;
    else if(getpixel(x,y)==YELLOW) l=2;
    else if(getpixel(x,y)==DARKGRAY) l=3;
    else if((x>=930 && x<=969) && (y>=10 && y<=40)) l=4;
    else if(getpixel(x,y)==GREEN) l=5;
}
void level_2_bck(char s[], char st[], int q)
{
    int i;
    readimagefile("sample.jpg",0,0,1000,500);
    int x, y;
    setcolor(WHITE);
    for(y=60; y<=360; y+=100)
    {
        for(x=360; x<=660; x+=100)
        {
            circle(x,y,40);
            setfillstyle(SOLID_FILL,BLACK);
            floodfill(x+1,y+1,WHITE);
            setcolor(WHITE);
        }
    }
    x=50;
    for(i=1; i<=q; i++)
    {
        setcolor(WHITE);
        fillellipse(x,20,15,10);
        setfillstyle(SOLID_FILL,BLUE);
        floodfill(x,20,WHITE);
        x+=35;
    }
    setcolor(BLACK);
    rectangle(930,10,969,40);
    setfillstyle(SOLID_FILL,BLACK);
    bar(942,15,947,35);
    bar(952,15,957,35);
    setcolor(CYAN);
    setfillstyle(SOLID_FILL,CYAN);
    floodfill(931,11,BLACK);
    setbkcolor(BLACK);
    setcolor(WHITE);
    settextstyle(1, HORIZ_DIR, 100);
    outtextxy(900,50,s);
    setbkcolor(BLACK);
    setcolor(WHITE);
    settextstyle(1, HORIZ_DIR, 100);
    outtextxy(214,55,st);

}
void level_1_bck(char s[], char st[], int q)
{
    readimagefile("e.jpg",0,0,1000,500);
    int i;
    int x, y;
    setcolor(WHITE);
    for(y=160; y<=360; y+=100)
    {
        for(x=360; x<=560; x+=100)
        {
            circle(x,y,40);
            setfillstyle(SOLID_FILL,BLACK);
            floodfill(x+1,y+1,WHITE);
            setcolor(WHITE);
        }
    }
    x=50;
    for(i=1; i<=q; i++)
    {
        setcolor(WHITE);
        fillellipse(x,20,15,10);
        setfillstyle(SOLID_FILL,BLUE);
        floodfill(x,20,WHITE);
        x+=35;
    }
    setcolor(BLACK);
    rectangle(930,10,969,40);
    setfillstyle(SOLID_FILL,BLACK);
    bar(942,15,947,35);
    bar(952,15,957,35);
    setcolor(CYAN);
    setfillstyle(SOLID_FILL,CYAN);
    floodfill(931,11,BLACK);
    setbkcolor(BLACK);
    setcolor(WHITE);
    settextstyle(1, HORIZ_DIR, 100);
    outtextxy(750,50, "Your score : ");
    setbkcolor(BLACK);
    setcolor(WHITE);
    settextstyle(1, HORIZ_DIR, 100);
    outtextxy(900,50,s);
    setbkcolor(getpixel(25,50));
    setcolor(WHITE);
    settextstyle(1, HORIZ_DIR, 100);
    outtextxy(25,50, "TIME REMAINING : ");
    setbkcolor(getpixel(275,50));
    setcolor(WHITE);
    settextstyle(1, HORIZ_DIR, 100);
    outtextxy(275,50,st);

}
void level4(int q,int p, char s[], int sp)
{
    initwindow(1366,768,"LEVEL COMPLETE");
    readimagefile("com.jpg",0,0,1366,768);
    delay(2000);
    closegraph();
    initwindow(1276,700,"LEVEL 4");
    readimagefile("l41.jpg",0,0,1276,700);
    delay(800);
    readimagefile("l42.jpg",0,0,1276,700);
    delay(800);
    readimagefile("l43.jpg",0,0,1276,700);
    delay(800);
    closegraph();
    initwindow(1000,500,"LEVEL 2");
    readimagefile("sample.jpg",0,0,1000,500);
    char cha;
    int n,i,c,t,m,f,tmp;
    int x,y,x2,y2;
    l=0;
    char st[100]={'6','0'};
    level_2_bck(s,st,q);
    registermousehandler(WM_LBUTTONDOWN, click_handler);
    c=0;
    t=0;
    m=60;
    f=0;
    while(t<=60000)
    {
        if(kbhit()==true) cha=getch();
        t+=1000;
        m--;
        st[1]=(m%10)+48;
        st[0]=(m/10)+48;
        setbkcolor(BLACK);
        setcolor(WHITE);
        settextstyle(1, HORIZ_DIR, 100);
        outtextxy(214,55,st);
        if(l==1)
        {
            setfillstyle(SOLID_FILL,BLACK);
            floodfill(x,y,BLACK);
            readimagefile("egg.jpg",(x-14),(y-30),(x+14),(y+30));
            delay(400);
            setfillstyle(SOLID_FILL,BLACK);
            floodfill(x,y,BLACK);
            c++;
            l=0;
            p++;
            if(p<=9)
            {
                s[2]++;
            }
            else if(p<=99)
            {
                s[0]='0';
                s[1]=(p/10)+48;
                s[2]=(p%10)+48;
            }

            else if(p<=199)
            {
                tmp=p;
                s[2]=(tmp%10)+48;
                tmp=tmp/10;
                s[1]=(tmp%10)+48;
                s[0]=(tmp/10)+48;
            }

            setbkcolor(BLACK);
            setcolor(WHITE);
            settextstyle(1, HORIZ_DIR, 100);
            outtextxy(900,50,s);
            l=0;
            continue;
        }
        n=rand()%19;
        if(n==17)
        {
            n=rand()%16;
            f=2;
        }
        else if(n==16)
        {
            n=rand()%16;
            f=1;
        }
        else if(n==18)
        {
            n=rand()%16;
            f=3;
        }
        if(n==0)
        {
            x=360;
            y=160;
        }
        else if(n==1)
        {
            x=460;
            y=160;
        }
        else if(n==2)
        {
            x=560;
            y=160;
        }
        else if(n==3)
        {
            x=360;
            y=260;
        }
        else if(n==4)
        {
            x=460;
            y=260;
        }
        else if(n==5)
        {
            x=560;
            y=260;
        }
        else if(n==6)
        {
            x=360;
            y=360;
        }
        else if(n==7)
        {
            x=460;
            y=360;
        }
        else if(n==8)
        {
            x=560;
            y=360;
        }
        else if(n==9)
        {
            x=360;
            y=60;
        }
        else if(n==10)
        {
            x=460;
            y=60;
        }
        else if(n==11)
        {
            x=560;
            y=60;
        }
        else if(n==12)
        {
            x=660;
            y=60;
        }
        else if(n==13)
        {
            x=660;
            y=160;
        }
        else if(n==14)
        {
            x=660;
            y=260;
        }
        else if(n==15)
        {
            x=660;
            y=360;
        }
        if(f==0)
        {
            setcolor(RED);
            fillellipse(x,y,20,30);
            setfillstyle(SOLID_FILL,WHITE);
            floodfill(x,y,RED);
        }
        else if(f==1)
        {
            setcolor(RED);
            fillellipse(x,y,20,30);
            setfillstyle(SOLID_FILL,YELLOW);
            floodfill(x,y,RED);
        }
        else if(f==2)
        {
            setcolor(WHITE);
            fillellipse(x,y,20,30);
            setfillstyle(SOLID_FILL,DARKGRAY);
            floodfill(x,y,WHITE);
        }
        else if(f==3)
        {
            setcolor(WHITE);
            fillellipse(x,y,20,30);
            setfillstyle(SOLID_FILL,GREEN);
            floodfill(x,y,WHITE);

        }
        if(l==1) continue;
        else if(l==2)
        {
            c+=5;
            l=0;
            p+=5;
            if(p<=9)
            {
                s[2]=s[2]+5;
            }
            else if(p<=99)
            {
                s[0]='0';
                s[1]=(p/10)+48;
                s[2]=(p%10)+48;
            }

            else if(p<=199)
            {
                s[2]=(p%10)+48;
                p=p/10;
                s[1]=(p%10)+48;
                s[0]=(p/10)+48;
            }
            setbkcolor(getpixel(750,50));
            setcolor(WHITE);
            settextstyle(1, HORIZ_DIR, 100);
            outtextxy(750,50,s);
            setbkcolor(getpixel(700,200));
            setcolor(BLUE);
            settextstyle(1,HORIZ_DIR,100);
            outtextxy(700,200,"BONUS 5");
            delay(600);
            level_2_bck(s,st,q);
            f=0;
            l=0;
            continue;


        }
        else if(l==3)
        {
            q--;
            if(q==0)
            {
                closegraph();
                game_over(s,p);
            }
            setbkcolor(getpixel(700,200));
            setcolor(BLUE);
            settextstyle(1,HORIZ_DIR,100);
            outtextxy(700,200,"OOPS");
            settextstyle(1,HORIZ_DIR,100);
            outtextxy(700,250,"LIFE LOST");
            delay(600);
            level_2_bck(s,st,q);
            f=0;
            l=0;
            continue;
        }
        else if(l==4 || cha==27)
        {
            printf("in4\n");
            l=0;
            cha=0;
            res1();
            if(l==2) menu();
            else if(l==3)
                ex_window();
            else
            {
                printf("in\n%s\n%s\n",s,st);
                l=0;
                level_2_bck(s,st,q);
                registermousehandler(WM_LBUTTONDOWN, click_handler);

                continue;
            }
            l=0;

        }
        else if(l==5)
        {
            if(q<4)
            {
                q++;
            }
            setbkcolor(getpixel(700,200));
            setcolor(BLUE);
            settextstyle(1,HORIZ_DIR,100);
            outtextxy(700,200,"OOPS");
            settextstyle(1,HORIZ_DIR,100);
            outtextxy(700,250,"LIFE LOST");
            delay(600);
            level_2_bck(s,st,q);
            f=0;
            l=0;
            continue;
        }
        f=0;
        delay(sp);
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(x,y,BLACK);
    }
    l=0;
    closegraph();
    game_over(s,p);


}

void level3(int q, int p, char  s[],int sp)
{
    initwindow(1366,768,"LEVEL COMPLETE");
    readimagefile("com.jpg",0,0,1366,768);
    delay(2000);
    closegraph();
    initwindow(1276,700,"LEVEL 3");
    readimagefile("l31.jpg",0,0,1276,700);
    delay(800);
    readimagefile("l32.jpg",0,0,1276,700);
    delay(800);
    readimagefile("l33.jpg",0,0,1276,700);
    delay(800);
    closegraph();
    initwindow(1000,500,"LEVEL !");
    readimagefile("e.jpg",0,0,1000,500);
    char st[100]= {'6','0'};
    char cha;
    int n,i,c,t,m,f,tmp;
    int x,y,x2,y2;
    l=0;
    level_1_bck(s,st,q);
    registermousehandler(WM_LBUTTONDOWN, click_handler);
    c=0;
    t=0;
    m=60;
    f=0;
    while(t<=60000)
    {
        if(kbhit()==true) cha=getch();
        t+=1000;
        m--;
        st[1]=(m%10)+48;
        st[0]=(m/10)+48;
        setbkcolor(getpixel(275,50));
        setcolor(WHITE);
        settextstyle(1, HORIZ_DIR, 100);
        outtextxy(275,50,st);
        if(l==1)
        {
            setfillstyle(SOLID_FILL,BLACK);
            floodfill(x,y,BLACK);
            readimagefile("egg.jpg",(x-14),(y-30),(x+14),(y+30));
            delay(400);
            setfillstyle(SOLID_FILL,BLACK);
            floodfill(x,y,BLACK);
            c++;
            l=0;
            p++;
            if(p<=9)
            {
                s[2]++;
            }
            else if(p<=99)
            {
                s[0]='0';
                s[1]=(p/10)+48;
                s[2]=(p%10)+48;
            }

            else if(p<=199)
            {
                tmp=p;
                s[2]=(tmp%10)+48;
                tmp=tmp/10;
                s[1]=(tmp%10)+48;
                s[0]=(tmp/10)+48;
            }

            setbkcolor(getpixel(900,50));
            setcolor(WHITE);
            settextstyle(1, HORIZ_DIR, 100);
            outtextxy(900,50,s);
            l=0;
            continue;
        }
        n=rand()%12;
        if(n==10)
        {
            n=rand()%9;
            f=2;
        }
        else if(n==9)
        {
            n=rand()%9;
            f=1;
        }
        else if(n==11)
        {
            n=rand()%9;
            f=3;
        }
        if(n==0)
        {
            x=360;
            y=160;
        }
        else if(n==1)
        {
            x=460;
            y=160;
        }
        else if(n==2)
        {
            x=560;
            y=160;
        }
        else if(n==3)
        {
            x=360;
            y=260;
        }
        else if(n==4)
        {
            x=460;
            y=260;
        }
        else if(n==5)
        {
            x=560;
            y=260;
        }
        else if(n==6)
        {
            x=360;
            y=360;
        }
        else if(n==7)
        {
            x=460;
            y=360;
        }
        else if(n==8)
        {
            x=560;
            y=360;
        }
        if(f==0)
        {
            setcolor(RED);
            fillellipse(x,y,20,30);
            setfillstyle(SOLID_FILL,WHITE);
            floodfill(x,y,RED);
        }
        else if(f==1)
        {
            setcolor(RED);
            fillellipse(x,y,20,30);
            setfillstyle(SOLID_FILL,YELLOW);
            floodfill(x,y,RED);
        }
        else if(f==2)
        {
            setcolor(WHITE);
            fillellipse(x,y,20,30);
            setfillstyle(SOLID_FILL,DARKGRAY);
            floodfill(x,y,WHITE);
        }
        else if(f==3)
        {
            setcolor(WHITE);
            fillellipse(x,y,20,30);
            setfillstyle(SOLID_FILL,GREEN);
            floodfill(x,y,WHITE);
        }
        if(l==1) continue;
        else if(l==2)
        {
            c+=5;
            l=0;
            p+=5;
            if(p<=9)
            {
                s[2]=s[2]+5;
            }
            else if(p<=99)
            {
                s[0]='0';
                s[1]=(p/10)+48;
                s[2]=(p%10)+48;
            }

            else if(p<=199)
            {
                s[2]=(p%10)+48;
                p=p/10;
                s[1]=(p%10)+48;
                s[0]=(p/10)+48;
            }
            setbkcolor(getpixel(750,50));
            setcolor(WHITE);
            settextstyle(1, HORIZ_DIR, 100);
            outtextxy(750,50,s);
            setbkcolor(getpixel(700,200));
            setcolor(BLUE);
            settextstyle(1,HORIZ_DIR,100);
            outtextxy(700,200,"BONUS 5");
            delay(600);
            level_1_bck(s,st,q);
            f=0;
            l=0;
            continue;


        }
        else if(l==3)
        {
            q--;
            if(q==0)
            {
                closegraph();
                game_over(s,p);

            }
            setbkcolor(getpixel(700,200));
            setcolor(WHITE);
            settextstyle(1,HORIZ_DIR,100);
            outtextxy(700,200,"OOPS");
            settextstyle(1,HORIZ_DIR,100);
            outtextxy(700,250,"LIFE LOST");
            delay(600);
            level_1_bck(s,st,q);
            f=0;
            l=0;
            continue;
        }
        else if(l==4 || cha==27)
        {
            printf("in4\n");
            l=0;
            cha=0;
            res1();
            if(l==2) menu();
            else if(l==3)
                ex_window();
            else
            {
                printf("in\n%s\n%s\n",s,st);
                l=0;
                level_1_bck(s,st,q);
                registermousehandler(WM_LBUTTONDOWN, click_handler);

                continue;
            }
            continue;
        l=0;
        }
        else if(l==5)
        {

            if(q<4)
            {
                q++;
            }
            setbkcolor(getpixel(700,200));
            setcolor(WHITE);
            settextstyle(1,HORIZ_DIR,100);
            outtextxy(700,200,"BONUS LIFE");
            delay(600);
            level_1_bck(s,st,q);
            f=0;
            l=0;
            continue;
        }
        f=0;
        delay(sp);
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(x,y,BLACK);
    }

    closegraph();
    l=0;
    if(p>=15)
    level4(q,p,s,500);
    else game_over(s,p);

}

void level2(int q,int p, char s[], int sp)
{
    initwindow(1366,768,"LEVEL COMPLETE");
    readimagefile("com.jpg",0,0,1366,768);
    delay(2000);
    closegraph();
    initwindow(1276,700,"LEVEL 2");
    readimagefile("l21.jpg",0,0,1276,700);
    delay(800);
    readimagefile("l22.jpg",0,0,1276,700);
    delay(800);
    readimagefile("l23.jpg",0,0,1276,700);
    delay(800);
    closegraph();
    initwindow(1000,500,"LEVEL 2");
    readimagefile("sample.jpg",0,0,1000,500);
    char cha;
    int n,i,c,t,m,f,tmp;
    int x,y,x2,y2;
    l=0;
    char st[100]={'6','0'};
    level_2_bck(s,st,q);
    registermousehandler(WM_LBUTTONDOWN, click_handler);
    c=0;
    t=0;
    m=60;
    f=0;
    while(t<=60000)
    {
        if(kbhit()==true) cha=getch();
        t+=1000;
        m--;
        st[1]=(m%10)+48;
        st[0]=(m/10)+48;
        setbkcolor(BLACK);
        setcolor(WHITE);
        settextstyle(1, HORIZ_DIR, 100);
        outtextxy(214,55,st);
        if(l==1)
        {
            setfillstyle(SOLID_FILL,BLACK);
            floodfill(x,y,BLACK);
            readimagefile("egg.jpg",(x-14),(y-30),(x+14),(y+30));
            delay(400);
            setfillstyle(SOLID_FILL,BLACK);
            floodfill(x,y,BLACK);
            c++;
            l=0;
            p++;
            if(p<=9)
            {
                s[2]++;
            }
            else if(p<=99)
            {
                s[0]='0';
                s[1]=(p/10)+48;
                s[2]=(p%10)+48;
            }

            else if(p<=199)
            {
                tmp=p;
                s[2]=(tmp%10)+48;
                tmp=tmp/10;
                s[1]=(tmp%10)+48;
                s[0]=(tmp/10)+48;
            }

            setbkcolor(BLACK);
            setcolor(WHITE);
            settextstyle(1, HORIZ_DIR, 100);
            outtextxy(900,50,s);
            l=0;
            continue;
        }
        n=rand()%19;
        if(n==17)
        {
            n=rand()%16;
            f=2;
        }
        else if(n==16)
        {
            n=rand()%16;
            f=1;
        }
        else if(n==18)
        {
            n=rand()%16;
            f=3;
        }
        if(n==0)
        {
            x=360;
            y=160;
        }
        else if(n==1)
        {
            x=460;
            y=160;
        }
        else if(n==2)
        {
            x=560;
            y=160;
        }
        else if(n==3)
        {
            x=360;
            y=260;
        }
        else if(n==4)
        {
            x=460;
            y=260;
        }
        else if(n==5)
        {
            x=560;
            y=260;
        }
        else if(n==6)
        {
            x=360;
            y=360;
        }
        else if(n==7)
        {
            x=460;
            y=360;
        }
        else if(n==8)
        {
            x=560;
            y=360;
        }
        else if(n==9)
        {
            x=360;
            y=60;
        }
        else if(n==10)
        {
            x=460;
            y=60;
        }
        else if(n==11)
        {
            x=560;
            y=60;
        }
        else if(n==12)
        {
            x=660;
            y=60;
        }
        else if(n==13)
        {
            x=660;
            y=160;
        }
        else if(n==14)
        {
            x=660;
            y=260;
        }
        else if(n==15)
        {
            x=660;
            y=360;
        }
        if(f==0)
        {
            setcolor(RED);
            fillellipse(x,y,20,30);
            setfillstyle(SOLID_FILL,WHITE);
            floodfill(x,y,RED);
        }
        else if(f==1)
        {
            setcolor(RED);
            fillellipse(x,y,20,30);
            setfillstyle(SOLID_FILL,YELLOW);
            floodfill(x,y,RED);
        }
        else if(f==2)
        {
            setcolor(WHITE);
            fillellipse(x,y,20,30);
            setfillstyle(SOLID_FILL,DARKGRAY);
            floodfill(x,y,WHITE);
        }
        else if(f==3)
        {
            setcolor(WHITE);
            fillellipse(x,y,20,30);
            setfillstyle(SOLID_FILL,GREEN);
            floodfill(x,y,WHITE);

        }
        if(l==1) continue;
        else if(l==2)
        {
            c+=5;
            l=0;
            p+=5;
            if(p<=9)
            {
                s[2]=s[2]+5;
            }
            else if(p<=99)
            {
                s[0]='0';
                s[1]=(p/10)+48;
                s[2]=(p%10)+48;
            }

            else if(p<=199)
            {
                s[2]=(p%10)+48;
                p=p/10;
                s[1]=(p%10)+48;
                s[0]=(p/10)+48;
            }
            setbkcolor(getpixel(750,50));
            setcolor(WHITE);
            settextstyle(1, HORIZ_DIR, 100);
            outtextxy(750,50,s);
            setbkcolor(getpixel(700,200));
            setcolor(BLUE);
            settextstyle(1,HORIZ_DIR,100);
            outtextxy(700,200,"BONUS 5");
            delay(600);
            level_2_bck(s,st,q);
            f=0;
            l=0;
            continue;


        }
        else if(l==3)
        {
            q--;
            if(q==0)
            {
                closegraph();
                game_over(s,p);

            }
            setbkcolor(getpixel(700,200));
            setcolor(BLUE);
            settextstyle(1,HORIZ_DIR,100);
            outtextxy(700,200,"OOPS");
            settextstyle(1,HORIZ_DIR,100);
            outtextxy(700,250,"LIFE LOST");
            delay(600);
            level_2_bck(s,st,q);
            f=0;
            l=0;
            continue;
        }
        else if(l==4 || cha==27)
        {
            printf("in4\n");
            l=0;
            cha=0;
            res1();
            if(l==2) menu();
            else if(l==3)
                ex_window();
            else
            {
                printf("in\n%s\n%s\n",s,st);
                l=0;
                level_2_bck(s,st,q);
                registermousehandler(WM_LBUTTONDOWN, click_handler);

                continue;
            }
            l=0;

        }
        else if(l==5)
        {
            if(q<4)
            {
                q++;
            }
            setbkcolor(getpixel(700,200));
            setcolor(BLUE);
            settextstyle(1,HORIZ_DIR,100);
            outtextxy(700,200,"OOPS");
            settextstyle(1,HORIZ_DIR,100);
            outtextxy(700,250,"LIFE LOST");
            delay(600);
            level_2_bck(s,st,q);
            f=0;
            l=0;
            continue;
        }
        f=0;
        delay(sp);
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(x,y,BLACK);
    }
    l=0;
    closegraph();
    if(p>=10) level3(q,p,s,500);
    else
    game_over(s,p);


}

void level1()
{
    initwindow(1276,700,"LEVEL 1");
    readimagefile("l11.jpg",0,0,1276,700);
    delay(800);
    readimagefile("l12.jpg",0,0,1276,700);
    delay(800);
    readimagefile("l13.jpg",0,0,1276,700);
    delay(800);
    closegraph();
    initwindow(1000,500,"LEVEL 1");
    readimagefile("e.jpg",0,0,1000,500);
    char s[100]= {'0','0','0'};
    char st[100]= {'6','0'};
    char cha;
    int n, p,i,c,t,m,f,tmp,q;
    q=3;
    int x,y,x2,y2;
    l=0;
    level_1_bck(s,st,q);
    registermousehandler(WM_LBUTTONDOWN, click_handler);
    c=0;
    t=0;
    p=0;
    m=60;
    f=0;
    while(t<=60000)
    {
        if(kbhit()==true) cha=getch();
        t+=1000;
        m--;
        st[1]=(m%10)+48;
        st[0]=(m/10)+48;
        setbkcolor(getpixel(275,50));
        setcolor(WHITE);
        settextstyle(1, HORIZ_DIR, 100);
        outtextxy(275,50,st);
        if(l==1)
        {
            setfillstyle(SOLID_FILL,BLACK);
            floodfill(x,y,BLACK);
            readimagefile("egg.jpg",(x-14),(y-30),(x+14),(y+30));
            delay(400);
            setfillstyle(SOLID_FILL,BLACK);
            floodfill(x,y,BLACK);
            c++;
            l=0;
            p++;
            if(p<=9)
            {
                s[2]++;
            }
            else if(p<=99)
            {
                s[0]='0';
                s[1]=(p/10)+48;
                s[2]=(p%10)+48;
            }

            else if(p<=199)
            {
                tmp=p;
                s[2]=(tmp%10)+48;
                tmp=tmp/10;
                s[1]=(tmp%10)+48;
                s[0]=(tmp/10)+48;
            }

            setbkcolor(getpixel(900,50));
            setcolor(WHITE);
            settextstyle(1, HORIZ_DIR, 100);
            outtextxy(900,50,s);
            l=0;
            continue;
        }
        n=rand()%12;
        if(n==10)
        {
            n=rand()%9;
            f=2;
        }
        else if(n==9)
        {
            n=rand()%9;
            f=1;
        }
        else if(n==11)
        {
            n=rand()%9;
            f=3;
        }
        if(n==0)
        {
            x=360;
            y=160;
        }
        else if(n==1)
        {
            x=460;
            y=160;
        }
        else if(n==2)
        {
            x=560;
            y=160;
        }
        else if(n==3)
        {
            x=360;
            y=260;
        }
        else if(n==4)
        {
            x=460;
            y=260;
        }
        else if(n==5)
        {
            x=560;
            y=260;
        }
        else if(n==6)
        {
            x=360;
            y=360;
        }
        else if(n==7)
        {
            x=460;
            y=360;
        }
        else if(n==8)
        {
            x=560;
            y=360;
        }
        if(f==0)
        {
            setcolor(RED);
            fillellipse(x,y,20,30);
            setfillstyle(SOLID_FILL,WHITE);
            floodfill(x,y,RED);
        }
        else if(f==1)
        {
            setcolor(RED);
            fillellipse(x,y,20,30);
            setfillstyle(SOLID_FILL,YELLOW);
            floodfill(x,y,RED);
        }
        else if(f==2)
        {
            setcolor(WHITE);
            fillellipse(x,y,20,30);
            setfillstyle(SOLID_FILL,DARKGRAY);
            floodfill(x,y,WHITE);
        }
        else if(f==3)
        {
            setcolor(WHITE);
            fillellipse(x,y,20,30);
            setfillstyle(SOLID_FILL,GREEN);
            floodfill(x,y,WHITE);
        }
        if(l==1) continue;
        else if(l==2)
        {
            c+=5;
            l=0;
            p+=5;
            if(p<=9)
            {
                s[2]=s[2]+5;
            }
            else if(p<=99)
            {
                s[0]='0';
                s[1]=(p/10)+48;
                s[2]=(p%10)+48;
            }

            else if(p<=199)
            {
                s[2]=(p%10)+48;
                p=p/10;
                s[1]=(p%10)+48;
                s[0]=(p/10)+48;
            }
            setbkcolor(getpixel(750,50));
            setcolor(WHITE);
            settextstyle(1, HORIZ_DIR, 100);
            outtextxy(750,50,s);
            setbkcolor(getpixel(700,200));
            setcolor(BLUE);
            settextstyle(1,HORIZ_DIR,100);
            outtextxy(700,200,"BONUS 5");
            delay(600);
            level_1_bck(s,st,q);
            f=0;
            l=0;
            continue;


        }
        else if(l==3)
        {
            q--;
            if(q==0)
            {
                closegraph();
                game_over(s,p);

            }
            setbkcolor(getpixel(700,200));
            setcolor(WHITE);
            settextstyle(1,HORIZ_DIR,100);
            outtextxy(700,200,"OOPS");
            settextstyle(1,HORIZ_DIR,100);
            outtextxy(700,250,"LIFE LOST");
            delay(600);
            level_1_bck(s,st,q);
            f=0;
            l=0;
            continue;
        }
        else if(l==4 || cha==27)
        {
            printf("in4\n");
            l=0;
            cha=0;
            res1();
            if(l==2) menu();
            else if(l==3)
                ex_window();
            else
            {
                printf("in\n%s\n%s\n",s,st);
                l=0;
                level_1_bck(s,st,q);
                registermousehandler(WM_LBUTTONDOWN, click_handler);

                continue;
            }
            continue;
        l=0;
        }
        else if(l==5)
        {

            if(q<4)
            {
                q++;
            }
            setbkcolor(getpixel(700,200));
            setcolor(WHITE);
            settextstyle(1,HORIZ_DIR,100);
            outtextxy(700,200,"BONUS LIFE");
            delay(600);
            level_1_bck(s,st,q);
            f=0;
            l=0;
            continue;
        }
        f=0;
        delay(800);
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(x,y,BLACK);
    }

    closegraph();
    l=0;
    if(p>=5)
    level2(q,p,s,800);
    else game_over(s,p);

}

