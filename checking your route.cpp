#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
unordered_map<int,set<int>>ans;
int dfs(int node, auto &adj, int dis, int n, auto &vis){
	
	vis[node]=1;
	if(dis<0){vis[node]=0;return 0;}
//	cout<<"p";
	if(node==n){vis[node]=0;return 1;}
	int an=0;
	for(auto i:adj[node]){
		
		int x=i.first;
		int d=i.second;
		if(vis[x])continue;
	//	cout<<x<<" "<<d<<endl;
		int l=dfs(x,adj,dis-d,n,vis);
		an=max(an,l);
		if(l){
			
			//ans.insert({node,x});
			ans[node].insert(x);
			ans[x]=node;
			//ans.insert({x,node});
		}
	}
	vis[node]=0;
	return an;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--){ 	
	 	int n,e;
	 	cin>>n>>e;
	 	vector<vector<pair<int,int>>>adj(n+1);//{node,dist}
	 	vector<vector<int>>A;
	 	for(int i=0;i<e;i++){
			int x,y,w; cin>>x>>y>>w;
			adj[x].push_back({y,w});
			adj[y].push_back({x,w}); 
			A.push_back({x,y});
		}
		vector<int>dist(n+1,inf);
		int src=1;
		dist[src]=0;
		set<pair<int,int>>s;//{dist,node}
		s.insert({dist[src],src});
		while(!s.empty()){
			auto x=*(s.begin());
			s.erase(s.begin());
			int d=x.first,node=x.second;
			for(auto i:adj[node]){
				if(dist[i.first]>d+i.second){
					s.erase({dist[i.first],i.first});
					dist[i.first]=d+i.second;
					s.insert({dist[i.first],i.first});
				}
			}
		}
		vector<int>vis(n+1,0);
	
		dfs(1,adj,dist[n],n,vis);
		for(int i=0;i<e;i++){
			int x=A[i][0],y=A[i][1];
			if(ans.find({x,y})!=ans.end() or ans.find({y,x})!=ans.end())cout<<"Yes"<<'\n';
			else cout<<"No"<<'\n';
		}
//		for(auto i:ans){
//		 for(auto j:i)cout<<j<<" "; 
//		 cout<<'\n';
//		}
	}
	
	
return 0;
}
