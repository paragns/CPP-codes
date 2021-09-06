#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
vector<vector<int>>adj;
int dfs(int node, int par, int &pathmax){
	if(adj[node].size()==1)return 0;
	
	set<int, greater<int>>s;
	for(int i:adj[node]){
		if(i==par)continue;
		int temp=1+dfs(i,node,pathmax);
		s.insert(temp);
		if(s.size()==3)s.erase(--s.end());
	}
	int t=0;
	for(auto i:s)t+=i;
	pathmax=max(pathmax,t);
	return *(s.begin());
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	int n;cin>>n;
	 	adj.resize(n+1);
	 	vector<vector<int>>edges(n-1);
	 	for(int i=0;i<n-1;i++){
	 		int x,y;
	 		cin>>x>>y;
		 	edges[i]={x,y};
		 	adj[x].push_back(y);
		 	adj[y].push_back(x);
		}	 
		int ans=-1;	
	 	for(int i=0;i<n-1;i++){
			int path1=0;
			dfs(edges[i][0],edges[i][1],path1);
			int path2=0;
			dfs(edges[i][1],edges[i][0],path2);
			ans=max(path1*path2, ans);
			cout<<path1<<" "<<path2<<" "<<edges[i][0]<<"*"<<edges[i][1]<<endl; 
		}
		cout<<ans;
	 }
return 0;
}
