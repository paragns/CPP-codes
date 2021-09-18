#include<bits/stdc++.h>
using namespace std;
vector<int>vis;
pair<int,int>dfs(int v,vector<vector<int>> &adj,vector<int> &val){
   vis[v]=1;
   int x,y;
   if(val[v]){
   		x=1;
   		y=1;
   }
   else {x=0, y=2;}
	for(auto u:adj[v]){
    	if(vis[u])continue;
   		auto p=dfs(u,adj,val);
		   x+=min(p.first, p.second);
		   y+=min(p.first+1,p.second-1);	
    }    
   return {x,y};
}
int main(){
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin>> n;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
		adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> val(n+1);
    vis.resize(n+1);    
    for(int i=1;i<=n;i++)cin>>val[i];	
	for(int i=1;i<=n;i++){
        int a;cin>>a;
        val[i]=val[i]^a;    //now val stores if value at node i is corrupted or not
    }    
    auto p=dfs(1,adj,val);
	int ans=min(p.first,p.second);
    cout<<ans;
    return 0;
}




