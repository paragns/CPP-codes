#include <bits/stdc++.h>
using namespace std;
int func(int n, int p,vector<vector<int>>&dp){
    
    if(p==1 and n<2)return dp[n][p]=2;
    if(p==2 and n<2)return dp[n][p]=1;
    if(dp[n][p]!=-1)return dp[n][p];
    //cout<<n<<" "<<p<<endl;
    if(p==1){
        int t1=0,t2=0,t3=0;
        if(n>=2){
            t1=func(n-2,2,dp);
        }
        if(n>=3){
            t2=func(n-3,2,dp);
        }
        if(n>=5){t3=func(n-5,2,dp);}
        if(t1==1 or t2==1 or t3==1)return dp[n][p]=1;
        else return dp[n][p]=2;
    }
    if(p==2){
        int t1=0,t2=0,t3=0;
        if(n>=2){
            t1=func(n-2,1,dp);
        }
        if(n>=3){
            t2=func(n-3,1,dp);
        }
        if(n>=5){t3=func(n-5,1,dp);}
        if(t1==2 or t2==2 or t3==2)return dp[n][p]= 2;
        else return dp[n][p]=1;
    }
    return 1;
}
int main(){
    int t; cin>>t;
    vector<vector<int>>dp(103,vector<int>(3,-1));
    for(int i=1;i<101;i++){
        func(i,1,dp);
    }
    while(t--){   
        int n;cin>>n;
        int ans=dp[n][1];
        if(ans==1)cout<<"First"<<'\n';
        else cout<<"Second"<<'\n';
    }

    return 0;
}


