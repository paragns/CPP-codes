        #include<bits/stdc++.h>
        using namespace std;
        #define ll long long
        void solve(){
            int n;
            cin>>n;
           vector<int>a(n),b(n);
           for(int i=0;i<n;i++)cin>>a[i];
            cin>>n;
            for( int i=0;i<n;i++)cin>>b[i];
			for( int i=0;i<n;i++){
                // cout<<a[i]<<" "<<b[i]<<" \n";
                // ll x=b[i] ^ a[i];
                // cout<<;
                if((a[i]-b[i])%2!=0||a[i]<b[i])cout<<0;
                else{
                    ll x=a[i]-b[i];
                    x/=2;
                    ll y =a[i]-x;
                    ll ans=2*x+3*y;
                    ll x4 =x ^ y;
                    if(x4!=b[i])cout<<0 ;
                    else cout<<ans;
                }
                cout<<"\n";
            }
    }
    int main(){
             ios_base::sync_with_stdio(false);
             cin.tie(0);
             cout.tie(0);
            solve();
          return 0;
    }    
