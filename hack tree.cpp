#include <bits/stdc++.h>
using namespace std;
int ans;
void dfs(int node,auto &vis,auto &cost,vector<vector<int>>&adj, int &sum,auto &mp, int k) {
       vis[node]=1
	   sum+=cost[node-1];
  		ans+=mp[sum%k];
       mp[sum%k]++;
		for(int i:adj[node]){
			if(vis[i])continue;
			dfs(i,vis,cost,adj,sum,mp, k);  
		}
		sum-=cost[node-1];
		mp[sum%k]--;
        return;
    }
// Driver code
int main(){
	ans=0;
	int n;
	cin>>n;
	vector<vector <int> >adj(n+1);
	vector<int> cost(n),vis(n+1);
	for(int i=0;i<n;i++)cin>>cost[i];
	cin>>n;
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int l,k;
		cin>>l>>k;
		adj[l].push_back(k);
		adj[k].push_back(l);
	} 
	int k;cin>>k;  
	int sum=0;
	map<int, int>mp;
	mp[0]++;
	dfs(1,vis,cost,adj,sum,mp, k);
    cout<<ans;
	return 0;
}
