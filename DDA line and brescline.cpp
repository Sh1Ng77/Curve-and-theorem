#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

int num;
class Brescircle
{
	public:
		int x,y,r,del,yi,xi,sig1,sig2,limit;
		void circle(int,int,int);
		void mh();
		void md();
		void mv();
};
void Brescircle::circle(int x,int y,int r)
{
	limit=0;
	xi=0; 
	yi=r;
	del=2*(1-r);
	while (yi>=limit)
	{
		putpixel(x+xi,y+yi,3);
		putpixel(x+xi,y-yi,5);
		putpixel(x-xi,y+yi,9);
		putpixel(x-xi,y-yi,14);
		//delay(10);
		if(del<0)
		{
			sig1=((2*del)+(2*yi)-1);
			if(sig1<=0)
				mh();
			else
				md();
		}
		else if(del>0)
		{
			sig2=((2*del)-(2*xi)-1);
        
			if(sig2<=0)
				md();
			else
				mv();
		}
		else if(del==0)
			md();
	}
}
       
void Brescircle::mh()
{
	xi=xi+1;
	del=del+(2*xi)+1;
}
   
void Brescircle::mv()
{
	yi=yi-1;
	del=del-(2*yi)+1;
}
     
void Brescircle::md()
{
	xi=xi+1;
	yi=yi-1;
	del=del+(2*xi)-(2*yi)+2;
}

void DDA_line(int x1,int y1,int x2,int y2,int icolour)
{
	int i;
	float dx,dy,steps,xinc,yinc,x,y;
	dx=(x2-x1);
	dy=(y2-y1);
	if (fabs(dx)>fabs(dy))
		{steps=dx;}
	else
		{steps=dy;}
	xinc=dx/steps;
	yinc=dy/steps;
	
	x=x1;
	y=y1;
	
	for (i=0;i<steps;i++)
		{
			putpixel (floor(x),floor(y),icolour);
			//delay(10);
			x=x+xinc;
			y=y+yinc;
		}
}
    
    
void triangle()
{
	
	DDA_line(232,290,408,290,RED);
	DDA_line(320,142,232,290,RED);
	DDA_line(320,142,408,290,RED);
	Brescircle b,c;
	b.circle(320,240,50);
	c.circle(320,240,100);

}

void square()
{
	
	DDA_line(200,200,500,200,CYAN);
	DDA_line(200,200,200,400,CYAN);
	DDA_line(500,200,500,400,CYAN);
	DDA_line(200,400,500,400,CYAN);
	DDA_line(200,300,350,200,RED);
	DDA_line(350,200,500,300,RED);
	DDA_line(200,300,350,400,RED);
	DDA_line(350,400,500,300,RED);
	Brescircle b;
	b.circle(350,300,82);

}

void get_data()
{

	cout<<"1.Circle-triangle-circle\n2.rectangle-rectangle-circle\n";
	cin>>num;
}

int main()
{
	int gd,gm;
	
	get_data();
	switch(num)
	{
		case 1:
			gd= DETECT;
			initgraph(&gd,&gm,NULL);
        		triangle();           	
                       break;
 
		case 2:
			gd= DETECT;
			initgraph(&gd,&gm,NULL);
			square();          
			break;
		default:
			cout<<"ENTER VALID CHOISE";
	}
	delay(10000);
	closegraph();
	return 0;
}
