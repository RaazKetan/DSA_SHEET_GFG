//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
     
    int ct = 0;
        sort(arr.begin(), arr.begin()+n/2);
        sort(arr.begin()+n/2, arr.end());
        for (int i =n/2; i<n; i++) {
            if (lower_bound(arr.begin(), arr.begin()+n/2, arr[i]*5)!=arr.begin()+n/2) {
                int x = n/2-(lower_bound(arr.begin(), arr.begin()+n/2, arr[i]*5)-arr.begin());
                ct+=x;
            }
        }
        return ct;
    }  
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends