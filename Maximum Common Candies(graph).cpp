#include <bits/stdc++.h>
using namespace std;
bool comp(vector<int> A,vector<int> B){
	if(A.size()>B.size())return 1;
	else return 0;
}
void dfs(int node,int can,vector<vector<vector<int>>> &graph,vector<int> &vis, vector<int> & path ){
	vis[node]=1;
	path.push_back(node);
	
	for(int i:graph[can][node]){
		if(vis[i])continue;
		dfs(i,can,graph,vis,path);
	}
	
	return;
}
  
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	vector<vector<vector<int>>>graph(101,vector<vector<int>>(101,vector<int>(201)));
	int n;
	int m;
	cin>>n>>m;
	vector<int>f(m);
	for(int i=0;i<m;i++){
		cin>>f[i];
	}
	cin>>m;
	vector<int>t(m);
		for(int i=0;i<m;i++){
		cin>>t[i];
	}
	cin>>m;
	vector<int>c(m);
		for(int i=0;i<m;i++){
		cin>>c[i];
	}
	for(int i=0;i<m;i++){
		graph[c[i]][t[i]].push_back(f[i]);
		graph[c[i]][f[i]].push_back(t[i]);
	}

	vector<vector<int>>mat;
	for(int i=1;i<101;i++){
		vector<int>vis(101,0);
		for(int j=0;j<101;j++){
			vector<int>path;
			dfs(j,i,graph,vis,path);
				if(path.size()>1)mat.push_back(path);
			}
		}
		
		
	
	sort(mat.begin(),mat.end(),comp);
	int i=0,ans=0;
	int sz=mat[0].size();
	while(mat[i].size()==sz){
		sort(mat[i].begin(),mat[i].end(),greater<int>());
		ans=max(ans,mat[i][0]*mat[i][1]);
		i++;
	}
		
	
cout<<ans;
return 0;
}
