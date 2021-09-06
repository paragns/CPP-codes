#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int n;
#define ll long long
  vector<int>iv;
  vector<int>pages;
  
  int func(int sz, ll int target, ll int sc){
  		
		if(dp[sz][target]!=-1)return dp[sz][target];	  
	  if(sz==0 or target==0)return dp[sz][target]=sc ;
	  if(pages[sz-1]>target)return dp[sz][target]= func(sz-1,target,sc);
  	   
		 int l=func(sz-1,target-pages[sz-1],sc+iv[sz-1]);
  		 int r=func(sz-1,target,sc);
  		 return dp[sz][target]= max(l,r);
  }//  
  // 3 4 
  // 4 
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	memset(dp,-1,sizeof(dp));
	cin>>n;
	iv.resize(n);
	for(int i=0;i<n;i++){
		cin>>iv[i];
	}
	cin>>n;
	
	pages.resize(n);
	for(int i=0;i<n;i++){
		cin>>pages[i];
		pages[i]*=2;
	}
	ll int target;
	cin>>target;
	cout<<func(n,target,0);
	
return 0;
}
