#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int m;
vector<ll int> ans;
vector<vector<int>>adj;
vector<vector<int>>dp;
void dfs(int node, int par){
	long long int t=0;
	if(node==1){
		for(int i:adj[node]){
			dfs(i,node);
		}
	}
	else{
		
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dp[node][i]+=dp[par][j]*(__gcd(i,j)>1);
			}
			t=(t+dp[node][i])%mod;
		}
		for(int i:adj[node]){
			dfs(i,node);
		}
	}
	if(adj[node].size()==0)ans.push_back(t);
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n;
	 	cin>>n>>m;
	 	adj.resize(n+1);
	 	for(int i=0;i<n-1;i++){
			int x,y;
			cin>> x>>y;
			adj[x].push_back(y);
			//adj[y].push_back(x);
		}
		dp.resize(n+1,vector<int>(m+1));
		for(int i=1;i<=m;i++){
			dp[1][i]=1;
		}
		dfs(1,-1);
		ll int sol1=1,sol2=1;
	 	for(int i=0;i<ans.size();i++){
			sol1=(sol1*m)%mod;
			sol2=(sol2*(m-ans[i]))%mod; 
		}
		sol1=(mod+sol1-sol2)%mod;
		 cout<<sol1;
	}
return 0;
}
