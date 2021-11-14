#include <bits/stdc++.h>
using namespace std;
#define N 10001
int n;
int rec(int index,vector<int>&A, vector<int>& lsd,vector<int>&dp){
    if(index == n) return 0;
    int maxe = -1e9;
	if(dp[index]!=INT_MIN)return dp[index];
    maxe=max(maxe,A[index]+rec(index+1,A,lsd,dp));
    for(int i=0;i<lsd.size();i++){
		if(lsd[i]+index>=n)break;
		maxe=max(maxe,A[index]+rec(index+lsd[i],A,lsd,dp));
	}
    return dp[index] = maxe;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>sieve(N+1,0),lsd;
	sieve[0]=sieve[1]=1;
	for(int i=2;i*i<N;i++){
		if(sieve[i])continue;
		int t=i*i;
		for(int j=t;j<N;j+=i)
			sieve[j]=1;
	}	
//	cout<<(103%10)<<" ";
	//cout<<endl;
	cin>>n;
	for(int i=2;i<=n;i++){
		if(sieve[i])continue;
		if(i%10==3)lsd.push_back(i);
	}
	//cout<<lsd.size()<<endl;
	vector<int>A(n),dp(n,INT_MIN);
	for(int i=0;i<n;i++)cin>>A[i];
	cout<<rec(0,A,lsd,dp);
return 0;
}

