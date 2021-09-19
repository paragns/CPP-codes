#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
int n;
int recur(int pos, int mask,vector<int> &dp){
	if(pos>n)return 1;
	if(dp[mask]!=-1)return dp[mask];
	int ans=0;
	for(int i=0;i<n;i++){
		if(mask & (1<<i))continue;
		if(pos%(i+1)==0 or (i+1)%pos==0){
			ans+=recur(pos+1,mask|(1<<i),dp);
		}
	}
	return dp[mask]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	//cin>>t;
	 while(t--){
		 cin>>n;
		 ll int ans=0;
			 vector<int>dp(pow(2,n+1),-1);
			 ans+=recur(1,0, dp);
			 cout<<ans<<" ";
	 }	
return 0;
}
// 1 2 3 4 5
// * * * * 1
