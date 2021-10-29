#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
vector<vector<vector<int>>>adj;
vector<vector<int>>st;
ll int ans=0;
void func(int e, int o, auto &A){
	int odd=0,even=0;
	for(int i=0;i<A.size();i++){
		odd+=A[i][1];
		even+=A[i][0];
		ans+=A[i][0]*(o-odd);
		ans+=A[i][1]*(e-even);
	}
}
vector<int>dfs(int node, int sum, int par){
	vector<vector<int>>temp;
	int odd=0,even=0;
	for(auto i: adj[node]){
		int x=i[0],y=i[1];
		if(x==par)continue;
		auto v=dfs(x,y,node);
		temp.push_back(v);
		even+=v[0];
		odd+=v[1];
	}
	ans+=odd;
	//st[node]={even, odd};
	func(even, odd, temp);
	if(sum%2==0) return {even+1,odd};
	return {odd,even+1};
	
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n;
		cin>>n;
		adj.resize(n+1);
		st.resize(n+1);
		for(int i=0;i<n-1;i++){
			int x,y,w;
			cin>>x>>y>>w;
			adj[x].push_back({y,w});
			adj[y].push_back({x,w});
		}
		dfs(1,0,0);
		cout<<ans;
	}
return 0;
}
