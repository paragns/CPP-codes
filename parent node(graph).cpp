#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
vector<int> dfs(int node, char req, vector<vector<int>>& adj, vector<int > &vis, vector<char > &val){
	vis[node]=1;
	vector<int>cnt(26,0);
	for( auto i:adj[node]){
		vector<int>temp;
		if(!vis[i] ){
			temp=dfs(i,req,adj,vis,val);
			for(int i=0;i<26;i++)cnt[i]+=temp[i];
		}
	}
	cnt[val[node]-'a']++;
    vis[node]=cnt[val[node]-'a'];
    return cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	cin>>t;
	 while(t--){
	 	int n;cin>>n;
	 	vector<vector<int>>adj(n+1);
	 	vector<int >vis(n+1,0);
	 	vector<char>val(n+1);
	 
	 	for(int i=1;i<=n;i++){
		 	cin>>val[i];
		 }
		for(int i=0;i<n-1;i++){
			int a,b;
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		vector<int>t=dfs(1,val[1],adj,vis,val);
		
	 	for(int i=1;i<=n;i++) cout<<vis[i]<<" ";
	 	
	 }
	
	
return 0;
}
