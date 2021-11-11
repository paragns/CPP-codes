#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
int dfs(int node, int par,vector<vector<int>>adj, int n){
	int sub=1;
	vector<int>subtr;
	for(int ch:adj[node]){
			if(ch==par)continue;
			int val=dfs(ch,node,adj,n);
			subtr.push_back(val);
			sub+=val;
	}
	ans[node]=2*(n-1);
	int baaki=n-sub;
	ans[node]+=2*baaki*(sub-1);
	for(int i=0;i<subtr.size();i++){
		ans[node]+=(subtr[i]*(sub-1-subtr[i]));
	}
	return sub;
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adj(n+1);
	ans.resize(n+1);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,-1,adj,n);
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	
}
