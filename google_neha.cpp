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
	 	int n;
	 	cin>>n;
	 	string A="",B="";
	 	
	 	for(int i=0;i<n;i++){
			int t; cin>>t;
			A+=to_string(t); 
		}
		int ans=0;
		map<string, int>mp;
		for(int i=0;i<n;i++){
			string C="";
			for(int j=i;j<n;j++){
				C+=A[j];
				ans+=mp[C];
				mp[C]++;
			}
		}
		cout<<ans<<'\n';
	}
return 0;
}
