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
	cin>>t;
	 while(t--){
	 	int n; cin>>n;
		vector<int>A(n+1);
		int ans=n;
		for(int i=1;i<=n;i++){cin>>A[i];A[i]--;}
		int i=n, ans2=n;
		int ans3=0, prev=0;i=1 ;
		int x=0;
		while(i<=n){
			if(A[i]==0 or i==n){ans=max(ans,ans2-prev+x+(i==n and A[i]>0)); prev=i; x=0;i++; continue;}
			x++; i++;
		}
		
		cout<<ans<<'\n';
		
	 }
	
	
return 0;
}
