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
	 	int dp[n+1][n+1];
	 	for(int i=0;i<n;i++){
			if(A[n-1]%A[i]==0)dp[i][n-1]=2;
			else dp[i][n-1]=1;
			ans=max(ans,dp[i][n-1]);
		}
		
		for(int j=n-2;j>=0;j--){
			int i=j-1,k=j+1;
			
			while(i>=0 and j<=n-1){
				//cout<<i<<" "<<j<<" "<<k<<endl;
				if(A[i]*A[k]<A[j]*A[j]){
					k++;
				}
				else if(A[i]*A[k]>A[j]*A[j]){
					if(A[j]%A[i]==0)dp[i][j]=2;
					else dp[i][j]=1;
					ans=max(ans,dp[i][j]);
					i--;
				}
				else if(A[i]*A[k]==A[j]*A[j]){
					if(A[j]%A[i]==0)dp[i][j]=dp[j][k]+1;
					else dp[i][j]=1;
					ans=max(ans,dp[i][j]);
					i--;
					k++;
				}	
			}
			if(i>=0){
				if(A[j]%A[i]==0)dp[i][j]=2;
				else dp[i][j]=1;
				ans=max(ans,dp[i][j]);
			}
		}
		cout<<ans;
	}
return 0;
}
