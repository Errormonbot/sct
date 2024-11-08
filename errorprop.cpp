#include<conio.h>
#include<iostream.h>
#include<math.h>
void main()
{
	clrscr();
	float l,c,s1,n1,n2,w10,b10,w20,b20,w11,b11,w21,b21,p,t,a0=-1,a1,a2,e,s2;
	cout<<"enter the input weights/base of second n/w= ";
	cin>>w10>>b10;
	cout<<"enter the input weights/base of second n/w= ";
	cin>>w20>>b20;
	cout<<"enter the learning coefficient of n/w c= ";
	cin>>c;
	/* Step1:Propagation of signal through n/w */
	n1=w10*p+b10;
	a1=tanh(n1);
	n2=w20*a1+b20;
	a2=tanh(n2);
	e=(t-a2);
	s2=-2*(1-a2*a2)*e;
	s1=(1-a1*a1)*w20*s2;
	w21=w20-(c*s2*a1);
	w11=w10-(c*s1*a0);
	b21=b20-(c*s2);
	b11=b10-(c*s1);
	cout<<"The uploaded weight of first n/w w11= "<<w11;
	cout<<"\n"<<"The uploaded weight of second n/w w21= "<<w21;
	cout<<"\n"<<"The uploaded base of second n/w b11= "<<b11;
	cout<<"\n"<<"The uploaded base of second n/w b21= "<<b21;
	getch();
}


//0.23 -0.2,0.45 0.3,0.45