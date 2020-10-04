AUTOMORPHIC NUMBER
GFG LINK:-"https://www.geeksforgeeks.org/automorphic-number/"
SOLUTION TO PROBLEM:-

For Input:
76
your output is: 
Automorphic
#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
		string is_AutomorphicNumber(int n)
		{
		    // Code here
		    string s="NotAutomorphic";
		    int num=n*n;
		    while(n>0)
		    {
		        if(n%10!=num%10)
		            return s;
		        n=n/10;
		        num=num/10;
		    }
		    s="Automorphic";
		    return s;
		}
};
// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_AutomorphicNumber(n);
    	cout << ans <<"\n";
    }
	return 0;
}  // } Driver Code Ends








NEON CODE
refered document link:-"https://www.quora.com/What-are-10-neon-numbers"
#include <iostream> 
using namespace std; 
#include <math.h> 
  
int checkNeon(int x) 
{ 
    // storing the square of x 
    int sq = x * x; 
  
    // calculating the sum of sum of digits 
    // of sq 
    int sum_digits = 0; 
    while (sq != 0) { 
        sum_digits = sum_digits + sq % 10; 
        sq = sq / 10; 
    } 
    return (sum_digits == x); 
} 
  
// Driver Code 
int main(void) 
{ 
    // Printing Neon Numbers upto 10000 
    for (int i = 1; i <= 1000000; i++)  
        if (checkNeon(i)) 
            cout << i << " ";     
} 

OUTPUT:-1 9









MAGIC NUMBER
refered doc:-"https://www.geeksforgeeks.org/check-number-magic-recursive-sum-digits-1/"
#include<iostream> 
using namespace std; 
  
void isMagic(int n) 
{ 
    int sum = 0,v=n; 
      
    // Note that the loop continues 
    // if n is 0 and sum is non-zero. 
    // It stops when n becomes 0 and 
    // sum becomes single digit. 
    while (n > 0 || sum > 9) 
    { 
        if (n == 0) 
        { 
            n = sum; 
            sum = 0; 
        } 
        sum += n % 10; 
        n /= 10; 
    } 
      
    // Return true if sum becomes 1. 
    if(sum == 1)
        cout<<v<<" is a magic number"<<endl;
    else
        cout<<v<<" is not a magic number"<<endl;
} 
   
// Driver code 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        isMagic(n);
    }
}
INPUT
3
50113
1234
12345
OUTPUT
50113 is a magic number
1234 is a magic number
12345 is not a magic number
