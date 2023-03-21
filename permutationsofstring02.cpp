
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
  set<string> converttoset(vector<string> v)
  {
    set<string> s;
    for (auto it : v)
    {
      s.insert(it); //convert vector to set
    }
    return s;
  }
  void permute(string s,int index, vector<string> &ds)
  {
    if (index==s.size())
    {
      ds.push_back(s);
      return;
    }

    for (int i = index; i <s.size(); i++)
    {
      swap(s[index], s[i]);  // l starts from 0 
      permute(s, index + 1, ds);
      
   // after rching l==r we backtrack 

      swap(s[index], s[i]);
    }
  }
  vector<string> find_permutation(string s)
  {
    vector<string> ds;

    permute(s, 0, ds);

    set<string> s1;
    s1 = converttoset(ds);
    vector<string> ds2(s1.begin(), s1.end());  //convert set to vector
    return ds2;
  }
};

int main(){
    string a="ABCD";
    Solution X;
    vector<string>ans=X.find_permutation(a);
 for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<"/";
    }
    return 0;
}
