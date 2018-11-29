#include <stdio.h>
#include "graphics.h"
#include "game.h"
main()
{
    int l,k,f;
     f=start();
    printf("%d\n",f);
    while(1)
    {
        if(f==1) return 0;
        f=new_menu();
        if(l==1) level1();
        else if(l==2) menu();
        if(f==2) new_menu();
    }
    return 0;


}


