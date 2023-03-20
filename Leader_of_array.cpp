#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>val = {16,17,4,3,5,2};
    vector<int>ans;
    stack<int>st;
    int n  = val.size();
    st.push(val[n-1]);
    ans.push_back(val[n-1]);


    for(int i = n-2; i>=0; i--)
    {
        if(st.top() <= val[i])
        {
        st.push(val[i]);
        ans.push_back(val[i]);
        }
    } 
    reverse(ans.begin(), ans.end());
    for(auto i:ans)
    cout<<i<<" "<<endl;
   
}