class Solution {
  public:
    void Combination(int i, int B,  vector<vector<int>>&ans,  vector<int>&arr,  vector<int>&ds)
    {
        if(i == arr.size())
        {
            if(B == 0)
            {
                
                ans.push_back(ds);
            }
            return;
        }
        if(arr[i]<=B){
            ds.push_back(arr[i]);
        Combination(i, B-arr[i], ans, arr, ds);
        ds.pop_back();
        }
        Combination(i+1, B, ans, arr, ds);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(A.begin(), A.end());
        // Now the what the unique function will do is group togethter all the unique 
        //element and will return an iterator which will point at that grouped elements
        //and in rest of the array will be unidentified elemennts for example
        // 1,1,1,2,2,3 the unique function will return 1,2,3,{1,2,1} the elements in the bracket
        //are the unidentied elemnnts which will be removed by the erase function
        A.erase(unique(A.begin(), A.end()), A.end());
        Combination(0 ,B, ans, A, ds);
        return ans;
    }
};