#include <bits/stdc++.h>
using namespace std;
	vector<int> par;
  int find_par(int x){
  	if(par[x]==x)return x;
  	else par[x]=find_par(par[x]);
  }
  vector<int>vis;
  void dfs(vector<vector<int>> &adj, vector<int>&path, int ele,int tar,bool &found){
  	vis[ele]=1;
  	path.push_back(ele);
  	if(ele==tar){
  		found=1;
  		return;
	  }
	  for(auto i:adj[ele]){
	  	if(vis[i])continue;
	  	dfs(adj,path,i,tar,found)
	  	if(found)return;
	  	path.pop_back();
	  }
	  return;
  }
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	int m;
	cin>>n>>m;
	vector<vector<int>>adj(n+1);
	vis.resize(n+1,0);
	vector<vector<int>>edges(m);
	for(int i=0;i<m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		edges[i]={z,x,y};
	}
	sort(edges.begin(),edges.end());
    par.resize(n+1);
    	vector<int> sz(n+1,1);
	for(int i=0;i<n+1;i++)
		par[i]=i;
	for(int){
		int x=par[edges[i][1]];
		int y=par[edges[i][2]];
		if(x==y)continue;
		adj[edges[i][1]].push_back(edges[i][2]);
		adj[edges[i][2]].push_back(edges[i][1]);
		if(sz[edges[i][1]]<edges[i][2])swap(edges[i][2],edges[i][1]);
		par[edges[i][2]]=x;	 
	}
	vector<int>path;
	dfs(adj,path,1,n,tar,0);
return 0;
}




