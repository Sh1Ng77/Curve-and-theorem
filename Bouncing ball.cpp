#include<graphics.h> 
#include<iostream>

using namespace std;

int main()
{
	int i,flag=0;
	float x=1;
	int gd,gm;
	gd= DETECT;
	initgraph(&gd,&gm,NULL);
	setcolor(3);
	while(true)
	{
		if(flag==0)
		{
			for(i=50;i!=0;i++)
			{	
				cleardevice();
				
				circle(x,i,50);
				floodfill(x,i,50);
				delay(2);
				x=x+0.2;
				if(i==420)
				{
					flag=1;
					break;
				}	
				
			}
		}
		else if(flag==1)
		{
			for(i=420;i!=0;i--)
			{	
				cleardevice();
				circle(x,i,50);
				floodfill(x,i,50);
				delay(2);
				x=x+0.2;
				if(i==50)
				{
					flag=0;
					break;
				}
				
			}
		}
	}
	delay(5000);
	closegraph();
	return 0 ;
}
