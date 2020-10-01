#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void breline(int,int,int,int);
int main()
{
	int gd=DETECT,gm;
	int x1,y1,xn,yn;
	
	printf("enter the starting co-ordinates:");
	scanf("%d%d",&x1,&y1);
	printf("enter the end co-ordinates:");
	scanf("%d%d",&xn,&yn);
	initgraph(&gd,&gm,"");
	breline(x1,y1,xn,yn);
	
	getch();
	return 0;

}

void breline(int x1,int y1,int xn,int yn)
{
	int dx,dy,s,t,p;
	dx=xn-x1;
	dy=yn-y1;
	p=2*dy-dx;
	s=2*dy;
	t=2*(dy-dx);
	putpixel(x1,y1,RED);
	while(x1<xn)
	{
		x1++;
		if(p<0)
		{
			p=p+s;
		}
		else
		{
			y1++;
			p=p+t;
		}
		putpixel(x1,y1,RED);
		
	}
}
