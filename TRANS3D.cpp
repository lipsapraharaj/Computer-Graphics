
#include<iostream.h>
#include<process.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void disp(int n,float c[][3]){
float maxx,maxy;
int i;
maxx=getmaxx();
//getmaxx returns the maximum (screen-relative) x value for the
maxy=getmaxy();
//getmaxx returns the maximum (screen-relative) Y value for the
maxx=maxx/2;
maxy=maxy/2;
i=0;
while(i<n-1){
line(maxx+c[i][0],maxy-c[i][1],maxx+c[i+1][0],maxy-c[i+1][1]);
i++;}
i=n-1;
line(maxx+c[i][0],maxy-c[i][1],maxx+c[0][0],maxy-c[0][1]);
setcolor(15);
line(0,maxy,maxx*2,maxy);
line(maxx,0,maxx,maxy*2);
setcolor(15);}

void mul(int n,float b[][4],float c[][4],float a[][4]){
int i,j,k;
for(i=0;i<n;i++)
for(j=0;j<3;j++)
a[i][j]=0;
for(i=0;i<n;i++)
for(j=0;j<4;j++)
for(k=0;k<4;k++) {
a[i][j]=a[i][j] + (c[i][k] * b[k][j]); }
}

void zproj(int n,float c[][4])
{
float b[10][4],a[10][4];
int i=0,j;
for(i=0;i<4;i++)
for(j=0;j<4;j++)
b[i][j]=0;
b[0][0]=1;
b[1][1]=1;
b[2][2]=0;
b[3][3]=1;
mul(n,b,c,a);
setcolor(RED);
float m[10][3];
int i1,j1;
for(i=0, i1=0;i<n,i1<n;i++,i1++)
for(j=0, j1=0;j<3,j1<3;j++,j1++)
m[i][j]=a[i1][j1];
for(i=0;i<n;i++)
  m[i][2]=1;
disp(n,m);
}

void translation(int n,float c[][4],float tx,float ty,float tz){
int i;
for(i=0;i<n;i++) {
c[i][0]=c[i][0]+tx;
c[i][1]=c[i][1]+ty;
c[i][2]=c[i][2]+tz; }}

void scaling(int n,float c[][4],float sx,float sy,float sz){
float b[10][4],a[10][4];
int i=0,j;
for(i=0;i<4;i++)
for(j=0;j<4;j++)
b[i][j]=0;
b[0][0]=sx;
b[1][1]=sy;
b[2][2]=sz;
b[3][3]=1;
mul(n,b,c,a);
setcolor(RED);
zproj(n,a);}

void rotation(int n,float c[][4],float ra){
int i=0,j;
float b[10][4],xp,yp,a[10][4];
xp=c[0][0];
yp=c[0][1];
for(i=0;i<4;i++)
for(j=0;j<4;j++)
b[i][j]=0;
b[0][0]=b[1][1]=cos(ra*3.14/180);
b[0][1]=sin(ra*3.14/180);
b[1][0]=-sin(ra*3.14/180);
/*b[2][0]=(-xp*cos(ra*3.14/180))+(yp*sin(ra*3.14/180))+xp;
b[2][1]=(-xp*sin(ra*3.14/180))-(yp*cos(ra*3.14/180))+yp;  */
b[2][2]=1;
b[3][3]=1;
mul(n,b,c,a);
setcolor(15);
zproj(n,a);}

void refthryz(int n,float c[][4]){
int i=0,j;
float a[10][4],b[10][4];
for(i=0;i<4;i++)
for(j=0;j<4;j++)
b[i][j]=0;
b[0][0]=-1;b[0][1]=0;b[0][2]=0;b[0][3]=0;
b[1][0]=0;b[1][1]=1;b[1][2]=0;b[1][3]=0;
b[2][0]=0;b[2][1]=0;b[2][2]=1;b[2][3]=0;
b[3][0]=0;b[3][1]=0;b[3][2]=0;b[3][3]=1;
mul(n,b,c,a);
setcolor(3);
zproj(n,a);
}
void refthrxy(int n,float c[][4]){
int i=0,j;
float a[10][4],b[10][4];
for(i=0;i<4;i++)
for(j=0;j<4;j++)
b[i][j]=0;
b[0][0]=1;b[0][1]=0;b[0][2]=0;b[0][3]=0;
b[1][0]=0;b[1][1]=1;b[1][2]=0;b[1][3]=0;
b[2][0]=0;b[2][1]=0;b[2][2]=-1;b[2][3]=0;
b[3][0]=0;b[3][1]=0;b[3][2]=0;b[3][3]=1;
mul(n,b,c,a);
setcolor(3);
zproj(n,a);
}
void refthrxz(int n,float c[][4]){
int i=0,j;
float a[10][4],b[10][4];
for(i=0;i<4;i++)
for(j=0;j<4;j++)
b[i][j]=0;
b[0][0]=1;b[0][1]=0;b[0][2]=0;b[0][3]=0;
b[1][0]=0;b[1][1]=-1;b[1][2]=0;b[1][3]=0;
b[2][0]=0;b[2][1]=0;b[2][2]=1;b[2][3]=0;
b[3][0]=0;b[3][1]=0;b[3][2]=0;b[3][3]=1;
mul(n,b,c,a);
setcolor(3);
zproj(n,a);
}
/*
void refthry(int n,float c[][3]){
int i=0,j;
float b[10][3],a[10][3];
for(i=0;i<3;i++)
for(j=0;j<3;j++)
b[i][j]=0;
b[0][0]=-1;b[0][1]=0;b[0][2]=0;
b[1][0]=0;b[1][1]=1;b[1][2]=0;
b[2][0]=0;b[2][1]=0;b[2][2]=1;
mul(n,b,c,a);
setcolor(3);
disp(n,a);}

void refthrxeqtoy(int n,float c[][3]){
int i=0,j;
float b[10][3],a[10][3];
for(i=0;i<3;i++)
for(j=0;j<3;j++)
b[i][j]=0;
b[0][0]=0;b[0][1]=1;b[0][2]=0;
b[1][0]=1;b[1][1]=0;b[1][2]=0;
b[2][0]=0;b[2][1]=0;b[2][2]=1;
mul(n,b,c,a);
setcolor(3);
disp(n,a); }

void refthrxnegy(int n,float c[][3]){
int i=0,j;
float b[10][3],a[10][3];
for(i=0;i<3;i++)
for(j=0;j<3;j++)
b[i][j]=0;
b[0][0]=0;b[0][1]=-1;b[0][2]=0;
b[1][0]=-1;b[1][1]=0;b[1][2]=0;
b[2][0]=0;b[2][1]=0;b[2][2]=1;
mul(n,b,c,a);
setcolor(3);
disp(n,a); }

void refaboutorigin(int n,float c[][3]){
int i=0,j;
float b[10][3],a[10][3];
for(i=0;i<3;i++)
for(j=0;j<3;j++)
b[i][j]=0;
b[0][0]=-1;
b[1][1]=-1;
b[2][2]=1;
mul(n,b,c,a);
setcolor(3);
disp(n,a); }    */


void shearing(int n,float c[][4]){
float b[10][4],sh,a[10][4];
int i=0,ch,j;
cleardevice();
cout<<"\n\t* * * MENU * * *";
cout<<"\n\t1) X Shearing";
cout<<"\n\t2) Y Shearing";
cout<<"\n\t1) EXIT";
cout<<"\n\tEnter your Choice: ";
cin>>ch;
if(ch==3)
return;
cout<<"\n\tEnter the value for Shearing ";
cin>>sh;
cleardevice();
for(i=0;i<4;i++)
for(j=0;j<4;j++)
b[i][j]=0;
for(i=0;i<4;i++)
b[i][i]=1;
switch(ch) {
case 1:
zproj(n,c);
b[1][0]=sh;
break;
case 2:
zproj(n,c);
b[0][1]=sh;
break;
case 3:
break;
default:
cout<<"\n\tINVALID CHOICE !!!";
break; }
mul(n,b,c,a);
setcolor(RED);
zproj(n,a);}


int main(){
int gd=DETECT,gm;
initgraph(&gd,&gm,"C://TURBOC3//BGI");
int i,j,k,cho,n,ch2,shx,shy,shz,yref,xref,zref,ch3;
float c[10][4],tx,ty,tz,sx,sz,sy,ra;
cout<<"Enter the number of vertices :";
cin>>n;
for(i=0;i<n;i++) {
cout<<"Enter the coordinates of the vertex :",i+1;
cin>>c[i][0]>>c[i][1]>>c[i][2];
c[i][3]=1;}
do {
cleardevice();

cout<<"\n\t\t * * * MENU * * *";
cout<<"\n\t 1) TRANSLATION";
cout<<"\n\t 2) SCALING";
cout<<"\n\t 3) ROTATION";
cout<<"\n\t 4) REFLECTION";
cout<<"\n\t 5) SHEARING";
cout<<"\n\t 6) Exit";
cout<<"\nYou will see the original figure in white and the transformed figure in colors";
cout<<"\nEnter your Choice :";
cin>>cho;
switch(cho) {
case 1 :
 cout<<"\n\tEnter Translation factor for X ,Y and Z axis:\t";
 cin>>tx>>ty>>tz;
 cleardevice();
 setcolor(20);
 zproj(n,c);
 translation(n,c,tx,ty,tz);
 getch();
 break;
case 2 :
 cout<<"\n\tEnter scaling Factor for X,Y and Z axis :\t";
 cin>>sx>>sy>>sz;
 cleardevice();
 setcolor(15);
 zproj(n,c);
 scaling(n,c,sx,sy,sz);
 getch();
 break;

case 3 :
 cout<<"\n\n\tEnter the angle of Rotation";
 cin>>ra;
 cleardevice();
 setcolor(15);
 zproj(n,c);
 rotation(n,c,ra);
 getch();
 break;
case 4 :
 cout<<"\n1. Ref thru xy plane";
 cout<<"\n2. Ref thru yz plane";
 cout<<"\n3. Ref thru zx plane";
 cin>>ch2;
 switch(ch2){
 case 1:
   cleardevice();
   setcolor(15);
   zproj(n,c);
   refthrxy(n,c);
   break;}
 case 2:
   cleardevice();
   setcolor(15);
   zproj(n,c);
   refthryz(n,c);
   break;}
 case 3:
   cleardevice();
   setcolor(15);
   zproj(n,c);
   refthrxz(n,c);
   break;
 default:
   cout<<"Not a valid choice";
   } /*
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
   break; }*///end ref switch
 break;
case 5 :
 setcolor(15);
 zproj(n,c);
 shearing(n,c);
 getch();
 break;
case 6 :
exit(0);
break;
default :
cout<<"\n\t Invalid Choice ! !";
break;}
}while(cho!=4);
getch();
closegraph();
return 0;
}