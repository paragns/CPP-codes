#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
ll int ans;
vector<vector<ll int>>adj;
void dfs(int node, int par, vector<ll int>&val){
	ll int maxch=INT_MIN;
	for(auto i:adj[node]){
		if(i==par)continue;
		dfs(i, node,val);
		maxch=max(maxch,val[i]);
	}
	val[node]=max(val[node],val[node]+maxch);
	ans=max(ans,val[node]);
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	int n;cin>>n;
	 	adj.resize(n);
	 	//vector<int>par(n);
	 	
	 	int w;
		 cin>>w;
		 w=1;
	 	for(int i=0;i<n-1;i++){
	 		int x;cin>>x;
		 	adj[w].push_back(x);
		 	adj[x].push_back(w);
		 	w++;
		 }
		 vector<ll int>val(n);
		 cin>>n;
	 	for(int i=0;i<n;i++)cin>>val[i];
	 	ans=val[0];
		 dfs(0,-1,val);
		 cout<<ans;
	 }
	
	
return 0;
}
