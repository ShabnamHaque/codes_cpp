#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2, string &ans)
{
	int n = text1.length(), m = text2.length();

	int dp[n + 1][m + 1];

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}

			else if (text1[i - 1] == text2[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
				ans += text1[i - 1];
			}

			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[n][m];
}

int main()
{
	string a, b;
	string ans = "";
	cout << "enter the strings\n";

	cin >> a >> b;
	cout << "The length of the longest common subseq is "
		 << longestCommonSubsequence(a, b, ans) << endl;

	cout << "the common subseq is " << ans;
	//this will only if the strings do not contain repeating characters.
	return 0;
}
