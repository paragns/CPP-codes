#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll int modS(ll int a, ll int b,ll int m=mod){return ((a%m)-(b%m)+m)%m;}
ll int modP(ll int a, ll int b,ll int m=mod){a %= m;ll int res = 1;while (b > 0){if (b & 1) res = res * a % m; a = a * a % m; b >>= 1;}return res;}
ll int modA(ll int a, ll int b,ll int m=mod){return ((a%m)+(b%m))%m;}
ll int modM(ll int a, ll int b,ll int m=mod){return ((a%m)*(b%m))%m;}

ll int power(ll int x, ll int y){
        if (y == 0)
            return 1;
        ll int st= power(x, y / 2)%mod;   
         if (y % 2 == 0)
            return ((st)%mod * (st)%mod)%mod;
        else
            return (x%mod *(st)%mod * (st)%mod)%mod;
    }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.precision(17);
    int t=1;
    // cin>>t;
    while(t--){
    	int n,k; cin>>n>>k;
     vector<vector<ll int>> dp(n+1,vector<ll int>(2));
     vector<ll int>ans(n+1);
     dp[0][0]=dp[0][1]=1;
    ans[0]=1;
    for(int i=1;i<=n;i++){
	 	dp[i][1]=(21*(ans[i-1]))%mod;
	 	dp[i][0]=(5*(ans[i-1]))%mod;
	 	if(i>k){
			dp[i][0]= (mod+dp[i][0]-(dp[i-(k+1)][1]*power(5,k+1))%mod)%mod;
		}
		 ans[i]=(dp[i][1]+dp[i][0])%mod;
	 }
	 cout<<ans[n];
	
}
    return 0;
}

