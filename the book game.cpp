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
	 	ll int n,k;
	 	cin>>n>>k;
	 	ll int ans=0;
	 	for(int i=0;i<k;i++){
			ll int t=ans;
			ll int m;
			cin>>m;
			m=m%10;
			ans=max(ans,t+m);
			 ans=max(ans,t*m);
			 if(ans==mod){ans=0; break;}
			 ans= ans%mod;
			 
		}
		cout<<ans<<endl;
	 }
	
	
return 0;
}
