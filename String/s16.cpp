//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
unordered_map<string,int> dp;
int solve(string A,vector<string> &B)
{
    int n=A.size();
    if(n==0)
    {
        return 1;
    }
    if(dp[A]!=0)
    {
        return dp[A];
    }
    for(int i=1;i<=n;i++)
    {bool flag=false;
        string ss=A.substr(0,i);
        for(int j=0;j<B.size();j++)
        {
            if(ss.compare(B[j])==0)
            {
                flag=true;
                break;
            }
        }
        if(flag==true && solve(A.substr(i,n-i),B)==1)
        {
            return dp[A]=1;
        }
    }
    return dp[A]=-1;
}
    int wordBreak(string A, vector<string> &B) {
       int res=solve(A,B);
       if(res==1)
       {
           return 1;
       }
       return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends