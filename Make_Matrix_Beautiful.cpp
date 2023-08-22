//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        int maxSumRow = INT_MIN;
        int maxSumCol = INT_MIN;
        vector<int>storeR;
        vector<int>storeC;
        
        for(int i = 0;i<n;i++)
        {
            int sumR = 0;
            int sumC = 0;
            for(int j = 0;j<n;j++)
            {
                sumR+=matrix[i][j];
                sumC+=matrix[j][i];
            }
            storeR.push_back(sumR);
            storeC.push_back(sumC);
            maxSumRow = max(sumR,maxSumRow);
            maxSumCol = max(sumC,maxSumCol);
        }
        
        int count = 0;
        for(int i = 0;i<n;i++)
        {
            if(maxSumRow > maxSumCol)
             count += maxSumRow-storeR[i];
             else
             count+=maxSumCol-storeC[i];
        }
        return count;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends