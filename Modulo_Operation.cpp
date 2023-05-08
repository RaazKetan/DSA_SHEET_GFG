//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
        int modulo(string s,int m)
        {
           int c = 0;
           int base = 1;
           for(int i = s.length()-1; i>=0; i--)
           {
               c+=(base)*(s[i] - '0');
               c%=m;
               base = (base*2)%m;
           }
           return c;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends