
#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN


vector<vector<int>>adj;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	//cin>>t;
	 while(t--){
	 	int n, ed; cin>>n>>ed;
	 	adj.resize(n+1);
	 	for(int i=0;i<ed;i++){
		 	int x,y;
		 	cin>>x>>y;
		 	adj[x].push_back(y);
		 	adj[y].push_back(x);
		 }
		int ans=inf;
	 	for(int i=1;i<=n;i++){
		 	if(adj[i].size()<2)continue;
		 	for(int j=0;j<adj[i].size()-1;j++){
			 	for(int k=j+1;k<adj[i].size();k++){
				 	auto x=find(adj[adj[i][j]].begin(), adj[adj[i][j]].end(),adj[i][k]);
				 	if(x!=adj[adj[i][j]].end()){
				 		int t=adj[i].size()+adj[adj[i][j]].size()+adj[adj[i][k]].size()-6;
					 	ans=min(ans,t);
					 	cout<<i<<" "<<adj[i][j]<<" "<<adj[i][k]<<endl;
					 }
				 }
			 }
		 }
			 
			 if(ans==inf)cout<<-1;
			 else cout<<ans;	
	 }	
return 0;
}
