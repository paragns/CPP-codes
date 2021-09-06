#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int t;
	cin>>t;
	vector<vector<ll int>>dp(500001,vector<ll int>(51,0));
	for(ll int c=0;c<=50;c++){
		dp[0][c]=0;                 //base case
		//dp[1][c]=1;
		//dp[2][c]=2;
}
dp[0][0]=1;
	for(ll int i=1;i<=500000;i++){
		for(ll int c=0;c<=50;c++){
			dp[i][c]=(dp[i-1][c])%mod;
			if(i>1)dp[i][c]=(dp[i][c]+dp[i-2][c])%mod;
			if(c>0 and i>2)dp[i][c]=(dp[i][c]+dp[i-3][c-1])%mod;
			//cout<<i<<"*"<<c<<"*"<<dp[i][c]<<"  ";
		}
		//cout<<endl;
	}
	while(t--){		
		ll int l,m;
		cin>>l>>m;
		ll int ans=0;
		for(int i=0;i<=m;i++)ans=(ans+dp[l][i])%mod;
		cout<<ans<<endl;
	}
return 0;
}
