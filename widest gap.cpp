#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
		ll int n;cin>>n;
		int m;cin>>m;
		vector<vector<ll int>>s(m,vector<ll int>(2)),A;
		
		for(int i=0;i<m;i++)cin>>s[i][0];
		cin>>m;
		for(int i=0;i<m;i++)cin>>s[i][1];
	 	
	 	sort(s.begin(),s.end());
	 	A.push_back({0,1});
	 	A.push_back({s[0][0],s[0][1]});
		 for(int i=0;i<m;i++){
		 	if(s[i][0]<=A[A.size()-1][1])A[A.size()-1][1]=max(A[A.size()-1][1],s[i][1]);
		 	else {
			 	A.push_back({s[i][0],s[i][1]});
			 }
		 }
	 	
	 	ll int ans=0;
	 	for(int i=1;i<A.size()-1;i++)A[i][1]+=1;
	 	A.push_back({n,n});
	 	for(int i=1;i<A.size();i++){
		 	ans=max(ans,A[i][0]-A[i-1][1]);
		 }
		 cout<<ans;
	 }
	
	
return 0;
}
