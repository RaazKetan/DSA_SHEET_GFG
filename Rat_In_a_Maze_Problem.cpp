//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void Solve(int i , int j,int n,vector<string>&ans,string move, vector<vector<int>> &m, vector<vector<int>> &vis){
        if(i == n-1 && j==n-1)
        {
            ans.push_back(move);
            return;
        }
        //downwardCase
        if(i+1<n && m[i+1][j] == 1 && !vis[i+1][j])
        {
            vis[i][j] = 1;
            Solve(i+1, j, n, ans,move+'D',m,vis);
            vis[i][j] = 0;
        }
        //LeftCase
         if(j-1>=0 && m[i][j-1] == 1 && !vis[i][j-1])
        {
            vis[i][j] = 1;
            Solve(i, j-1, n, ans,move+'L',m,vis);
            vis[i][j] = 0;
        }
        //RightCase
         if(j+1<n && m[i][j+1] == 1 && !vis[i][j+1])
        {
            vis[i][j] = 1;
            Solve(i, j+1, n, ans,move+'R',m,vis);
            vis[i][j] = 0;
        }
        //Upward Case
         if(i-1>=0 && m[i-1][j] == 1 && !vis[i-1][j])
        {
            vis[i][j] = 1;
            Solve(i-1, j, n, ans,move+'U',m,vis);
            vis[i][j] = 0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>>vis(n ,vector<int>(n,0));
        vector<string>ans;
        if(m[0][0] == 1)Solve(0, 0,n,ans,"",m,vis);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends