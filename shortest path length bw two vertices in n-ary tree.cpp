#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
ll int result=inf;
pair<ll int ,ll int> dfs(int node, int a, int b,vector<vector<int>> &adj){
	ll int d1=inf,d2=inf;
	if(node==a){
		d1=0;
		for(int i:adj[node]){
			auto x=dfs(i,-1,b,adj);
			d1=min(d1,x.first);
			d2=min(d2,x.second);
		}
		result=min(result,d1+d2);
	}
	else if(node==b){
		d2=0;
		for(int i:adj[node]){
			auto x=dfs(i,a,-1,adj);
			d1=min(d1,x.first);
			d2=min(d2,x.second);
		}
		result=min(result,d1+d2);
	}
	else{
		for(int i:adj[node]){
			auto x=dfs(i,a,b,adj);
			d1=min(d1,x.first);
			d2=min(d2,x.second);
		}
		result=min(result,d1+d2);
	}
	if(d1!=inf)d1++;
	if(d2!=inf)d2++;
	return {d1,d2};
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	int n; cin>>n;
	 	vector<vector<int>>adj(n+1);
	 	int a,b; cin>>a>>b;
	 	for(int i=0;i<n-1;i++){
		 int x,y; cin>>x>>y;
		 adj[x].push_back(y);
		 //adj[y].push_back(x);
		}
		dfs(1,a,b,adj);
		if(a==b)cout<<0;
		else cout<< result;
	 }
	
	
return 0;
}
