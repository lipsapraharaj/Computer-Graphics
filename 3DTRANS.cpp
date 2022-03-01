#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>

void disp(int n,float c[][4])
{
  float maxx,maxy;
  int i;
  maxx=getmaxx();
  //getmaxx returns the maximum (screen-relative) x value for the
  maxy=getmaxy();
  //getmaxx returns the maximum (screen-relative) Y value for the
  maxx=maxx/2;
  maxy=maxy/2;
  i=0;

  while(i<n-1)
 {
   line(maxx+c[i][0],maxy-c[i][1],maxx+c[i+1][0],maxy-c[i+1][1]);
   i++;
 }

   i=n-1;
   line(maxx+c[i][0],maxy-c[i][1],maxx+c[0][0],maxy-c[0][1]);
   setcolor(15);
   line(0,maxy,maxx*2,maxy);
   line(maxx,0,maxx,maxy*2);
   setcolor(WHITE);
}

void mul(int n,float b[][3],float c[][3],float a[][3])
{
  int i,j,k;
  for(i=0;i<n;i++)
  for(j=0;j<4;j++)
  a[i][j]=0;
  for(i=0;i<n;i++)
  for(j=0;j<4;j++)
  for(k=0;k<4;k++) 
  {
    a[i][j]=a[i][j] + (c[i][k] * b[k][j]); 
   }
}

void translation(int n,float c[][4],float tx,float ty)
{
  int i;
  for(i=0;i<n;i++) 
{
  c[i][0]=c[i][0]+tx;
  c[i][1]=c[i][1]+ty; 
}
}

void scaling(int n,float c[][3],float sx,float sy)
{
  float b[10][4],a[10][4];
  int i=0,j;
  for(i=0;i<4;i++)
  for(j=0;j<4;j++)
  b[i][j]=0;
  b[0][0]=sx;
  b[1][1]=sy;
  b[2][2]=1;
  mul(n,b,c,a);
  setcolor(MAGENTA);
  disp(n,a);
}

void rotationanticlock(int n,float c[][3],float ra)
{
  int i=0,j;
  float b[10][4],xp,yp,a[10][4];
  xp=c[0][0];
  yp=c[0][1];

   for(i=0;i<3;i++)
   
      for(j=0;j<4;j++)
          b[i][j]=0;
          b[0][0]=b[1][1]=cos(ra*3.14/180);
          b[0][1]=sin(ra*3.14/180);
          b[1][0]=-sin(ra*3.14/180);
          b[2][0]=(-xp*cos(ra*3.14/180))+(yp*sin(ra*3.14/180))+xp;
          b[2][1]=(-xp*sin(ra*3.14/180))-(yp*cos(ra*3.14/180))+yp;
          b[2][2]=1;
   	  
    mul(n,b,c,a);
    setcolor(10);
    disp(n,a);
}

void rotationclock(int n,float c[][3],float ra)
{
   int i=0,j;
   float b[10][3],xp,yp,a[10][3];
   xp=c[0][0];
   yp=c[0][1];

   for(i=0;i<4;i++)
   
     for(j=0;j<3;j++)
        b[i][j]=0;
        b[0][0]=b[1][1]=cos(ra*3.14/180);
        b[0][1]=-sin(ra*3.14/180);
        b[1][0]=sin(ra*3.14/180);
        b[2][0]=(-xp*cos(ra*3.14/180))+(yp*sin(ra*3.14/180))+xp;
        b[2][1]=(-xp*sin(ra*3.14/180))-(yp*cos(ra*3.14/180))+yp;
        b[2][2]=1;
    mul(n,b,c,a);
    setcolor(10);
    disp(n,a);
   
}


void refthrx(int n,float c[][3])
{
   int i=0,j;
   float a[10][4],b[10][4];
   
   for(i=0;i<4;i++)
	   
   for(j=0;j<4;j++)
	   
       b[i][j]=0;
       b[0][0]=1;b[0][1]=0;b[0][2]=0;
       b[1][0]=0;b[1][1]=-1;b[1][2]=0;
       b[2][0]=0;b[2][1]=0;b[2][2]=1;
	   
    mul(n,b,c,a);
    setcolor(3);
    disp(n,a);
}

void refthry(int n,float c[][3])
{
    int i=0,j;
    float b[10][4],a[10][4];
	
    for(i=0;i<3;i++)
		
        for(j=0;j<3;j++)
			
            b[i][j]=0;
            b[0][0]=-1;b[0][1]=0;b[0][2]=0;
            b[1][0]=0;b[1][1]=1;b[1][2]=0;
            b[2][0]=0;b[2][1]=0;b[2][2]=1;
			
    mul(n,b,c,a);
    setcolor(3);
    disp(n,a);
}

void refthrxeqtoy(int n,float c[][3])
{
      int i=0,j;
      float b[10][4],a[10][4];
	  
      for(i=0;i<3;i++)
		  
      for(j=0;j<3;j++)
		  
         b[i][j]=0;
         b[0][0]=0;b[0][1]=1;b[0][2]=0;
         b[1][0]=1;b[1][1]=0;b[1][2]=0;
         b[2][0]=0;b[2][1]=0;b[2][2]=1;
		 
      mul(n,b,c,a);
      setcolor(3);
      disp(n,a); 
}

void refthrxnegy(int n,float c[][3])
{
    int i=0,j;
    float b[10][4],a[10][4];
	
    for(i=0;i<3;i++)
		
        for(j=0;j<4;j++)
			
        b[i][j]=0;
        b[0][0]=0;b[0][1]=-1;b[0][2]=0;
        b[1][0]=-1;b[1][1]=0;b[1][2]=0;
        b[2][0]=0;b[2][1]=0;b[2][2]=1;
		
    mul(n,b,c,a);
    setcolor(3);
    disp(n,a); 
}

void refaboutorigin(int n,float c[][3])
{
    int i=0,j;
    float b[10][4],a[10][4];
	
    for(i=0;i<3;i++)
		
       for(j=0;j<3;j++)
		   
          b[i][j]=0;
          b[0][0]=-1;
          b[1][1]=-1;
          b[2][2]=1;
    mul(n,b,c,a);
    setcolor(3);
    disp(n,a);  
}

void xshearwithy(int n,float c[][4],float shx)
{
   int i=0,j;
   float b[10][4],a[10][4];
   for(i=0;i<3;i++)
	   
      for(j=0;j<4;j++)
		  
        b[i][j]=0;
        b[0][0]=b[1][1]=b[2][2]=1;
        b[1][0]=shx;
    mul(n,b,c,a);
    setcolor(3);
    disp(n,a); 
}

void shearing(int n,float c[][3])
{
   float b[10][4],sh,a[10][4];
   int i=0,ch,j;
   cleardevice();

   cout<<"\n\t* * * MENU * * *\n";
   cout<<"\n\t1) X Shearing";
   cout<<"\n\t2) Y Shearing";
   cout<<"\n\t3) EXIT\n";
   cout<<"\n\tEnter your Choice : ";
   cin>>ch;

   if(ch==3)
      return;
  
     cout<<"\n\tEnter the value for Shearing : ";
     cin>>sh;
     cleardevice();

    for(i=0;i<4;i++)
		
       for(j=0;j<4;j++)
         b[i][j]=0;
           for(i=0;i<4;i++)
              b[i][i]=1;

          switch(ch) 
          {
            case 1:
                 disp(n,c);
                 b[1][0]=sh;
            break;

            case 2:
                disp(n,c);
                b[0][1]=sh;
            break;

           case 3:
           break;

            default:
               cout<<"\n\tINVALID CHOICE !!!";
            break;
    }
 
    mul(n,b,c,a);
    setcolor(RED);
    disp(n,a);
 }

int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");

int i,j,k,cho,n,ch2,shx,shy,yref,xref,ch3,clk;
float c[10][4],tx,ty,sx,sy,ra;

cout<<"Enter the number of vertices :";
cin>>n;

for(i=0;i<n;i++) 
{
  cout<<"\nEnter the co-ordinates of the vertex "<<i+1<<" : ";
  cin>>c[i][0]>>c[i][1];
  c[i][2]=1;}
do 
{
  cleardevice();
  cout<<"\n\t\t * * * MENU FOR 2D TRANFORMATIONS * * *\n";
  cout<<"\n\t 1) TRANSLATION";
  cout<<"\n\t 2) SCALING";
  cout<<"\n\t 3) ROTATION";
  cout<<"\n\t 4) REFLECTION";
  cout<<"\n\t 5) SHEARING";
  cout<<"\n\t 6) EXIT";
  cout<<"\n\n   Enter your Choice :";
  cin>>cho;

switch(cho)
 {
   case 1 :
       cout<<"\n\tENTER THE TRANSLATION FACTOR FOR X-AXIS : \t";
       cin>>tx;
       cout<<"\n\tENTER THE TRANSLATION FACTOR FOR Y-AXIS : \t";
       cin>>ty;
       cleardevice();
       setcolor(15);
       disp(n,c);
       translation(n,c,tx,ty);
       setcolor(14);
       disp(n,c);
       getch();
    break;

    case 2 :
       cout<<"\n\tENTER THE SCALING FACTOR FOR X-AXIS :\t";
       cin>>sx;
       cout<<"\n\tENTER THE SCALING FACTOR FOR Y-AXIS :\t";
       cin>>sy;
       cleardevice();
       setcolor(15);
       disp(n,c);
       scaling(n,c,sx,sy);
       getch();
    break;

    case 3 :
       cout<<"\n1. CLOCKWISE ROTATION";
       cout<<"\n2. ANTI-CLOCKWISE ROTATION\n";
       cout<<"\n   Enter your Choice : ";
       cin>>clk;
       cout<<"\n\nENTER THE ANGLE OF ROTATION (IN DEGREE) : ";
       cin>>ra;
       cleardevice();

         switch(clk)
        {
            case 1:
                setcolor(15);
                rotationanticlock(n,c,ra);
                disp(n,c);
                getch();
            break;
 
            case 2: 
                setcolor(15);
                rotationclock(n,c,ra);
                disp(n,c);
                getch();
           break;

           default:
               cout<<"\nINVALID CHOICE !!!";
            break;
        }

    case 4 :
        cout<<"\n1. REFLECTION THROUGH X-AXIS ";
        cout<<"\n2. REFLECTION THROUGH Y-AXIS";
        cout<<"\n3. REFLECTION THROUGH Y=X AXIS";
        cout<<"\n4. REFLECTION THROUGH Y=-X AXIS";
        cout<<"\n5. REFLECTION ABOUT ORIGIN";
        cout<<"\n6. EXIT\n";
        cout<<"\n   Enter your Choice: ";
        cin>>ch2;
        cleardevice();

        switch(ch2)
         {
           case 1:
               setcolor(15);
               disp(n,c);
               refthrx(n,c);
               break;

            case 2:
                setcolor(15);
                disp(n,c);
                refthry(n,c);
            break;

    case 3:
        setcolor(15);
        disp(n,c);
        refthrxeqtoy(n,c);
    break;

    case 4:
        setcolor(15);
        disp(n,c);
        refthrxnegy(n,c);
    break;

    case 5:
        setcolor(15);
        disp(n,c);
        refaboutorigin(n,c);
    break; 
 }//end ref switch
   break;

    case 5 :
       setcolor(15);
       disp(n,c);
       shearing(n,c);
       getch();
    break;

    case 6 :
        exit(0);
    break;

    default :
           cout<<"\n\t Invalid Choice ! !";
    break;
 }

}
  while(cho!=4);
  getch();
  closegraph();
  return 0;
 }