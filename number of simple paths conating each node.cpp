#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
void dfs(int node, int par,vector<vector<int>>adj){
	int sub=1;
	vector<int>subtr;
	for(int ch:adj[node]){
			if(ch==par)continue;
			int val=dfs(ch,node,adj);
			subtr.push_back(val);
			sub+=val;
	}
	ans[node]=2*(n-1);
	int baaki=n-sub;
	ans[node]+=baaki*(sub-1);
	for(int i=0;i<subtr.size();i++){
		ans[node]+=(subtr[i]*(sub-1-subtr[i]));
	}
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
	dfs(1,-1,adj);
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	
}
