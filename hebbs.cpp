#include<iostream.h>
#include<conio.h>
#include<math.h>
void main(){
clrscr();
float n,w,x=1,net,d,div,a,at=0.3,dw;
cout<<"Consider a single neuron perceptron with single i/p";
cin>>w;
cout<<"\nEnter the learning coefficient";
cin>>d;
for (int i=0;i<10;i++){
net=x+w;
if(w<0){
a=0;
}
else{
a=1;
}
div=at+a+w;
w=w+div;
cout<<"\ni+1 in fraction are i"<<a<<"\tchange in weight"<<div<<"\nadjustment at"<<w<<"\tnet value is "<<net;
}
getch();
}

//1,1