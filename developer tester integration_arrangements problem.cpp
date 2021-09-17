#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007
# define ll long long
  ll int dp[2000001][2];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int d,t,q;
	cin>>d>>t>>q;
	vector<vector<ll int>>dp(2000001,vector<ll int>(2,0));
	dp[0][0]=1;
	dp[0][1]=1;
	dp[1][0]=1;
	dp[1][1]=1;
	vector<ll int>ans(2000001,0);
	ans[0]=2;
	ans[1]=2;
	for(int i=2;i<=2000000;i++){
		dp[i][0]=dp[i][1]=ans[i-1];
		if(i>=d)dp[i][1]=(dp[i][1]-ans[i-d]+dp[i-d][1]+mod)%mod;
		if(i>=t)dp[i][0]=(dp[i][0]-ans[i-t]+dp[i-t][0]+mod)%mod;
		ans[i]=(dp[i][0]+dp[i][1])%mod;
	}
	while(q--){
		int n;
		cin>>n;
		
		cout<<ans[n]<<"\n";
	}
return 0;
}
