#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter array size: "<<endl;
    cin>>n;
    int a[1000],cs=0,ms=0;
    cout<<"Enter the array of nos. :"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cs=cs+a[i];
        if(cs<0){
            cs=0;
        }
        ms= max(cs,ms);
    }
    cout << "Maximum is " << ms << endl;
    return 0;
}
