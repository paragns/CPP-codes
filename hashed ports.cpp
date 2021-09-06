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
	int T=1;
	//cin>>T;
	 while(T--){
	 	int n; cin>>n;
	 	int tt; cin>>tt;
	 	int x;cin>>x;
	 	vector<int>A(x);
	 	for(auto &i:A)cin>>i;
	 	set<vector<int>>busy;
	 	map<int,int>mp;
	 	for(int i=0;i<n;i++)mp[i]=1;
	 	vector<int>ans(x);
	 	int time=1;
	 	int in=0;
	 	while(in!=x){
			while(!busy.empty()){
				auto v=*(busy.begin());
				if(v[0]>time)break;
				mp[v[1]]=1;
				busy.erase(busy.begin());
			}
			if(busy.size()==n){
				auto v=*(busy.begin());
				time=v[0];
				continue;
			}
			 int port=(A[in])%n;
			 if(mp[port]){
			 	mp[port]=0;
			 	ans[in]=port;
			 	busy.insert({time+tt,port});
			 }
			 else{
			 	 
			 	while(mp[port]!=1){
				 	port=(port+1)%n;
				 }
				 busy.insert({time+tt,port});
				 ans[in]=port;
				 mp[port]=0;
			 }
			 in++;
			 time++;
		}
	 	for(int i:ans)cout<<i<<'\n';
	 }
return 0;
}
