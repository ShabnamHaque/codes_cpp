#include <bits/stdc++.h>
using namespace std;

 int f(int i, int j, string &s ,string &t, vector<vector<int>> &dp){
    
        // top down approach //memoization
         
        if(i<0 || j<0) return 0;  // zero char long strings present in testcase
      
        if(dp[i][j]!=-1) {return dp[i][j];}
      
        int ans=0;
      
        if(s[i]==t[j]) {ans=1+f(i-1,j-1,s,t,dp);}
        //both move}
      
        else{ 
        ans=0;           //reset the answer.
        f(i-1,j,s,t,dp); //one moves 
        f(i,j-1,s,t,dp); //one moves and in the rest is checked.
        }
        
        return dp[i][j]=ans;
    }
    int longestCommonSubstr (string S1, string S2, int n, int m){
       
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=INT_MIN;
       
        f(n-1,m-1,S1,S2,dp);
       
        for(auto x: dp){
            for(auto y : x){
               ans = max(ans,y);
            }
        }
		for(auto x: dp){
            for(auto y : x){
               cout<<y<<" ";
            }
			cout<<endl;
        }

		
        return ans;
    }

int main()
{
	string a, b;
	string ans = "";
	cout << "enter the strings\n";

	cin >> a >> b;
	cout << "The length of the longest common subseq is "
		 << longestCommonSubstr(a, b, a.length(),b.length()) << endl;

	
	return 0;
}

/*
enter the strings
abcde
bcdirhhirbcde
The length of the longest common subseq is 4

abcdgh
acdge
1 0 0 0 0
0 0 0 0 0
0 1 0 0 0
0 0 2 0 0
0 0 0 3 0
0 0 0 0 0
The length of the longest common subseq is 3

*/

