//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void calc(int r, int c,vector<vector<int>>& vis,vector<vector<int>>& m)
    {
        if(r<0 || r>=m.size() || c<0 || c>=m[0].size() || vis[r][c]==1 || m[r][c]==0)
         return;
        vis[r][c]=1;
        calc(r+1,c,vis,m);
        calc(r-1,c,vis,m);
        calc(r,c+1,vis,m);
        calc(r,c-1,vis,m);
    }
    int closedIslands(vector<vector<int>>& m, int N, int M) {
        // Code here
        int ans=0;
        vector<vector<int>>vis(N,vector<int>(M,0));
        for(int i=0;i<M;++i)
        {
            if(vis[0][i]==0 && m[0][i]==1)
              calc(0,i,vis,m);
            if(vis[N-1][i]==0 && m[N-1][i]==1)
              calc(N-1,i,vis,m);
        }
        for(int i=0;i<N;++i)
        {
            if(vis[i][0]==0 && m[i][0]==1)
             calc(i,0,vis,m);
            if(vis[i][M-1]==0 && m[i][M-1]==1)
             calc(i,M-1,vis,m);
        }
        for(int i=1;i<N;++i)
        {
            for(int j=1;j<M;++j)
            {
                if(vis[i][j]==0 && m[i][j]==1){
                 calc(i,j,vis,m);
                 ++ans;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends