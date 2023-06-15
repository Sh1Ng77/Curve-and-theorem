//Write C++ program to implement Cohen Southerland line clipping algorithm

#include<iostream>
#include<graphics.h>

using namespace std;
class lineclip

{
	private:
		int x1,x2,y1,y2,xl,xh,yl,yh, x,y;
		int Right=2,Left=1,Top=8,Bottom=4;
	public:
		int getcode(int x,int y);
		void process();
};
int lineclip::getcode(int x,int y)
{
	int code=0;
	if (y>yh)
		code|=Top;
	if (y<yl)
		code|=Bottom;
	if (x<xl)
    		code|=Left;
 	if (x>xh)
   		code|=Right;
  	return code;
}
 
void lineclip::process()
{
  	int code1,code2;
  	cout<<"Enter coordinates of rectangle";
  	cin>>xl>>yl>>xh>>yh;
  	setcolor(YELLOW);
  	rectangle(xl,yl,xh,yh);
  
  	cout<<"Enter coordinates of line";
  	cout<<"Start points";
  	cin>>x1>>y1;
  	cout<<"End points";
  	cin>>x2>>y2;
  	setcolor (WHITE);
  	line(x1,y1,x2,y2);
  	delay(1000);
  
  	code1=getcode(x1,y1);
  	code2=getcode(x2,y2);
  	int temp;
  	float m;
  	int flag=0;
  	while(1)
  	{
    		m=(float)(y2-y1)/(x2-x1);
    		if (code1==0 && code2==0)
    		{
     			flag=1;
     			break;
     		}
     		else if((code1&code2)!=0)
     		{
       		break;
       	}
     		else
     		{
        		if (code1==0)
        		temp=code2;
        		else
        		temp=code1;
        
       		if (temp & Top)
       		{
        			x=x1+(yh-y1)/m;
        			y=yh;
        		}
        		else if(temp & Bottom)
        		{
          			x=x1+(yl-y1)/m;
          			y=yl;
        		}
        		else if(temp & Left)
        		{
          			y=y1+m*(xl-x1);
          			x=xl;
          		}
        		else if(temp & Right)
           		{
           			y=y1+m*(xh-x1);
           			x=xh;
           		}  
      			if (temp==code1)
      			{
       			x1=x;
       			y1=y;
       			code1=getcode(x1,y2);
       		}
       		else
       		{
       			x2=x;
       			y2=y;
       			code2=getcode(x2,y2);
       		}
       	}
	}
       
	cleardevice();
    	rectangle(xl,yl,xh,yh);
    	setcolor(YELLOW);
    
    	if(flag==1)
    	{
		line(x1,y1,x2,y2);
		delay(100000);
	}
	getch();
     	closegraph();
}
     
int main ()
{
  	int gd=DETECT,gm;
  	initgraph(&gd,&gm,NULL);
  	lineclip p;
  	p.process();
  	return 0;
}     
  
