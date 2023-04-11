#include <bits/stdc++.h>
using namespace std;
//stack
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        stack<int>s1,s2; // s1 and s2 will store the indices of the  prev smaller
        //and next smaller elemnts respectively.

        int n=arr.size();
        vector<int>prev_smaller(n),next_smaller(n);

        for(int i=0;i<n;i++){
            prev_smaller[i]=i;
            next_smaller[i]=n-1-i;
        }
        
        for(int i=0;i<n;i++){
           
           while(!s1.empty() && arr[s1.top()]>arr[i]){
          next_smaller[s1.top()]=i-s1.top()-1;  //no of elements in the left greater (strictly)than the presnt element
          //prev elemnt smaller or equal to present elemnt
            
               s1.pop();
           }

           s1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            //>= to handle duplicates
           while(!s2.empty() && arr[s2.top()]>=arr[i]){
             prev_smaller[s2.top()]=s2.top()-1-i;
              //no of elements to the right greater (strictly)than the presnt element
               s2.pop();
           }
           s2.push(i);
        }

cout<<"prev_smaller array\n";
for(auto x:prev_smaller){
    cout<<x<<" ";
}
cout<<"\nnext smaller array \n";
for(auto x:next_smaller){
    cout<<x<<" ";
}
cout<<endl;
        int ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            ans+=(arr[i]*(prev_smaller[i]+1)*(next_smaller[i]+1));
            ans%=mod;
        }

    return ans;

    }
};


int main()
{
    vector<int> v = {11,81,94,43,3};
    Solution obj;
    cout<< obj.sumSubarrayMins(v);
    cout<<"\n--------\n";
    vector<int>arr={3,1,2,4};
    Solution obj2;
    cout<< obj2.sumSubarrayMins(arr);
    
    return 0;
}
/*
prev_smaller array
0 0 0 2 4
next smaller array
3 1 0 0 0
444
--------
prev_smaller array
0 1 0 0
next smaller array
0 2 1 0
17

*/
