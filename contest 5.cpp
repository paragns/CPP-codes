#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7;

 long int dp[4001][4001];
long int back(int n, int k){
	 if (k == 0 && n == 0)
    return dp[n][k]=1;

  if (n <= 0 || k <= 0)
    return 0;
if(dp[n][k]!=-1)return dp[n][k];
long int l=	back(n-1,k-1);
long int r=back(n-k,k);
//	cout<<(r+l)%mod<<endl;;
	return dp[n][k]=(r+l)%mod;
	
}  
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	memset(dp,-1,sizeof(dp));
int n;
cin>>n;
int k;
cin>>k;

cout<<back(n,k)%mod;

return 0;
}
