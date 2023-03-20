#include <bits/stdc++.h>
using namespace std;

// [()]{}{[()()]()}

// class Solution
// {
// public:
//     bool ispar(string a)
//     {

//         stack<char> st;
//         int l = a.length();
//         if (l / 2 != 0)
//             return false;
//         for (int i = 0; i < l; i++)
//         {
//             if (a[i] == '{' || a[i] == '[' || a[i] == '(')
//             {
//                 st.push(a[i]);
//                 cout << st.top() << endl;
//             }
//             cout << "\n\n";
//             if ((st.top() == '(' && a[i] == ')') || (st.top() == '{' && a[i] == '}') || (st.top() == '[' && a[i] == ']'))
//             {
//                 cout << st.top();
//                 st.pop();
//             }
//         }
//         if (st.empty())
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
// };

int main()
{
    int t;
    string a;
    cin >> a;
    stack<char> st;
    for (int i = 0; i < a.length(); i++)
    {
        if (st.empty())
        {
            st.push(a[i]);
            cout << st.top();
        }

        else if ((st.top() == '(' && a[i] == ')') || (st.top() == '{' && a[i] == '}') || (st.top() == '[' && a[i] == ']'))
        {
            st.pop();
        }
        else
            st.push(a[i]);
    }
    if (st.empty())
        cout << "balanced";
    else
        cout << "not blanaced";
}