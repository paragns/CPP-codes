#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int dp[27][27][27][27];
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	//memset<dp,-1,sizeofdp>;
	 	int ans=0;
	 	int n,m;
	 	cin>>n>>m;
	 	vector<vector<int>>A(n+1,vector<int>(m+1));
	 	for(int i=1;i<=n;i++){
		 string x; cin>>x;
		 for(int j=1;j<=m;j++){
			A[i][j]=(x[j-1]-'0');
		 }
		 }
		
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				for(int k=0;k<=n;k++){
					for(int l=0;l<=m;l++){
						dp[i][j][k][l]=1;
					}}}}
		 
//		for(int i=0;i<n;i++){
//		 for(int j=0;j<m;j++)cout<<A[i][j];
//		 cout<<endl;
//	}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int k=i;k<=n;k++){
					for(int l=j;l<=m;l++){
						if(A[i][j]==1 or A[k][l]==1)dp[i][j][k][l]=0;
						else if(i==k and j==l and A[i][j]==0){dp[i][j][k][l]=4;ans=max(ans,dp[i][j][k][l]);}
						else if(dp[i][j][k-1][l] and dp[i][j][k][l-1] and A[k][l]==0){
								dp[i][j][k][l]=2*((k-i+1)+(l-j+1));
								ans=max(ans,dp[i][j][k][l]);
								if(i==1 and j==1 and k==3 and l==2)	cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<(dp[i][j][k-1][l] )<<endl;
									
							}
							else dp[i][j][k][l]=0;
								
					}
				}
			}//1,1 (1,3)
		}
		//cout<<dp[1][1][2][2] and dp[1][1][3][1]  ;
		cout<<ans;
	}
return 0;
}
