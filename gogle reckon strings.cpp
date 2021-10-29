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
	cin>>T;
	 while(T--){
	 	int n,m;
	 	cin>>n>>m;
		map<char, set<char>>mp;
	 	unordered_map<string, int>sp;
	 	for(int i=0;i<m;i++){
			char c,d;
			cin>>c>>d;
//			string ab=c+d,ba=d+c;
//			if(sp.find(ab)!=sp.end() or sp.find(ba)!=sp.end())continue;
			mp[c].insert(d);
			mp[d].insert(c); 
		}
		for (auto i:mp){
			char t=i.first;
			for(auto j:mp[t]){
				for(auto k:mp[j]){
					if(k!=t)mp[t].insert(k);
				}
			}
		}
		vector<ll int>ans(n,0);
		vector<vector<ll int>>dp(n+1,vector<ll int>(27,0));
		ans[0]=26;
		for(int i=0;i<26;i++)dp[0][i]=1;
		
		for(int i=0;i<26;i++){
			char t=('a'+i);
			dp[1][i]=26-mp[t].size();
			ans[1]= (ans[1]+dp[1][i])%mod;
		//	cout<<mp[t].size()<<" ";
		}
		//cout<<endl;
		
		for(int i=2;i<n;i++){
			for(int j=0;j<26;j++){
				dp[i][j]+=ans[i-1];
				char t='a'+j;
				for(char k:mp[t]){
					dp[i][j]=(mod+dp[i][j]- dp[i-1][k-'a'])%mod;
					ans[i]= (ans[i]+dp[i][j])%mod;
				}
			}
		}
		cout<<ans[0]<<' '<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<" "<<ans[4];
		//cout<<ans[n-1]<<endl;
	}
return 0;
}
