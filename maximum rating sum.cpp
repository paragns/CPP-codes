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
	 	vector<ll int>A(n);
	 	for(int i=0;i<n;i++)cin>>A[i];
	 	ll int sum=0,ans=INT_MIN;
	 	for(int i=0;i<n;i++){
			 if(A[i]>sum+A[i])sum=A[i];
			 else sum+=A[i];
			 ans=max(ans,sum);
		}
	 	cout<<ans;
	 }
	
	
return 0;
}
