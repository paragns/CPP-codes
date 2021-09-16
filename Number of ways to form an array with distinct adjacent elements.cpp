#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n,m,x;cin>>n>>m>>x;
	 	vector<int>ans(n);
	 	vector<vector<int>>dp(n+1,vector<int>(m+1,0));
	 	for(int i=1;i<=m;i++){
			 dp[0][i]=0;
			 dp[1][i]=1;
		}
		dp[0][x]=1;dp[1][x]=0;
		ans[0]=1;ans[1]=m-1;
		for(int i=2;i<n-1;i++){
			for(int j=1;j<=m;j++){
				if(i==n-2 and j==1)continue;//since last element is 1
				dp[i][j]=ans[i-1];
				dp[i][j]-=(ans[i-2]-dp[i-2][j]);
				ans[i]+=dp[i][j];
				cout<<j<<" "<<dp[i][j]<<endl;
			}
		}
		cout<<ans[n-2];
	}
return 0;
}
