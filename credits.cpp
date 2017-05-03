#include "./lib/graphics.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <DOS.H>

void main()
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
   setbkcolor(DARKGRAY);
/*   setcolor(WHITE);
   settextstyle(4,0,5);
   outtextxy(85,10,"Terna Engineering College");
   setcolor(LIGHTGRAY);
   settextstyle(10,0,3);
   outtextxy(15,80,"Graphical game of Tower of Hanoi");
   setcolor(RED);
   settextstyle(3,0,3);
   outtextxy(300,150,"BY");
   outtextxy(220,200,"S.E DIV-A COMPS");
   settextstyle(2,0,7);    */
   for(int i=0;i<480;i=i+5)
   {
   cleardevice();
   setcolor(LIGHTBLUE);
   outtextxy(150,i+0,"TU3F1011028 - Aditya Mishra - Roll No.25");
   setcolor(LIGHTRED);
   outtextxy(150,i+20,"TU3F1011049 - Kirtan Shetty - Roll No.40");
   setcolor(GREEN);
   outtextxy(146,i+40,"TU3F1011051 - Ashwin Kalekar - Roll No.42");
   setcolor(LIGHTGRAY);
   delay(100);
   }
   settextstyle(4,0,7);
   outtextxy(130,200,"THANK YOU");
  /* line(0,80,640,80);
   line(0,140,640,140);
   line(0,250,640,250);
   rectangle(1,1,638,478);*/
   getch();
}
