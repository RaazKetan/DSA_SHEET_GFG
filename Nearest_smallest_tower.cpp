//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        stack<int> stk,stk2;
        
        int size=arr.size();
        
        vector<int> left(size),right(size);
        
        for(int i=0;i<size;i++)
        {
            while(stk.size()&&arr[stk.top()]>=arr[i])stk.pop();
            
            if(stk.size())
               left[i]=stk.top();
            else
               left[i]=-1;
               
            stk.push(i);   
        }
        
         
        for(int i=size-1;i>=0;i--)
        {
            while(stk2.size()&&arr[stk2.top()]>=arr[i])stk2.pop();
            
            if(stk2.size())
               right[i]=stk2.top();
            else
               right[i]=-1;
               
            stk2.push(i);   
        }
        
        vector<int> ans(size);
        
        for(int i=0;i<size;i++)
        {
            if(left[i]==-1&&right[i]==-1)
              ans[i]=-1;
            else if(left[i]==-1)
            {
                ans[i]=right[i];
            }
            else if(right[i]==-1)
               ans[i]=left[i];
            else{   
               
            int diff_left=i-left[i],diff_right=right[i]-i;
            
            if(diff_left<diff_right)
            {
                ans[i]=left[i];
            }
            else if(diff_left>diff_right)
            {
                ans[i]=right[i];
            }
            else
            {
                if(arr[left[i]]<arr[right[i]])
                {
                    ans[i]=left[i];
                }
                else if(arr[left[i]]>arr[right[i]])
                {
                    ans[i]=right[i];
                }
                else
                  {
                      ans[i]=left[i];
                  }
            }
            
            }  
            
        }
                
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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends