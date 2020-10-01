#include<stdio.h>
#include<graphics.h>
#include<conio.h>
int n=0;
int *pixels;
void ExportPixels(int r)
{
	FILE *fp = fopen("Pixels.txt", "w");
    for(int i=0; i<n; i++)
	{
		if(i>1)
		{
   			fprintf(fp, "%d, %d\n", pixels[2*i+0], pixels[2*i+1]);
   		}
   		else
   		{
   			fprintf(fp,"Center_X = %d, Center_Y = %d\nRadius = %d\n", pixels[2*i+0], pixels[2*i+1],r);
   			fprintf(fp,"Number of pixels : %d\n",n);
   			fprintf(fp, "Coordinates : \nx, y\n");
		}
	}	
  	fclose(fp);
  	printf("Pixel coordinates exported to Pixels.txt successfully!\n");
}
void Export2SVG(int width, int height)
{
    int scale = 10;
    int margin = 100;
    int i;
    int x1 = pixels[0], x2 = pixels[0];
    int y1 = pixels[1], y2 = pixels[1];
    for(i=1; i<n; i++)
	{
        if(x1>pixels[2*i+0])
		 x1=pixels[2*i+0]; 
        if(x2<pixels[2*i+0])
		 x2=pixels[2*i+0];
        if(y1>pixels[2*i+1])
		 y1=pixels[2*i+1]; 
        if(y2<pixels[2*i+1])
		 y2=pixels[2*i+1];
    }
    x1 *=scale; x2 *=scale;
    y1 *=scale; y2 *=scale;
  	FILE *fp = fopen("svg", "w");
  	fprintf(fp, "<svg width=\"%d\" height=\"%d\" viewBox=\"0 0 %d %d\" fill=\"none\" xmlns=\"http://www.w3.org/2000/svg\"  version=\"1.1\">",width,height,width,height);
    for(i=0; i<n; i++)
    {
        fprintf(fp,"\n<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:yellow;stroke:red;stroke-width:.30;fill-opacity:0.76;stroke-opacity:0.90\"/>", scale*pixels[2*i+0]-x1+100, scale*pixels[2*i+1]-y1+100, scale, scale);
    }
  	fclose(fp);
  	printf("SVG created successfully!\n");
}
void Export2HTML(int width, int height)
{
  	int scale = 10;
    int margin = 100;
    int i;
    int x1 = pixels[0], x2 = pixels[0];
    int y1 = pixels[1], y2 = pixels[1];
    for(i=1; i<n; i++)
	{
        if(x1>pixels[2*i+0])
		 x1=pixels[2*i+0]; 
        if(x2<pixels[2*i+0])
		 x2=pixels[2*i+0];
        if(y1>pixels[2*i+1]) 
		y1=pixels[2*i+1]; 
        if(y2<pixels[2*i+1])
		y2=pixels[2*i+1];
    }
    x1 *=scale; x2 *=scale;
    y1 *=scale; y2 *=scale;
  	FILE *fp = fopen("html", "w");
  	fprintf(fp, "<!DOCTYPE html>\n<html>\n<body>\n"); 
	fprintf(fp, "<svg width=\"%d\" height=\"%d\" viewBox=\"0 0 %d %d\" fill=\"none\" xmlns=\"http://www.w3.org/2000/svg\"  version=\"1.1\">",width,height,width,height);
    for(i=0; i<n; i++)
    {
        fprintf(fp,"\n<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:yellow;stroke:red;stroke-width:.30;fill-opacity:0.76;stroke-opacity:0.90\"/>", scale*pixels[2*i+0]-x1+100, scale*pixels[2*i+1]-y1+100, scale, scale);
    }
    
    fprintf(fp, "\n </svg>\n");
    fprintf(fp, "\n</body>\n</html>\n");
    fclose(fp);
  	printf("HTML created successfully!\n");
}
int *midPointCircleDraw(int x_c, int y_c, int r, int c)
{
	int x,y,p,m=0;
	x=0;y=r;
	int *pixels=(int *)malloc(12*r*sizeof(int)); 
	pixels[2*m+0]=x_c;
    pixels[2*m+1]=y_c;
    m++;
	
	pixels[2*m+0]=x+x_c;
    pixels[2*m+1]=y+y_c;
    m++;

	pixels[2*m+0]=x+x_c;
    pixels[2*m+1]=-y+y_c;
    m++;

	pixels[2*m+0]=y+x_c;
    pixels[2*m+1]=x+y_c;
    m++;

	pixels[2*m+0]=-y+x_c;
    pixels[2*m+1]=x+y_c;
    m++;

	p=1-r;
	while(x<y)
	{
		if(p<0) 
		{
			p=p+2*x+3;
		}
		else
		{
		   p=p+2*x+3-2*y-2;
		   y=y-1;
	  	}
	  	x=x+1;	
	  	pixels[2*m+0]=x+x_c;
    	pixels[2*m+1]=y+y_c;
    	m++;
		
		pixels[2*m+0]=x+x_c;
    	pixels[2*m+1]=-y+y_c;
    	m++;
		
		pixels[2*m+0]=-x+x_c;
    	pixels[2*m+1]=y+y_c;
    	m++;
		
		pixels[2*m+0]=-x+x_c;
    	pixels[2*m+1]=-y+y_c;
    	m++;
		
		pixels[2*m+0]=y+x_c;
    	pixels[2*m+1]=x+y_c;
    	m++;
		
		pixels[2*m+0]=y+x_c;
    	pixels[2*m+1]=-x+y_c;
    	m++;
		
		pixels[2*m+0]=-y+x_c;
    	pixels[2*m+1]=x+y_c;
    	m++;

		pixels[2*m+0]=-y+x_c;
    	pixels[2*m+1]=-x+y_c;
    	m++;
	}
	n=m;
	return pixels;
}
void display()
{
    for(int i=0;i<n;i++)
    {
        putpixel(pixels[2*i+0],pixels[2*i+1],6);
    }
    printf("Waiting for you to close the display-window...\n");
}
int main()
{
    int gd=DETECT,gm,r,x,y; 
    printf("Enter the co-ordinate for the Centre of the Circle : ");
    printf("Enter the X co-ordinate : ");
    scanf("%d",&x);
    printf("Enter the Y co-ordinate : ");
    scanf("%d",&y);
    printf("Enter the radius of the circle : ");
    scanf("%d",&r);    
    initgraph(&gd,&gm,NULL);
    pixels=midPointCircleDraw(x,y,r,2); 
    ExportPixels(r);    
    Export2HTML(5000,5000);
	Export2SVG(5000,5000);
	display();
    getch();    
    closegraph();    
    return 0;
}
