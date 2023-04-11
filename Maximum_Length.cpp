//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        // code here
          int maxi =max(a,(max(b,c)));
        int temp;
        if(maxi%2==0)  temp = maxi/2;
        else temp =(maxi/2) +1;
        int sum =a+b+c;
        sum = sum-maxi;
        if(temp -1 > sum) return -1;
        else return (a+b+c);
    
            
        
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends