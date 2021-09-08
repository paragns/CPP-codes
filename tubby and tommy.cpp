#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int dfs(int d, int c, auto adj, int turn, int par1, int par2, int timer){
	cout<<d<<" "<<c<<" "<<turn<<" "<< timer<<endl;
	if(turn==0){
		if(d==c)return timer;
		int ans=inf;
		for(auto i:adj[d]){
			if(i==par1)continue;
			ans=min(ans,dfs(i,c,adj,turn^1,d,par2,timer+1));
		}
		return ans;
	}
	else{
		if(d==c)return timer;
		int ans=minf;
		for(auto i:adj[c]){
			if(i==par2)continue;
			ans=max(ans,dfs(d,i,adj,turn^1,par1,c,timer+1));
		}
		ans=max(ans,dfs(d,c,adj,turn^1,par1,par2,timer+1));
		return ans;
	}	
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n,e; cin>>n>>e;
	 	vector<vector<int>>adj(n+1);
	 	for(int i=0;i<e;i++){
			int x,y; cin>>x>>y;
			adj[x].push_back(y);
    		adj[y].push_back(x);
		}
		int d,c; cin>>d>>c;
		cout<<dfs(d,c,adj,0,-1,-1,0);
	}
return 0;
}
