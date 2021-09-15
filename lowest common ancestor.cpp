#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
vector<int>euler, first, height, tree;
vector<int>vis;
vector<vector<int>>adj;
void dfs(int node,int h){
	vis[node]=1;
	first[node]=euler.size();
	euler.push_back(node);
	height[node]=h;
	for(int i:adj[node]){
		if(vis[i])continue;
		dfs(i,h+1);
		euler.push_back(node);	
	}
}
void build(int node, int s, int e){
	if(s==e){
		tree[node]=euler[s];
		return;
	}
	int mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	int l=tree[2*node],r=tree[2*node+1];
	tree[node]= (height[l]<height[r])? l:r;
	return;
}
int query(int node, int s, int e, int l, int r ){
	if(s>=l and e<=r)return tree[node];
	if(s>r or e<l)return -1;
	int mid=(s+e)/2;
	int a=query(2*node,s,mid,l,r);
	int b=query(2*node+1,mid+1,e,l,r);
	if(a==-1)return b;
	else if(b==-1)return a;
	else return (height[a]<height[b])? a:b;
}
int lca(int u, int v){
	int l=first[u],r=first[v];
	if(r<l)swap(l,r);
	return query(1,0,euler.size()-1,l,r);
}
int main(){
	int T=1;
	//cin>>T;
	while(T--){
		int n; cin>>n;
		adj.resize(n+1);
		for(int i=0;i<n-1;i++){
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		first.resize(n+1);
		height.resize(n+1);
		vis.resize(n+1);
		dfs(1,0);
		int sz=euler.size();
		tree.resize(4*sz);
		build(1,0,sz-1);
		int q; cin>>q;
		for(int i=0;i<q;i++){
			int u,v;cin>>u>>v;
			cout<<lca(u,v)<<"\n";
		}
	}
return 0;
}
