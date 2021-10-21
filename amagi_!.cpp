#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int n,m;
vector<vector<int>>A,dp;
int func(int i, int j){
	if(i==n-1 and j==m-1)return A[i][j];
	if(i>=n or i<0 or j>=m and j<0)return -1;
	if(dp[i][j]!=-1)return dp[i][j];
	int l=func(i+1,j);
	int r=func(i,j+1);
	return dp[i][j]= A[i][j]+max(l,r);
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	cin>>n;
	 	cin>>m;
	 	A.resize(n,vector<int>(m,0));
	 	dp.resize(n,vector<int>(m,-1));
	 	for(int i=0;i<n;i++)
	 	for(int j=0;j<m;j++)cin>>A[i][j];
	 	
	 	func(0,0);
	}
return 0;
}
