#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int>mp;
vector<vector<int>> grid;
vector<int>vis;
vector<int>val;
int dfs(int node){
	string key;
    vis[node]=1;
	int x=1;
	for(int c:grid[node]){
		if(vis[c])continue;
		key=to_string(node)+" "+to_string(c);
		if(mp.find(key)!=mp.end()){ if(!mp[key]) {vis[node]=0;return 0;} else continue;}
		if(val[c]>val[node]) {mp[key]=0; vis[node]=0; return 0 ;} 
		x=dfs(c);
		mp[key]=x;
		if(x==0){vis[node]=0;return 0;}
	}
	vis[node]=0;
return x;
}
int main(){
	//memset(dp,-1,sizeof(dp));
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
		int n,maxe=INT_MIN,e;
	cin>>n>>e;
	grid.resize(n);
	
	for(int i=0;i<e;i++){
		int temp1, temp2;
		cin>>temp1>>temp2;
		grid[temp1].push_back(temp2);
		grid[temp2].push_back(temp1);
	}
	cin>>n;
	vis.resize(n,0);
	val.resize(n);
	for(int i=0;i<n;i++){
		cin>>val[i];
		maxe=max(maxe,val[i]);
	}
	int ans=0;
   
    
	for(int i=0;i<n;i++){
	     
		if(val[i]==maxe)ans+=dfs(i);
		//cout<<dfs(i)<<endl;
	}
cout<<ans;
return 0;
}

