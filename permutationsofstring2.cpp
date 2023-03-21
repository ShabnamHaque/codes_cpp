
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    set<string> converttoset(vector<string> v)
    {
        set<string> s;
        for (auto it : v)
        {
            s.insert(it); // convert vector to set
        }
        return s;
    }

    void permute(string s, int l, int r, vector<string> &ds)
    {

        if (l == r)
        {
            ds.push_back(s);

            return;
        }

        for (int i = l; i <= r; i++)
        {
            swap(s[l], s[i]); // BFS
            permute(s, l + 1, r, ds);

            swap(s[l], s[i]);
        }
    }
    vector<string> find_permutation(string s)
    {
        vector<string> ds;

        permute(s, 0, s.size() - 1, ds);

        set<string> s1;
        s1 = converttoset(ds);

        vector<string> ds2(s1.begin(), s1.end()); // convert set to vector

        return ds2;
    }
};

int main()
{

    string a = "ABCD";
    Solution X;
    vector<string> ans = X.find_permutation(a);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "/";
    }
    return 0;
}
