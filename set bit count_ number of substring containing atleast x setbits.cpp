#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN

ll int bins(ll int low,ll int high, auto &A,ll int x){
	ll int st=low;
	while(low<high){
		ll int mid=low+(high-low)/2;
		//cout<<mid<<endl;
		if(A[mid]-A[st-1] >=x)high=mid;
		else low=mid+1;
	}
	return high;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	cin>>T;
	 while(T--){
	 	ll int n; cin>>n;
	 	string A;
	 	cin>>A;
	 	ll int x; cin>>x;
	 	vector<ll int>pref(n+1);
	 	//if(A[0]=='1')pref[0]=1;
	 	for(int i=1;i<=n;i++){
			pref[i]+=pref[i-1]+(A[i-1]=='1'); 
		}
	//	for(int i:pref)cout<<i<<" ";
		ll int tot=pref[n];
		ll int ans=0;
		for(int i=1;i<=n;i++){
			if(tot-pref[i-1]>=x){
				ll int ind=bins(i,n,pref,x);
			//	cout<<ind<<"*";
				ans+=(n-ind+1);
			}
		}
		cout<<ans<<'\n';
	}
	
return 0;
}
