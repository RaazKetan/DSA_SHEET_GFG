//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    typedef pair<long long, long long> pll;
    
    // pll bestPartitions(int start, int end, vector<long long> prefixSum){  // NOT WORKING - TLE
    pll bestPartitions(int start, int end, long long prefixSum[]){      // WORKING
        long long maxx = LLONG_MAX, minn = 0;
        int orig_start = start, orig_end = end;
        // pll res = {-1, -1};
        while(start <= end){
            int mid = (start + end)/2;      // include mid in left
            long long s1 = prefixSum[mid+1] - prefixSum[orig_start], s2 = prefixSum[orig_end+1] - prefixSum[mid+1];

            if(abs(s1 - s2) < maxx - minn) {
                maxx = max(s1, s2), minn = min(s1, s2);
            }
            
            if(s1==s2){
                return {minn, maxx}; // diff = 0
            }
            else if(s1 > s2) end = mid - 1;
            else start = mid + 1;
        }
        
        return {minn, maxx};
    }
    
    long long minDifference(int N, vector<int> &A) {
        // vector<long long> prefixSum(N+1);        // NOT WORKING - TLE
        long long prefixSum[N+1];                   // WORKING
        for(int i = 0; i < N; i++){
            prefixSum[i+1] = prefixSum[i] + A[i];
        }
        
        long long res = LLONG_MAX;
        for(int i = 1; i < N-2; i++){
            pll partion12 = bestPartitions(0, i, prefixSum);
            pll partion34 = bestPartitions(i+1, N-1, prefixSum);
            res = min(res, max(partion12.second, partion34.second) - min(partion12.first, partion34.first));
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        long long ans = ob.minDifference(N, A);
        cout<<ans<<endl;
    }
    return 0;
} 
// } Driver Code Ends