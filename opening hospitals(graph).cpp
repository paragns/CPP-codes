#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
 vector<vector<int>> adj;
void dfs(int v,int p){
    int x=adj.size()+1,y=0,t=0,s=0;
    for(auto u:adj[v]){
        if(u!=p){
            dfs(u,v);
            y+=(min({dp[u][0],dp[u][1],dp[u][2]}));
            int z=(min({dp[u][0],dp[u][1]}));
            t+=z;
            x=min(x,dp[u][0]-z);
 
        }
    }
    dp[v][0]=1+y;
    dp[v][1]=x+t;
    dp[v][2]=t;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	dp.resize(n+1,vector<int>(3,0));
	int edges;
	cin>>edges;
	adj.resize(n+1);
	for(int i=0;i<edges;i++){
		int l,m;
		cin>>l>>m;
		adj[l].push_back(m);
		adj[m].push_back(l);		
	}
	dfs(1,1);
	int ans=min(dp[1][0],dp[1][1]);
	cout<<ans;
return 0;
}
