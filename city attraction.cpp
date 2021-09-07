#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int n, m, max_t;
int ans = 0;
vector<int> beauty, u, v, t;
vector<pair<int, int>> adj[10000];
bool vis[10000];
void dfs(int s, int t, int ct){
	vis[s]=true;
	cout<<s<<" "<<t<<" "<<ct<<endl;
    if(t > max_t)
        return;
    if(s ==0 ){
        ans = max(ans, ct);
    }
    for(int i=0;i<adj[s].size();i++){
        int x = adj[s][i].first;
        int d = adj[s][i].second;
        if(vis[x]) dfs(x, t + d, ct);
        else{
            dfs(x,t+d,ct+beauty[x]);
            
        }
    }
    vis[s]=false;
}
void solve(){
    for(int i=0;i<m;i++){
        adj[u[i]].push_back({v[i], t[i]});

        adj[v[i]].push_back({u[i], t[i]});
    }
    vis[0] = true;
    dfs(0, 0, beauty[0]);
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	
		 	cin>>n>>m>>max_t;
	
	
	    beauty.resize(n);
	    u.resize(m);
	    v.resize(m);
	    t.resize(m);

		cin>>n;
		    for(int i=0;i<n;i++)
		        cin>>beauty[i];
		cin>>m;
		    for(int i=0;i<m;i++)
		        cin>>u[i];
		cin>>m;
		    for(int i=0;i<m;i++)
		        cin>>v[i];
		cin>>m;
		    for(int i=0;i<m;i++)
		        cin>>t[i];
		    solve();
		
		    cout<<ans<<endl;
	}
	
	
return 0;
}
