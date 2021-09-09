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
		////1 2 3 4 5 6 7 8 9 _ 11 _ _
		ll int n,k; cin>>n>>k;
		vector<ll int>A(n);
		for(ll int i=0;i<n;i++)cin>>A[i];
		ll int ans=LLONG_MAX;
		for(int i=0;i<=k;i++){
			int ptr=i;
			ll int temp=0;
			while(ptr<n){
				temp+=A[ptr];
				ptr+=(2*k+1);
			}
			ptr=ptr-2*k-1;
			if(ptr+k>=n-1){
				//	cout<<temp;
				ans=min(ans,temp);
			}
		
		}
		cout<<ans; 	
	}
return 0;
}
