#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
const int N=1001;
vector<int>A;
vector<vector<vector<int>>>dp(N,vector<vector<int>>(N,vector<int>(2,-1)));
vector<int> func(int i, int j,int k ){
	//string key=to_string(i)+" "+to_string(j)+to_string(k);
	if(j>=A.size())return {A[i],A[i]};
	if(k>=A.size())return {max(A[i],A[j]),max(A[i],A[j])};
	//if(mp.find(key)!=mp.end())return mp[key];
	auto v=dp[i][j];
	if(v[0]!=-1 and v[1]!=-1)return dp[i][j];
	vector<int> x=func(k, k+1,k+2);
	vector<int> y=func(j, k+1,k+2);
	vector<int> z=func(i, k+1,k+2);
	int l=min({max(A[i], A[j])+x[0],max(A[i], A[k])+y[0], max(A[k], A[j])+z[0]});
	int r=max({max(A[i], A[j])+x[1],max(A[i], A[k])+y[1], max(A[k], A[j])+z[1]});
	return dp[i][j]={l,r};
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n;
	 	cin>>n;
	 	A.resize(n,0);
	 	for(int i=0;i<n;i++)cin>>A[i];
	 	auto v=func(0,1,2);
	 	cout<<v[0]<<" "<<v[1]<<'\n';
	}
return 0;
}
