    #include <bits/stdc++.h>
    using namespace std;
    # define ll long long
    #define mod 1000000007
    #define inf INT_MAX
    #define minf INT_MIN
   ll int power(ll int x, ll int y){
        if (y == 0)return 1;
        ll int st= power(x, y / 2)%mod;   
         if (y % 2 == 0)
            return ((st)%mod * (st)%mod)%mod;
        else
            return (((x%mod) *st)%mod * (st)%mod)%mod;
    }
    int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	//cin>>t;
	 while(t--){
	 	ll int n;cin>>n;
	 	ll int ans= ((((mod+power(24,n)- (9*power(8,n))%mod)%mod + (18*power(3,n))%mod)%mod + (9*power(2,n))%mod)%mod-24)%mod ;
		 cout<<ans;
	 }
return 0;
}

