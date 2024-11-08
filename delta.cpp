#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr( );
	float input[3],d,del,a,val[10],w[10],weight[3],delta;
	for(int i=0;i < 3 ; i++)
	{
		cout<<"\n initilize weight vector "<<i<<"\t";
		cin>>input[i];
	}
	cout<<"\n enter the desired output\t";
	cin>>d;
	do
	{
		del=d-a;
		if(del<0)
		for(i=0 ;i<3 ;i++)
		w[i]=w[i]-input[i];
		else if(del>0)
		for(i=0;i<3;i++)
		weight[i]=weight[i]+input[i];
		for(i=0;i<3;i++)
		{
			val[i]=del*input[i];
			weight[+1]=weight[i]+val[i];
		}
		cout<<"\n value of delta is "<<del;
		cout<<"\n weight have been adjusted";
	}
	while(del==0);
	if(del==0)
	cout<<"\n output is correct";
	getch();
}

//1,2,1,0