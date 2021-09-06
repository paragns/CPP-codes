#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
const int N=100001;
vector<int>primes;
int spf[N];
int dfs(int node, vector<int> &val, int par, vector<vector<int>> &adj,vector<int>& subt){
		int ans=0;
		for(auto j:adj[node]){
			if(j==par)continue;
			ans+=dfs(j,val,node,adj,subt);
		}
		return subt[node]=(spf[val[node]]==val[node])+ans;
	}
int main()
{
	spf[0]=spf[1]=0;
	for(int i=2;i<N;i++){
		if(spf[i]==0){
			spf[i]=i;
			primes.push_back(i);
		}
		for(int j=0;j<primes.size() and i*primes[j]<N; j++){
			spf[i*primes[j]]=primes[j];
		}
	}
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	int n,m; cin>>n>>m;
	 	vector<vector<int>>e(m,vector<int>(2));
	 	for(int i=0;i<m;i++){
		 	cin>>e[i][0];
		 }
		 cin>>m;
	 	for(int i=0;i<m;i++){
		 	cin>>e[i][1];
		 }
		 vector<vector<int>>adj(n+1);
		 for(int i=0;i<e.size();i++){
		 	adj[e[i][0]].push_back(e[i][1]);
		 	adj[e[i][1]].push_back(e[i][0]);
		 }
		 
	 	cin>>n;
	 	vector<int>val(n+1);
	 	for(int i=1;i<=n;i++)cin>>val[i];
	 	int q;cin>>q;
	 	vector<int>query(q);
	 	for(int i=0;i<q;i++)cin>>query[i];
	 	vector<int>subt(n+1);
		 dfs(1,val,-1,adj,subt);
		// for(int i:subt)cout<<i<<" ";
		for(int i:query)cout<<subt[i]<<'\n';
	 }
return 0;
}
