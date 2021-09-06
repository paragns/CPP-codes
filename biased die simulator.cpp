#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	int n;cin>>n;
	 	vector<ll int >A(7);
	 	for(int i=1;i<=6;i++){
		 	cin>>A[i];
		 }
	 	vector<vector<ll int>>dp(n+1,vector<ll int>(7,0));
	 	vector<ll int>sum(n+1,0);
	 	sum[0]=1;
	 	for(int i=1;i<=n;i++){
		 	//sum[i]=sum[]
			 for(int j=1;j<=6;j++){
		 		dp[i][j]=sum[i-1];
		 		if(i>A[j])dp[i][j]=(mod+dp[i][j]-(mod+sum[i-A[j]-1]-dp[i-A[j]-1][j])%mod)%mod;
		 		sum[i]=(sum[i]+dp[i][j])%mod;
			 }
			 
		 }
		 cout<<sum[n];
	 }
	//11
	
return 0;
}
