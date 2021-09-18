#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
//int ans=0;

vector<vector<vector<ll int>>>dp;
ll int func(int in, string &A, int rem, int m,int flag){
	 if(rem==0 and flag)return dp[in][rem][flag]= (1+func(in,A,0,m,0))%mod;
	 int n=A.size();
	 if(in>=n)return 0;
	 if(dp[in][rem][flag]!=-1)return dp[in][rem][flag]%mod;
	 ll int l=func(in+1,A,rem,m,0);
	 ll int r=func(in+1,A,(rem*10+(A[in]-'0'))%m,m,1);
	 return dp[in][rem][flag]=(l+r)%mod;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n,m;
	 	string A;
	 	cin>>A;
	 	n=A.size();
	 	cin>>m;
	 	dp.resize(n+1,vector<vector<ll int>>(m+1,vector<ll int>(2,-1)));
	 		cout<<func(0,A,0,m,0)%mod;
	}
return 0;
}
