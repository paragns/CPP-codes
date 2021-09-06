#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX 
// Driver code
int main()
{
	int n,m;cin>>n>>m;
	vector<int >dist (n+1,inf);
	vector<vector<pair<int,int>>> graph(n+1);//{vertex,wt} form
	
	for(int i=0;i<m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		graph[x].push_back({y,w});
		graph[y].push_back({x,w});
	}
	int src;
	cin>>src;
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
	cout<<"dist from source"<<"->"<<src<<endl; 
	for(int i=1;i<=n;i++){
		if(dist[i]==inf)cout<<i<<"->"<<"can't be reached"<<endl;
		cout<<i<<"->"<<dist[i]<<endl;
	}
return 0;
}
