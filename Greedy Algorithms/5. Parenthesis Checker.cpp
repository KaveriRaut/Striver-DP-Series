#include<bits/stdc++.h>
using namespace std;

//Time : O(N) = O(str.length)
//Space : O(N) => for stack
//Using Greedy + Stack approach

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string str)
    {
        int n = str.length();
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            //opening bracket=>push into stack
            //closing bracket=>pop corresponding open_bracket from stack
            if(str[i]=='('||str[i]=='{'||str[i]=='[')
            {
                st.push(str[i]);
            }
            else
            {
                if(str[i]==')')
                {
                    if(!st.empty() && st.top()=='(')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(str[i]==']')
                {
                    if(!st.empty() && st.top()=='[')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(str[i]=='}')
                {
                    if(!st.empty() && st.top()=='{')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        //after complete scan of string=>stack is still not empty
        if(!st.empty())
        {
            return false;
        }
        return true;
    }

};

//{ Driver Code Starts.

int main()
{
   string a;
    cin>>a;
    Solution obj;
    if(obj.ispar(a))
    cout<<"balanced"<<endl;
    else
    cout<<"not balanced"<<endl;
}
// } Driver Code Ends
