/* Operator Overloading – Complex number */
#include<iostream>
using namespace std;

class complex
{
	private:
	float real;
	float imag;
	public:
       complex()                //default constructor
       {
         real=0;
         imag=0;
        }
      friend  istream &operator>>(istream&in,complex&c);
      friend  ostream &operator<<(ostream&out,complex&c);
	complex operator+(complex t);
	complex operator*(complex t);
};

istream &operator>>(istream&in,complex&c)
{
      cout<<"\nEnter real and imaginary parts of number:";
      in>>c.real>>c.imag;
      return in;
}
   
ostream &operator<<(ostream&out,complex&c)
{   cout<<"\nThe complex no is:";
       out<<c.real<<"+"<<c.imag<<"i";
       return out;
}

complex complex::operator+(complex t)
{
	complex temp;
	temp.real=real + t.real;
	temp.imag=imag + t.imag;
	return temp;
}
complex complex::operator*(complex t)
{
	complex temp;
	temp.real=(real*t.real)-(imag*t.imag);
	temp.imag=(real*t.imag)+(t.real*imag);
	return temp;
}

int main()
{
	complex c1,c2,c3;
	
	cout<<"\nFOR 1ST COMPLEX NO";
    	cin>>c1;
      	cout<<c1;
     
	cout<<"\nFOR 2ND COMPLEX NO";
	cin>>c2;
    	cout<<c2;
	
	int choice;

	cout<<"\nENTER THE OPERATION WHICH IS TO BE PERFORMED:\n1.ADDITION \n2.MULTIPLICATION ";
	cin>>choice;

	switch(choice)	
	{
		case 1:	cout<<"\n PERFORMING C1 + C2";
			c3=c1+c2;
			cout<<c3;
			break;
		case 2:	cout<<"\n PERFORMING C1 * C2";
			c3=c1*c2;
			cout<<c3;
			break;
		
		default: cout<<"INVALID CHOICE";
	}

}
