//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void f(int ind, string ans, string S, vector<string>&ds)
    {
       if(ind == S.size())
       {
           ds.push_back(ans);
           return;
       }
       for(int i = ind; i<S.size(); i++)
       {
           swap(S[ind], S[i]);
           f(ind+1, ans+S[ind], S,ds);
           swap(S[ind], S[i]);
       }
    }
    vector<string> permutation(string S)
    {
        vector<string>ds;
        f(0, "",S,ds);
        sort(ds.begin(), ds.end());
        return ds;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends