#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n;cin>>n;
	 	unordered_map<int, vector<int>>mp;
		 vector<int>A(n+1,-1),dp(n+1,INT_MAX);
		 dp[n]=0;
	 	for(int i=1;i<n;i++){
			cin>>A[i];
			if(i+A[i]<=n)mp[i+A[i]].push_back(i);
			if(i-A[i]>0)mp[i-A[i]].push_back(i);
		}
		queue<int>q;
    q.push(n);
		while(!q.empty()){
			int t=q.front();
			q.pop();
			for(int i=0;i<mp[t].size();i++){
				q.push(mp[t][i]);
				dp[mp[t][i]]=min(dp[mp[t][i]],dp[t]+1);
			}	
		}
		for(int i=1;i<=n;i++){
			if(dp[i]==INT_MAX)dp[i]=-1;
		cout<<dp[i]<<'\n';
		}
	}
return 0;
}
