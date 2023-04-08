class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        int n = arr.size();
        stack<int>st;
        for(int i = 0;i <n; i++)
        {
            if((!st.empty())&&((st.top()>=0 && arr[i]<0)||(st.top()<0 && arr[i]>=0)))
            {
            st.pop();
            }
            else{
            st.push(arr[i]);
            }
        }
        arr.clear();
        while(!st.empty())
        {
            arr.push_back(st.top());
            st.pop();
        }
        reverse(arr.begin(),arr.end());
        return arr;
        
    }
};