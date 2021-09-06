#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
vector<vector<int>>adj1,adj2;
vector<int>vis;
void dfs(int node, vector<int>& A){
	vis[node]=1;
	for(int i:adj1[node]){
		if(!vis[i])dfs(i,A);
	}
	A.push_back(node);
}
void dfs1(int node, vector<int>& A){
	vis[node]=1;
	A.push_back(node);
	for(int i:adj2[node]){
		if(!vis[i])dfs1(i,A);
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	//cin>>t;
	 while(t--){
	 	int n;
	 	cin>>n;
	 	int e; cin>>e;
	adj1.resize(n+1), adj2.resize(n+1);
	 	for(int i=0;i<e;i++){
		 	int x,y;
		 	cin>>x>>y;
		 	x++,y++;
		 	adj1[x].push_back(y);
		 	adj2[y].push_back(x);
		 }
		 vector<int>lis(n+1,0);
		 vis=lis;
		 vector<int>intime;
		 for(int i=1;i<=n;i++){
		 	if(!vis[i])dfs(i,intime);
		 }
		 vis=lis;
		 vector<vector<int>>ans;
		 for(int i=intime.size()-1;i>=0;i--){ //remember to traverse backwards cause we're not using stack;
		 	vector<int>temp;
		 	if(!vis[intime[i]])dfs1(intime[i],temp);
		 	if(temp.size())ans.push_back(temp);
		 }
		 for(auto i:intime) cout<<i<<" ";
		 cout<<endl;
	 	for(auto i:ans){
		 for(int j:i)cout<<j<<" ";
		 	cout<<endl;
		 }
	 }
	
return 0;
}
