    #include <bits/stdc++.h>
    using namespace std;
    # define ll long long
    #define mod 1000000007
    #define inf INT_MAX
    #define minf INT_MIN
     
    int main(){
    	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        //
        vector<vector<vector<ll int>>>dp(51,vector<vector<ll int>>(101,vector<ll int>(51,0)));
    	vector<vector<vector<ll int>>>ans(51,vector<vector<ll int>>(101,vector<ll int>(51,0)));
    	
        for(int j =1; j<=100;j++){
            dp[0][j][0]=1;
            ans[0][j][0]=ans[0][j-1][0]+dp[0][j][0];
        }
        for(int i =1;i<50;i++){
            for(int j =1;j<=100;j++){
                for(int k =0;k<=i;k++){
                    dp[i][j][k] =(dp[i-1][j][k]*j)%mod;
                    if(k>=1){
                        dp[i][j][k]=(dp[i][j][k]+ans[i-1][j-1][k-1])%mod;        
                    }
                    ans[i][j][k]=(ans[i][j-1][k]+dp[i][j][k])%mod;
                }
            }
        }
    	int T=1;
    	//cin>>t;
    	 while(T--){	
    	 	int q;cin>>q;
    	 	vector<int>n(q),m(q),tc(q);
    	    for(int i =0; i<q;i++) cin>>n[i];
    	    cin>>q;
    	    for(int i =0; i<q;i++) cin>>m[i];
    	    cin>>q;
    	    for(int i =0; i<q;i++) cin>>tc[i];
    	    for(int i =0;i<q;i++) cout<<ans[n[i]-1][m[i]][tc[i]]<<'\n';
    	 }
    return 0;
    }
