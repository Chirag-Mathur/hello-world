#include <bits/stdc++.h>
using namespace std;

vector<int> fact(int n)
{
    vector<int> ans;
    ans.push_back(1);
    for(int i = 2; i <= n; i++)
    {
        int carry = 0;
        for(int j = ans.size() - 1; j >= 0; j--)
        {
            int prod = ans[j] * i + carry;
            ans[j] = prod % 10;
            carry = prod / 10;
        }
        while(carry)
        {
            ans.insert(ans.begin(), carry%10);
            carry = carry/10;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter a number" << endl;
    cin >> n;
    vector<int> ans;
    ans = fact(n);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
}