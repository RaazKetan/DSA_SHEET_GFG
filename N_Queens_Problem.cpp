//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

bool Check(int row, int col, vector<vector<int>>&ds, int n)
{
    int dupcol = col;
    int duprow = row;
    
    //to check for the upper diagonal
    while(row>=0&&col>=0)
    {
        if(ds[row][col] == 1)
        return false;
        
            row--;
            col--;
    }
    col = dupcol;
    row= duprow;
    
    // to check for same row
    while(col>=0)
    {
         if(ds[row][col] == 1)
        return false;
    
            col--;
    }
    col = dupcol;
    row = duprow;
    
    //to check for lower diagonal
     while(row<n&&col>=0)
    {
        if(ds[row][col] == 1)
        return false;
        
      
            row++;
            col--;
    }
    return true;
    
}

void Solve(int col, vector<vector<int>>&ans, vector<vector<int>>&ds, int n)
{
    if(col == n)
    {
        vector<int>temp;
        
        for(int col = 0; col<n; col++)
        {
            for(int row = 0; row<n; row++)
            {
                if(ds[row][col] == 1)
                {
                    temp.push_back(row+1);
                }
            }
        }
        ans.push_back(temp);
        return;
    }
    
    for(int row = 0; row<n; row++)
    {
        if(Check(row ,col, ds,n))
        {
            ds[row][col] = 1;
            Solve(col+1, ans, ds,n);
            ds[row][col] = 0;
        }
    }
}
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>>ans;
        vector<vector<int>>ds(n, vector<int>(n, 0));
        
        Solve(0, ans, ds, n);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends