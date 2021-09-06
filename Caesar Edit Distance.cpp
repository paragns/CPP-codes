#include <bits/stdc++.h>
using namespace std;
int c=0;
int dp[501][501];
 int func(string &A, string &B,int n, int m){
    if(n==0)return m;
    if(m==0)return n;
    if(dp[n][m]!=-1)return dp[n][m];
    if(A[n-1]==B[m-1])return dp[n][m]=func(A,B,n-1,m-1);
    
    else return dp[n][m]=min(min(2+func(A,B,n-1,m-1),1+func(A,B,n-1,m)),1+func(A,B,n,m-1));
}
// Driver code

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i=26;
    memset(dp,-1,sizeof(dp));
    string s,d;
    int ans=INT_MAX;
    cin>>s>>d;
   
  // cout<<func(s,d,0,0);	
while(i--){
	
	ans=min(ans,func(s,d,s.size(),d.size()));
	memset(dp,-1,sizeof(dp));
	cout<<s<<"*"<<ans<<endl;
	for(int i=0;i<s.size();i++){
		s[i]++;
		if(s[i]>'z')s[i]='a';
	}
	
}

cout<<ans;
return 0;
}
