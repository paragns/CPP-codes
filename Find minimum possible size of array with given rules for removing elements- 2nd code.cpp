#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
//apply dp
int k;
int func(int l,int h, vector<int>&A){
	if(h-l+1<3)return h-l+1;
	int ans=1+func(l+1,h,A);
	for(int i=l+1;i<=h;i++){
		if(A[i]-A[l]==k and !func(l+1,i-1,A)){
			for(int j=i+1;j<=h;j++){
				if(A[j]-A[i]==k and !func(i+1,j-1,A))
				ans=min(ans,func(j+1,h,A));
			}
		} 
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	int n; cin>>n;
	 	vector<int>A(n);
	 	for(int i=0;i<n;i++)cin>>A[i];
	 	cin>>k;
	 	cout<<func(0,n-1,A);
	 }
	
	
return 0;
}
