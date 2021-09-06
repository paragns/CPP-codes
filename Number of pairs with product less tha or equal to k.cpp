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
	//cin>>t;
	 while(T--){
	 	int n;cin>>n;
	 	vector<int>A(n);
	 	for(int i=0;i<n;i++)cin>>A[i];
	 	sort(A.begin(),A.end());
	 	int k;cin>>k;
	 	int ans=0;
	 	for(int i=0;i<n;i++){
		 	int m=k/A[i];
		 int t=upper_bound(A.begin(),A.end(),m)-(A.begin()+i+1);
		 	if(t>0)ans+=t;
			// cout<<ans<<" ";
		 	
		 }
	 	cout<<ans;
	 	
	 	
	 	
	 }
	
	
return 0;
}
