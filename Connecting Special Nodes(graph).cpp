#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
vector<vector<ll int>>adj;
vector<ll int>vis,par,sz;
void dfs(ll int node,ll int &sz,ll int &ed,ll int paa){
	vis[node]=1;
	par[node]=paa;
	ed+=adj[node].size();
	for(auto i:adj[node]){
		if(vis[i])continue;
		sz++;
		
		dfs(i,sz,ed,paa);
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int t=1;
	//cin>>t;
	 while(t--){
	 	ll int n;cin>>n;
	 	ll int edges;cin>>edges;
	 	ll int k; cin>>k;
	 	adj.resize(n+1);
	 	vis.resize(n+1);
	 	for(ll int i=0;i<edges;i++){
		 	ll int x, y;
		 	cin>>x>>y;
			 adj[x].push_back(y);
			 adj[y].push_back(x);
	 	}
	 	vector<ll int>sp(k);
	 	for(ll int i=0;i<k;i++)cin>>sp[i];
	 	
	 	par.resize(n+1);
		sz.resize(n+1,1);
		
	 	for(ll int i=0;i<n+1;i++)par[i]=i;
	 	ll int ans1=0, ans2=0;
	 	ll int maxe=0;
	 	
	 	for(ll int i=0;i<k;i++){
	 		ll int x=1,y=0;
		    dfs(sp[i],x,y,sp[i]);
		    sz[sp[i]]=x;
		    y/=2;
		    maxe=max(maxe,x);
		    ans1+=((x*(x-1)/2)-y);
		    //cout<<y<<" ";
		 }
		  
		 //////////
		 ll int tot_n=0,tot_ed=0;
		 for(ll int i=1;i<=n;i++){
		 	if(vis[i])continue;
	 		ll int x=1,y=0;
		    dfs(i,x,y,i);
		    sz[i]=x;
		    y/=2;
		    ans1+=((x*(x-1)/2)-y);
		    ans1+=tot_n*x;
		    ans2+=(tot_n*x);
	        tot_n+=x;
		 }
		
		ans1+=maxe*tot_n;
		ans2+=maxe*tot_n;
		 cout<<ans1<<" "<<ans2;
	 	
	 }
return 0;
}
