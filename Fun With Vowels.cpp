#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll int dp[500001][2][2][2][2][2];
	string A;

ll int func(int indx, bool a, bool e, bool i ,bool o, bool u, bool ok){
	if(dp[indx][a][e][i][o][u]!=-1  )return dp[indx][a][e][i][o][u];
	if(indx>=A.size()){
		if(ok)return 0;
		else return -1;
	}
	ll int t=-1;
	if(A[indx]=='a' and a )t=1+func(indx+1,1,1,0,0,0,0);
	if(A[indx]=='e' and e )t=1+func(indx+1,0,1,1,0,0,0);
	if(A[indx]=='i' and i )t=1+func(indx+1,0,0,1,1,0,0);
	if(A[indx]=='o' and o )t=1+func(indx+1,0,0,0,1,1,0);
	if(A[indx]=='u' and u )t=1+func(indx+1,0,0,0,0,1,1);
	t==0? t=-1:t;
	t=max(t,func(indx+1,a,e,i,o,u,ok));
	
 dp[indx][a][e][i][o][u]=t;
	cout<<indx<<"-"<<a<<"-"<<e<<"-"<<i<<"-"<<o<<"-"<<u<<"-"<<t<<"*"<<endl;
	return t;
}
  
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	memset(dp,-1,sizeof(dp));
	cin>>A;
	ll int t=0;
	cout<<max(t,func(0,1,0,0,0,0,0));
return 0;
}

//uaaeioooua
