#include <bits/stdc++.h>
using namespace std;
bool solve(vector<vector<bool>>&dp,int i,int j,string&s){
    
        if(i == j)
        {
            return dp[i][j] = true;
        }

        if(j-i == 1){ //side by side
            if(s[i] == s[j]){
                return dp[i][j] = true;
            }
            else{
                return dp[i][j] = false;
            }
        }
        
        // dp[i+1][j-1]==1  if not true then toh reset krna parega i,j ko

        if(s[i]==s[j] && dp[i+1][j-1]==1){
            return dp[i][j]=1;
        }

        else {
            return dp[i][j] = false;
        }

    }
    string longestPalindrome(string s) {
        
        int n=s.size();
        int startindex=0,maxlen=0;

        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int k=0;k<n;k++){
            for(int i=0,j=k;j<n;i++,j++){
                solve(dp,i,j,s);
                if(dp[i][j]==true){
                    if(j-i+1>maxlen){
                        startindex=i;
                        maxlen=j-i+1;
                    }
                }
            }
        }
        for(auto x:dp){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<endl;
        }
        return s.substr(startindex,maxlen);
    }

int main()
{
	string a;
	cout << "enter the string\n";

	cin >> a ;
	cout << "The longest common substring is "
		 << longestPalindrome(a) << endl;

	
	return 0;
}

/*
enter the string
abcbs
1 0 0 0 0
0 1 0 1 0
0 0 1 0 0
0 0 0 1 0
0 0 0 0 1
The longest common substring is bcb



yabadedeededi    aba   ded  ede  **dedeeded***     ded  ede  
1 0 0 0 0 0 0 0 0 0 0 0 0
0 1 0 1 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0 0 0 0
0 0 0 0 1 0 1 0 0 0 0 1 0
0 0 0 0 0 1 0 1 0 0 1 0 0 
0 0 0 0 0 0 1 0 0 1 0 0 0
0 0 0 0 0 0 0 1 1 0 0 0 0
0 0 0 0 0 0 0 0 1 0 1 0 0
0 0 0 0 0 0 0 0 0 1 0 1 0 
0 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0 0 0 1
The longest common substring is dedeeded
*/
