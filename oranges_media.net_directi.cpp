#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
	vector<vector<vector<int>>>adj1;
	vector<int>mark;
void dfs(int node, int price, vector<int>&ans){
	ans[node]=price;
	for(auto i: adj1[node]){
		int child=i[0],cost=i[1],tax=i[2];
		if(ans[child]<price+cost+cost*tax)continue;
		dfs(child,price+cost+cost*tax,ans);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n=0;
	 		cin>>n;
	 		mark.resize(n);
	 		set<vector<int>>s;
	 		vector<int>ans(n,0);
			for(int i=0;i<n;i++){
				cin>>mark[i];
				s.insert({mark[i],i});
				ans[i]=mark[i];
			}
			adj1.resize(n+1);
			int sz; cin>>sz;
			for(int i=0;i<sz;i++){
				int u,v,w,x;
				cin>>u>>v>>w>>x;
				u--;v--;
				adj1[u].push_back({v,w,x});
				adj1[v].push_back({u,w,x});
//				adj1[u].push_back({v,x});
//				adj1[v].push_back({u,x});
			}
			while(s.size()){
				auto t=*(s.begin());
				s.erase(s.begin());
				int price=t[0],node=t[1];
				if(ans[node]<price)continue;
				dfs(node, price,ans);
			}
			for(int i:ans)cout<<i<<" ";
		}
	return 0;
}
