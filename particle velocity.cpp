#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n;
	 	cin>>n;
	 	vector<int>A(n);
	 	for(int i=0;i<n;i++)cin>>A[i];
	 	vector<int>diff;
	 	int prev=A[1]-A[0],cnt=1;
	 	for(int i=2;i<n;i++){
			if(A[i]-A[i-1]==prev)cnt++;
			if(i==n-1 or A[i]-A[i-1]!=prev){
				diff.push_back(cnt+1);
				prev=A[i]-A[i-1];
				cnt=1;
			}
		}
		int ans=0;
		for(int i=0;i<diff.size();i++){
			//cout<<diff[i]<<" ";
		 	if(diff[i]>=3){
			 	ans+=((diff[i]-2)*(diff[i]-1))/2;
			 }
		 }
	 cout<<ans;
	}
return 0;
}
