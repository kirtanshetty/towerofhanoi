
//**************************************************************************
//*|----------------------------------------------------------------------|*
//*| Project of "Tower of Hanoi Game"                		          |*
//*| by Aditya Mishra,Kirtan Shetty,Ashwin Kalekar                        |*
//*| S.E Terna Engineering College,Nerul,Navi Mumbai.                     |*
//*|----------------------------------------------------------------------|*
//**************************************************************************

#include "./lib/graphics.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

//*****************Definition of co-ordinates of the rings
int ring1x1=20,ring1y1=349,ring1x2=205,ring1y2=310;
int ring2x1=40,ring2y1=309,ring2x2=185,ring2y2=270;
int ring3x1=60,ring3y1=269,ring3x2=165,ring3y2=230;
int ring4x1=80,ring4y1=229,ring4x2=145,ring4y2=190;

int ring1x1atb=225,ring1x2atb=410;
int ring2x1atb=245,ring2x2atb=390;
int ring3x1atb=265,ring3x2atb=370;
int ring4x1atb=285,ring4x2atb=350;

int ring1x1atc=430,ring1x2atc=615;
int ring2x1atc=450,ring2x2atc=595;
int ring3x1atc=470,ring3x2atc=575;
int ring4x1atc=490,ring4x2atc=555;
int e;
char from_peg,to_peg;
void movement_of_rings(char,char);
void finish();
//******************************************************************
//******************************************************************
//************************************START OF RING DRAWING FUNCTION
int error(char,char);
void draw_ring1(int x1,int y1,int x2,int y2)
{
   setcolor(LIGHTCYAN);
   rectangle(x1,y1,x2,y2);
   setfillstyle(SOLID_FILL,CYAN);
   floodfill(x1+2,y1-2,LIGHTCYAN);
   setcolor(WHITE);
   settextstyle(3,0,4);
   outtextxy(x1+85,y2,"1");
}
void draw_ring2(int x1,int y1,int x2,int y2)
{
   setcolor(LIGHTGREEN);
   rectangle(x1,y1,x2,y2);
   setfillstyle(SOLID_FILL,GREEN);
   floodfill(x1+2,y1-2,LIGHTGREEN);
   setcolor(WHITE);
   settextstyle(3,0,4);
   outtextxy(x1+65,y2,"2");
}
void draw_ring3(int x1,int y1,int x2,int y2)
{
   setcolor(LIGHTRED);
   rectangle(x1,y1,x2,y2);
   setfillstyle(SOLID_FILL,RED);
   floodfill(x1+2,y1-2,LIGHTRED);
   setcolor(WHITE);
   settextstyle(3,0,4);
   outtextxy(x1+45,y2,"3");
}
void draw_ring4(int x1,int y1,int x2,int y2)
{
   setcolor(LIGHTBLUE);
   rectangle(x1,y1,x2,y2);
   setfillstyle(SOLID_FILL,BLUE);
   floodfill(x1+2,y1-2,LIGHTBLUE);
   setcolor(WHITE);
   settextstyle(3,0,4);
   outtextxy(x1+25,y2,"4");
}
/*char c;
void quit_game()
{
       setcolor(LIGHTGRAY);
       rectangle(3,477,636,427);
       setfillstyle(SOLID_FILL,LIGHTGRAY);
       floodfill(5,460,DARKGRAY);
       setcolor(RED);
       settextstyle(6,0,4);
       outtextxy(40,430,"ARE YOU SURE YOU WANT TO QUIT (Y/N)");
       c=(char)getch();
       if(c=='Y' || c=='y')
       exit;
       else
       return ;

}*/

//**************************************END OF THE RING DRAWING FUNCTIONS

void erase_ring(int x1,int y1,int x2,int y2)
{
   setfillstyle(SOLID_FILL,BLACK);
   if(getpixel(x1+2,y1-2)==BLUE)
   floodfill(x1+2,y1-2,LIGHTBLUE);
   if(getpixel(x1+2,y1-2)==RED)
   floodfill(x1+2,y1-2,LIGHTRED);
   if(getpixel(x1+2,y1-2)==GREEN)
   floodfill(x1+2,y1-2,LIGHTGREEN);
   if(getpixel(x1+2,y1-2)==CYAN)
   floodfill(x1+2,y1-2,LIGHTCYAN);

   setcolor(BLACK);
   rectangle(x1,y1,x2,y2);
}

//*******************************************************************
//*******************************************************************
//**********************************START OF THE GAME SCREEN FUNCTION

void game_screen()
{
   /*********** DRAWING THE BACKGROUND */
   setcolor(LIGHTGRAY);
   rectangle(0,0,639,479);
   setcolor(LIGHTGRAY);
   rectangle(0,350,639,479);
   rectangle(0,0,639,100);
   setfillstyle(SOLID_FILL,DARKGRAY);
   floodfill(2,402,LIGHTGRAY);
   floodfill(2,2,LIGHTGRAY);
    setcolor(LIGHTGRAY);
   rectangle(3,477,636,427);
   setfillstyle(SOLID_FILL,LIGHTGRAY);
   floodfill(5,460,LIGHTGRAY);
   /************ DRAWING THE RINGS IN FIRST POSITION */
   draw_ring1(ring1x1,ring1y1,ring1x2,ring1y2);
   draw_ring2(ring2x1,ring2y1,ring2x2,ring2y2);
   draw_ring3(ring3x1,ring3y1,ring3x2,ring3y2);
   draw_ring4(ring4x1,ring4y1,ring4x2,ring4y2);
  /************ WRITING ON THE GAME PAGE */
   settextstyle(7,0,4);
   outtextxy(225,1,"Game Page");
   settextstyle(3,0,4);
   outtextxy(65,350,"Peg-A");
   outtextxy(270,350,"Peg-B");
   outtextxy(475,350,"Peg-C");

   while(1)
   {
     finish();
     from_peg=(char)getch();
     to_peg=(char)getch();
     if(from_peg=='Q' || from_peg=='q' || to_peg=='Q' || to_peg=='q')
     break;
     if(from_peg=='R' || from_peg=='r' || to_peg=='R' || to_peg=='r')
     {
	cleardevice();
	game_screen();
     }
     e=error(from_peg,to_peg);
     if(e==0)
     {
	setcolor(LIGHTGRAY);
	rectangle(3,477,636,427);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	floodfill(5,460,DARKGRAY);
	movement_of_rings(from_peg,to_peg);
     }

   }
}
//*************************************END OF GAME SCREEN FUNCTION

//****************************************************************
//****************************************************************
//********************************START OF MOVEMENT FUNCTION
int error(char from_peg,char to_peg)
{
   if(from_peg==to_peg)
   {
       setcolor(LIGHTGRAY);
       rectangle(3,477,636,427);
       setfillstyle(SOLID_FILL,LIGHTGRAY);
       floodfill(5,460,DARKGRAY);
       setcolor(RED);
       settextstyle(6,0,4);
       outtextxy(100,430,"UNABLE TO MOVE TO SAME PEG.");
       return(1);
   }
   else if(from_peg!='a'&&from_peg!='b'&&from_peg!='c'||to_peg!='a'&&to_peg!='b'&&to_peg!='c')
   {
       setcolor(LIGHTGRAY);
       rectangle(3,477,636,427);
       setfillstyle(SOLID_FILL,LIGHTGRAY);
       floodfill(5,460,DARKGRAY);
       setcolor(RED);
       settextstyle(6,0,4);
       outtextxy(230,430,"INVALID PEG.");
       return(2);
   }

   else return(0);
}
void movement_of_rings(char from_peg,char to_peg)
{
//**********DECIDING THE X-CO-ORDINATES OF FROMPEG AND TOPEG
   int frompegx,topegx;
   if((from_peg=='A'|| from_peg=='a') && (to_peg=='B' ||to_peg=='b'))
   {
	frompegx=ring4x1+2;
	topegx=ring4x1atb+2;
   }
   else if((from_peg=='A'|| from_peg=='a') && (to_peg=='C' ||to_peg=='c'))
   {
	frompegx=ring4x1+2;
	topegx=ring4x1atc+2;
   }
   else if((from_peg=='B'|| from_peg=='b') && (to_peg=='A' ||to_peg=='a'))
   {
	frompegx=ring4x1atb+2;
	topegx=ring4x1+2;
   }
   else if((from_peg=='B'|| from_peg=='b') && (to_peg=='C' ||to_peg=='c'))
   {
	frompegx=ring4x1atb+2;
	topegx=ring4x1atc+2;
   }
   else if((from_peg=='C'|| from_peg=='c') && (to_peg=='A' ||to_peg=='a'))
   {
	frompegx=ring4x1atc+2;
	topegx=ring4x1+2;
   }
   else if((from_peg=='C'|| from_peg=='c') && (to_peg=='B' ||to_peg=='b'))
   {
	frompegx=ring4x1atc+2;
	topegx=ring4x1atb+2;
   }

//********END OF DESICION MAKING AND FROMPEG AND TOPEG CO-ORDINATES DECIDED
///////////////////////////////////////////////////////////////////////
     if(getpixel(frompegx,ring4y1-2)==BLUE)
     {
	erase_ring(frompegx-2,ring4y1,frompegx+63,ring4y2);
	if(getpixel(topegx,ring1y1-2)==BLACK)
	draw_ring4(topegx-2,ring1y1,topegx+63,ring1y2);
	else if(getpixel(topegx,ring2y1-2)==BLACK)
	draw_ring4(topegx-2,ring2y1,topegx+63,ring2y2);
	else if(getpixel(topegx,ring3y1-2)==BLACK)
	draw_ring4(topegx-2,ring3y1,topegx+63,ring3y2);
	else if(getpixel(topegx,ring4y1-2)==BLACK)
	draw_ring4(topegx-2,ring4y1,topegx+63,ring4y2);
     }
     else if(getpixel(frompegx,ring3y1-2)==BLUE)
     {
	erase_ring(frompegx-2,ring3y1,frompegx+63,ring3y2);
	if(getpixel(topegx,ring1y1-2)==BLACK)
	draw_ring4(topegx-2,ring1y1,topegx+63,ring1y2);
	else if(getpixel(topegx,ring2y1-2)==BLACK)
	draw_ring4(topegx-2,ring2y1,topegx+63,ring2y2);
	else if(getpixel(topegx,ring3y1-2)==BLACK)
	draw_ring4(topegx-2,ring3y1,topegx+63,ring3y2);
	else if(getpixel(topegx,ring4y1-2)==BLACK)
	draw_ring4(topegx-2,ring4y1,topegx+63,ring4y2);
     }
     else if(getpixel(frompegx,ring2y1-2)==BLUE)
     {
	erase_ring(frompegx-2,ring2y1,frompegx+63,ring2y2);
	if(getpixel(topegx,ring1y1-2)==BLACK)
	draw_ring4(topegx-2,ring1y1,topegx+63,ring1y2);
	else if(getpixel(topegx,ring2y1-2)==BLACK)
	draw_ring4(topegx-2,ring2y1,topegx+63,ring2y2);
	else if(getpixel(topegx,ring3y1-2)==BLACK)
	draw_ring4(topegx-2,ring3y1,topegx+63,ring3y2);
	else if(getpixel(topegx,ring4y1-2)==BLACK)
	draw_ring4(topegx-2,ring4y1,topegx+63,ring4y2);
     }
     else if(getpixel(frompegx,ring1y1-2)==BLUE)
     {
	erase_ring(frompegx-2,ring1y1,frompegx+63,ring1y2);
	if(getpixel(topegx,ring1y1-2)==BLACK)
	draw_ring4(topegx-2,ring1y1,topegx+63,ring1y2);
	else if(getpixel(topegx,ring2y1-2)==BLACK)
	draw_ring4(topegx-2,ring2y1,topegx+63,ring2y2);
	else if(getpixel(topegx,ring3y1-2)==BLACK)
	draw_ring4(topegx-2,ring3y1,topegx+63,ring3y2);
	else if(getpixel(topegx,ring4y1-2)==BLACK)
	draw_ring4(topegx-2,ring4y1,topegx+63,ring4y2);
     }
///////////////////////////////////////////

//***********************************************************FOR RING 3
//////////FOR RING THREE AT POSITION 3


     else if(getpixel(frompegx,ring3y1-2)==RED && getpixel(topegx,ring1y1-2)!=BLUE && getpixel(topegx,ring2y1-2)!=BLUE && getpixel(topegx,ring3y1-2)!=BLUE)
     {
	erase_ring(frompegx-22,ring3y1,frompegx+83,ring3y2);
	if(getpixel(topegx,ring1y1-2)==BLACK)
	draw_ring3(topegx-22,ring1y1,topegx+83,ring1y2);
	else if(getpixel(topegx,ring2y1-2)==BLACK)
	draw_ring3(topegx-22,ring2y1,topegx+83,ring2y2);
	else if(getpixel(topegx,ring3y1-2)==BLACK)
	draw_ring3(topegx-22,ring3y1,topegx+83,ring3y2);
     }
///////////FOR RING THREE AT POSITION 2
     else if(getpixel(frompegx,ring2y1-2)==RED && getpixel(topegx,ring1y1-2)!=BLUE && getpixel(topegx,ring2y1-2)!=BLUE && getpixel(topegx,ring3y1-2)!=BLUE )
     {
	erase_ring(frompegx-22,ring2y1,frompegx+83,ring2y2);
	if(getpixel(topegx,ring1y1-2)==BLACK)
	draw_ring3(topegx-22,ring1y1,topegx+83,ring1y2);
	else if(getpixel(topegx,ring2y1-2)==BLACK)
	draw_ring3(topegx-22,ring2y1,topegx+83,ring2y2);
	else if(getpixel(topegx,ring3y1-2)==BLACK)
	draw_ring3(topegx-22,ring3y1,topegx+83,ring3y2);
     }
///////////FOR RING THREE AT POSITION 1
     else if(getpixel(frompegx,ring1y1-2)==RED && getpixel(topegx,ring1y1-2)!=BLUE && getpixel(topegx,ring2y1-2)!=BLUE && getpixel(topegx,ring3y1-2)!=BLUE)
     {
	erase_ring(frompegx-22,ring1y1,frompegx+83,ring1y2);
	if(getpixel(topegx,ring1y1-2)==BLACK)
	draw_ring3(topegx-22,ring1y1,topegx+83,ring1y2);
	else if(getpixel(topegx,ring2y1-2)==BLACK)
	draw_ring3(topegx-22,ring2y1,topegx+83,ring2y2);
	else if(getpixel(topegx,ring3y1-2)==BLACK)
	draw_ring3(topegx-22,ring3y1,topegx+83,ring3y2);
     }
//**********************************************************FOR RING 2
///////////////FOR RING TWO AT POSITION 2
     else if(getpixel(frompegx,ring2y1-2)==GREEN && getpixel(topegx,ring1y1-2)!=BLUE && getpixel(topegx,ring1y1-2)!=RED)
     {
	erase_ring(frompegx-42,ring2y1,frompegx+103,ring2y2);
	if(getpixel(topegx,ring1y1-2)==BLACK)
	draw_ring2(topegx-42,ring1y1,topegx+103,ring1y2);
	else if(getpixel(topegx,ring2y1-2)==BLACK)
	draw_ring2(topegx-42,ring2y1,topegx+103,ring2y2);
     }
///////////////FOR RING TWO AT POSITION 1
     else if(getpixel(frompegx,ring1y1-2)==GREEN && getpixel(topegx,ring1y1-2)!=BLUE && getpixel(topegx,ring1y1-2)!=RED)
     {
	erase_ring(frompegx-42,ring1y1,frompegx+103,ring1y2);
	if(getpixel(topegx,ring1y1-2)==BLACK)
	draw_ring2(topegx-42,ring1y1,topegx+103,ring1y2);
	else if(getpixel(topegx,ring2y1-2)==BLACK)
	draw_ring2(topegx-42,ring2y1,topegx+103,ring2y2);
     }
//******************************************************FOR RING 1
////////////////FOR RING ONE AT POSITION 1
     else if(getpixel(frompegx,ring1y1-2)==CYAN && getpixel(topegx,ring1y1-2)!=GREEN && getpixel(topegx,ring1y1-2)!=RED && getpixel(topegx,ring1y1-2)!=BLUE)
     {
	erase_ring(frompegx-62,ring1y1,frompegx+123,ring1y2);
	if(getpixel(topegx,ring1y1-2)==BLACK)
	draw_ring1(topegx-62,ring1y1,topegx+123,ring1y2);
     }

  else
    { setcolor(LIGHTGRAY);
   rectangle(3,477,636,427);
   setfillstyle(SOLID_FILL,LIGHTGRAY);
   floodfill(5,460,DARKGRAY);
       setcolor(RED);
       settextstyle(6,0,4);
       outtextxy(220,430,"INVALID MOVE.");
}
  ///////////////////////////////////////////////////////////////////////

}
void finish()
{
if(getpixel(ring1x1atb+5,ring1y1-5)==CYAN && getpixel(ring2x1atb+5,ring2y1-5)==GREEN && getpixel(ring3x1atb+5,ring3y1-5)==RED && getpixel(ring4x1atb+5,ring4y1-5)==BLUE)
{
   setcolor(LIGHTGRAY);
   rectangle(3,477,636,427);
   setfillstyle(SOLID_FILL,LIGHTGRAY);
   floodfill(5,460,DARKGRAY);
       setcolor(RED);
       settextstyle(6,0,4);
       outtextxy(70,430,"CONGRATULATIONS YOU HAVE WON !!!");

}
else if(getpixel(ring1x1atc+5,ring1y1-5)==CYAN && getpixel(ring2x1atc+5,ring2y1-5)==GREEN && getpixel(ring3x1atc+5,ring3y1-5)==RED && getpixel(ring4x1atc+5,ring4y1-5)==BLUE)
{
   setcolor(LIGHTGRAY);
   rectangle(3,477,636,427);
   setfillstyle(SOLID_FILL,LIGHTGRAY);
   floodfill(5,460,DARKGRAY);
       setcolor(RED);
       settextstyle(6,0,4);
       outtextxy(70,430,"CONGRATULATIONS YOU HAVE WON !!!");

}
}




//*********************************************************************
//*********************************************************************
//********************************************************MAIN FUNCTION

void main()
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
   game_screen();

   getch();
}