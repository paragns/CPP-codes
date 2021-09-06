#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN

ll int func(ll int pos, ll int cnt,ll int currmax, vector<vector<vector<ll int>>> &dp, ll int &n, ll int &m, ll int &tc){
	if(pos>=n and cnt==tc){ return 1;}
	if(pos>=n  or cnt>tc) { return 0;}
	if(dp[pos][cnt][currmax]!=-1)return dp[pos][cnt][currmax]%mod;
	ll int ans=0;
    for(ll int dig=1;dig<=m;dig++){
    	//cout<<dig<<" ";
    	ll int temp=max(dig,currmax);
		ans= (ans+func(pos+1,cnt+(dig>currmax and pos!=0),temp,dp,n,m,tc))%mod;
		if(cnt+(dig>currmax and pos!=0)>tc)break;
		
		//cout<<endl;
	}
	//cout<<pos<<" "<<cnt<<" "<<prev<<" "<<ans<<endl;
	return dp[pos][cnt][currmax]=ans%mod;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	//cin>>T;
	 while(T--){
		ll int q;cin>>q;
	 	vector<ll int>n(q),m(q),tc(q);
	    for(ll int i =0; i<q;i++) cin>>n[i];
	    cin>>q;
	    for(ll int i =0; i<q;i++) cin>>m[i];
	    cin>>q;
	    for(ll int i =0; i<q;i++)cin>>tc[i];
	    
		for(ll int i=0;i<q;i++){
			vector<vector<vector< ll int>>> dp(n[i]+1,vector<vector<ll int>>(m[i]+1,vector<ll int>(m[i]+1,-1)));
			cout<<func(0,0,0,dp,n[i],m[i],tc[i])<<'\n';
			
		}
	 }
return 0;
}

