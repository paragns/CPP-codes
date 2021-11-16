#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
int LCA(int a, int b, auto &spar, auto &lev){
	if(lev[a]>lev[b])swap(a,b);
	int l=lev[b]-lev[a];
	while(l!=0){
		int t=log2(l);
		l=l-(pow(2,t));
		b=spar[b][t];
	}
	if(a==b)return a;
	int high=spar[0].size(),low=0;
	while(low<high){
		int mid=low+(high-low)/2;
		if(spar[a][mid]==spar[b][mid])high=mid;
		else low=mid+1;
	}
	return spar[a][high];
}
vector<int>lev;
void dfs(int node, int p, int l, auto &ord, auto &par){
	lev[node]=l;
	par[node]=p;
	ord.push_back(node);
	for(int i:adj[node]){
		if(i==p)continue;
		dfs(i,node,l+1,ord,par);
	}
}
int main(){
	int n;cin>>n;
	lev.resize(n+1,0);
	adj.resize(n+1);
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);	
	}
	int q;
	cin>>q;
	vector<int>ord,par(n+1);
	dfs(1,-1,1,ord,par);
	int temp=log2(n)+1;
	vector<vector<int>>sparse(n+1,vector<int>(temp,-1));
	for(int j=0;j<temp;j++){
		for(int i=1;i<n;i++){
			if(j==0){
				sparse[ord[i]][j]=par[ord[i]];
				continue;
			}
			if(sparse[ord[i]][j-1]!=-1)sparse[ord[i]][j]=sparse[sparse[ord[i]][j-1]][j-1];
		}
	}
	for(int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		cout<<LCA(a,b,sparse,lev)<<endl;
	}
	
return 0;
}
