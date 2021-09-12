#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
vector<int> in, pre;
int timer=1,ans=0;
vector<vector<int>>mat;
void dfs1(int node, int par, vector<int>&vis, auto adj){
	in[node]=pre[node]=timer++;
	
	vis[node]=1;
	for(auto child:adj[node]){
		if(child==par)continue;
		if(vis[child]){
			pre[node]=min(pre[node],in[child]);
		}
		else{
			dfs1(child,node,vis,adj);
			if(pre[child]>in[node]){
				// a critical connection;
			
				mat[node][child]=0;
				mat[child][node]=0;
				ans++;
			}
			pre[node]=min(pre[node],pre[child]);
		}
	}
}

//void dfs2(int node,vector<int> &vis,auto adj){
//	vis[node]=1;
//	for(int i:adj[node]){
//		if(vis[i])continue;
//		dfs2(i,vis,adj);
//	}
//}
void make_adj(vector<vector<int>>&adj){
	for(int i=1;i<mat.size();i++){
		for(int j=1;j<mat[i].size();j++){
			if(mat[i][j]==1)adj[i].push_back(j);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n;
		cin>>n;
		vector<vector<int>>adj1(n+1),adj2(n+1);
		in.resize(n+1,0);
		pre.resize(n+1,0);
		mat.resize(n+1,vector<int>(n+1,0));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>mat[i][j];
			}
		}
		make_adj(adj1);
		
		vector<int>vis1(n+1,0);
		//auto vis2=vis1;
		dfs1(1,-1,vis1,adj1);
		
		//no of countries =no of bridges +1
		cout<<(ans+1);
	}
return 0;
}
