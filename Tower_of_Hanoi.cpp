//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // You need B complete this function

    // avoid space at the starting of the string in "move disk....."
    long long toh(int N, int A, int B, int C) {
        
        if(N == 0)
        return 0;
        
        long long a1 = toh(N-1, A, C, B);
        cout<<"move disk "<<N<<" from rod "<<A<<" to rod "<<B<<endl;
        long long b1 = toh(N-1, C,B,A);
      
        
        return a1+b1+1;
    }

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.
// } Driver Code Ends