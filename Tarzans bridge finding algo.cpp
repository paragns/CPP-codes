#include <bits/stdc++.h>
using namespace std;
vector<int>in,low,vis;
int timer=0;
vector<vector<int>>adj;
void dfs(int node, int par){
  	vis[node]=1;
  	in[node]=low[node]=timer;
  	timer++;
  	for(int child:adj[node]){
  		if(child==par)continue;
  		if(vis[child]==1){
  			//there is a back edge
  			low[node]=min(low[node], in[child]);
		  }
		  else{
		  	//forword edge
			  	dfs(child,node);
			  	if(low[child]>in[node]){ // if(low[child]>=in[node])--for articulation pt;
			  	cout<<"bridge between"<<node<<"->"<<child<<endl;
			  	} 
			  	low[node]=min(low[node],low[child]);
		  }     
  		
	  }
  }
// Driver code
int main()
{
	int n,e;
	cin>>n>>e;
	adj.resize(n+1);
    vis.resize(n+1);
	in.resize(n+1);
	low.resize(n+1);
	
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,-1);
	
return 0;
}
