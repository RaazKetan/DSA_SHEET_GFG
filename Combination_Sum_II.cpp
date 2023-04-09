//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
 void Combination(int ind,int target, vector<vector<int>>&ans, vector<int>&arr, vector<int>&ds)
 {
     if(target == 0)
     {
         ans.push_back(ds);
         return;
     }
     for(int i = ind; i < arr.size(); i++)
     {
         if(i>ind &&arr[i]==arr[i-1])
         continue;
         if(arr[i]>target)
         break;
         
         ds.push_back(arr[i]);
         Combination(i+1,target-arr[i], ans,arr,ds);
         ds.pop_back();
     }
 }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>>ans;
        vector<int>ds;
        Combination(0,k, ans,arr,ds);
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends