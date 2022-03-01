#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void drawcircle(int x0, int y0, int radius)
{
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
putpixel(x0 + x, y0 + y, 7);
putpixel(x0 + y, y0 + x, 7);
putpixel(x0 - y, y0 + x, 7);
putpixel(x0 - x, y0 + y, 7);
putpixel(x0 - x, y0 - y, 7);
putpixel(x0 - y, y0 - x, 7);
putpixel(x0 + y, y0 - x, 7);
putpixel(x0 + x, y0 - y, 7);

if (err <= 0)
{
    y += 1;
    err += 2*y + 1;
}

if (err > 0)
{
    x -= 1;
    err -= 2*x + 1;
}
    }
}

int main()
{
int gdriver=DETECT, gmode, error, x, y, r;
initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

cout<<"Enter the co-ordinates of center (x and y) of the circle: ";
cin>>x>>y;

cout<<"Enter the radius of the circle: ";
cin>>r;


cout<<"\n\n\n****** DRAWING THE CIRCLE USING BRESENHAM's OR MID POINT CIRCLE DRAWING ALGORITHM ******";
drawcircle(x, y, r);

return 0;
}
