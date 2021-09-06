#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	//cin>>t;
	 while(t--){
	 	int n,e; cin>>n>>e;
	 	vector<vector<int>>adj(n+1);
	 	for(int i=0;i<e;i++){
		 	int x,y;
		 	cin>>x>>y;
		 	adj[x].push_back(y);
		 	adj[y].push_back(x);
		 }
		 vector<int>vis(n+1,0);
		queue<int>q;
		q.push(1);
		vis[1]=1;
		int ans=1;
		while(!q.empty()){
			int x=q.size();
			int temp=0;
			while(x--){
			    int t=q.front();

			    q.pop();
			    for(int i:adj[t]){
			    	if(vis[i])continue;
			    	q.push(i); vis[i]=1;
			    	temp+=i;
			    }
			}
			ans=max(ans,temp);
		}
		cout<<ans; 
	 	
	 	
	 }
	
	
return 0;
}
  
