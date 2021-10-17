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
	 	int n;
	 	cin>>n;
	 	map<string, int>mp;
	 	while(n--){
	 		string A; int t;
			cin>>A; cin>>t;
			mp[A]+=t;
		}
		for(auto i:mp){
			cout<<i.first<<" "<<i.second<<'\n';
		}
	}
return 0;
}
