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
	 	int n,k; cin>>n>>k;
	 	ll int sum=0;
		for(int i=0;i<k;i++){
			int m; cin>>m;
			m%=10;
			if(sum!=mod){
				sum=max(sum+m,sum*m);
				sum=sum%mod;
			}
			else{
				if(m==1)sum=1;
			}	
		}
	 	cout<<sum;
	}
return 0;
}
