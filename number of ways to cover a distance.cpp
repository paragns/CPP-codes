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
	 	vector<int>dp(n+1);
	 	dp[0]=1;
	 	for(int i=1;i<=n;i++){
			if(i-1>=0)dp[i]+=dp[i-1]; 
			if(i-2>=0)dp[i]+=dp[i-2];
			if(i-3>=0)dp[i]+=dp[i-3];
		}
		cout<<dp[n];
;	}
return 0;
}
