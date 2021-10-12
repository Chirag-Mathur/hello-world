#include<vector>
using namespace std;
//guide a robot to the destination for (0,0) using only right or downward moves
int r,c;
//recursion
int ways(int i,int j)
{
    if(i==r-1 && j==c-1)
        return 1;
    if(i>=r || j>=c)
        return 0;
    return ways(i+1,j)+ways(i,j+1);
}

int main()
{
    cin>>r;
    c=r;
    int m=0;
    m=ways(0,0);
    cout<<m<<endl;
    return 0;
}
