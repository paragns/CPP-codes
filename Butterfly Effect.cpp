#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007;       
 int dp[100001][5];
 int n, k, x;
 
   int func(int indx,int par){
  	if(indx>=n)return 1;
	  if(dp[indx][par]!=-1)return dp[indx][par];
	  
  	int ans=0;
  	for(int i=1;i<=k;i++){
  		if(i==par and par!=x)continue;
  			//cout<<indx<<"*"<<i<<endl;
  			dp[indx+1][i]=func(indx+1,i);
  			ans=(ans+dp[indx+1][i])%mod;
	  }
	  return dp[indx][par]= ans;
  }
// Driver code
int main()
{
	
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int T; 
cin>>T;
 
for(int z=0;z<T;z++){
    cin>>n>>k>>x;
   memset(dp,-1,sizeof(dp));
    cout<< func(0,0)<<endl;
}
return 0;
}
