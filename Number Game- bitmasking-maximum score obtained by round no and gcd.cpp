
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 int t;
 t=1;
while(t--){
    int n;
    cin>>n;
    n=2*n;
    vector<ll int>A(n);
    for(int i=0;i<n;i++)cin>>A[i];
    
    vector<vector<ll int>>GCD(n,vector<ll int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        	GCD[i][j]=__gcd(A[i],A[j]);
    }
    vector<ll int> dp((1<<n),0);
    for(int i=0;i<(1<<n);i++){
    	int c1= __builtin_popcount(i);
    	 if(c1%2)continue;
    	 for(int j=0;j<n;j++){
    	 	if(!((1<<j)&i)){
    	 		for(int k=0;k<n;k++){
    	 			if(k==j)continue;
    	 			if(!((1<<k)&i)){
                        dp[((i|(1<<j))|(1<<k))]= max(dp[((i|(1<<j))|(1<<k))],dp[i]+GCD[j][k]*(c1+2)/2);
                    }
                }
            }
        }
    }
 cout<<dp[(1<<n)-1]<<'\n';
}
    return 0;
}


