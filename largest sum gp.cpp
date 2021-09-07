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
	 	int n; cin>>n;
	 	vector<int>A(n);
	 	for(int i=0;i<n;i++)cin>>A[i];
	 	sort(A.begin(),A.end());
	 	int ans=0;
	 vector<vector<int>>dp(n+1,vector<int>(n+1,0));
	 
	 		
	 	dp[n-1][n-1]=A[n-1];
	 	for(int i=0;i<n-1;i++){
			if(A[n-1]%A[i]==0)dp[i][n-1]=A[i]+A[n-1];
			else dp[i][n-1]=A[i];
			ans=max(ans,dp[i][n-1]);
		}
		
		for(int j=n-2;j>=0;j--){
			int i=j-1,k=j+1;
			
			while(i>=0 and j<=n-1){
			//	cout<<i<<" "<<j<<" "<<k<<endl;
				if(A[i]*A[k]<A[j]*A[j]){
					k++;
				}
				else if(A[i]*A[k]>A[j]*A[j]){
					if(A[j]%A[i]==0)dp[i][j]=A[i]+A[j];
					else dp[i][j]=A[i];
					ans=max(ans,dp[i][j]);
					i--;
				}
				else if(A[i]*A[k]==A[j]*A[j]){
					if(A[j]%A[i]==0)dp[i][j]=dp[j][k]+A[i];
					else dp[i][j]=A[i];
					ans=max(ans,dp[i][j]);
					i--;
					k++;
				}	
			}
			if(i>=0){
				if(A[j]%A[i]==0)dp[i][j]=A[i]+A[j];
				else dp[i][j]=A[i];
				ans=max(ans,dp[i][j]);
			}

		}
//			for(int i=0;i<n;i++){
//				for(int j=0;j<n;j++)cout<<dp[i][j]<<" ";
//				cout<<endl;
//			}
		
		cout<<ans;
	
	}
return 0;
}
