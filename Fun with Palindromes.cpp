#include <bits/stdc++.h>
using namespace std;
int dp[3001][3001];
long long int func(string  &A, int i,int j){
	if(dp[i][j]!=-1)return dp[i][j];
	if(i==j)return dp[i][j]=1;
	if(j<i)return 0;
	if(A[i]==A[j])return dp[i][j]=2+func(A,i+1,j-1);
	long long int l=func(A,i+1,j);
	long long int r=func(A,i,j-1);
	 return dp[i][j]=max(l,r);
}
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
	string A;
	cin>>A;
	long long int ans=0;
	for(int len=A.size()-1;len>0;len--){
		ans=max(ans,func(A,0,len-1)*func(A,len,A.size()-1));			
	}
	cout<<ans;

return 0;
}


