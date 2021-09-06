#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007
# define ll long long
  ll int dp[2000001][2];
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int d,t,q;
	cin>>d>>t>>q;
	dp[0][0]=1;
	dp[0][1]=1;
	dp[1][0]=1;
	dp[1][1]=1;
	ll int dev_window=2;
	ll int test_window=2;
	
	for(int i=2;i<=2000000;i++){
		if(i>=d)dev_window=((dev_window-dp[i-d][1])+mod)%mod;
		if(i>=t)test_window=((test_window-dp[i-t][0])+mod)%mod;
		dp[i][0]=dev_window;
		dp[i][1]=test_window;
		dev_window=(dev_window+dp[i][1])%mod;
		test_window=(test_window+dp[i][0])%mod;
	}
	while(q--){
		int n;
		cin>>n;
		ll int ans=(dp[n][0]+dp[n][1])%mod;
		cout<<ans<<endl;
	}
return 0;
}
