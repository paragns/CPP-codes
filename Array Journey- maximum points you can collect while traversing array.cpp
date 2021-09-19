#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN

int k,n;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t=1;
	//cin>>t;
	 while(t--){
		 cin>>n;
		 vector<int>A(n);
		for(int i=0;i<n;i++){ cin>>A[i];}	
		cin>>k;
	vector<ll int>dp(n,0);
	//
	deque<ll int>q;
	q.push_back(0);
	dp[0]=a[0];
	for(int i=1;i<n;i++){
		while(!q.empty() and i-q.front()>k)q.pop_front();
		dp[i]=a[i]+dp[q.front()];
		while(!q.empty() and dp[i]>=dp[q.back()])q.pop_back();
		q.push_back(i);
		// cout<<dp[i]<<" ";	
	}
	 cout<<dp[n-1];
	 }
	
	
return 0;
}//1 3
//1 2 3 4 5 6
// 10 12 2
// 10 2 -10 5 20
// 12 2
// 
//        





