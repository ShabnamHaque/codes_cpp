#include <bits/stdc++.h>
using namespace std;

void prevless(vector<int> v, vector<int> &ans)
{
    stack<int> stk;
    vector<int> prev_less(v.size(), -1);
    stk.push(0);

    for (int i = 1; i < v.size(); i++)
    {
        while (v[stk.top()] <= v[i] && stk.empty() == 0){stk.pop();}
        //previous element strictly greater than the concerned element.     
        
     if((stk.empty() == 0)) {  prev_less[i] =   v[stk.top()];}
        stk.push(i);
    }

    for(int i=0;i<v.size();i++){
        ans[i]=prev_less[i];
    }
}

int main()
{
    vector<int> v = {1, 5,3,3,0};
    vector<int> ans(v.size(),-1);
    prevless(v, ans);
    for (int i=0;i<v.size();i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
