#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
void dfs(int node, vector<vector<int>>&adj,vector<int>&vis, vector<vector<int>> &A, int &cred, int & diff ){
	vis[node]=1;
	cred+=A[node][0];
	diff+=A[node][1];
	for(auto i:adj[node]){
		if(vis[i])continue;
		dfs(i,adj,vis,A,cred,diff);
	}
}
vector<vector<int>>dp;
int func(int pos, vector<vector<int>>&A, int b){
 	int n=A.size();
	 if(pos==n)return 0;
	 if(dp[pos][b]!=-1)return dp[pos][b];
	 if(b-A[pos][1]<0)return func(pos+1,A,b);
	 int l=func(pos+1,A,b);
	 int r=A[pos][0]+func(pos+1,A,b-A[pos][1]);
	 return dp[pos][b]=max(l,r);
}
int knap(vector<vector<int>>&A, int b){
	dp.resize(A.size()+1,vector<int>(b+1,-1));
	return func(0,A,b);
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n,t;
	 	cin>>n>>t;
	 	vector<vector<int>>adj(n+1),A(n+1);
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			A[i]={u,v};
		}
		int q;
		cin>>q>>t;
		for(int i=0;i<q;i++){
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int B;
		cin>>B;
		vector<int>vis(n+1,0);
		vector<vector<int>>temp;
		for(int i=1;i<=n;i++){
			int cred=0,diff=0;
			if(!vis[i]){dfs(i,adj,vis,A,cred,diff);
				temp.push_back({cred,diff});
			}
		}
//		for(int i=0;i<temp.size();i++){
//			cout<<temp[i][0]<<" "<<temp[i][1]<<endl;
//		}
		cout<<knap(temp,B);
	}
return 0;
}

