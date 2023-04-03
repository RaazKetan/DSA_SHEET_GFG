//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


class Solution
{

public:
    int xmod11(string x)
    {
      long long int even = 0;
      long long int odd = 0;
      int ans = 0;
       
    for(long long int i = 0; i < x.length(); i++)
    {
        if(i%2 == 0)
        even += x[i];
        else
        odd += x[i];
    }

    
    ans = ((odd-even)%11+11)%11;
    return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends