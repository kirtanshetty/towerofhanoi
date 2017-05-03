#include "./lib/graphics.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void main()
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
   setbkcolor(DARKGRAY);
   setcolor(WHITE);
   settextstyle(4,0,5);
   outtextxy(85,10,"Terna Engineering College");
   setcolor(LIGHTGRAY);
   settextstyle(10,0,3);
   outtextxy(15,80,"Graphical game of Tower of Hanoi");
   setcolor(RED);
   settextstyle(3,0,3);
   outtextxy(300,150,"BY");
   outtextxy(220,200,"S.E DIV-A COMPS");
   settextstyle(2,0,7);
   setcolor(LIGHTBLUE);
   outtextxy(90,300,"TU3F1011028 - Aditya Mishra - Roll No.25");
   setcolor(LIGHTRED);
   outtextxy(90,320,"TU3F1011049 - Kirtan Shetty - Roll No.40");
   setcolor(GREEN);
   outtextxy(85,340,"TU3F1011051 - Ashwin Kalekar - Roll No.42");
   setcolor(LIGHTGRAY);
   line(0,80,640,80);
   line(0,140,640,140);
   line(0,250,640,250);
   rectangle(1,1,638,478);
   getch();
}
