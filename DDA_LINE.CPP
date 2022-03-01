#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#define round(val)(int)(val+0.5)

void line_dda(int x1,int y1,int x2,int y2)
{
int Dx=x2-x1,Dy=y2-y1 ,length,k;
float xin,yin,x=x1,y=y1;
if(abs(Dx)>abs(Dy))
length=abs(Dx);
else
length=abs(Dy);
xin=Dx/(float)length;
yin=Dy/(float)length;

for(k=0;k<length;k++)
{
x=x+xin;
y=y+yin;
for (int i=0; i<=15; i++)
{
putpixel(round(x),round(y),YELLOW);
}
}
}

int main()
{
int gd=DETECT,gm;
int x1,x2,y1,y2;
void line_dda(int ,int,int,int);
cout<<"Enter the value of x1: ";
cin>>x1;
cout<<"Enter the value of y1: ";
cin>>y1;

cout<<"\nEnter the value of x2: ";
cin>>x2;
cout<<"Enter the value of y2: ";
cin>>y2;

initgraph(&gd,&gm, "c:\\turboc3\\bgi");
cleardevice();
cout<<"\n\n\n***** DRAWING THE LINE USING DIGITAL DIFFERENTIAL ANALYAZER (DDA) LINE DRAWING ALGORITHM *****";

line_dda(x1,y1,x2,y2);
getch();
closegraph();
return 0;
}


