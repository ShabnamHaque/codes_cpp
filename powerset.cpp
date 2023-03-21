
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solveforpowerset(string s, vector<vector<char>> &a, vector<char> res,int n)
    {
        // n=index....
        
        if (n == 0)
        {
            a.push_back(res);
            return;
        }

        res.push_back(s[n - 1]);
        solveforpowerset(s,a, res, n - 1);
        res.pop_back();
        solveforpowerset(s, a,res, n - 1);
    }

    vector<vector<char>> powerset(string s)
    {
        vector<vector<char>> ds;
        vector<char> a;
        solveforpowerset(s, ds, a,s.size()-1);

        return ds;
    }
};

int main()
{

    string a = "ABCD";
    Solution X;
    vector<vector<char>> ans2 = X.powerset(a);
    for (int i = 0; i < ans2.size(); i++)
    {
        for (int j = 0; j < ans2[i].size(); j++)
        {
            cout << ans2[i][j];
        }
        cout << "/";
    }
    // output   CBA/CB/CA/C/BA/B/A// 
    return 0;
}
