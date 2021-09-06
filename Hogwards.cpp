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
	 	int n; cin>>n;
	 	vector<ll int>A(n+1);
	 	for(int i=1;i<=n;i++){
		 	cin>>A[i];
		 }
		 int k; cin>>k;
		ll int high=A[n]-A[1], low=-1;
		 for(int i=2;i<=n;i++){
		 	low=max(low,A[i]-A[i-1]);
		 }
		 while(low<high){
		 	ll int mid=low+(high-low)/2;
		 	int cnt=0;
		 	ll int p=A[1];
			 for(int i=2;i<=n;i++){
			 	if(i==n){
				 	if(A[i]-p>mid){p=A[i-1]; i--;cnt--;}
				 	else if(A[i]-p==mid)p=A[i];
				
				 }
			    else if(A[i]-p<mid)cnt++;
				else if(A[i]-p>mid){
					{ p=A[i-1]; i--;cnt--;}
				}
				else if(A[i]-p==mid){
					p=A[i];
				}		
			 }
			if(cnt>=k)high=mid;
			else low=mid+1; 
		 }
		 
		 cout<<high;
	 }
return 0;
}
