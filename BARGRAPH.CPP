#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>

#define            MAX        50
#define            ARRAYMAX   3

void makegraph(float p[],int n);

void main(void)
{
clrscr();
  int              i,no,n;
  int              scores[50];
  float            percents[50];
  printf("\nEnter the number of months ( 0 - 12) ");
  scanf("%d", &no);

  for (i = 0; i < no; i++)
    {
    printf("\nEnter score between 0 and %d:  ", MAX);
    scanf("%d", &scores[i]);
    if(scores[i]>50 || scores[i]<0)
    {
    i--;
    continue;
    }
    }
  for (i = 0; i < no; i++)
    percents[i] = ((float) scores[i]) / MAX;

  printf("\n\n\n\tSCORE\tPERCENT");
  for (i = 0; i < no; i++)
    printf("\n%d. \t%d\t%3.0f", i + 1, scores[i], (percents[i] * 100));
  getch();
  makegraph(percents,no);
}

void makegraph(float p[],int n)
{
  int              g_driver, g_mode;
  int              i, left, top, wide, bottom, deep;
  char str[5];
  char month[][20]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
  detectgraph(&g_driver, &g_mode);
  initgraph(&g_driver, &g_mode, "C:\\TC\\bgi");
  wide = (int)((getmaxx()) / ((n * 2 ) + 1));
  bottom = getmaxy() - 20;
  deep = (int) (wide / 4);
  left = wide;
  line(0,bottom,getmaxx(),bottom);
  for (i = 0; i < n; i++)
    {
    top = (bottom) - ((int)(p[i] * 300));
    setfillstyle(XHATCH_FILL,i+1);
    bar3d(left, top, (left + wide), bottom, deep,1);
    itoa((int)(p[i]*100),str,10);
    outtextxy((left+(left+wide))/2,top-15, str);
    outtextxy((left+(left+wide))/2-10,bottom+5,month[i]);
    left += (wide * 2);
    }
  getch();
  closegraph();
  return;
}
