#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
vector<vector<int>>adj;
int ans;
void dfs(int node,int st, auto &vis, int par){
	//cout<<node<<" ";
	vis[node]=1;
	for(int i:adj[node]){
		if(i==par)continue;
		if(i==st){ans++;}
		if(vis[i])continue;
		dfs(i,st,vis,node);
	}
	if(node!=st)vis[node]=0;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	ans=0;
	 	int n,e;
		cin>>n>>e;
		adj.resize(n+1);
	 	for(int i=0;i<e;i++){
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		vector<bool>vis(n+1,0);
		for(int i=1;i<=n;i++){
			dfs(i,i,vis,-1);
		}
		cout<<ans/2;
	}
return 0;
}
