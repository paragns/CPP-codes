#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
bool is_safe(int x,int y ,int n, int m){
	if(x>=1 and y>=1 and x<=n and y<=m)return 1;
	else return 0;
}
int go(int x,int y, vector<vector<int>> &A, int n, int m,vector<vector<int>> &dp){
	if( dp[x][y]!=-1){ return dp[x][y]; }
	if(x==n and y==m )return dp[x][y]=0;
	if(!is_safe(x,y,n,m) or A[x][y]==0)return minf;
	int l=go(x+A[x][y],y,A,n,m,dp);
	int r=go(x,y+A[x][y],A,n,m,dp);
	if(l==minf and r==minf)return dp[x][y]=minf;
	else if(l==minf)return dp[x][y]=1+r;
	else if(r==minf)return dp[x][y]=1+l;
	else return dp[x][y]=1+min(l,r);
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	cin>>t;
	 while(t--){
	 	vector<vector<int>>dp(1030,vector<int>(1030,-1));
		int n,m;
		cin>>n>>m;
		vector<vector<int>>A(n+1,vector<int>(m+1,0));	
	 	for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)cin>>A[i][j]; 
		}
	 	cout<<max(-1,go(1,1,A, n,m,dp))<<'\n';
	 }
	
	
return 0;
}
