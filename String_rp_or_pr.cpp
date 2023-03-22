//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    long long solve(int X, int Y, string S)
    {
        string a = "pr";
        string b = "rp";
        long long ans = 0;
        if (X < Y)
        {
            swap(X, Y);
            swap(a, b);
        }

        int n = S.size();
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
                st.push(S[i]);

            else if (S[i] == a[1] && st.top() == a[0])
            {
                ans += X;
                st.pop();
            }
            else
            st.push(S[i]);
        }
        S = "";
        while (!st.empty())
        {
            S += st.top();
            st.pop();
        }
        reverse(S.begin(), S.end());
        n = S.size();
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
                st.push(S[i]);

            else if (S[i] == b[1] && st.top() == b[0])
            {
                ans += Y;
                st.pop();
            }
            else
            st.push(S[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int X, Y;
        cin >> X >> Y;
        string S;
        cin >> S;
        Solution obj;
        long long answer = obj.solve(X, Y, S);
        cout << answer << endl;
    }
}
// } Driver Code Ends