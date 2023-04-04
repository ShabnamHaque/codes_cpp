#include<bits/stdc++.h>
using namespace std;
//anuj utube

long long int fastpower(long x,long n,int md){
    long long int res=1;
    while(n>0){
        if(n&1==1){
            res=(res*x%md) % md;
        }
        x=(x%md*x%md)%md;
        n=n>>1;

    }
    return res;
}

int main(){

cout<<fastpower(3978432,5,1000000007);

    return 0;
}

