#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int func(int mask, int currcity, vector<vector<int>> &mat, vector<vector<int>> &dp ){
	int n=mat.size();
	if(mask==(1<<n)-1){ return mat[currcity][0];}
	
	if(dp[mask][currcity]!=-1)return dp[mask][currcity]; 
	int ans=inf;
	for(int city=0;city<n;city++){
		if((mask &(1<<city))==0){
			int t=mat[currcity][city]+func(mask|(1<<city),city,mat,dp);
			//cout<<t;
			ans=min(ans,t);
		}
	}
	//cout<<ans<<"*";
	return dp[mask][currcity]=ans;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	cin>>T;
	 while(T--){
	 	int N; cin>>N;
	 	
	 	vector<vector<int>>dp((1<<N)+1,vector<int>(N+1,-1));
	 	vector<vector<int>>mat(N,vector<int>(N,0));
	 	for(int i=0;i<N;i++){
			for(int j=0;j<N;j++)cin>>mat[i][j];
		}
		
		cout<<func(1,0,mat,dp)<<'\n';
	}
return 0;
}
