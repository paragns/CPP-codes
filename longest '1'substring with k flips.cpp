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
	int t=1;
	//cin>>t;
	 while(t--){
	 	int n;cin>>n;
	 	vector<int>A(n);
	 	for(int i=0;i<n;i++)cin>>A[i];
	 	int k; cin>>k;
		 int l=0;
	 	int ans=0;
	 	int cnt0=0;
	 	for(int i=0;i<n;i++){
		 
		 	if(A[i]==0)cnt0++;
		 	if(cnt0>k){
			 	while(cnt0>k){
				 	if(A[l]==0)cnt0--;
				 	l++;
				 }
			 }
		 	ans=max(ans,i-l+1);	
		 }
	 	
	 	cout<<ans;
	 	
	 }
	
	
return 0;
}
