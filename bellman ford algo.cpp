#include <bits/stdc++.h>
using namespace std;

  
// Driver code
int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>>edges;
	
	for(int i=0;i<m;i++){
		int l,p,w;
		cin>>l>>p>>w;
	edges.push_back({l,p,w});	
	}
	int src;
	cin>>src;
	
	vector<long long int >dist(n,INT_MAX);
	dist[src]=0;
	cout<<"GFdssghnjzkfgdb"<<endl;
	for(int i=0;i<n-1;i++){
		for(auto e:edges){
			
			dist[e[1]]=min(dist[e[1]], dist[e[0]]+e[2]);
		}
	}
	
	cout<<"distance from source"<<endl;
	for(int i=0;i<dist.size();i++){
		cout<<i<<"--->"<<dist[i]<<endl;
	}
	
return 0;
}
