#include <bits/stdc++.h>

using namespace std;

class complexNumber{
private :
int real;
int imaginary;

public:

complexNumber()
{
    real=0;
    imaginary=0;
}

complexNumber(int r,int i)
{
    real=r;
    imaginary=i;
}
void getComplexNumber()
{
    cout<<"Enter Real Number";
    cin>>real;
    cout<<endl<<"Enter Imaginary Number";
    cin>>imaginary;
}

void showComplexNumber()
{
    cout<<endl<<"Real Part "<<real;
    cout<<endl<<"Imaginary Part "<<imaginary;
}

complexNumber operator +(complexNumber)const;
void operator *=(complexNumber);

 operator float()const;

};

 complexNumber :: operator float()const
 {
     float finalFloatValue=0;

     finalFloatValue+=real;

     int temp=imaginary;

     int count=0;
       
    while(temp>0)
    {
        temp=temp/10;
        count++;
    }
     finalFloatValue+=static_cast<float>(imaginary/pow(10,count));
    return finalFloatValue;
}

void complexNumber :: operator *=(complexNumber c2)
{
    int temp=real;
 real=real*c2.real-imaginary*c2.imaginary;
 imaginary=temp*c2.imaginary+imaginary*c2.real;

// complexNumber(r,i);

}


complexNumber complexNumber::operator+(complexNumber c2)const
{
int r=real+c2.real;
int i=imaginary+c2.imaginary;

return complexNumber(r,i);
}

int main()
{
    complexNumber c1,c3,c4;
     
        c1.getComplexNumber();
        complexNumber c2(10,5);
         c4=c1+c2;
        float x;

    c1.showComplexNumber();
    c2.showComplexNumber();
    c4.showComplexNumber();//sum
    c1*=c2;
    c1.showComplexNumber();//multiplication

    x=c2;//typecasting
    cout<<endl<<x;
    
    return 0;
}