#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
vector<vector<int>>dp;
int func(int l, int r, string &A){
	if(l>r)return 0;
	if(l==r)return dp[l][r]=1;
	if(dp[l][r]!=-1)return dp[l][r];
	int ans=1+func(l+1,r,A);
	for(int i=l+1;i<=r;i++){
		if(A[i]==A[l])ans=min(ans,func(l+1,i-1,A)+func(i,r,A));
	}
	return dp[l][r]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	string A;
	 	cin>>A;
	 	
	 	int n=A.size();
	 	dp.resize(n,vector<int>(n,-1));
	 	cout<<func(0,n-1,A);
	 	
	 	
	 }
	
	
return 0;
}
//aa
