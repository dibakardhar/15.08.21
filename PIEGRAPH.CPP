#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
int main(void)
{
   clrscr();
   int gd = DETECT, gm, midx, midy,i,dx,dy,value[20],n,degree=0;
   long start,end;

   char str[5];
   clrscr();
   printf("Enter the no of slices : ");
   scanf("%d",&n);

   initgraph(&gd, &gm, "C:\\TC\\bgi");

   setcolor(MAGENTA);

   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
   setcolor(WHITE);
   outtextxy(275,10,"Pie Chart");

   midx = getmaxx()/2;
   midy = getmaxy()/2;

   start = 0;
   end=0;
   value[0]=0;
   printf("Enter the percentage : \n ");
   for( i=1;i<=n;i++)
  {
   scanf("%d",&value[i]);
  degree= degree +((long)value[i] * 360)/100;
  if ( degree >360)
  {
    printf("Exceded 100 % ..Program terminating.. press any key to continue");
   getch();
   exit(0);
  }
  delay(30);
  }
   for(i=0;i<n;i++)
   {

  end = start +(long)(value[i+1]*360)/100;
   setfillstyle(i+1,i+1);
   pieslice(midx, midy, start,end, 100);
   itoa(value[i+1],str,10);

   dx= midx+100*cos(((double)(start+end)/2)*(3.14f/180));
   dy= midy+100*sin((-1*(double)(start+end)/2)*(3.14f/180));
  outtextxy(dx, dy , str);
   start= start+((long)value[i+1]*360)/100;
  }

  getch();
closegraph();
  return 0;
}
