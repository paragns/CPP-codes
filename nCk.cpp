#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	int n,k; cin>>n>>k;
	 	vector<int>dp1(k+2,0),dp2(k+2,0);
	 	dp1[0]=1,dp2[0]=1;
	 	for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				dp2[j]=dp1[j]+dp1[j-1];
			}
			dp1=dp2; 
		}
	 	cout<<dp2[k];
	 	
	 }
	
	
return 0;
}
