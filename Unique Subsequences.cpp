    #include <bits/stdc++.h>
    using namespace std;
    # define ll long long
    #define mod 1000000007
    ll int dp[100001][27];
    	string A;	
    ll int func(int pos, char req, bool check){	
    	if(dp[pos][req-'a']!=-1)return dp[pos][req-'a'];
    	if(pos>=A.size() and check)return dp[pos][req-'a']= 1;
    	if(pos>=A.size())return dp[pos][req-'a']=0;
    	if(A[pos]!=req)return dp[pos][req-'a']= func(pos+1,req,check);
    	bool z=check;
    	if(A[pos]=='z' and req=='z')z=1;
    	ll int r=func(pos+1,req+1,z);	
    	ll int l=func(pos+1,req,check);
    	return dp[pos][req-'a']=(r+l)%mod;
    }
    int main(){
    	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    	int t=1;
    	cin>>t;
    	while(t--){
    		memset(dp,-1,sizeof(dp));
    		int n;
    		cin>>n;
    		cin>>A;
    		if(n<26)cout<<0<<'\n';
    		else cout<< func(0,'a',0)<<'\n'; 		
	 }  
    return 0;
    }
