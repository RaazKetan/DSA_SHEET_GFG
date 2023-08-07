//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku.
        bool isValid(int row, int col ,int c, int grid[N][N])
    {
       
        for(int i = 0; i < 9; i++){
 // to check for entire row
            if(grid[i][col] == c)
            return false;
//to check for entire col
            if(grid[row][i] == c)
            return false;

            // to check for 3*3 matrix now
            if(grid[3*(row/3)+i/3][3*(col/3)+i%3] == c)
            return false;
        }
        return true; 
    }
   
    bool SolveSudoku(int grid[N][N])  
    { 
        for(int i = 0;i<N;i++)
        {
            for(int j = 0;j<N; j++)
            {
                if(grid[i][j] == 0)
                {
                    for(int k = 1;k<=9;k++)
                    {
                        if(isValid(i,j,k,grid)){
                        grid[i][j] = k;
                        
                        if(SolveSudoku(grid) == true)
                        return true;
                        
                        else
                        grid[i][j] = 0;
                        }
                    }
                return false;
                }
            }
        }
        return true;
    }
    
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i = 0;i<N;i++)
        {
            for(int j = 0;j<N; j++)
            {
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends