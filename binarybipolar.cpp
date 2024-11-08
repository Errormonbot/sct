#include<iostream.h>
#include<conio.h>
#include<math.h>
void main() {
clrscr();
int i=0;
float x[10],b,w[10],net,n,sumxw=0,sigmo,e=2.71828;
float out;
cout<<"Enter the number of input : ";
cin>>n;
for(i=0;i<n;i++){
cout<<"Enter the value of X"<<i+1;
cin>>x[i];
cout<<"Enter the value of weight"<<i+1;
cin>>w[i];
}
cout<<"Enter the value of bias : ";
cin>>b;
for(i=0;i<n;i++){
sumxw = sumxw+w[i]*x[i];
}
net=(sumxw+b);
cout<<"*****Output*****";
cout<<"\nnet = "<<net<<endl;
if(net<0){
out=0;
}
else if((net>=0)&&(net<=1)){
out=net;
}
else {
out=1;
}
cout<<"Output : "<<out;
cout<<"\n\n\nBinary Sigmodial Actification Function : "<<(1/(1+(pow(e,-net))));
cout<<"\n\n\nBipolar Sigmodial Actification Function : "<<(2/(1+(pow(e,-net))));
getch();
}


//3,0.8,0.1,0.6,0.3,0.4,-0.2,0.35
