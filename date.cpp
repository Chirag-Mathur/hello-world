#include <bits/stdc++.h>
using namespace std;

static string a[]={"Jan","February","March","April","May","June","July","August","September","October","November","December"};

// int monthsInArray[]={31,28,31,30,31,30,31,30,31,30,31,30};

class Date1{
private:

int date;
int month;
int year;
public:
Date1(int d,int m,int y){
date=d;
month=m;
year=y;
}

void getDate(){
    cout<<"\nEnter Date ";
    cin>>date;
    cout<<"\nEnter Month as integer  ";
    cin>>month;
    cout<<"\nEnter Year ";
    cin>>year;
    
}
int returnDate()
{
    return date;
}
int getMonth()
{
    return month;
}
int getYear()
{
    return year;
}
void showDate(){
    cout<<date<<"-"<<month<<"-"<<year<<"-";
}
int Date1::operator -(Date2 d1);

};


class Date2{
private:

int date;
string month;
int year;
public:
Date2(int d,string m,int y){
date=d;
month=m;
year=y;
}

void getDate(){
    cout<<"\nEnter Date ";
    cin>>date;
    cout<<"\nEnter Month as string ";
    cin>>month;
    cout<<"\nEnter Year ";
    cin>>year;
    
}

void showDate(){
    cout<<date<<" "<<month<<", "<<year<<endl;
}

int operator -(Date1 d1);

int returnDate()
{
    return date;
}
string getMonth()
{
    return month;
}
int getYear()
{
    return year;
}

};

int Date2::operator -(Date1 d1)
{
// assuming every month has 30 days
int days=0;
days+=abs(year-d1.getYear())*365;


// if(month=="Jan")

int m;

for(int i=0;i<12;i++)
{
    if(a[i]==month)
   { m=i+1;
    break;

   }
}

days+=(m-d1.getMonth())*30;

days=days+(date-d1.returnDate());
return days;
}

int Date1::operator -(Date2 d1)
{
// assuming every month has 30 days
int days=0;
days+=abs(year-d1.getYear())*365;


// if(month=="Jan")

int m;

for(int i=0;i<12;i++)
{
    if(a[i]==d1.getMonth())
   { m=i+1;
    break;

   }
}

days+=(month-m)*30;

days=days+(date-d1.returnDate());
return days;
}


int main()
{

Date1 d1(12,05,2003);
Date2 d2(11,"June",2005);

int x=d2-d1;
// int x=d1-d2;
cout<<x;
    return 0;

}