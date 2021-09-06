#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
vector<vector<int>>adj;
void dfs (int node, vector<int>&p, int par){
	cout<<node<<endl;
	if(adj[node].size()==1)return ;
	for(int i:adj[node]){
		if(i==par)continue;
		dfs(i,p,node);
		if(p[i]==0){p[node]=1;}
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
		 vector<int>p(n+1);
		 dfs(1,p,-1);
		 for(auto i:p)cout<<i<<" ";
	 	
	 }
	
	
return 0;
}
