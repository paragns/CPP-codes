#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int dp[1000][1000];
int func(vector<int> &A, int low, int high,int k){
 	if(dp[low][high]!=-1)return dp[low][high];
 	if(high-low+1<3)return high-low+1;
 	int ans=1+func(A,low+1,high,k);
 	for(int i=low+1;i<high;i++){
	 	for(int j=i+1;j<=high;j++){
		 	if(func(A,low+1,i-1,k)==0 and func(A,i+1,j-1,k)==0 and A[low]+k==A[i] and A[i]+k==A[j])
				ans=min(ans,func(A,j+1,high,k)); 	
		}
	 }
	return dp[low][high]=ans; 
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	//cin>>t;
	 while(t--){
	 	memset(dp,-1,sizeof(dp));
		 int n;cin>>n;
	 	vector<int>A(n);
	 	for(int i=0;i<n;i++)cin>>A[i];
	 	int k; cin>>k;
	 	cout<<func(A,0,n-1,k); 	
	 }
return 0;
}
