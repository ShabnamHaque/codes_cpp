#include <bits/stdc++.h>
using namespace std;
//DP
int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{

	if (i < 0 || j < 0)
		return 0; // zero char long strings present in testcase
	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}

	int ans = INT_MIN;

	if (s.at(i) == t.at(j))
	{
		ans = 1 + f(i - 1, j - 1, s, t, dp);
	}
	// both move}

	else
	{
		ans = 0;
		f(i - 1, j, s, t, dp); // one moves
		f(i, j - 1, s, t, dp); // one moves and in the rest is checked.
	}
	return dp[i][j] = ans;
}

int longestcommonsubstring(string S1, string S2, int n, int m)
{
	vector<vector<int>> dp(n, vector<int>(m, -1));
	int ans = INT_MIN;

	f(n - 1, m - 1, S1, S2, dp);

	for (auto x : dp)
	{
		for (auto y : x)
		{
			ans = max(ans, y);
		}
	}
	return ans;
}

int main()
{
	string a, b;
	cout<<"enter the strings\n";
	cin >> a >> b;
	cout << "The length of the longest common substring is\n"
		 << longestcommonsubstring(a, b, a.length(), b.length());

	return 0;
}
