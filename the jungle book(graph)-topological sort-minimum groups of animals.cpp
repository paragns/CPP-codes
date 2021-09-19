#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,e;
	cin>>n>>e;
	vector<int>pred(n+1,0);
	vector<vector<int>>adj(n+1);
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		pred[y]++;
	}
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(!pred[i])q.push(i); 
	}
	
	int ans=0;
	while(!q.empty()){
		int sz=q.size();
		while(sz--){
			int t=q.front();
			q.pop();
			for(int j:adj[t]){
				pred[j]--;
				if(!pred[j]) {q.push(j);}
			}
		}
		 ans++;
	}
	cout<<ans<<'\n';
	return 0;
}
