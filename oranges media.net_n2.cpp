#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX 
// Driver code
vector<vector<pair<int, int>>> adj1,adj2;
vector<int> dijkshtra(int src, vector<vector<pair<int, int>>> &graph){
	int n=graph.size();
	vector<int >dist (n,inf);
	dist[src]=0;
	set<pair<int,int>>s;//{wt,vertex} form;
	s.insert({0,src});
	while(!s.empty()){
		auto x=*(s.begin());
		s.erase(x);
		for(auto i:graph[x.second]){
			if(dist[i.first]>dist[x.second]+i.second){
			//	s.erase({dist[i.first],i.first});
				dist[i.first]=dist[x.second]+i.second;
				s.insert({dist[i.first],i.first});
			}
		}		
	}
	return dist;
}
int main(){
	int n;
	cin>>n;
	vector<int>mark(n);
	vector<int>ans(n,0);
	for(int i=0;i<n;i++){
		cin>>mark[i];
		ans[i]=mark[i];
	}
	adj1.resize(n);
	adj2.resize(n);
	int sz; cin>>sz;
	for(int i=0;i<sz;i++){
		int u,v,w,x;
		cin>>u>>v>>w>>x;
		u--;v--;
		adj1[u].push_back({v,w});
		adj1[v].push_back({u,w});
		adj2[u].push_back({v,w*x});
		adj2[v].push_back({u,w*x});
	}
	for(int i=0;i<n;i++){
		vector<int>temp1=dijkshtra(i,adj1);
		vector<int>temp2=dijkshtra(i,adj2);
		int t=mark[i];
		for(int j=0;j<n;j++){
			t=min(t,mark[j]+temp1[j]+temp2[j]);
		}
		ans[i]=t;
	}
	for(int i:ans)cout<<i<<" ";
return 0;
}


